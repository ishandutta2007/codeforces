#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55, big = sz*sz;

ll dp[sz][sz*sz], mod;
ll cmb[sz][sz], fac[sz], cum[sz][sz];
ll dpcum[sz][sz*sz];

ll fnc(int n, int k) {
   if(!n) return 0;
   if(!k) return 1;
   ll &w = dp[n][k] = dpcum[n-1][k];
   int r = k - min(k, n - 1);
   if(r) w -= dpcum[n-1][r-1];
   if(w < 0) w += mod;
	return w;
}

void prec() {
   for(int i=0; i<sz; i++) {
      cmb[i][0] = cmb[i][i] = 1;
      for(int j=1; j<i; j++) {
         cmb[i][j] = cmb[i-1][j] + cmb[i-1][j-1];
         if(cmb[i][j] >= mod) cmb[i][j] -= mod;
      }
   }
   fac[0] = 1;
   for(int i=1; i<sz; i++) fac[i] = fac[i-1] * i % mod;
}

ll solve(int n, int k, int a, int b, int ca, int cb) {
   ll ans = cmb[a-1][ca] * cmb[b-a-1][cb-ca-1] % mod;
   ans = ans * cmb[n-b][n-k-cb] % mod;
   ans = ans * fac[k-1] % mod;
   ans = ans * cum[n-k][cb-ca+1] % mod;
   return ans;
}

int main() {
   int n;
   cin >> n >> mod;
   prec();

   for(int i=0; i<=n; i++) {
      dpcum[i][0] = fnc(i, 0);
      for(int j=1; j<big; j++) {
         dpcum[i][j] = fnc(i, j) + dpcum[i][j-1];
         if(dpcum[i][j] >= mod) dpcum[i][j] -= mod;
      }
   }

   for(int i=1; i<=n; i++) {
      for(int d=1; d<=n+2; d++) {
         ll &w = cum[i][d], sum = 0;
         for(int j=d; j<=i*i; j++) {
            sum += fnc(i, j-d);
            sum >= mod ? sum -= mod : 1;
            w += sum * fnc(i, j) % mod;
            w >= mod ? w -= mod : 1;
         }
      }
   }

   ll ans = 0;
   for(int k=1, r=n-1; k<=n; k++, r--) {
      for(int a=1; a<n; a++) {
         for(int b=a+1; b<=n; b++) {
            for(int ca=0; ca<=min(a-1, r-1); ca++) {
               for(int cb=ca+1; cb<=min(b-1, r); cb++) {
                  if(r-cb > n-b) continue;
                  ans += solve(n, k, a, b, ca, cb);
                  if(ans >= mod) ans -= mod;
               }
            }
         }
      }
   }
   cout << ans % mod;
}