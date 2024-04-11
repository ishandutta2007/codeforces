#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   ll ans = LLONG_MAX;
   ll sum[2] = {};
   int mn[2]; mn[0] = mn[1] = INT_MAX;
   ll rem[2]; rem[0] = rem[1] = n;
   for(int i=1; i<=n; i++) {
      sum[i & 1] += a[i];
      mn[i & 1] = min(mn[i & 1], a[i]);
      rem[i & 1]--;
      if(i < 2) continue;
      ll now = 0;
      for(int j=0; j<2; j++) {
         now += sum[j] + rem[j] * mn[j];
      }
      ans = min(ans, now);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}