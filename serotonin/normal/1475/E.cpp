#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005, mod = 1e9+7;

int a[sz], c[sz];
ll fac[sz], finv[sz], inv[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
}

ll cmb(int n, int r) {
   if(n < r or r < 0) return 0;
   ll d = finv[r] * finv[n-r] % mod;
   return fac[n] * d % mod;
}

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), c[a[i]]++;
   sort(a, a+n, greater<int>());
   int x = a[k-1], z = 0;
   for(int i=n; i>x; i--) k -= c[i];
   printf("%d\n", cmb(c[x], k));
   for(int i=1; i<=n; i++) c[i] = 0;
}

int main() {
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}