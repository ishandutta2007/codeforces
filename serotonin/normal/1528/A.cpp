#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], b[sz];
ll dp[sz][2];
vector <int> g[sz];

ll fnc(int u, int p, int f) {
   ll &w = dp[u][f];
   if(w >= 0) return w;
   w = 0;
   int x = f ? b[u] : a[u];
   for(int v : g[u]) if(v ^ p) {
      ll one = abs(b[v] - x) + fnc(v, u, 1);
      ll two = abs(a[v] - x) + fnc(v, u, 0);
      w += max(one, two);
   }
   return w;
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]), g[i].clear();
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   for(int i=1; i<=n; i++) dp[i][0] = dp[i][1] = -1;
   printf("%lld\n", max(fnc(1, 0, 0), fnc(1, 0, 1)));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}