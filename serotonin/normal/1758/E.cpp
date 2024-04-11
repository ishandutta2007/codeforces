#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7, mod = 1e9+7;

vector <int> a[sz], now;
vector <pair<int,int>> g[sz];
bool vis[sz];
int ara[sz], h;

void dfs(int u) {
   vis[u] = 1;
   now.push_back(u);
   for(auto &[v, sum] : g[u]) if(!vis[v]) {
      ara[v] = sum - ara[u];
      if(ara[v] < 0) ara[v] += h;
      dfs(v);
   }
}

void solve() {
   int n, m;
   scanf("%d %d %d", &n, &m, &h); 
   for(int i=0; i<n; i++) {
      a[i].clear();
      a[i].resize(m);
      for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
   }

   for(int i=0; i<n+m; i++) vis[i] = 0, g[i].clear();

   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(~a[i][j]) {
            int u = i, v = n + j;
            if(a[i][j]) a[i][j] = h - a[i][j];
            g[u].emplace_back(v, a[i][j]);
            g[v].emplace_back(u, a[i][j]);
         }
      }
   }

   ll ans = 1;
   int cnt = 0;
   for(int i=0; i<n+m; i++) if(!vis[i]) {
      now.clear();
      ara[i] = 0;
      dfs(i);
      for(int u : now) if(u < n) {
         for(int v=0; v<m; v++) if(~a[u][v]) {
            int sum = ara[u] + ara[n + v];
            if(sum >= h) sum -= h;
            if(sum != a[u][v]) ans = 0;
         }
      }
      cnt++;
   }
   while(--cnt) ans = ans * h % mod;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}