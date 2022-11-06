#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 1e16, mod = 1e9+7;

void solve() {
   ll n;
   scanf("%lld", &n);
   ll lcm = 1, ans = 0;
   for(ll i=2; i<43; i++) {
      ll g = __gcd(lcm, i);
      ll d = n / lcm;
      lcm *= i / g;
      ll x = n / lcm;
      ans += i * (d - x) % mod;
      ans %= mod;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}