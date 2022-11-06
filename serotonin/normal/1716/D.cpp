#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mod = 998244353;

int ans[sz], dp[sz], cum[sz];

int main() {
   int n, k;
   cin >> n >> k;
   dp[0] = 1;
   for(int j = k, sum = 0; sum <= n; sum += j, j++) {
      for(int i=0; i<=n; i++) {
         cum[i] = 0;
         if(i >= j) {
            cum[i] += cum[i - j];
            cum[i] >= mod ? cum[i] -= mod : 1;
         }
         cum[i] += dp[i];
         cum[i] >= mod ? cum[i] -= mod : 1;

         dp[i] = cum[i] - dp[i];
         dp[i] < 0 ? dp[i] += mod : 1;

         ans[i] += dp[i];
         ans[i] >= mod ? ans[i] -= mod : 1;
      }
   }

   for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}