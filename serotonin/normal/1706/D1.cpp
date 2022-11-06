#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3005;

int a[sz], upto[sz];
vector <int> g[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) {
      scanf("%d", &a[i]); g[i].clear();
      for(int j=1; j<=k; j++) g[i].push_back(a[i] / j);
      sort(g[i].begin(), g[i].end());
      g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
      upto[i] = 0;
   }

   int ans = sz, mxv = *max_element(a + 1, a + n + 1);
   for(int up = mxv / k; up <= mxv; up++) {
      int dn = mxv;
      for(int i=1; i<=n; i++) {
         int &j = upto[i];
         while(j + 1 < g[i].size() and g[i][j + 1] <= up) j++;
         dn = min(dn, g[i][j]);
      }
      ans = min(ans, up - dn);
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}