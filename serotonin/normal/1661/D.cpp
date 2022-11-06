#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll a[sz], h[sz], cum[sz];

ll fnc(int i) {
   return i < 0 ? 0 : cum[i];
}

int main() {
   int n; ll k;
   cin >> n >> k;
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   reverse(a+1, a+n+1);

   ll ans = 0, cut = 0;
   for(int i=1; i<=n; i++) {
      if(i <= n-k+1) cut += h[i-1] * (k - 1);
      cut -= fnc(i-2) - fnc(i-2-k+1);

      a[i] = max(0LL, a[i] - cut);
      cum[i] = cum[i-1];
      if(i >= n-k+1) continue;

      h[i] = (a[i] + k - 1) / k;
      cum[i] += h[i];
      // printf("%lld ", h[i]);

      ans += h[i];
   }
   // puts("");

   ll mx = 0, kk = k;
   for(int i=n-k+1; i<=n; i++) {
      ll now = (a[i] + kk - 1) / kk;
      mx = max(mx, now);
      kk--;
   }
   // cout << mx << endl;
   cout << ans + mx;
}