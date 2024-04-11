#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

bitset <sz> vis, qd;
vector <int> g[sz];

void dfs(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v]) dfs(v);
}

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) vis[i] = 0, g[i].clear();
   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dfs(1);
   int ans = 0;
   for(int i=1; i<=n; i++) ans += vis[i], vis[i] = qd[i] = 0;
   if(ans < n) {
      puts("NO");
      return;
   }

   vector <int> res;
   queue <int> q;
   q.push(1); qd[1] = 1;
   while(!q.empty()) {
      int u = q.front(); q.pop();
      if(vis[u]) continue;
      vis[u] = 1;
      res.push_back(u);
      for(int v : g[u]) {
         if(vis[v]) continue;
         vis[v] = 1;
         for(int w : g[v]) {
            if(!vis[w] && !qd[w]) qd[w] = 1, q.push(w);
         }
      }
   }

   puts("YES");
   printf("%d\n", res.size());
   for(int x : res) printf("%d ", x);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}