#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 1e9+7;

ll dp[69];

ll bigmod(ll b, ll n) {
   b %= mod;
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
   int n;
   scanf("%d", &n);
   dp[1] = 6;
   for(int i=2; i<=n; i++) {
      ll x = dp[i-1] * bigmod(6, -1) % mod;
      x = x * 4 % mod;
      x = x * x % mod;
      dp[i] = x * 6 % mod;
   }
   if(dp[n] < 0) dp[n] += mod;
   cout << dp[n];
}