#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 17, sz = 1<<N, mod = 998244353;

char s[1005];
ll dp[N+1][sz], bigmod[1005];
vector <int> clen[sz];

int main() {
   int n; cin >> n;
   scanf("%s", s); 
   
   int tq = 0;
   for(int i=0; i<n; i++) tq += s[i] == '?';

   for(int i=0; i<n; i++) {
      int l = i, r = i + 1, qc = 0, m = 0;
      while(0 <= l and r < n) {
         if(s[l] == '?' and s[r] == '?') qc++;
         else if(s[l] == '?') qc++, m |= 1 << (s[r] - 'a');
         else if(s[r] == '?') qc++, m |= 1 << (s[l] - 'a');
         else if(s[l] != s[r]) break;
         clen[m].push_back(tq - qc);
         l--, r++;
      }

      l = i, r = i, qc = 0, m = 0;
      while(0 <= l and r < n) {
         if(s[l] == '?' and s[r] == '?') {
            if(l != r) qc++;
         }
         else if(s[l] == '?') qc++, m |= 1 << (s[r] - 'a');
         else if(s[r] == '?') qc++, m |= 1 << (s[l] - 'a');
         else if(s[l] != s[r]) break;
         clen[m].push_back(tq - qc);
         l--, r++;
      }
   }
   
   bigmod[0] = 1;
   for(int j=1; j<=N; j++) {
      for(int i=1; i<=n; i++) bigmod[i] = bigmod[i-1] * j % mod;
      for(int i=0; i<sz; i++) {
         for(int len : clen[i]) dp[j][i] += bigmod[len];
         dp[j][i] %= mod;
      }
   }
   
   for(int k=1; k<=N; k++) {
      for(int i=0; i<N; i++) {
         for(int j=0; j<sz; j++) {
            if(j & 1 << i) {
               dp[k][j] += dp[k][j ^ 1 << i];
               if(dp[k][j] >= mod) dp[k][j] -= mod;
            }
         }
      }
   }
   
   int q; cin >> q;
   while(q--) {
      scanf("%s", s);
      int m = 0;
      for(int i=0; s[i]; i++) m |= 1 << (s[i] - 'a');
      printf("%lld\n", dp[__builtin_popcount(m)][m]);
   }
}