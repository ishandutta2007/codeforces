#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int dp[sz];
char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   ll ans = 0;
   for(int i=n-1, j=n; i>=0; i--) {
      if(j == n) ans += n - i, dp[i] = n - 1;
      else if(s[i] == '?') ans += dp[j] - i + 1, dp[i] = dp[j];
      else if(s[i+1] == s[i]) ans++, dp[i] = i;
      else if(s[i+1] == '?') {
         int d = j - i;
         if((d & 1) == (s[i] ^ s[j])) ans += dp[j] - i + 1, dp[i] = dp[j];
         else ans += j - i, dp[i] = j - 1;
      }
      else ans += dp[i+1] - i + 1, dp[i] = dp[i+1];

      if(s[i] != '?') j = i;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}