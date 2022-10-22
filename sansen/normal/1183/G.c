#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<assert.h>

typedef struct binary_heap {
  void *array;
  size_t heap_size;
  size_t max_size;
  size_t val_size;
  int (*cmp) (const void *, const void *);
} heap;

heap* new_binary_heap (const size_t val_size, int (*cmp_func) (const void *, const void *)) {
  heap *h = (heap *) calloc (1, sizeof (heap));
  h->array = malloc (val_size * (1 + 1));
  h->heap_size = 0;
  h->max_size = 1;
  h->val_size = val_size;
  h->cmp = cmp_func;
  return h;
}

int32_t get_heap_size (const heap *h) {
  return h->heap_size;
}

int is_empty (const heap *h) {
  return h->heap_size == 0;
}

void free_heap (heap *h) {
  free (h->array);
  free (h);
}

void init_heap (heap *h) {
  h->heap_size = 0;
}

static inline void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) a;
    uint64_t *q = (uint64_t *) b;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      const uint64_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  } else {
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (val_size--) {
      const uint8_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  }
}

static inline void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
  const uint8_t *p = (const uint8_t *) src;
  uint8_t *q = (uint8_t *) dst;
  while (val_size--) {
    *q++ = *p++;
  }
}

void push (heap * const h, const void *val) {
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1;
    h->array = realloc (h->array, h->val_size * (h->max_size + 1));
  }
  h->heap_size++;
  uint8_t * const array = (uint8_t *) h->array;
  size_t k = h->heap_size;
  const size_t val_size = h->val_size;
  int (* const cmp) (const void *, const void *) = h->cmp;
  heap_func_copy(array + k * val_size, val, val_size);
  while (k > 1) {
    size_t parent = k / 2;
    if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
      return;
    }
    heap_func_swap (array + parent * val_size, array + k * val_size, val_size);
    k = parent;
  }
}

void pop (heap * const h, void *res) {
  assert (!is_empty (h));
  uint8_t * const array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
  heap_func_copy (array + val_size, array + val_size * h->heap_size, val_size);
  h->heap_size--;
  int (* const cmp) (const void *, const void *) = h->cmp;
  const size_t n = h->heap_size;
  size_t k = 1;
  while (2 * k  + 1 <= n) {
    const int c = cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1));
    const size_t next = 2 * k + (c <= 0 ? 0 : 1);
    if (cmp (array + val_size * k, array + val_size * next) <= 0) return;
    heap_func_swap (array + val_size * k, array + val_size * next, val_size);
    k = next;
  }
  if (2 * k <= n && cmp (array + val_size * k, array + val_size * 2 * k) > 0) {
    heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
  }
}

void top (const heap *h, void *res) {
  assert (!is_empty (h));
  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
}

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

typedef struct node {
  i32 cnt;
  i32 one;
} node;

int cmp_node_cnt (const void *a, const void *b) {
  i32 d = ((node *)a)->cnt - ((node *)b)->cnt;
  return d == 0 ? 0 : d > 0 ? -1 : 1;
}

int cmp_node_one (const void *a, const void *b) {
  i32 d = ((node *)a)->one - ((node *)b)->one;
  return d == 0 ? 0 : d > 0 ? -1 : 1;
}

void run (void) {
  i32 q = read_int();
  heap *h = new_binary_heap (sizeof (node), cmp_node_cnt);
  heap *g = new_binary_heap (sizeof (node), cmp_node_one);
  while (q--) {
    i32 n = read_int();
    i32 *cnt = ALLOC (2 * n, i32);
    for (i32 i = 0; i < n; ++i) {
      i32 a = read_int() - 1;
      i32 f = read_int();
      cnt[f * n + a] += 1;
    }
    init_heap (h);
    init_heap (g);
    for (i32 i = 0; i < n; ++i) {
      i32 c = cnt[i] + cnt[n + i];
      if (c == 0) continue;
      push (h, &(node){c, cnt[n + i]});
    }
    i32 sum = 0;
    i32 sum_one = 0;
    i32 prev = n + 1;
    while (prev > 1 && !(is_empty (h) && is_empty (g))) {
      i32 v = prev - 1;
      if (is_empty (g)) {
        node t;
        top (h, &t);
        v = t.cnt;
      }
      while (!is_empty (h)) {
        node t;
        top (h, &t);
        if (t.cnt < v) break;
        pop (h, &t);
        push (g, &t);
      }
      sum += v;
      node t;
      pop (g, &t);
      sum_one += MIN (v, t.one);
      prev = v;
    }
    print_int (sum);
    putchar (' ');
    print_int (sum_one);
    puts ("");
    free (cnt);
  }
}

int main (void) {
  run ();
  return 0;
}