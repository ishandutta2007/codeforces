#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5, mod = 1e9+7;

ll fac[sz], finv[sz], inv[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
}

ll cmb(int n, int r) {
   if(n < r or r < 0) return 0;
   ll d = finv[r] * finv[n-r] % mod;
   return fac[n] * d % mod;
}

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

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);

   ll zer = 0;
   for(int i=0; i<=n; i+=2) zer += cmb(n, i);
   zer %= mod;

   ll eq = 1, ans = 0;
   for(int i=0; i<k; i++) {
      // 10
      if(~n & 1) ans += eq * bigmod(2, n * (k - i - 1LL)) % mod;

      // 00
      ll now = zer;
      if(~n & 1) now--;

      // 11
      if(n & 1) now++;

      eq = eq * now % mod;
   }
   ans += eq;
   ans %= mod;
   if(ans < 0) ans += mod;
   printf("%lld\n", ans);
}

int main() {
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}