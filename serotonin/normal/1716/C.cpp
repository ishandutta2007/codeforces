#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

ll a[2][sz], spir[2][sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int j=0; j<2; j++) {
      for(int i=1; i<=n; i++) scanf("%lld", &a[j][i]), a[j][i]++;
   }

   a[0][1] = 0;
   spir[0][n] = max(a[0][n] + 1, a[1][n]);
   spir[1][n] = max(a[1][n] + 1, a[0][n]);

   for(int i=n-1; i; i--) {
      for(int j=0; j<2; j++) {
         ll &w = spir[j][i];
         if(a[j][i] + 1 <= a[j][i + 1]) w = spir[j][i + 1];
         else {
            ll took = spir[j][i + 1] - a[j][i + 1];
            ll need = (n - i - 1) * 2 + 1;
            ll ex = a[j][i] + 1 - a[j][i + 1];
            w = spir[j][i + 1] + max(0LL, ex - took + need);
         }
         w = max(w + 1, a[j ^ 1][i]);
      }
   }

   ll ans = spir[0][1], now = 0;
   for(int i=1; i<n; i++) {
      int j = i & 1;
      now = max(now + 1, a[j][i]);

      if(now + 1 <= a[j][i + 1]) ans = min(ans, spir[j][i + 1]);
      else {
         ll took = spir[j][i + 1] - a[j][i + 1];
         ll need = (n - i - 1) * 2 + 1;
         ll ex = now + 1 - a[j][i + 1];
         ans = min(ans, spir[j][i + 1] + max(0LL, ex - took + need));
      }

      now = max(now + 1, a[j][i + 1]);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}