#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int n, z, c[sz];

bool fnc(int m) {
   int t = m - z;
   for(int i=1; i<=n; i++) {
      if(!c[i]) return 1;
      int now = max(0, c[i] - 1 - m + i);
      if(now > t) return 0;
      t -= now;
   }
   return 1;
}

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) c[i] = 0;
   for(int i=1; i<n; i++) {
      int p;
      scanf("%d", &p);
      c[p]++;
   }
   sort(c+1, c+n+1);
   reverse(c+1, c+n+1);

   z = 1;
   for(int i=1; i<=n; i++) z += c[i] > 0;

   int lo = z, hi = n + 10;
   while(lo < hi) {
      int md = lo + hi >> 1;
      if(fnc(md)) hi = md;
      else lo = md + 1;
   }
   printf("%d\n", lo);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}