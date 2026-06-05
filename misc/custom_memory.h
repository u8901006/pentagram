#ifndef CUSTOM_MEMORY_H
#define CUSTOM_MEMORY_H

namespace Pentagram {
typedef void* (*allocFunc)(size_t size);
typedef void (*deallocFunc)(void* ptr);
extern allocFunc palloc;
extern deallocFunc pfree;
}

#define ENABLE_CUSTOM_MEMORY_ALLOCATION()					\
	void * operator new(size_t size);						\
	void operator delete(void * ptr);

#define DEFINE_CUSTOM_MEMORY_ALLOCATION(Classname)			\
void * Classname::operator new(size_t size) {				\
	return Pentagram::palloc(size);							\
}															\
															\
void Classname::operator delete(void * ptr) {				\
	Pentagram::pfree(ptr);									\
}

#endif
