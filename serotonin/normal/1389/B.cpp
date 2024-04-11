#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n, k, z;
   scanf("%d %d %d", &n, &k, &z);
   k++;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int res = 0;
   for(int i=1; i<=k; i++) res += a[i];
   if(z) res += max(0, a[k-2] - a[k]);

   for(int t=1; t<=z; t++) {
      int j = k - 2 * t;
      if(j < 2) break;

      int now = 0, big = 0;
      for(int i=1; i<=j; i++) {
         now += a[i];
         if(i > 1) big = max(big, a[i-1] + a[i]);
      }
      now += big * t;
      if(t < z) now += max(0, a[j-2] - a[j]);
      res = max(res, now);
   }
   printf("%d\n", res);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}