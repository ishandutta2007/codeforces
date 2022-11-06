#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

ll p[sz], h[sz], sum[sz], bad[sz];
bool yes;
vector <int> g[sz];

void dfs(int u, int par) {
   sum[u] = p[u];
   bad[u] = 0;
   for(int v : g[u]) if(v ^ par) {
      dfs(v, u);
      sum[u] += sum[v];
      bad[u] += bad[v];
   }
   ll x = sum[u] - h[u];
//   printf("* %lld %lld %d\n", x, bad[u], u);
   if(x & 1) yes = 0;
   x >>= 1;
   if(x > sum[u] || x < 0) yes = 0;
   if(x - bad[u] > p[u]) yes = 0;
   bad[u] = x;
}

void solve() {
   int n, m;
   cin >> n >> m;
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<=n; i++) scanf("%lld", &p[i]);
   for(int i=1; i<=n; i++) scanf("%lld", &h[i]);
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   yes = 1;
   dfs(1, 0);
   if(yes) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}