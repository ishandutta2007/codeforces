#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7, mod = 1e9+7;

ll fac[sz], finv[sz], inv[sz];
ll two[sz], three[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
   two[0] = three[0] = 1;
   for(int i=1; i<sz; i++) two[i] = two[i-1] * 2 % mod;
   for(int i=1; i<sz; i++) three[i] = three[i-1] * 3 % mod;
}

ll cmb(int n, int r) {
   if(n < r or r < 0) return 0;
   ll d = finv[r] * finv[n-r] % mod;
   return fac[n] * d % mod;
}

int main() {
   prec();
   int n, k;
   cin >> n >> k;

   if(!k) {
      cout << three[n];
      return 0;
   }

   ll ans = 0;
   for(int x = 1; x <= k; x++) {
      int f;
      
      // ends with carry
      f = n - k - x + 1;
      if(f >= 0) {
         ll now = three[k - x] * three[f] % mod;
         now = now * cmb(f + x - 1, f) % mod;
         now = now * cmb(k - 1, k - x) % mod;
         ans += now, ans %= mod;
      }

      // doesn't end with carry
      f = n - k - x;
      if(f >= 0) {
         ll now = three[k - x] * three[f] % mod;
         now = now * cmb(f + x, f) % mod;
         now = now * cmb(k - 1, k - x) % mod;
         ans += now, ans %= mod;
      }
   }

   ans %= mod; ans += mod; ans %= mod;
   cout << ans;
}