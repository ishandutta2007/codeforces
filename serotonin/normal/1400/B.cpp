#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

void solve() {
   ll a, b;
   ll x, y;
   ll wx, wy;
   scanf("%lld %lld", &a, &b);
   scanf("%lld %lld", &x, &y);
   scanf("%lld %lld", &wx, &wy);
   ll ans = 0;
   for(ll i=0; i<=x; i++) {
      ll wa = i * wx;
      if(wa > a) break;
      ll j = min(y, (a - wa) / wy);
      ll now = i + j;
      ll rx = x - i, ry = y - j;
      if(wx <= wy) {
         ll mx = min(rx, b / wx);
         ll r = b - mx * wx;
         ll my = min(ry, r / wy);
         ans = max(ans, now + mx + my);
      }
      else {
         ll my = min(ry, b / wy);
         ll r = b - my * wy;
         ll mx = min(rx, r / wx);
         ans = max(ans, now + mx + my);
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}