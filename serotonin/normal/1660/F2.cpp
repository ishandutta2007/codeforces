#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7, mag = 2e5+2;

char s[sz];
int cum[sz];

struct fenwick {
   ll bit[sz];

   void add(int x, int v) {
      x += mag;
      while(x < sz) {
         bit[x] += v;
         x += x & -x;
      }
   }

   ll query(int x) {
      x += mag;
      ll res = 0;
      while(x) {
         res += bit[x];
         x -= x & -x;
      }
      return res;
   }
} fen[3];

void solve() {
   int n; 
   scanf("%d %s", &n, s + 1);
   for(int i=1; i<=n; i++) {
      cum[i] = s[i] == '+' ? 1 : -1;
      cum[i] += cum[i-1];
   }
   ll ans = 0;
   for(int i=1; i<=n; i++) {
      int x = cum[i] % 3;
      if(x < 0) x += 3;
      ans += fen[x].query(-cum[i]);
      fen[x].add(-cum[i], +1);
   }
   for(int i=1; i<=n; i++) {
      int x = cum[i] % 3;
      if(x < 0) x += 3;
      fen[x].add(-cum[i], -1);
   }
   printf("%lld\n", ans);
}

int main() {
   fen[0].add(0, 1);
   int t;
   cin >> t;
   while(t--) solve();
}