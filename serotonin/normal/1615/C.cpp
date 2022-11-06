#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char a[sz], b[sz];

void solve() {
   int n;
   scanf("%d %s %s", &n, a, b);
   int c[4] = {};
   for(int i=0; i<n; i++) {
      int x = a[i] - '0';
      int y = b[i] - '0';
      c[x << 1 | y]++;
   }

   int ans = n + 5;

   int z = c[0] + c[3], x = n - z;

   if(z & 1) {
      int one = c[3], zer = c[0];
      if(one == zer + 1) {
         ans = min(ans, z);
      }
   }
   
   if(~x & 1) {
      int one = c[2], zer = c[1];
      if(one == zer) {
         ans = min(ans, x);
      }
   }

   if(ans > n) puts("-1");
   else printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}