#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz][22];

void solve() {
   int l, r;
   scanf("%d %d", &l, &r);
   int ans = r - l;
   for(int j=0; j<20; j++) {
      int one = a[r][j] - a[l-1][j];
      if(!one) continue;
      int now = r - l + 1 - one;
      ans = min(ans, now);
   }
   printf("%d\n", ans);
}

int main() {
   for(int i=1; i<sz; i++) {
      for(int j=0; j<20; j++) {
         a[i][j] = (i & 1 << j) > 0;
         a[i][j] += a[i-1][j];
      }
   }
   int t;
   cin >> t;
   while(t--) solve();
}