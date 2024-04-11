#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005, mod = 998244353;

int na, nb, dp[4][4][sz][sz];
char a[sz], b[sz];

int fnc(int taken, int match, int x, int y) {
   int &w = dp[taken][match][x][y];
   if(w >= 0) return w;
   w = 0;
   if(taken == 3) w = 1;
   if(!(match & 1) and x < na) {
      int nmatch = 0;
      if(a[x] == a[x + 1]) nmatch |= 1;
      if(a[x] == b[y]) nmatch |= 2;
      w += fnc(taken | 1, nmatch, x + 1, y);
      if(w >= mod) w -= mod;
   }
   if(!(match & 2) and y < nb) {
      int nmatch = 0;
      if(b[y] == a[x]) nmatch |= 1;
      if(b[y] == b[y + 1]) nmatch |= 2;
      w += fnc(taken | 2, nmatch, x, y + 1);
      if(w >= mod) w -= mod;
   }
   return w;
}

int main() {
   scanf("%s %s", a, b);
   na = strlen(a), nb = strlen(b);
   memset(dp, -1, sizeof(dp));
   ll ans = 0;
   for(int i=0; i<na; i++) {
      for(int j=0; j<nb; j++) {
         ans += fnc(0, 0, i, j);
      }
   }
   ans %= mod;
   if(ans < 0) ans += mod;
   cout << ans;
}