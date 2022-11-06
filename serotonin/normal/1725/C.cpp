#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, mod = 998244353;

ll a[sz];

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
   int n, m;
   cin >> n >> m;
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

   ll sum = 0;
   for(int i=1; i<=n; i++) sum += a[i];
   if(sum & 1) {
      cout << bigmod(m, n);
      return 0;
   }

   sum >>= 1;

   int cnt = 0;
   for(int i=1; i<=n; i++) a[i] += a[i-1];

   set <ll> st;
   for(int i=1; i<n; i++) st.emplace(a[i]);
   for(int i=0; i<n; i++) {
      if(st.count(a[i] + sum)) cnt++;
   }

   if(!cnt) {
      cout << bigmod(m, n);
      return 0;
   }

   ll ans = 0;
   for(int i=0; i<=cnt; i++) {
      if(i > m) break;
      ll now = cmb(m, i) * cmb(cnt, i) % mod;
      now = now * fac[i] % mod;
      ll c = m - i;
      now = now * bigmod(c * (c - 1) % mod, cnt - i) % mod;
      now = now * bigmod(c, n - cnt * 2) % mod;
      ans += now;
   }
   ans %= mod, ans += mod, ans %= mod;
   cout << ans;
}