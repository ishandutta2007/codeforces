#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a + n);

   ll ans = 0;
   for(int i=0; i+2<n; i++) {
      ll now = 2LL * a[i] - a[i+1] - a[n-1];
      ans = max(ans, abs(now));
   }
   reverse(a, a + n);
   for(int i=0; i+2<n; i++) {
      ll now = 2LL * a[i] - a[i+1] - a[n-1];
      ans = max(ans, abs(now));
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}