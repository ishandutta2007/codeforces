#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll a[sz], b[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);
   sort(a, a+n);

   ll ans = 0;
   for(int i=0; i<n; i++) ans += a[i], b[i] = a[i];

   for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) a[i] = b[i];
      for(int i=0; i<n; i++) if(i ^ k) {
         while(~a[i] & 1) {
            a[i] >>= 1;
            a[k] <<= 1;
            ll sum = 0;
            for(int j=0; j<n; j++) sum += a[j];
            ans = max(ans, sum);
         }
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t = 1;
   cin >> t;
   while(t--) solve();
}