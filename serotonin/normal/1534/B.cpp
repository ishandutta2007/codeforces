#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   a[n+1] = 0;

   ll ans = 0;
   for(int i=1; i<=n; i++) {
      int y = max(a[i-1], a[i+1]);
      if(a[i] > y) {
         ans += a[i] - y;
         a[i] = y;
      }
      ans += abs(a[i] - a[i-1]);
   }
   printf("%lld\n", ans + a[n]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}