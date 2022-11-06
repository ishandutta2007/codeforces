#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 2e5+5;

typedef pair <ll,ll> pii;
#define x first
#define y second

void solve() {
   ll n, k;
   cin >> n >> k;
   pii a, b;
   cin >> a.x >> a.y >> b.x >> b.y;
   if(a.x > b.x) swap(a, b);

   ll dis = b.x - a.y;
   if(dis >= 0) {
      ll can = b.y - a.x;
      ll ans = k;
      if(k <= dis) ans += dis, k = 0;
      for(ll i=1; i<=n && k>dis; i++) {
         ans += dis, k -= can;
      }
      ans += max(0LL, k);
      printf("%lld\n", ans);
   }
   else if(a.y <= b.y) {
      dis = -dis;
      k -= dis * n;
      ll ans = 0;
      ll can = b.y - a.x - dis;
      for(ll i=1; i<=n && k>0; i++) {
         ll now = min(k, can);
         ans += now;
         k -= now;
      }
      ans += max(0LL, k * 2);
      printf("%lld\n", ans);
   }
   else {
      ll can = (a.y - a.x) - (b.y - b.x), ans = 0;
      k -= n * (b.y - b.x);
      if(k > 0) {
         ans = min(can * n, k);
         k -= ans;
         ans += k * 2;
      }
      printf("%lld\n", ans);
   }
}

int main() {
   ll t;
   cin >> t;
   while(t--) solve();
}