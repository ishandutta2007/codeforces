#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 998244353;

ll dp[sz], pw[sz];
string s[sz];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);

   pw[0] = 1;
   for(int i=1; i<sz; i++) pw[i] = (pw[i-1] << 1) % mod;

   for(int i=2; i<sz; i++) {
      dp[i] = pw[i-2] + 2 * dp[i-2] + dp[i-1];
      dp[i] %= mod;
   }

   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++) cin >> s[i];

   int zero = 0;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         zero += s[i][j] == 'o';
      }
   }

   ll ans = 0;
   for(int i=0; i<n; i++) {
      int k = 0;
      for(int j=0; j<m; j++) {
         if(s[i][j] == 'o') k++;
         else {
            ans += dp[k] * pw[zero - k] % mod;
            if(ans >= mod) ans -= mod;
            k = 0;
         }
      }
      ans += dp[k] * pw[zero - k] % mod;
      if(ans >= mod) ans -= mod;
   }
   for(int j=0; j<m; j++) {
      int k = 0;
      for(int i=0; i<n; i++) {
         if(s[i][j] == 'o') k++;
         else {
            ans += dp[k] * pw[zero - k] % mod;
            if(ans >= mod) ans -= mod;
            k = 0;
         }
      }
      ans += dp[k] * pw[zero - k] % mod;
      if(ans >= mod) ans -= mod;
   }

   ans %= mod;
   if(ans < 0) ans += mod;
   cout << ans;
}