#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

int a[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   int m = n << 1;
   for(int i=1; i<=m; i++) {
      for(int j=1; j<=m; j++) {
         scanf("%d", &a[i][j]);
      }
   }
   ll ans = 0;
   for(int i=n+1; i<=m; i++) {
      for(int j=n+1; j<=m; j++) {
         ans += a[i][j];
         a[i][j] = 0;
      }
   }

   if(n == 1) {
      printf("%lld\n", ans + min(a[1][2], a[2][1]));
      return;
   }

   vector <pair<int,int>> v;
   v.emplace_back(1, 1);
   v.emplace_back(1, n);
   v.emplace_back(n, 1);
   v.emplace_back(n, n);

   int cut = INT_MAX;
   for(auto [x, y] : v) {
      cut = min(cut, a[x + n][y]);
      cut = min(cut, a[x][y + n]);
   }
   printf("%lld\n", ans + cut);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}