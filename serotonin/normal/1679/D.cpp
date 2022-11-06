#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, lim = 1e9;

bool no;
int a[sz], dis[sz], md, color[sz];
vector <int> g[sz];

void dfs(int u, int p) {
   if(a[u] > md) return;
   color[u] = 1;
   for(int v : g[u]) {
      if(no) return;
      if(color[v] == 1) {
         no = 1;
         return;
      }
      if(!color[v]) dfs(v, u);
   }
   color[u] = 2;
}

bool vis[sz];
vector <int> ts;

void go(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v] and a[v] <= md) go(v);
   ts.push_back(u);
}

void t_sort(int n) {
   ts.clear();
   for(int i=1; i<=n; i++) vis[i] = 0;
   for(int i=1; i<=n; i++) if(!vis[i] and a[i] <= md) go(i);
}

int main() {
   int n, m, k;
   cin >> n >> m >> k;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
   }

   int lo = 1, hi = lim + 1;
   while(lo < hi) {
      md = lo + hi >> 1;
      no = 0;
      for(int i=1; i<=n; i++) color[i] = 0;
      for(int i=1; i<=n; i++) if(!color[i]) dfs(i, -1);

      if(no) {
         hi = md;
         continue;
      }

      t_sort(n);
      int res = 0;
      for(int x : ts) {
         dis[x] = 1;
         for(int y : g[x]) if(a[y] <= md) dis[x] = max(dis[x], 1 + dis[y]);
         res = max(res, dis[x]);
      }
      if(res >= k) hi = md;
      else lo = md + 1;
   }
   if(lo > lim) puts("-1");
   else cout << lo;
}