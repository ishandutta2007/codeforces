#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7, mod = 1e9+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   int mx = 0;
   for(int j=0; j<30; j++) {
      for(int i=0; i<n; i++) {
         if(a[i] & 1 << j) continue;
         mx |= 1 << j;
      }
   }
   ll cnt = 0;
   for(int i=0; i<n; i++) {
      if(a[i] & mx) continue;
      cnt++;
   }
   ll ans = cnt * (cnt - 1) % mod;
   for(int i=1; i<=n-2; i++) ans = ans * i % mod;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}