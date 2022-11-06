#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 1e9+7;

int a[sz];
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

int main() {
   prec();

   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   ll sum = 0;
   for(int i=0; i<n; i++) sum += a[i];
   if(sum % n) {
      puts("0");
      return 0;
   }
   sum /= n;

   ll ans = 1;
   map <int,int> mp;
   for(int i=0; i<n; i++) mp[a[i]]++;
   for(auto [v, c] : mp) ans = ans * finv[c] % mod;

   int smol = 0, big = 0;
   for(int i=0; i<n; i++) {
      smol += a[i] < sum;
      big += a[i] > sum;
   }

   if(smol <= 1 or big <= 1) {
      ans = ans * fac[n] % mod;
      printf("%lld\n", ans);
      return 0;
   }

   ans = ans * (fac[smol] * fac[big] % mod) % mod;
   ans = ans * 2 % mod;

   ans = ans * fac[n] % mod;
   ans = ans * finv[smol + big] % mod;

   if(ans < 0) ans += mod;
   printf("%lld\n", ans);
}