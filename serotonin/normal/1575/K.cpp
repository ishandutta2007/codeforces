#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5, mod = 1e9+7;

ll bigmod(ll b, ll n) {
   b %= mod;
   ll ans = 1;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

int main() {
   ll n, m, k, r, c;
   cin >> n >> m >> k >> r >> c;
   ll ax, ay, bx, by;
   cin >> ax >> ay >> bx >> by;

   if(ax == bx and ay == by) {
      cout << bigmod(k, n * m);
      return 0;
   }

   ll cx = min(ax, bx) + r - max(ax, bx);
   ll cy = min(ay, by) + c - max(ay, by);
   cx = max(cx, 0LL);
   cy = max(cy, 0LL);

   ll cov = 2 * r * c - cx * cy;

   cout << bigmod(k, n * m + r * c - cov - cx * cy);
}