#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 205;

int cr[sz], cg[sz], cb[sz], dp[sz][sz][sz];

int fnc(int r, int g, int b) {
   int q = 0;
   q += r > 0;
   q += g > 0;
   q += b > 0;
   if(q < 2) return 0;
   int &w = dp[r][g][b];
   if(w < 0) {
      w = 0;
      if(r && g) w = max(w, cr[r] * cg[g] + fnc(r-1, g-1, b));
      if(r && b) w = max(w, cr[r] * cb[b] + fnc(r-1, g, b-1));
      if(g && b) w = max(w, cg[g] * cb[b] + fnc(r, g-1, b-1));
   }
   return w;
}

int main() {
   int r, g, b;
   cin >> r >> g >> b;
   for(int i=1; i<=r; i++) scanf("%d", &cr[i]);
   for(int i=1; i<=g; i++) scanf("%d", &cg[i]);
   for(int i=1; i<=b; i++) scanf("%d", &cb[i]);
   sort(cr, cr+r+1);
   sort(cg, cg+g+1);
   sort(cb, cb+b+1);
   memset(dp, -1, sizeof(dp));
   cout << fnc(r, g, b);
}