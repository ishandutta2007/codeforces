#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5, mod = 998244353;

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

int fnc(int n, int k) {
   return cmb(n - k, k);
}

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

ll fuck(int n) {
   return fac[2 * n] * finv[n] % mod * bigmod(inv[2], n) % mod;
}

ll dp[sz];

void solve() {
   int n;
   scanf("%d", &n);
   ll ans = 0;
   for(int i=0; i*4<=n; i++) {
      ll now = fnc(n, i * 2) * fuck(i) % mod;
      now = now * bigmod(2, i) % mod;
      ans += now * dp[n - i * 4] % mod;
   }
   ans %= mod, ans += mod;
   printf("%lld\n", ans % mod);
}

int main() {
   prec();
   dp[0] = dp[1] = 1;
   for(int i=2; i<sz; i++) {
      dp[i] = dp[i-1] + (i-1) * dp[i-2] % mod;
      dp[i] %= mod;
   }
   int t;
   cin >> t;
   while(t--) solve();
}