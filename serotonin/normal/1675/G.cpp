#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 255, inf = 1e8;

int m, dp[sz][sz][sz<<1], a[sz], cum[sz];

int fnc(int i, int pa, int suck) {
   int &w = dp[i][pa][suck];
   if(w >= 0) return w; w = inf;
   int here = a[i] + suck - m;

   if(i == 1) {
      if(here >= pa) w = 0;
      return w;
   }

   for(int j=0; ; j++) {
      int now = here - j;
      if(now < pa) break;
      int oth = cum[i - 1] + j;
      if(oth < now * (i - 1)) continue;
      w = min(w, j + fnc(i - 1, now, m + j));
   }
   for(int j=max(0, pa - here); ; j++) {
      int now = here + j;
      int oth = cum[i - 1] - j;
      if(oth < now * (i - 1)) break;
      w = min(w, j + fnc(i - 1, now, m - j));
   }
   return w;
}

int main() {
   int n;
   cin >> n >> m;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), cum[i] = a[i] + cum[i-1];
   if(n == 1) {
      puts("0");
      return 0;
   }
   memset(dp, -1, sizeof(dp));
   cout << fnc(n, 0, m);
}