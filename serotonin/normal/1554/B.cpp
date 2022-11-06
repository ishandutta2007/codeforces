#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

ll a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   ll ans = LLONG_MIN;
   int d = min(n, 105);
   for(ll i=1; i<=d; i++) {
      for(ll j=i+1; j<=d; j++) {
         ll x = n - i + 1, y = n - j + 1;
         ll now = x * y - k * (a[x] | a[y]);
         ans = max(ans, now);
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}