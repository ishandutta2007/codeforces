#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int n, m, q;
bool ara[sz][sz];
set <int> st[sz << 1];

int fnc(int z, int b) {    // <= b
   int a = z + b;
   if(a < 1 or a > n or b < 1 or b > m) return b;
   auto it = st[z + sz].upper_bound(b);
   return *prev(it);
}

int gnc(int z, int b) {    // >= b
   int a = z + b;
   if(a < 1 or a > n or b < 1 or b > m) return b;
   return *st[z + sz].lower_bound(b);
}

int main() {
   cin >> n >> m >> q;

   for(int i=1; i<=n; i++) st[i - 1 + sz].insert(0);
   for(int j=2; j<=m; j++) st[1 - j + sz].insert(j - 1);

   for(int i=1; i<=n; i++) st[i - m + sz].insert(m + 1);
   for(int j=1; j<m; j++) st[n - j + sz].insert(j + 1);

   ll ans = 0;

   for(int x=1; x<=n; x++) {
      for(int y=1; y<=m; y++) {
         int z = x - y, bx, by, y1, y2;

         // right -> higher y
         y2 = gnc(z - 1, y + 1), y1 = gnc(z, y + 1);
         if(y2 <= y1) by = y2, bx = z - 1 + by;
         else by = y1, bx = z + by;
         int d_right = abs(x - bx) + abs(y - by);

         // down -> higher x
         y2 = gnc(z, y + 1), y1 = gnc(z + 1, y);
         if(y2 <= y1) by = y2, bx = z + by;
         else by = y1, bx = z + 1 + by;
         int d_down = abs(x - bx) + abs(y - by);

         ans += d_right + d_down - 1;
      }
   }

   while(q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      int z = x - y, bx, by, y1, y2;

      // y2 above y1, z increases down

      // up -> lower x
      y2 = fnc(z - 1, y), y1 = fnc(z, y - 1);
      if(y2 > y1) by = y2, bx = z - 1 + by;
      else by = y1, bx = z + by;
      int d_up = abs(x - bx) + abs(y - by);

      // right -> higher y
      y2 = gnc(z - 1, y + 1), y1 = gnc(z, y + 1);
      if(y2 <= y1) by = y2, bx = z - 1 + by;
      else by = y1, bx = z + by;
      int d_right = abs(x - bx) + abs(y - by);

      // left -> lower y
      y2 = fnc(z, y - 1), y1 = fnc(z + 1, y - 1);
      if(y2 > y1) by = y2, bx = z + by;
      else by = y1, bx = z + 1 + by;
      int d_left = abs(x - bx) + abs(y - by);

      // down -> higher x
      y2 = gnc(z, y + 1), y1 = gnc(z + 1, y);
      if(y2 <= y1) by = y2, bx = z + by;
      else by = y1, bx = z + 1 + by;
      int d_down = abs(x - bx) + abs(y - by);

      ll sum = d_up * d_right + d_left * d_down - 1;
      if(!ara[x][y]) {
         ans -= sum;
         st[z + sz].insert(y);
      }
      else {
         ans += sum;
         st[z + sz].erase(y);
      }
      ara[x][y] ^= 1;

      printf("%lld\n", ans);
   }
}