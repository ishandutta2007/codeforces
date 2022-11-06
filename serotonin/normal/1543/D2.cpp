#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e7+7;

void solve() {
   int n, k, d[20] = {};
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) {
      int v = i, c[20] = {};
      for(int j=0; v; j++) c[j] = v % k, v /= k;
      int q = 0;
      for(int j=0, m=1; m<sz and j<20; j++, m*=k) {
         int r = d[j];
         if(i & 1) r -= c[j];
         else r += c[j];
         if(r < 0) r += k;
         if(r >= k) r -= k;

         q += r * m;
         d[j] = r - d[j];
         if(d[j] < 0) d[j] += k;
      }
      printf("%d\n", q); fflush(stdout);
      scanf("%d", &q);
      if(q < 0) exit(0);
      if(q) break;
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}