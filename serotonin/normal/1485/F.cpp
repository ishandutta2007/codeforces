#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, mod = 1e9+7;

ll b[sz], cum[sz], dp[sz], dpb[sz], dpz[sz];
int who[sz];

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d", &n);
      for(int i=1; i<=n; i++) {
         scanf("%lld", &b[i]);
         cum[i] = b[i] + cum[i-1];
         who[i] = 0;
      }
      map <ll,vector<int>> mp;
      for(int i=n; i; i--) {
         ll f = cum[i] - b[i];
         if(mp.find(f) != mp.end()) {
            auto &v = mp[f];
            for(int j : v) who[j] = i;
            v.clear();
         }
         mp[cum[i]].push_back(i);
      }
      dp[1] = dpb[1] = dpz[1] = 1;
      if(b[1]) dpz[1] = 0;
      for(int i=2; i<=n; i++) {
         dpb[i] = dp[i-1];
         dpz[i] = dpb[who[i]];
         if(!b[i]) dpz[i] = dpb[i];
         dp[i] = dp[i-1] - dpz[i-1] + dpb[i];
         dp[i] %= mod;
         if(dp[i] < 0) dp[i] += mod;
      }
      printf("%lld\n", dp[n]);
   }
}