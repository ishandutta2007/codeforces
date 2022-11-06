#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 3005, mx = 101, inf = 1e18;

int a[sz], b[sz];
bitset <mx> d[mx], vis;

struct edge {
   int u, v;
   ll cap, flow = 0;
   edge () {}
   edge (int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
   int n;
   vector <edge> E;
   vector <vector <int>> g;
   vector <int> d, pt;

   Dinic (int n) : n(n), E(0), g(n), d(n), pt(n) {}

   void addEdge(int u, int v, ll cap) {
      g[u].emplace_back(E.size());
      E.emplace_back(u, v, cap);
      g[v].emplace_back(E.size());
      E.emplace_back(v, u, 0);
   }

   bool BFS(int S, int T) {
      queue <int> q; q.push(S);
      for(int i=0; i<n; i++) d[i] = n+1;
      d[S] = 0;
      while(!q.empty()) {
         int u = q.front(); q.pop();
         if(u == T) break;
         for(int k : g[u]) {
            edge &e = E[k];
            if(e.flow < e.cap && d[e.v] > d[e.u] + 1) {
               d[e.v] = d[e.u] + 1;
               q.push(e.v);
            }
         }
      }
      return d[T] != n+1;
   }

   ll DFS(int u, int T, ll flow = INT_MAX) {
      if(u == T || !flow) return flow;
      for(int &i=pt[u]; i<g[u].size(); i++) {
         int eid = g[u][i];
         edge &e = E[eid], &rve = E[eid ^ 1];
         if(d[e.v] ^ d[e.u] + 1) continue;
         if(ll pushed = DFS(e.v, T, min(e.cap - e.flow, flow))) {
            e.flow += pushed;
            rve.flow -= pushed;
            return pushed;
         }
      }
      return 0;
   }

   ll MaxFlow(int S, int T) {
      ll total = 0;
      while(BFS(S, T)) {
         for(int i=0; i<n; i++) pt[i] = 0;
         while(ll flow = DFS(S, T))
            total += flow;
      }
      return total;
   }
};

int main() {
   int n, ans = 0;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=n; i++) scanf("%d", &b[i]);
   for(int i=1; i<=n; i++) if(b[i] > 0) ans += b[i];

   for(int i=1; i<mx; i++)
      for(int j=1; j<=i; j++)
         if(i % j == 0) d[i][j] = 1;

   Dinic din(n+2);
   for(int i=1; i<=n; i++) {
      vis.reset();
      for(int j=i-1; j; j--) {
         if(!vis[a[j]] and d[a[i]][a[j]]) {
            din.addEdge(i, j, inf);
            vis |= d[a[j]];
         }
      }
      if(b[i] < 0) din.addEdge(i, n+1, -b[i]);
      else din.addEdge(0, i, b[i]);
   }
   cout << ans - din.MaxFlow(0, n+1);
}