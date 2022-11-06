#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005, mod = 998244353;

ll a[sz], b[sz];
bool vis[sz];
vector <int> g[sz], ts;

void dfs(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v]) dfs(v);
   ts.push_back(u);
}

void t_sort(int n) {
   ts.clear();
   for(int i=1; i<=n; i++) vis[i] = 0;
   for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
   reverse(ts.begin(), ts.end());
}

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   for(int i=1; i<=n; i++) g[i].clear();

   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
   }
   
   ll ans = 0;
   while(1) {
      bool yes = 0;
      for(int i=1; i<=n; i++) {
         for(int j : g[i]) if(!a[j] and a[i]) yes = 1;
      }
      if(!yes) break;
      for(int i=1; i<=n; i++) b[i] = 0;
      for(int i=1; i<=n; i++) {
         if(!a[i]) continue;
         a[i]--;
         for(int j : g[i]) b[j]++;
      }
      for(int i=1; i<=n; i++) a[i] += b[i];
      ans++;
   }

   t_sort(n);
   for(int i=1; i<=n; i++) a[i] %= mod;

   for(int i : ts) {
      for(int j : g[i]) {
         a[j] += a[i];
         a[j] %= mod;
      }
   }

   int v = ts.back();
   ans += a[v];
   ans %= mod; ans += mod; ans %= mod;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}