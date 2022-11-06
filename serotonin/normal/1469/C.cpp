#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll a[sz];

void solve() {
   int n;
   ll k;
   scanf("%d %lld", &n, &k);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);

   ll l = a[0], r = a[0];
   for(int i=1; i<n; i++) {
      ll lx = a[i], rx = a[i] + k - 1;
      if(i == n-1) rx = a[i];
      l -= k - 1, r += k - 1;
      l = max(l, lx), r = min(r, rx);
      if(l > r) {
         puts("NO");
         return;
      }
   }

   if(l <= a[n-1] && a[n-1] <= r) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}