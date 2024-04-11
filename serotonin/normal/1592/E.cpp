#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1100000;

int og[sz], a[sz], xcum[sz], last[sz], ara[sz], k;

inline void add(int i) {
   ara[k++] = xcum[i];
   last[xcum[i]] = i;
}

int main() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &og[i]);

   int ans = 0;
   for(int b=19, m=0; b>=0; b--) {
      m |= 1 << b;
      for(int i=1; i<=n; i++) a[i] = og[i] & m;
      for(int i=1; i<=n; i++) xcum[i] = a[i] ^ xcum[i-1];

      memset(last, -1, sizeof last);
      k = 0, add(0);
      for(int i=1; i<=n; i++) {
         if(!(a[i] & 1 << b)) {
            while(k--) last[ara[k]] = -1;
            k = 0, add(i);
            continue;
         }

         int &p = last[xcum[i]];
         if(p >= 0) {
            ans = max(ans, i - p);
//            printf("%d %d %d %d\n", i - p, p, i, b);
         }
         else add(i);
      }
   }
   cout << ans;
}