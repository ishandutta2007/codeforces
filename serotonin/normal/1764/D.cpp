#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5005;

int mod;

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
   int n;
   cin >> n >> mod;
   prec();
   
   ll ans = 0;
   for(int i=2; i<=(n+1)/2; i++) {
      int cnt = 0;
      for(int j=i+1; j<=n; j++) {
         int d = max(j - i - 1, n - j);
         if(d >= n / 2) continue;
         cnt++;
      }
      int gone = n - i - 1;
      int can = i - 2;
      for(int k=0; k<=can; k++) {
         ll ways = cmb(can, k) * fac[gone + k] % mod;
         ways = ways * cnt % mod;
         ans += ways, ans %= mod;
      }
   }
   ans = ans * n % mod;

   if(~n & 1) {
      ans += n * fac[n - 2] % mod;
      ans %= mod;
   }

   if(ans < 0) ans += mod;
   cout << ans;
}