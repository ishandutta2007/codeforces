#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct binaryHeap{
  void *array;
  size_t heap_size;
  size_t max_size;
  size_t val_size;
  int (*cmp) (const void *, const void *);
} heap;

heap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  heap *h = (heap *) calloc (1, sizeof (heap));
  h->array = malloc (val_size * (1 + 1));
  h->heap_size = 0;
  h->max_size = 1;
  h->val_size = val_size;
  h->cmp = cmpF;
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

static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) a;
    uint64_t *q = (uint64_t *) b;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      uint64_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  } else {
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (val_size--) {
      uint8_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  }
}

static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) src;
    uint64_t *q = (uint64_t *) dst;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      *q++ = *p++;
    }
  } else {
    uint8_t *p = (uint8_t *) src;
    uint8_t *q = (uint8_t *) dst;
    while (val_size--) {
      *q++ = *p++;
    }
  }
}

void push (heap *h, const void *val) {
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1;
    h->array = realloc (h->array, h->val_size * (h->max_size + 1));
  }
  h->heap_size++;
  uint8_t *array = (uint8_t *) h->array;
  size_t k = h->heap_size;
  const size_t val_size = h->val_size;
  int (*cmp) (const void *, const void *) = h->cmp;
  heap_func_copy(array + k * val_size, val, val_size);
  while(k>1){
    size_t parent = k / 2;
    if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
      return;
    }
    heap_func_swap (array + parent * val_size, array + k * val_size, val_size);
    k = parent;
  }
}

void pop (heap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array;
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
    int c = cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1));
    size_t next = 2 * k + (c <= 0 ? 0 : 1);
    if (cmp (array + val_size * k, array + val_size * next) <= 0) return;
    heap_func_swap (array + val_size * k, array + val_size * next, val_size);
    k = next;
  }
  if (2 * k <= n && cmp (array + val_size * k, array + val_size * 2 * k) > 0) {
    heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
  }
}

void top (const heap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
}

typedef int32_t edge_weight;

typedef struct directed_edge {
  int32_t vertex;
  int32_t next;
  edge_weight cost;
} graph_edge;

typedef struct directedGraph {
  graph_edge *edge;
  int32_t *start;
  int32_t pointer;
  int32_t vertex_num;
  int32_t edge_max_size;
} graph;

graph* new_graph (const int vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->vertex_num = vertex_num;
  g->edge_max_size = 1;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void free_graph (graph *g) {
  free (g->edge);
  free (g->start);
  free (g);
  return;
}

void clear_graph (graph *g) {
  g->pointer = 0;
  for (int32_t i = 0; i < g->vertex_num; ++i) {
    g->start[i] = -1;
  }
}

void add_edge (graph *g, int32_t from, int32_t to, edge_weight cost) {
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  g->edge[g->pointer] = (graph_edge) {to, g->start[from], cost};
  g->start[from] = g->pointer++;
}

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef struct node {
  i32 v;
  i64 d;
} node;

int cmp_node(const void *a, const void *b) {
  i64 d = ((node *)a)->d - ((node *)b)->d;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  const i32 k = read_int();
  graph * const g = new_graph (n);
  for (i32 i = 0; i < m; ++i) {
    i32 x = read_int() - 1;
    i32 y = read_int() - 1;
    i32 w = read_int();
    add_edge (g, x, y, w);
    add_edge (g, y, x, w);
  }
  i64 *dp = (i64 *) calloc (n, sizeof (i64));
  const i64 inf = (i64)1000000000 * n + 1;
  for (i32 i = 0; i < n; ++i) {
    dp[i] = inf;
  }
  dp[0] = 0;
  i32 *remain = (i32 *) calloc (m, sizeof (i32));
  heap *h = new_binary_heap (sizeof (node), cmp_node);
  push (h, &((node){0, 0}));
  i32 cnt = 0;
  while (!is_empty (h) && cnt < k) {
    node t;
    pop (h, &t);
    if (dp[t.v] < t.d) continue;
    for (i32 p = g->start[t.v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      i64 d = t.d - g->edge[p].cost;
      if (dp[u] == d) {
	remain[p / 2] = 1;
	cnt++;
	break;
      }
    }
    for (i32 p = g->start[t.v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      i64 d = t.d + g->edge[p].cost;
      if (d >= dp[u]) continue;
      dp[u] = d;
      push (h, &((node){u, dp[u]}));
    }
  }
  print_int (cnt);
  puts("");
  for (i32 i = 0; i < m; ++i) {
    if (remain[i]) {
      print_int (i + 1);
      cnt--;
      putchar (cnt == 0 ? '\n' : ' ');
    }
  }
}

int main (void) {
  run ();
  return 0;
}