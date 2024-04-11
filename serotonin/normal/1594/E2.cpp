#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 1e9+7;

ll tot[69], dp[sz][3];

set <ll> st[69];

map <ll,int> given, pos;

string color[] = {"White", "Yellow", "Green", "Blue", "Red", "Orange"};

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
   int n;
   scanf("%d", &n);
   tot[1] = 6;
   for(int i=2; i<=n; i++) {
      ll x = tot[i-1] * bigmod(6, -1) % mod;
      x = x * 4 % mod;
      x = x * x % mod;
      tot[i] = x * 6 % mod;
   }
   for(int i=1; i<=n; i++) tot[i] = tot[i] * bigmod(3, -1) % mod;

   int m;
   cin >> m;
   while(m--) {
      ll v; char s[20];
      scanf("%lld %s", &v, s);
      int c;
      for(int i=0; i<6; i++) if(toupper(s[0]) == color[i][0]) c = i;

      int b = 64 - __builtin_clzll(v);
      st[b].insert(v);
      given[v] = c >> 1;
//      cerr << given[v] << endl;
   }

   int k = 0;
   for(int j=n; j; j--) {
      for(ll u : st[j]) {
         ll zdp[3] = {};

         int ok[3] = {};
         if(given.find(u) != given.end()) ok[given[u]] = 1;
         else for(int i=0; i<3; i++) ok[i] = 2;

         if(j == n) for(int i=0; i<3; i++) zdp[i] = 1;
         else {
            ll x = u << 1, y = x | 1;
            ll xdp[3], ydp[3];
            if(pos.find(x) != pos.end()) for(int i=0; i<3; i++) xdp[i] = dp[pos[x]][i];
            else for(int i=0; i<3; i++) xdp[i] = tot[n-j];
            if(pos.find(y) != pos.end()) for(int i=0; i<3; i++) ydp[i] = dp[pos[y]][i];
            else for(int i=0; i<3; i++) ydp[i] = tot[n-j];

            for(int i=0; i<3; i++) {
               for(int xi=0; xi<3; xi++) {
                  for(int yi=0; yi<3; yi++) {
                     if(i == xi or i == yi) continue;
                     zdp[i] += xdp[xi] * ydp[yi] % mod;
                     if(zdp[i] >= mod) zdp[i] -= mod;
                  }
               }
            }
         }

         pos[u] = ++k;
//         cerr << u << endl;
//         for(int i=0; i<3; i++) printf("%lld ", zdp[i]); puts("");
         for(int i=0; i<3; i++) dp[k][i] = zdp[i] * ok[i];
//         for(int i=0; i<3; i++) printf("%lld ", dp[k][i]); puts("");
         st[j-1].insert(u >> 1);
      }
   }
//   cerr << tot[2] << endl;
   ll ans = 0;
   for(int i=0; i<3; i++) ans += dp[k][i];
   ans %= mod; ans += mod; ans %= mod;
   cout << ans;
}