#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct segment_tree_void {
  void *array;
  int32_t size;
  size_t val_size;
  void (*func) (void *, const void *, const void *);
} segment_tree;

static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
  uint8_t *p = dst;
  const uint8_t *q = src;
  while (size--) {
    *p++ = *q++;
  }
}

segment_tree* new_segment_tree (const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)) {
  int32_t k = 1;
  while (k < n) k *= 2;
  segment_tree *s = (segment_tree *) calloc (1, sizeof (segment_tree));
  s->array = calloc (2 * k, val_size);
  s->size = k;
  s->val_size = val_size;
  s->func = func;
  for (int32_t i = k; i < 2 * k; ++i) {
    segment_tree_memcpy ((uint8_t *)s->array + i * val_size, ini, val_size);
  }
  uint8_t *a = s->array;
  for (int32_t i = k - 1; i > 0; --i) {
    func (a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size);
  }
  return s;
}

void update (segment_tree * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t * const p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
  for (k >>= 1; k > 0; k >>= 1) {
    s->func (p + k * size, p + 2 * k * size, p + (2 * k + 1) * size);
  }
}

void update_tmp (segment_tree * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t * const p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
}

void update_all (segment_tree * const s) {
  uint8_t * const a = s->array;
  const size_t size = s->val_size;
  for (int32_t i = s->size - 1; i > 0; --i) {
    s->func (a + i * size, a + (2 * i) * size, a + (2 * i + 1) * size);
  }
}

void find (const segment_tree *s, int32_t l, int32_t r, void *res) {
  int32_t lindex[64];
  int32_t rindex[32];
  int32_t llen = 0;
  int32_t rlen = 0;
  for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lindex[llen++] = l++;
    if (r & 1) rindex[rlen++] = --r;
  }
  while (rlen > 0) {
    lindex[llen++] = rindex[--rlen];
  }
  const uint8_t *p = s->array;
  segment_tree_memcpy (res, p + lindex[0] * s->val_size, s->val_size);
  for (int32_t i = 1; i < llen; ++i) {
    s->func (res, res, p + lindex[i] * s->val_size);
  }
}

typedef int64_t i64;
typedef int32_t i32;

typedef i32 deque_val;

typedef struct Deque {
  deque_val *array;
  size_t front;
  size_t last;
  size_t mask;
} Deque;

Deque* new_deque (void) {
  const size_t len = 2;
  Deque *d = (Deque *) calloc (len, sizeof (Deque));
  d->array = (deque_val *) calloc (len, sizeof (deque_val));
  d->front = d->last = 0;
  d->mask = len - 1;
  return d;
}

void init_deque (Deque *d) {
  d->front = d->last = 0;
}

void free_deque (Deque *d) {
  free (d->array);
  free (d);
}

int is_empty (Deque *d) {
  return d->front == d->last;
}

size_t get_size (Deque *d) {
  return (d->last + (~d->front + 1)) & d->mask;
}

void deque_realloc (Deque *d) {
  deque_val *array = (deque_val *) calloc (2 * (d->mask + 1), sizeof (deque_val));
  size_t k = 0;
  for (size_t i = d->front; i != d->last; i = (i + 1) & d->mask) {
    array[k++] = d->array[i];
  }
  free (d->array);
  d->array = array;
  d->front = 0;
  d->last = k;
  d->mask = 2 * d->mask + 1;
}

deque_val pop_front (Deque *d) {
  deque_val res = d->array[d->front];
  d->front = (d->front + 1) & d->mask;
  return res;
}

deque_val pop_back (Deque *d) {
  d->last = (d->last + d->mask) & d->mask;
  return d->array[d->last];
}

deque_val get_front (const Deque *d) {
  return d->array[d->front];
}

deque_val get_back (const Deque *d) {
  return d->array[(d->last + d->mask) & d->mask];
}

void push_front (Deque *d, const deque_val v) {
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d);
  }
  d->front = (d->front + d->mask) & d->mask;
  d->array[d->front] = v;
}

void push_back (Deque *d, const deque_val v) {
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d);
  }
  d->array[d->last] = v;
  d->last = (d->last + 1) & d->mask;
}

deque_val get_at (Deque *d, size_t index) {
  return d->array[(d->front + index) & d->mask];
}

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void min_func (void *c, const void *a, const void *b) {
  i32 x = *(i32 *)a;
  i32 y = *(i32 *)b;
  *(i32 *)c = x < y ? x : y;
}

i32 can (i32 *a, i32 *b, i32 n, segment_tree *s) {
  Deque **d = ALLOC (n + 1, Deque *);
  for (i32 i = 1; i <= n; ++i) {
    d[i] = new_deque();
  }
  for (i32 i = 0; i < n; ++i) {
    update (s, i, a + i);
    push_back (d[a[i]], i);
  }
  i32 ok = 1;
  for (i32 i = 0; i < n; ++i) {
    if (is_empty (d[b[i]])) {
      ok = 0;
      break;
    }
    i32 k = pop_front (d[b[i]]);
    i32 v;
    find (s, 0, k + 1, &v);
    if (v < b[i]) {
      ok = 0;
      break;
    }
    i32 inf = n + 1;
    update (s, k, &inf);
  }
  for (i32 i = 1; i <= n; ++i) {
    free (d[i]);
  }
  free (d);
  return ok;
}

void run (void) {
  i32 t = read_int();
  i32 *a = ALLOC (300000, i32);
  i32 *b = ALLOC (300000, i32);
  i32 initial = 0;
  segment_tree *s = new_segment_tree (&initial, 300000, sizeof (i32), min_func);
  while (t--) {
    i32 n = read_int();
    for (i32 i = 0; i < n; ++i) {
      a[i] = read_int();
    }
    for (i32 i = 0; i < n; ++i) {
      b[i] = read_int();
    }
    puts (can (a, b, n, s) ? "YES" : "NO");
  }
}

int main (void) {
  run ();
  return 0;
}