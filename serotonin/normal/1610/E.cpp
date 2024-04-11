#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, mod = 1e9+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   
   int ans = n - 2;
   for(int i=1; i<=n; i++) {
      int x = a[i], now = 2;
      for(int j=i+1; j<=n; ) {
         int z = 2 * a[j] - x;
         j = lower_bound(a+j+1, a+n+1, z) - a;
         if(j > n) break;
         now++;
      }
      ans = min(ans, n - now);
      while(i<n and a[i+1] == a[i]) i++;
   }
   printf("%d\n", ans);
}

int main() {
   int t = 1;
   cin >> t;
   while(t--) solve();
}