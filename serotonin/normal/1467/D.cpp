#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5005, mod = 1e9+7;

ll a[sz], cum[sz], dp[sz][sz], pt[sz][sz];

int main() {
   int n, k, q;
   cin >> n >> k >> q;
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

   for(int i=1; i<=n; i++) dp[i][0] = 1;
   for(int j=0; j<k; j++) {
      for(int i=1; i<=n; i++) {
         dp[i-1][j+1] += dp[i][j];
         dp[i+1][j+1] += dp[i][j];
         dp[i-1][j+1] %= mod;
         dp[i+1][j+1] %= mod;
      }
   }

   for(int i=1; i<=n; i++) {
      for(int j=0; j<=k; j++) {
         pt[i][j] = dp[i][j] * dp[i][k-j] % mod;
      }
   }

   ll ans = 0;
   for(int i=1; i<=n; i++) {
      for(int j=0; j<=k; j++) cum[i] += pt[i][j];
      cum[i] %= mod;
      ans += cum[i] * a[i] % mod;
      ans %= mod;
   }

   while(q--) {
      int i, x;
      scanf("%d %d", &i, &x);
      ans += (x - a[i]) * cum[i] % mod;
      ans += mod; ans %= mod;
      printf("%lld\n", ans);
      a[i] = x;
   }
}