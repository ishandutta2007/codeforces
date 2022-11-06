#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105, mod = 998244353;

int n, ax[sz], ay[sz];
vector <int> g[sz], ara;
bool done[sz], vis[sz];

void dfs(int u) {
   vis[u] = 1;
   ara.push_back(u);
   for(int v : g[u]) if(!vis[v]) dfs(v);
}

ll ways[sz], idk[sz];

ll fac[sz], finv[sz], inv[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
}

ll prm(int n, int r) {
   if(n < r or r < 0) return 0;
   return fac[n] * finv[n-r] % mod;
}

int main() {
   prec();
   cin >> n;
   for(int i=1; i<=n; i++) cin >> ax[i] >> ay[i];

   map <int, vector<pair<int,int>>> mp;
   for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
         int d = abs(ax[i] - ax[j]) + abs(ay[i] - ay[j]);
         mp[d].emplace_back(i, j);
      }
   }

   vector <int> cc;
   for(auto &[xxx, vec] : mp) {
      for(int i=1; i<=n; i++) g[i].clear();
      for(auto [u, v] : vec) {
         g[u].push_back(v);
         g[v].push_back(u);
      }
      memset(vis, 0, sizeof vis);
      for(int i=1; i<=n; i++) if(!vis[i] and !g[i].empty()) {
         ara.clear();
         dfs(i);
         bool yes = 1;
         for(int u : ara) {
            if(done[u]) yes = 0;
            done[u] = 1;
         }
         int z = ara.size();
         int edges = z * (z - 1);
         for(int u : ara) edges -= g[u].size();
         if(edges) yes = 0;
         if(yes) cc.push_back(z);
      }
   }
   int sum = 0;
   for(int x : cc) sum += x;
   ways[n - sum] = 1;

   for(int x : cc) {
      memset(idk, 0, sizeof idk);
      for(int i=0; i+x<=n; i++) idk[i+x] += ways[i];
      for(int i=0; i<n; i++) idk[i+1] += ways[i];
      for(int i=0; i<=n; i++) ways[i] = idk[i];
   }

   ll ans = 0;
   for(int i=1; i<=n; i++) {
      ans += ways[i] * prm(n, i) % mod;
      ans %= mod;
   }
   cout << ans;
}