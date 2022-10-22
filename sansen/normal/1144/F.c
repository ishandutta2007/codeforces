#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

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

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  graph *g = new_graph (n);
  for (i32 i = 0; i < m; ++i) {
    i32 a = read_int() - 1;
    i32 b = read_int() - 1;
    add_edge (g, a, b);
    add_edge (g, b, a);
  }
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  i32 *stack = (i32 *) calloc (n, sizeof (i32));
  i32 top = 0;
  a[0] = 1;
  stack[top++] = 0;
  while (top > 0) {
    i32 v = stack[--top];
    for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      if (a[u] > 0 && a[u] == a[v]) {
	puts("NO");
	return;
      }
      if (a[u] == 0) {
	a[u] = a[v] ^ 1 ^ 2;
	stack[top++] = u;
      }
    }
  }
  puts("YES");
  for (i32 i = 0; i < m; ++i) {
    i32 f = g->edge[2 * i].vertex;
    putchar (a[f] == 1 ? '0' : '1');
  }
  puts("");
}

int main (void) {
  run ();
  return 0;
}