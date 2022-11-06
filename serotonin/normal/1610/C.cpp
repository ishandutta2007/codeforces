#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, a[sz], b[sz];

bool fnc(int m) {
   for(int i=1, k=m; k; k--, i++) {
      while(i <= n) {
         if(a[i] >= k - 1 and b[i] >= m - k) break;
         i++;
      }
      if(i > n) return 0;
   }
   return 1;
}

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);
   int lo = 0, hi = n;
   while(lo < hi) {
      int m = lo + hi + 1 >> 1;
      if(fnc(m)) lo = m;
      else hi = m - 1;
   }
   printf("%d\n", lo);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}