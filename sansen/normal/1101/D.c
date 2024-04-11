#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

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

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

i32 bfs (i32 src, i32 prime, graph *g, i32 *a, i32 *q, i32 *dp) {
  static uint8_t *used = NULL;
  if (used == NULL) {
    used = (uint8_t *) calloc (g->vertex_num, sizeof (uint8_t));
  }
  i32 front = 0;
  i32 last =  0;
  q[last++] = src;
  dp[src] = 0;
  used[src] = 1;
  while (front < last) {
    i32 v = q[front++];
    for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      if (used[u] || a[u] % prime !=0) continue;
      q[last++] = u;
      used[u] = 1;
      dp[u] = dp[v] + 1;
    }
  }
  for (i32 i = 0; i < last; ++i) {
    used[q[i]] = 0;
  }
  return last;
}

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  graph *g = new_graph (n);
  for (i32 i = 1; i < n; ++i) {
    i32 u = read_int() - 1;
    i32 v = read_int() - 1;
    add_edge (g, u, v);
    add_edge (g, v, u);
  }
  const i32 m = 200000;
  i32 *f = (i32 *) calloc (m + 1, sizeof (i32));
  for (i32 i = 1; i <= m; ++i) {
    f[i] = i;
  }
  for (i32 i = 2; i * i <= m; ++i) {
    if (f[i] != i) continue;
    for (i32 j = i * i; j <= m; j += i) {
      f[j] = i;
    }
  }
  i32 max = 0;
  i32 *q = (i32 *) calloc (n, sizeof (i32));
  i32 *dp = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    while (a[i] > 1) {
      i32 p = f[a[i]];
      i32 len = bfs (i, p, g, a, q, dp);
      bfs (q[len - 1], p, g, a, q, dp);
      if (max < dp[q[len - 1]] + 1) {
	max = dp[q[len - 1]] + 1;
      }
      for (i32 j = 0; j < len; ++j) {
	while (a[q[j]] % p == 0) {
	  a[q[j]] /= p;
	}
      }
    }
  }
  print_int (max);
  puts("");
}

int main (void) {
  run ();
  return 0;
}