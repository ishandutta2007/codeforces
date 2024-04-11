#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 2005, sz = mm * mm, mod = 1e9+7;

char s[mm][mm];
int two[sz];
ll fac[sz], finv[sz], inv[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   two[0] = fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
      two[i] = (two[i-1] << 1) % mod;
   }
}

ll cmb(int n, int r) {
   if(n < r or r < 0) return 0;
   ll d = finv[r] * finv[n-r] % mod;
   return fac[n] * d % mod;
}

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   int cnt = 0;
   for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
      if(s[i][j] == '#') cnt++;
   }
   int d = n * m;
   if(cnt < d) printf("%d\n", two[cnt]);
   else {
      int ans = 0;
      for(int i=1; i<=d; i++) {
         int now = cmb(d, i) * two[d - i] % mod;
         if(i & 1) ans += now;
         else ans -= now;
         ans %= mod;
      }
      if(ans < 0) ans += mod;
      printf("%d\n", ans);
   }
}

int main() {
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}