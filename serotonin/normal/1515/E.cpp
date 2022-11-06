#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 405;

int n, mod, dp[sz][sz];
ll fac[sz], finv[sz], cut[sz];

ll bigmod(ll b, ll n) {
   if(n == -1) n = mod - 2;
   ll ans = 1;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

int fnc(int i, int r) {
   if(i < 0) {
      if(!r) return 1;
      return 0;
   }
   if(i < r or !i) return 0;
   int &w = dp[i][r];
   if(w >= 0) return w;
   w = 0;
   for(int j=1; j<=r; j++) {
      w += cut[j] * fnc(i - j - 1, r - j) % mod;
      w >= mod ? w -= mod : 1;
   }
   return w;
}

int main() {
   cin >> n >> mod;
   fac[0] = 1;
   for(int i=1; i<=n; i++) fac[i] = fac[i-1] * i % mod;
   for(int i=0; i<=n; i++) finv[i] = bigmod(fac[i], -1);

   cut[0] = cut[1] = 1;
   for(int i=2; i<=n; i++) cut[i] = (finv[i] << 1) % mod;
   for(int i=3; i<=n; i++) {
      ll &w = cut[i], d = bigmod(i, -1);
      for(int j=2; j<i; j++) {
         ll now = finv[j-1] * finv[i-j] % mod;
         w += now * d % mod;
         if(w >= mod) w -= mod;
      }
   }

   ll ans = 0;
   memset(dp, -1, sizeof(dp));
   for(int k=n/2; k<=n; k++) {
      ans += fac[k] * fnc(n, k) % mod;
   }
   cout << ans % mod;
}