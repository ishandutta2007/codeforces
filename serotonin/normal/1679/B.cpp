#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], qt[sz];

int main() {
   int n, q;
   cin >> n >> q;
   ll sum = 0;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), sum += a[i];
   int ax = 0, wx = 0;
   for(int j=1; j<=q; j++) {
      int t;
      scanf("%d", &t);
      if(t == 1) {
         int i, x;
         scanf("%d %d", &i, &x);
         if(qt[i] < wx) a[i] = ax;
         sum += x - a[i];
         a[i] = x, qt[i] = j;
      }
      else {
         int x;
         scanf("%d", &x);
         ax = x, wx = j, sum = (ll) x * n;
      }
      printf("%lld\n", sum);
   }
}