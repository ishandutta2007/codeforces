#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mod = 998244353;

int n, a[sz], where[sz];

bool rhs(int i, int j) {
   return where[i] > where[j];
}

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

int main() {
   prec();
   int k;
   cin >> n >> k;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), where[a[i]] = i+1;
   int safe = 0;
   for(int i=1; i<n; i++) safe += rhs(a[i] + 1, a[i-1] + 1);

   ll ans = 0;
   for(int i=min(n, k); i; i--) {
      ans += cmb(k, i) * cmb(safe, n - i) % mod;
      ans %= mod;
   }
   cout << ans;
}