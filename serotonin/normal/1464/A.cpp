#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

vector <int> g[sz];
bitset <sz> vis;

int dfs(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v]) return 1 + dfs(v);
   return 1;
}

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n, m;
      scanf("%d %d", &n, &m);
      for(int i=1; i<=n; i++) vis[i] = 0, g[i].clear();
      while(m--) {
         int u, v;
         scanf("%d %d", &u, &v);
         if(u == v) continue;
         g[u].push_back(v);
         g[v].push_back(u);
      }
      int ans = 0;
      for(int i=1; i<=n; i++) {
         if(vis[i]) continue;
         if(g[i].size() == 1) ans += dfs(i) - 1;
      }
      for(int i=1; i<=n; i++) {
         if(g[i].empty() || vis[i]) continue;
         ans += dfs(i) + 1;
      }
      printf("%d\n", ans);
   }
}