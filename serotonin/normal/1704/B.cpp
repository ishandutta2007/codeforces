#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+6;

int a[sz];

void solve() {
   int n, x;
   scanf("%d %d", &n, &x);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int ans = 0;
   for(int i=1; i<=n; ) {
      int j = i, mx = a[i], mn = a[i];
      while(j <= n) {
         mx = max(mx, a[j]);
         mn = min(mn, a[j]);
         if(mx - mn > x * 2) break;;
         j++;
      }
      i = j;
      ans++;
   }
   printf("%d\n", ans - 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}