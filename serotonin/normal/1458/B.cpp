#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105, shift = 10001;

int n, a[sz], b[sz];
vector <int> dp[sz][sz];

int fnc(int i, int k, int can) {
   if(!i) return 0;
   int &w = dp[i][k][can];
   if(w < 0) {
      w = 0;
      if(k) {
         int now = b[i] << 1, f = (a[i] - b[i]) << 1;
         int eq = can - shift;
         if(eq < 0) {
            int water = -eq;
            int z = min(water, f);
            w = max(w, now + z + fnc(i-1, k-1, can + f));
         }
         else w = max(w, now + fnc(i-1, k-1, can + f));
      }
      if(i > k) {
         int eq = can - shift;
         if(eq > 0) {
            int z = min(eq, b[i]);
            w = max(w, z + fnc(i-1, k, can - b[i]));
         }
         else w = max(w, fnc(i-1, k, can - b[i]));
      }
   }
   return w;
}

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);
   for(int i=1; i<=n; i++)
      for(int k=0; k<=i; k++)
         dp[i][k].resize(2*sz*sz, -1);
   for(int i=1; i<=n; i++) {
      int ans = fnc(n, i, shift);
      if(ans & 1) printf("%d.5 ", ans / 2);
      else printf("%d ", ans / 2);
   }
}