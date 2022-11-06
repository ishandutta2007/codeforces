#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int n, q, row[sz], col[sz], cr[sz], cc[sz];

void add(int x, int bit[], int v) {
   while(x <= n) {
      bit[x] += v;
      x += x & -x;
   }
}

int quer(int x, int bit[]) {
   int res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> n >> q;
   while(q--) {
      int t;
      cin >> t;
      if(t == 1) {
         int x, y;
         cin >> x >> y;
         row[x]++, col[y]++;
         if(row[x] == 1) add(x, cr, 1);
         if(col[y] == 1) add(y, cc, 1);
      }
      else if(t == 2) {
         int x, y;
         cin >> x >> y;
         row[x]--, col[y]--;
         if(row[x] == 0) add(x, cr, -1);
         if(col[y] == 0) add(y, cc, -1);
      }
      else {
         int lx, ly, rx, ry;
         cin >> lx >> ly >> rx >> ry;
         if(quer(rx, cr) - quer(lx - 1, cr) == rx - lx + 1) puts("Yes");
         else if(quer(ry, cc) - quer(ly - 1, cc) == ry - ly + 1) puts("Yes");
         else puts("No");
      }
   }
}