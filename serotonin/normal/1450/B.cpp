#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll x[sz], y[sz];

ll fnc(int i, int j) {
   return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) scanf("%lld %lld", &x[i], &y[i]);

   for(int i=0; i<n; i++) {
      int now = 0;
      for(int j=0; j<n; j++) {
         if(fnc(i, j) <= k) now++;
      }
      if(now == n) {
         puts("1");
         return;
      }
   }
   puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}