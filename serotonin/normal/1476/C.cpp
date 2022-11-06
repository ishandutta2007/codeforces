#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

ll a[sz], b[sz], c[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%lld", &c[i]);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);
   for(int i=0; i<n; i++) scanf("%lld", &b[i]);
   ll ans = 0, now = 0;
   for(int i=1; i<n; i++) {
      if(a[i] == b[i]) {
         now = c[i] + 1;
      }
      else {
         ll one = now - abs(a[i] - b[i]) + 1;
         ll two = abs(a[i] - b[i]) + 1;
         now = max(one, two);
         now += c[i];
      }
      ans = max(ans, now);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}