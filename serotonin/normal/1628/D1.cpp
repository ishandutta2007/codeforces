#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005, mod = 1e9+7;

bool vis[sz][sz];
ll dp[sz][sz], k;

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

const ll bytwo = bigmod(2, -1);

ll fnc(int n, int x) {
   if(n == x) return n * k % mod;
   if(!x) return 0;
   bool &v = vis[n][x];
   ll &w = dp[n][x];
   if(v) return w; v = 1;
   ll val = fnc(n - 1, x) - fnc(n - 1, x - 1);
   val = val * bytwo % mod;
   w = val + fnc(n - 1, x - 1);
   w %= mod;
   return w;
}

void solve() {
   int n, m;
   scanf("%d %d %lld", &n, &m, &k);
   for(int i=0; i<=n; i++) memset(vis[i], 0, sizeof(vis[i]));
   ll ans = fnc(n, m);
   ans %= mod; ans += mod; ans %= mod;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}