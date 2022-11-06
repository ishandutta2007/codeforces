#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];
ll lhs[sz], rhs[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   if(n & 1) {
      ll ans = 0;
      for(int i=2; i<n; i+=2) ans += max(0, max(a[i-1], a[i+1]) + 1 - a[i]);
      printf("%lld\n", ans);
   }
   else {
      rhs[n+1] = 0;
      for(int i=2; i<n; i+=2) lhs[i] = lhs[i-2] + max(0, max(a[i-1], a[i+1]) + 1 - a[i]);
      for(int i=n-1; i>1; i-=2) rhs[i] = rhs[i+2] + max(0, max(a[i-1], a[i+1]) + 1 - a[i]);
      ll ans = LLONG_MAX;
      for(int i=0; i<n; i+=2) ans = min(ans, lhs[i] + rhs[i+3]);
      printf("%lld\n", ans);
   }
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}