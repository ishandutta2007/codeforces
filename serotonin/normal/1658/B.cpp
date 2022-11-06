#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5, mod = 998244353;

ll fac[sz];

void solve() {
   int n;
   scanf("%d", &n);
   if(n & 1) puts("0");
   else {
      n >>= 1;
      printf("%lld\n", fac[n] * fac[n] % mod);
   }
}

int main() {
   fac[0] = 1;
   for(int i=1; i<sz; i++) fac[i] = fac[i-1] * i % mod;
   int t;
   cin >> t;
   while(t--) solve();
}