#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int a[sz];
ll cum[sz];

int main() {
   int n, q, k;
   scanf("%d %d %d", &n, &q, &k);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=n; i++) {
      cum[i] = a[i+1] - a[i-1] - 2;
      cum[i] += cum[i-1];
   }
   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      if(l == r) {
         printf("%d\n", k - 1);
         continue;
      }
      ll ans = (a[l+1] - 2) + (k - a[r-1] - 1);
      ans += cum[r-1] - cum[l];
      printf("%lld\n", ans);
   }
}