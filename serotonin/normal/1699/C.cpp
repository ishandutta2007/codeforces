#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7, mod = 1e9+7;

int a[sz], w[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), w[a[i]] = i;
   ll ans = 1;
   for(int i=0, l=w[0], r=l; i<n; i++) {
      if(l <= w[i] and w[i] <= r) ans = ans * (r - l + 1 - i) % mod;
      else {
         l = min(l, w[i]);
         r = max(r, w[i]);
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}