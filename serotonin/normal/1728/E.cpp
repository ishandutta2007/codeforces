#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, a[sz], b[sz];
ll dp[sz];

ll solve() {
   ll res = 0;
   for(int i=0; i<n; i++) {
      int z = min(a[i], b[i]);
      a[i] -= z, b[i] -= z;
      res += z;
   }
   sort(a, a + n);
   reverse(a, a + n);
   sort(b, b + n);
   ll asum = 0, bsum = accumulate(b, b + n, 0LL);
   for(int i=0; i<=n; i++) {
      dp[i] = asum + bsum;
      asum += a[i];
      bsum -= b[i];
   }
   return res;
}

int gcd(int a, int b, ll &x, ll &y) {
   if(b == 0) {
      x = 1, y = 0;
      return a;
   }
   ll x1, y1;
   int d = gcd(b, a % b, x1, y1);
   x = y1;
   y = x1 - y1 * (a / b);
   return d;
}

int main() {
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d %d", &a[i], &b[i]);
   ll mn = solve();

   int m = 1;
   for(int i=1; i<n; i++) if(dp[i] > dp[m]) m = i;

   int q;
   cin >> q;
   while(q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      
      ll i, j;
      int g = gcd(x, y, i, j);
      if(n % g) {
         puts("-1");
         continue;
      }

      ll ans = -1;
      if(n % x == 0) ans = max(ans, dp[n]);
      if(n % y == 0) ans = max(ans, dp[0]);

      i *= n / g;
      j *= n / g;
      
      int d = y / g;
      ll del = (ll) x * y / g;

      if(x * i > m) {
         ll dif = x * i - m;
         ll z = 1 + (dif - 1) / del;
         i -= d * z;
      }
      else {
         ll dif = m - x * i;
         ll z = dif / del;
         i += d * z;
      }

      if(x * i > 0 and x * i < n) ans = max(ans, dp[x * i]);

      i += d;

      if(x * i > 0 and x * i < n) ans = max(ans, dp[x * i]);

      printf("%lld\n", ans < 0 ? -1 : ans + mn);
   }
}