#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7, mod = 1e9+7;

ll bigmod(ll b, ll n) {
   b %= mod;
   if(n == -1) n = mod - 2;
   ll ans = 1;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

const ll bytwo = bigmod(2, -1);

ll fac[sz], finv[sz], inv[sz], pwtwo[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
   pwtwo[0] = 1;
   for(int i=1; i<sz; i++)
      pwtwo[i] = pwtwo[i-1] * bytwo % mod;
}

ll cmb(int n, int r) {
   if(n < r or r < 0) return 0;
   ll d = finv[r] * finv[n-r] % mod;
   return fac[n] * d % mod;
}

void solve() {
   int n, m; ll k;
   scanf("%d %d %lld", &n, &m, &k);
   
   if(n == m) {
      printf("%lld\n", n * k % mod);
      return;
   }

   ll ans = 0;
   for(int i=1; i<=m; i++) {
      ll val = i * k % mod;
      val = val * pwtwo[n - i] % mod;
      ll ways = cmb(n - i - 1, m - i);
      ans += ways * val % mod;
      ans %= mod;
   }
   ans += mod; ans %= mod;
   printf("%lld\n", ans);
}

int main() {
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}