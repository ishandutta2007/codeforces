#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

char s[sz];
int dp[sz], up[sz], g[sz];

int main() {
   int k;
   cin >> k;
   scanf("%s", s);
   for(int i=0; s[i]; i++) up[i] = sz;
   int n = 1 << (k - 1);
   for(int i=0; i<n; i++) dp[i] = s[i] == '?' ? 2 : 1;

   int j = n; n >>= 1;
   while(n) {
      for(int i=0, c=j-n*2; i<n; i++, j++, c+=2) {
         g[j] = c;
         up[c] = up[c+1] = j;
         if(s[j] == '?') dp[j] = dp[c] + dp[c+1];
         else if(s[j] == '1') dp[j] = dp[c+1];
         else dp[j] = dp[c];
      }
      n >>= 1;
   }
   n = j - 1;

   int q, leaf = 1 << (k - 1);
   cin >> q;
   while(q--) {
      char ch;
      scanf("%d %c", &j, &ch); j--;
      s[j] = ch;
      while(j <= n) {
         int c = g[j];
         if(j < leaf) dp[j] = s[j] == '?' ? 2 : 1;
         else if(s[j] == '?') dp[j] = dp[c] + dp[c+1];
         else if(s[j] == '1') dp[j] = dp[c+1];
         else dp[j] = dp[c];
         j = up[j];
      }
      printf("%d\n", dp[n]);
   }
}