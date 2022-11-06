#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mod = 1e9+7;

ll bigmod(ll b, ll n) {
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
   ll ans = 0;
   for(int i=0; i<30; i++) if(k & 1 << i) {
      ans += bigmod(n, i);
   }
   ans %= mod;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}