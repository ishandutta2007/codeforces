#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 998244353;

char s[sz];

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

void solve() {
   int n, z = 0, p = 0;
   scanf("%d %s", &n, s);

   for(int i=0; i<n; i++) {
      if(s[i] == '1') z++;
      else p += z / 2, z = 0;
   }
   p += z / 2;

   z = 1;
   for(int i=0; i<n; i++) z += s[i] == '0';

   ll ans = cmb(z + p - 1, z - 1);
   printf("%lld\n", ans);
}

int main() {
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}