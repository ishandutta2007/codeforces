#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[2][sz], cum[2][sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<2; i++) {
      for(int j=1; j<=n; j++) {
         scanf("%d", &a[i][j]);
         cum[i][j] = cum[i][j-1] + a[i][j];
      }
   }

   int ans = cum[0][n];
   for(int j=1; j<=n; j++) {
      int now = max(cum[1][j-1], cum[0][n] - cum[0][j]);
      ans = min(ans, now);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}