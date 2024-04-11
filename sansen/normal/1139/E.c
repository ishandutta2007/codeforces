#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t flow_type;

const flow_type flow_inf = 5000;

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
  graph *g = (graph *) calloc (1, sizeof (graph));
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
  static int32_t *level = NULL, *queue = NULL, *iter = NULL;
  if (level == NULL) {
    level = (int32_t *) calloc (vertex_num, sizeof (int32_t));
    queue = (int32_t *) calloc (vertex_num, sizeof (int32_t));
    iter  = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  }
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
      flow_type f = dinic_dfs (src, g, dst, level, iter, flow_inf);
      if (f <= 0) break;
      flow += f;
    }
  }
  return flow;
}

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 *p = (i32 *) calloc (2 * n, sizeof (i32));
  i32 *c = p + n;
  for (i32 i = 0; i < n; ++i) {
    p[i] = read_int();
  }
  for (i32 i = 0; i < n; ++i) {
    c[i] = read_int() - 1;
  }
  i32 d = read_int();
  uint8_t *ng = (uint8_t *) calloc (n, sizeof (uint8_t));
  i32 *index = (i32 *) calloc (d, sizeof (i32));
  for (i32 i = 0; i < d; ++i) {
    index[i] = read_int() - 1;
    ng[index[i]] = 1;
  }
  const i32 q = 5001;
  graph *g = new_graph (1 + m + q + 1);
  const i32 src = m + q;
  const i32 dst = src + 1;
  for (i32 i = 0; i < n; ++i) {
    if (ng[i]) continue;
    add_edge (g, c[i] + q, p[i], flow_inf);
  }
  for (i32 i = 0; i < m; ++i) {
    add_edge (g, src, i + q, 1);
  }
  add_edge (g, 0, dst, 1);
  i32 *ans = (i32 *) calloc (d + 1, sizeof (i32));
  for (i32 i = d - 1; i >= 0; --i) {
    ans[i] = ans[i + 1];
    while (dinic (g, src, dst)) {
      ans[i]++;
      add_edge (g, ans[i], dst, 1);
    }
    i32 k = index[i];
    add_edge (g, c[k] + q, p[k], 1);
  }
  for (i32 i = 0; i < d; ++i) {
    print_int (ans[i]);
    putchar ('\n');
  }
}

int main (void) {
  run ();
  return 0;
}