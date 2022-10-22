#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef i64 flow_type;

const flow_type flow_inf = (i64) 1000000000 * 1000;

typedef struct flow_edge {
  int32_t vertex;
  int32_t next;
  flow_type capacity;
} flow_edge;

typedef struct maxFlowGraph {
  flow_edge *edge;
  int32_t *start;
  int32_t vertex_num;
  int32_t pointer;
  int32_t edge_length;
} graph;

graph* new_graph (const int32_t vertex_num) {
  graph * const g = (graph *) calloc (1, sizeof (graph));
  g->vertex_num = vertex_num;
  const int32_t initial_length = 4;
  g->edge = (flow_edge *) calloc (initial_length, sizeof (flow_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->edge_length = initial_length;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void free_graph (graph * const g) {
  free (g->edge);
  free (g->start);
  free (g);
}

void clear_graph (graph * const g) {
  g->pointer = 0;
  memset (g->start, -1, sizeof (int32_t) * g->vertex_num);
}

void add_edge (graph * const g, const int32_t from, const int32_t to, const flow_type capa) {
  if (g->pointer == g->edge_length) {
    g->edge_length *= 2;
    g->edge = (flow_edge *) realloc (g->edge, sizeof (flow_edge) * g->edge_length);
  }
  const int32_t p = g->pointer;
  g->edge[p] = (flow_edge) {to, g->start[from], capa};
  g->start[from] = p;
  g->edge[p + 1] = (flow_edge) {from, g->start[to], 0};
  g->start[to] = p + 1;
  g->pointer += 2;
}

void add_edge_undirected (graph * const g, const int32_t u, const int32_t v, const flow_type capa) {
  if (g->pointer == g->edge_length) {
    g->edge_length *= 2;
    g->edge = (flow_edge *) realloc (g->edge, sizeof (flow_edge) * g->edge_length);
  }
  const int32_t p = g->pointer;
  g->edge[p] = (flow_edge) {v, g->start[u], capa};
  g->start[u] = p;
  g->edge[p + 1] = (flow_edge) {u, g->start[v], capa};
  g->start[v] = p + 1;
  g->pointer += 2;
}

flow_type dinic_dfs (const int32_t v, const graph * const g, const int32_t dst, const int32_t * const level, int32_t * const iter, flow_type e) {
  if (v == dst) return e;
  flow_type sum = 0;
  for (int32_t p = iter[v]; p != -1; p = g->edge[p].next, iter[v] = p) {
    const int32_t u = g->edge[p].vertex;
    const flow_type capa = g->edge[p].capacity;
    if (level[u] <= level[v] || capa <= 0) continue;
    const flow_type f = dinic_dfs (u, g, dst, level, iter, capa < e ? capa : e);
    if (f > 0) {
      g->edge[p].capacity -= f;
      g->edge[p ^ 1].capacity += f;
      sum += f;
      e -= f;
      if (e <= 0) return sum;
    }
  }
  return sum;
}

flow_type dinic (const graph * const g, const int32_t src, const int32_t dst) {
  const int32_t vertex_num = g->vertex_num;
  int32_t * const level = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  int32_t * const queue = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  int32_t * const iter  = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  flow_type flow = 0;
  while (1) {
    memset (level, 0, sizeof (int32_t) * vertex_num);
    int32_t front = 0;
    int32_t last = 0;
    level[dst] = vertex_num;
    queue[last++] = dst;
    while (front < last && level[src] == 0) {
      const int32_t v = queue[front++];
      for (int32_t p = g->start[v]; p!=-1; p = g->edge[p].next) {
        const int32_t u = g->edge[p].vertex;
        if (g->edge[p ^ 1].capacity > 0 && level[u] == 0) {
          level[u] = level[v] - 1;
          queue[last++] = u;
        }
      }
    }
    if (level[src] == 0) break;
    memcpy (iter, g->start, sizeof (int32_t) * vertex_num);
    while (1) {
      const flow_type f = dinic_dfs (src, g, dst, level, iter, flow_inf);
      if (f <= 0) break;
      flow += f;
    }
  }
  free (level);
  free (queue);
  free (iter);
  return flow;
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  graph *g = new_graph (n + m + 2);
  i32 src = 0;
  i32 dst = n + m + 1;
  for (i32 i = 1; i <= n; ++i) {
    add_edge (g, m + i, dst, read_int());
  }
  i64 sum = 0;
  for (i32 i = 1; i <= m; ++i) {
    i32 u = read_int();
    i32 v = read_int();
    i32 w = read_int();
    sum += w;
    add_edge (g, src, i, w);
    add_edge (g, i, u + m, flow_inf);
    add_edge (g, i, v + m, flow_inf);
  }
  i64 ans = sum - dinic (g, src, dst);
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}