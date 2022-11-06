#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e4+5, mod = 998244353;

int a[22][sz], ara[22];

ll bigmod(ll b, ll n) {
   if(n == -1) n = mod - 2;
   ll ans = 1;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

int main() {
   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++)
      for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
   ll fac = 1;
   for(int i=1; i<=n; i++) fac = fac * i % mod;
   ll ans = m * fac % mod;
   for(int j=0; j<m; j++) {
      for(int i=0; i<n; i++) ara[i] = a[i][j];
      sort(ara, ara+n, greater<int>());
      ll tot = 1;
      for(int i=n+1, j=0, k=0; i>1; i--, k++) {
         while(j<n and ara[j]>=i) j++;
         if(k > j) tot = 0;
         else tot = tot * (j - k) % mod;
      }
      ans -= tot;
      ans < 0 ? ans += mod : 1;
   }
   ans = ans * bigmod(fac, -1) % mod;
   if(ans < 0) ans += mod;
   cout << ans;
}