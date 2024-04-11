#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair <ll,ll> pii;
#define x first
#define y second

const int N = 3<<10;
const ll INF = 1<<30;

struct Edge {
   int v, rpos;
   ll cap, cost, flow = 0;
   Edge() {}
   Edge(int v, int p, ll cap, ll c) : v(v), rpos(p), cap(cap), cost(c) {}
};

struct mcmf {
   int n;
   vector <vector<Edge>> E;

   ll mCap[N], dis[N];
   int par[N], pos[N];
   bitset <N> vis;

   mcmf (int n) : n(n), E(n) {}

   void addEdge(int u, int v, ll cap, ll cost = 0) {
      E[u].emplace_back(v, E[v].size(), cap, cost);
      E[v].emplace_back(u, E[u].size() - 1, 0, -cost);
   }

   inline bool SPFA(int S, int T) {
      vis.reset();
      for(int i=0; i<n; i++) mCap[i] = dis[i] = INF;
      queue <int> q; q.push(S);
      dis[S] = 0, vis[S] = 1;

      while(!q.empty()) {
         int i = 0, u = q.front(); q.pop();
         vis[u] = 0;
         for(auto &e : E[u]) {
            int v = e.v;
            ll f = e.cap - e.flow, w = dis[u] + e.cost;
            if(f > 0 && dis[v] > w) {
               dis[v] = w, par[v] = u, pos[v] = i;
               mCap[v] = min(mCap[u], f);
               if(!vis[v]) q.push(v);
               vis[v] = 1;
            }
            ++i;
         }
      }
      return dis[T] != INF;
   }

   pii solve(int S, int T) {
      ll F = 0, C = 0;
      while(SPFA(S, T)) {
         int v = T;
         ll f = mCap[v];
         F += f;
         while(v != S) {
            int u = par[v];
            Edge &e = E[u][pos[v]];
            e.flow += f;
            E[v][e.rpos].flow -= f;
            v = u;
         }
         C += dis[T] * f;
      }
      return make_pair(F, C);
   }
};

char s[15];
queue <int> q[N];

void go(int u) {
   if(q[u].empty()) return;
   int v = q[u].front(); q[u].pop();
   int x = u ^ v;
   int b = 31 - __builtin_clz(x);
   printf("%d ", b);
   go(v);
}

int main() {
   int d, n;
   cin >> d >> n;
   int nodes = (2 << d) + 2;
   mcmf g(nodes);
   int source = nodes - 2, sink = nodes - 1;
   for(int i=0; i<n; i++) {
      scanf("%s", s);
      int m = 0;
      for(int j=0; j<d; j++) if(s[j] == '1') m |= 1 << j;
      int u = m << 1, v = u | 1;
      g.addEdge(u, sink, 1, -1);
      g.addEdge(source, v, 1, 1);
   }
   for(int i=0; i<(1<<d); i++) {
      int u = i << 1, v = u | 1;
      g.addEdge(u, v, INF, 0);
      for(int j=0; j<d; j++) if(i & 1 << j) {
         int x = i ^ (1 << j);
         g.addEdge(v, x << 1, INF, 1);
      }
      if(!i) g.addEdge(u, sink, INF, 0);
   }
   auto [flow, cst] = g.solve(source, sink);
   assert(flow == n);
   printf("%d\n", cst - 1);

   for(int i=0; i<(1<<d); i++) {
      int v = i << 1 | 1;
      for(auto &e : g.E[v]) {
         int z = e.flow, x = e.v >> 1, y = i;
         while(z-- > 0) q[x].push(y);
      }
   }

   while(1) {
      go(0);
      if(q[0].empty()) break;
      printf("R ");
   }
}