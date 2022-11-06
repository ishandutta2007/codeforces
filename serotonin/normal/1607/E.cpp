#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

char s[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   scanf("%s", s);

   int l = 0, r = 0, d = 0, u = 0, x = 0, y = 0;
   bool xd = 0, yd = 0;
   int ansx, ansy;
   for(int i=0; s[i]; i++) {
      if(s[i] == 'L') x--;
      else if(s[i] == 'R') x++;
      else if(s[i] == 'U') y--;
      else y++;

      l = min(l, x), r = max(r, x);
      u = min(u, y), d = max(d, y);

      if(!xd and r - l == m - 1) {
         xd = 1;
         ansx = 1 - l;
      }
      if(!yd and d - u == n - 1) {
         yd = 1;
         ansy = 1 - u;
      }
   }
   if(!xd) ansx = 1 - l;
   if(!yd) ansy = 1 - u;
   if(n == 1) ansy = 1;
   if(m == 1) ansx = 1;
   printf("%d %d\n", ansy, ansx);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}