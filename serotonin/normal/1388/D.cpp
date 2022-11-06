#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

ll a[sz];
bitset <sz> vis;
vector <int> g[sz], ts;

void dfs(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v]) dfs(v);
   ts.push_back(u);
}

void t_sort(int n) {
   ts.clear();
   for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
   reverse(ts.begin(), ts.end());
}

int main() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]), g[i].clear();
   for(int i=1; i<=n; i++) {
      int j;
      scanf("%d", &j);
      if(j < 0) continue;
      g[i].push_back(j);
   }
   t_sort(n);

   ll ans = 0;
   vector <int> age, pore;
   for(int i : ts) {
      ll x = a[i];
      ans += x;
      for(int j : g[i]) a[j] += max(0LL, x);
      if(x < 0) pore.push_back(i);
      else age.push_back(i);
   }
   reverse(pore.begin(), pore.end());

   printf("%lld\n", ans);
   for(int x : age) printf("%d ", x);
   for(int x : pore) printf("%d ", x);
}