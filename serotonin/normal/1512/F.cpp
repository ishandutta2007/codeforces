#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

ll a[sz], b[sz];

void solve() {
   int n, c;
   scanf("%d %d", &n, &c);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   for(int i=1; i<n; i++) scanf("%lld", &b[i]);

   ll ans = LLONG_MAX, sum = 0, days = 0;
   for(int i=1; i<=n; i++) {
      ll rem = c - sum;
      ans = min(ans, days + (rem + a[i] - 1) / a[i]);

      if(b[i] <= sum) {
         sum -= b[i];
         days++;
      }
      else {
         rem = b[i] - sum;
         ll ex = (rem + a[i] - 1) / a[i];
         days += ex + 1;
         sum += ex * a[i] - b[i];
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}