#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz], b[sz];
vector <int> g[sz];
ll sum[sz], avg[sz];

bool lhs[sz], rhs[sz];
int lzag[sz], rzag[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   sort(a+1, a+n+1);
   rotate(a+1, a+1+n-m, a+n+1);
   n = m;

   for(int i=1; i<=n; i++) {
      g[i].clear();
      int k;
      scanf("%d", &k);
      g[i].resize(k);
      sum[i] = 0;
      for(int j=0; j<k; j++) scanf("%d", &g[i][j]), sum[i] += g[i][j];
      b[i] = avg[i] = (sum[i] + k - 1) / k;
   }
   sort(b+1, b+n+1);

   lhs[0] = 1;
   for(int i=1; i<=n; i++)
      lhs[i] = lhs[i-1] & (b[i] <= a[i]);
   rhs[n + 1] = 1;
   for(int i=n; i; i--) 
      rhs[i] = rhs[i+1] & (b[i] <= a[i]);

   for(int i=1; i<=n; i++) {
      lzag[i] = a[i] >= b[i-1];
      rzag[i] = a[i] >= b[i+1];
      lzag[i] += lzag[i-1];
      rzag[i] += rzag[i-1];
   }

   for(int i=1; i<=n; i++) {
      int k = g[i].size() - 1, pavg = avg[i];
      int me = lower_bound(b+1, b+n+1, pavg) - b;
      for(int x : g[i]) {
         ll nsum = sum[i] - x;
         int navg = (nsum + k - 1) / k;
         bool yes = 1;

         if(pavg == navg) {
            yes = lhs[n];
         }
         else if(pavg < navg) {
            int l = me, r = upper_bound(b+1, b+n+1, navg - 1) - b - 1;
            if(!lhs[l - 1] or !rhs[r + 1]) yes = 0;
            if(navg > a[r]) yes = 0;
            int cum = rzag[r - 1] - rzag[l - 1];
            if(cum < r - l) yes = 0;
         }
         else {
            int r = me, l = upper_bound(b+1, b+n+1, navg) - b;
            if(!lhs[l - 1] or !rhs[r + 1]) yes = 0;
            if(navg > a[l]) yes = 0;
            int cum = lzag[r] - lzag[l];
            if(cum < r - l) yes = 0;
         }
         printf("%d", yes);
      }
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}