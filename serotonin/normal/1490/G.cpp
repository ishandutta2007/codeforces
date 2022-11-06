#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];
ll cum[sz], d[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) {
      scanf("%d", &a[i]), cum[i] = a[i] + cum[i-1];
      d[i] = max(d[i-1], cum[i]);
   }

   while(m--) {
      ll x;
      scanf("%lld", &x);
      if(d[n] >= x) {
         int j = lower_bound(d+1, d+n+1, x) - d;
         printf("%d ", j - 1);
         continue;
      }
      if(cum[n] <= 0) {
         printf("-1 ");
         continue;
      }

      ll t = (x - d[n] + cum[n] - 1) / cum[n];
      x -= cum[n] * t;
      t *= n;

      int j = lower_bound(d+1, d+n+1, x) - d;
      if(!x) j = 0;
      printf("%lld ", j + t - 1);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}