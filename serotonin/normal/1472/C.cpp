#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];
ll dp[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   ll ans = 0;
   for(int i=n; i; i--) {
      dp[i] = a[i];
      if(i + a[i] <= n) dp[i] += dp[i + a[i]];
      ans = max(ans, dp[i]);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}