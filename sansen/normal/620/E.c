#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct directed_edge {
  int32_t vertex;
  int32_t next;
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

void add_edge (graph *g, int32_t from, int32_t to) {
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  g->edge[g->pointer] = (graph_edge) {to, g->start[from]};
  g->start[from] = g->pointer++;
}

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

typedef struct segment_node {
  i64 assign;
  i64 elem;
} node;

typedef struct segment_tree {
  node *a;
  i32 size, bit;
} segment_tree;

segment_tree* new_segment_tree (i32 n) {
  i32 bit = 0;
  while ((1 << bit) < n) ++bit;
  segment_tree *s = ALLOC (1, segment_tree);
  s->a = ALLOC (2 << bit, node);
  s->size = 1 << bit;
  s->bit = bit;
  return s;
}

i64 eval (node t) {
  return t.assign != 0 ? t.assign : t.elem;
}

void propagate (segment_tree *s, i32 x) {
  x += s->size;
  node *a = s->a;
  for (i32 i = s->bit; i > 0; --i) {
    i32 k = x >> i;
    if (a[k].assign == 0) continue;
    a[2 * k].assign = a[2 * k + 1].assign = a[k].elem = a[k].assign;
    a[k].assign = 0;
  }
}

void save (segment_tree *s, i32 x) {
  x += s->size;
  node *a = s->a;
  for (x >>= 1; x > 0; x >>= 1) {
    a[x].elem = eval (a[2 * x]) | eval (a[2 * x + 1]);
  }
}

void update (segment_tree *s, i32 l, i32 r, i32 c) {
  propagate (s, l);
  propagate (s, r - 1);
  for (i32 x = l + s->size, y = r + s->size; x < y; x >>= 1, y >>= 1) {
    if (x & 1) s->a[x++].assign = (i64) 1 << c;
    if (y & 1) s->a[--y].assign = (i64) 1 << c;
  }
  save (s, l);
  save (s, r - 1);
}

i64 query (segment_tree *s, i32 l, i32 r) {
  propagate (s, l);
  propagate (s, r - 1);
  i64 ans = 0;
  for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans |= eval (s->a[l++]);
    if (r & 1) ans |= eval (s->a[--r]);
  }
  return ans;
}

void euler_tour (i32 v, i32 *k, graph *g, i32 *l, i32 *r, uint8_t *used) {
  used[v] = 1;
  l[v] = *k;
  *k += 1;
  for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
    i32 u = g->edge[p].vertex;
    if (used[u]) continue;
    euler_tour (u, k, g, l, r, used);
  }
  r[v] = *k;
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 *c = ALLOC (n, i32);
  for (i32 i = 0; i < n; ++i) {
    c[i] = read_int();
  }
  graph *g = new_graph (n);
  for (i32 i = 1; i < n; ++i) {
    i32 x = read_int() - 1;
    i32 y = read_int() - 1;
    add_edge (g, x, y);
    add_edge (g, y, x);
  }
  i32 *l = ALLOC (n, i32);
  i32 *r = ALLOC (n, i32);
  uint8_t *used = ALLOC (n, uint8_t);
  i32 index = 0;
  euler_tour (0, &index, g, l, r, used);
  segment_tree *s = new_segment_tree (n);
  for (i32 i = 0; i < n; ++i) {
    update (s, l[i], l[i] + 1, c[i]);
  }
  while (m--) {
    i32 type = read_int();
    i32 v = read_int() - 1;
    if (type == 1) {
      i32 c = read_int();
      update (s, l[v], r[v], c);
    } else {
      i64 t = query (s, l[v], r[v]);
      t = (t & 0x5555555555555555) + ((t >> 1) & 0x5555555555555555);
      t = (t & 0x3333333333333333) + ((t >> 2) & 0x3333333333333333);
      t = (t & 0x0F0F0F0F0F0F0F0F) + ((t >> 4) & 0x0F0F0F0F0F0F0F0F);
      t = (t & 0x00FF00FF00FF00FF) + ((t >> 8) & 0x00FF00FF00FF00FF);
      t = (t & 0x0000FFFF0000FFFF) + ((t >> 16) & 0x0000FFFF0000FFFF);
      i32 ans = (t & 0x00000000FFFFFFFF) + (t >> 32);
      print_int (ans);
      puts ("");
    }
  }
}

int main (void) {
  run ();
  return 0;
}