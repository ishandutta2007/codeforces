#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int a[sz], b[sz], nxt[sz], dp[sz];
bitset <sz> prime;

void solve() {
   int n, e;
   scanf("%d %d", &n, &e);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   ll ans = 0;
   for(int k=1; k<=e; k++) {
      int c = 1;
      for(int j=k; j<=n; c++, j+=e) b[c] = a[j];
      c--;

      nxt[c+1] = c+1; dp[c+1] = 0;
      for(int i=c; i; i--) {
         nxt[i] = nxt[i+1];
         if(b[i] > 1) nxt[i] = i;
         // printf("%d ", nxt[i]);
         dp[i] = 0;
      }
      // puts("");

      for(int i=c; i; i--) {
         if(b[i] > 1) {
            if(!prime[b[i]]) continue;
            dp[i] = nxt[i+1] - i - 1;
            ans += dp[i];
         }
         else {
            int j = nxt[i+1];
            if(j > c or !prime[b[j]]) continue;
            ans += dp[j] + 1;
         }
      }
      // cout << ans << endl;
   }
   printf("%lld\n", ans);
}

int main() {
   prime.set(); prime[0] = prime[1] = 0;
   for(int i=2; i<sz; i++) {
      if(!prime[i]) continue;
      if(i > sz / i) continue;
      for(int j=i*i; j<sz; j+=i) prime[j] = 0;
   }
   int t;
   cin >> t;
   while(t--) solve();
}