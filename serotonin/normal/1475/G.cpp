#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], dp[sz];

void solve() {
   int n, mx = 0;
   scanf("%d", &n);
   memset(a, 0, sizeof a);
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      a[x]++; mx = max(mx, x);
   }
   int ans = 0;
   for(int i=mx; i>1; i--) {
      int &w = dp[i] = 0;
      for(int j=i+i; j<=mx; j+=i) w = max(w, dp[j]);
      w += a[i];
      ans = max(ans, w);
   }
   printf("%d\n", n - ans - a[1]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}