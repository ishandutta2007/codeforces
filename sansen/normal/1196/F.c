#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void msort_memcpy (uint8_t * restrict dst, uint8_t * restrict src, size_t size) {
  while (size--) {
    *dst++ = *src++;
  }
}

void msort (void * const array, const size_t num, const size_t size, int (* const cmp) (const void *, const void *)) {
  typedef struct operation {
    size_t l;
    size_t r;
    int32_t type;
  } op;
  uint8_t * const a = (uint8_t *) array;
  uint8_t * const tmp = (uint8_t *) malloc (size * num);
  op stack[64];
  int32_t top = 0;
  stack[top++] = (op) {0, num, 0};
  while (top > 0) {
    const op t = stack[--top];
    if (t.l + 1 >= t.r) continue;
    const size_t m = (t.l + t.r) / 2;
    if (t.type == 0) {
      stack[top++] = (op) {t.l, t.r, 1};
      stack[top++] = (op) {t.l, m  , 0};
      stack[top++] = (op) {m  , t.r, 0};
      continue;
    }
    msort_memcpy (tmp, a + t.l * size, (m - t.l) * size);
    size_t i = 0;
    size_t j = m * size;
    size_t k = t.l * size;
    while (i < (m - t.l) * size && j < t.r * size) {
      if (cmp (tmp + i, a + j) <= 0) {
        msort_memcpy (a + k, tmp + i, size);
        i += size;
      } else {
        msort_memcpy (a + k, a + j, size);
        j += size;
      }
      k += size;
    }
    msort_memcpy (a + k, tmp + i, (m - t.l) * size - i);
  }
  free (tmp);
}

typedef int64_t i64;
typedef int32_t i32;

typedef struct union_find {
  int32_t *parent;
  int32_t *next;
  int32_t size;
} union_find;

void init_union_find (union_find * const u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1;
    u->next[i] = i;
  }
}

union_find* new_union_find (const int32_t size) {
  union_find * const u = (union_find *) calloc (1, sizeof (union_find));
  u->parent = (int32_t *) calloc (2 * size, sizeof (int32_t));
  u->next = u->parent + size;
  u->size = size;
  init_union_find (u);
  return u;
}

void free_union_find (union_find * const u) {
  free (u->parent);
  free (u);
}

int32_t root (union_find * const u, int32_t x) {
  if (u->parent[x] < 0) return x;
  return u->parent[x] = root (u, u->parent[x]);
}

int same (union_find * const u, const int32_t x, const int32_t y) {
  return root (u, x) == root (u, y);
}

int32_t get_size (union_find * const u, const int32_t x) {
  return - (u->parent[root (u, x)]);
}

void unite (union_find * const u, int32_t x, int32_t y) {
  x = root (u, x);
  y = root (u, y);
  if (x == y) return;
  if (u->parent[x] > u->parent[y]) {
    const int32_t swap = x;
    x = y;
    y = swap;
  }
  u->parent[x] += u->parent[y];
  u->parent[y] = x;
  const int32_t swap = u->next[x];
  u->next[x] = u->next[y];
  u->next[y] = swap;
}

void enumerate (const union_find * const u, int32_t x, int32_t *res) {
  int32_t len = 0;
  res[len++] = x;
  int32_t y = u->next[x];
  while (y != x) {
    res[len++] = y;
    y = u->next[y];
  }
}

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

typedef struct edge {
  i32 a, b, c;
} edge;

int cmp_edge (const void *a, const void *b) {
  i32 d = ((edge *)a)->c - ((edge *)b)->c;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

int cmp_int32 (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

int cmp_int64 (const void *a, const void *b) {
  i64 d = *(i64 *)a - *(i64 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 to_index (i32 *z, i32 len, i32 v) {
  i32 l = 0;
  i32 r = len;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (z[m] <= v) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  const i32 k = read_int();
  edge *e = ALLOC (m, edge);
  for (i32 i = 0; i < m; ++i) {
    e[i].a = read_int() - 1;
    e[i].b = read_int() - 1;
    e[i].c = read_int();
  }
  SORT (e, m, cmp_edge);
  union_find *u = new_union_find (n);
  for (i32 i = 0; i < m && i < k; ++i) {
    edge f = e[i];
    if (same (u, f.a, f.b)) continue;
    unite (u, f.a, f.b);
  }
  uint8_t *used = ALLOC (n, uint8_t);
  i64 *ans = ALLOC (k * k, i64);
  i32 alen = 0;
  i32 *v = ALLOC (n, i32);
  i64 *d = ALLOC (401 * 401, i64);
  for (i32 i = 0; i < n; ++i) {
    const i32 r = root (u, i);
    const i32 size = get_size (u, r);
    if (size == 1 || used[r]) continue;
    used[r] = 1;
    enumerate (u, r, v);
    SORT (v, size, cmp_int32);
    for (i32 j = 0; j < size * size; ++j) {
      d[j] = (i64) size * 1000000000;
      if (j % size == j / size) {
        d[j] = 0;
      }
    }
    for (i32 j = 0; j < m && j < k; ++j) {
      if (!same (u, r, e[j].a)) continue;
      i32 a = to_index (v, size, e[j].a);
      i32 b = to_index (v, size, e[j].b);
      d[a * size + b] = d[b * size + a] = e[j].c;
    }
    for (i32 k = 0; k < size; ++k) {
      for (i32 a = 0; a < size; ++a) {
        for (i32 b = 0; b < size; ++b) {
          i64 v = d[a * size + k] + d[k * size + b];
          d[a * size + b] = MIN (d[a * size + b], v);
        }
      }
    }
    for (i32 j = 0; j < size; ++j) {
      for (i32 k = j + 1; k < size; ++k) {
        ans[alen++] = d[j * size + k];
      }
    }
  }
  SORT (ans, alen, cmp_int64);
  print_int (ans[k - 1]);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}