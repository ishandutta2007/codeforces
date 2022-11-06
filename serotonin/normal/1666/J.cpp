#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 205;

int n, a[sz][sz], par[sz][sz], res[sz];
ll cum[sz][sz], dp[sz][sz];

ll rec(int li, int ri, int lj, int rj) {
   return cum[ri][rj] - cum[li-1][rj] - cum[ri][lj-1] + cum[li-1][lj-1];
}

ll sum(int l, int r) {
   return rec(l, r, 1, l - 1) + rec(r + 1, n, l, r);
}

ll fnc(int l, int r) {
   if(l > r) return 0;
   ll &w = dp[l][r];
   if(w >= 0) return w;
   w = LLONG_MAX;
   for(int i=l; i<=r; i++) {
      ll now = fnc(l, i - 1) + fnc(i + 1, r);
      if(now < w) w = now, par[l][r] = i; 
   }
   w += sum(l, r);
   return w;
}

void go(int l, int r, int p) {
   if(l > r) return;
   int m = par[l][r];
   res[m] = p;
   go(l, m - 1, m), go(m + 1, r, m);
}

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         scanf("%d", &a[i][j]);
         cum[i][j] = a[i][j] + cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1];
      }
   }

   memset(dp, -1, sizeof(dp));
   fnc(1, n);
   go(1, n, 0);
   for(int i=1; i<=n; i++) printf("%d ", res[i]);
}