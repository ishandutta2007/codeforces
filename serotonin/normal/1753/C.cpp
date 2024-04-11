#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5, mod = 998244353;

int a[sz];

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

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int one = 0;
   for(int i=1; i<=n; i++) one += a[i];

   int x = 0;
   for(int i=0; i<one; i++) x += !a[n - i];

   ll ways = n * (n - 1LL) / 2 % mod;

   ll ans = 0;
   for(int i=1; i<=x; i++) ans += ways * bigmod((ll) i * i % mod, -1) % mod;
   ans %= mod;
   if(ans < 0) ans += mod;

   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}