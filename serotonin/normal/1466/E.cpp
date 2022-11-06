#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5, mod = 1e9+7;

ll a[sz], bt[69], pw[69], mp[69];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);
   for(int i=0; i<69; i++) bt[i] = 0;

   for(int i=0; i<n; i++) {
      ll x = a[i];
      for(int j=0; j<60; j++) if(x & pw[j]) bt[j]++;
   }

   ll ans = 0;
   for(int i=0; i<n; i++) {
      ll x = a[i], lhs = 0;
      for(int j=0; j<60; j++) if(x & pw[j]) {
         lhs += mp[j] * bt[j] % mod;
         lhs %= mod;
      }

      ll rhs = 0;
      for(int j=0; j<60; j++) {
         if(x & pw[j]) {
            rhs += mp[j] * n % mod;
            rhs %= mod;
         }
         else {
            rhs += mp[j] * bt[j] % mod;
            rhs %= mod;
         }
      }

      ans += lhs * rhs % mod;
      ans %= mod;
   }
   ans += mod; ans %= mod;
   printf("%lld\n", ans);
}

int main() {
   for(int i=0; i<69; i++) pw[i] = 1LL << i, mp[i] = pw[i] % mod;
   int t;
   cin >> t;
   while(t--) solve();
}