#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int n, a[sz], f[sz], l[sz], c[sz], cn[sz], dp[sz];

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) {
      int x;
      scanf("%d", &x);
      a[i] = x;
      if(!f[x]) f[x] = i;
      l[x] = i;
      c[x]++;
   }

   int ans = n, mx = 0;
   for(int i=1; i<=n; i++) {
      int x = a[i];
      ans = min(ans, cn[x] + (n - c[x]) - mx);
      if(l[x] == i) {
         mx = max(mx, dp[f[x] - 1] + c[x]);
         ans = min(ans, n - mx);
      }
      cn[x]++;
      dp[i] = mx;
   }
   printf("%d\n", ans);
}