#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   ll ans = 0;
   for(int i=0; i<n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a[i] = max(x, y);
      ans += (x + y) * 2LL;
   }
   sort(a, a + n);
   for(int i=0; i+1<n; i++) ans -= a[i] * 2LL;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}