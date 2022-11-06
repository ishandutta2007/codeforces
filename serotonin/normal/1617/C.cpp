#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

int a[sz], b[sz];

void solve() {
   int n, r = 0;
   scanf("%d", &n);
   for(int i=0; i<=n; i++) a[i] = b[i] = 0;
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      if(x <= n and !b[x]) {
         b[x] = 1;
         continue;
      }
      r++;
      x = (x - 1) / 2;
      x = min(x, n);
      a[x]++;
   }
   for(int i=n; i; i--) {
      if(!a[i] and !b[i]) {
         puts("-1");
         return;
      }
      if(!b[i]) a[i]--;
      a[i-1] += a[i];
   }
   printf("%d\n", r);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}