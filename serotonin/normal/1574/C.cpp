#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

ll a[sz];

int main() {
   int n;
   cin >> n;
   ll sum = 0;
   for(int i=0; i<n; i++) scanf("%lld", &a[i]), sum += a[i];
   sort(a, a+n);

   int q;
   cin >> q;
   while(q--) {
      ll def, atk;
      scanf("%lld %lld", &def, &atk);

      int j = upper_bound(a, a+n, def - 1) - a;

      ll ans = LLONG_MAX;

      if(j < n) {
         ll rem = sum - a[j];
         ans = min(ans, max(0LL, atk - rem));
      }

      if(j) {
         ll now = max(0LL, def - a[j-1]);
         ll rem = sum - a[j-1];
         ans = min(ans, now + max(0LL, atk - rem));
      }

      printf("%lld\n", ans);
   }
}