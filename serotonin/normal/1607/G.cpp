#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], b[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%d %d", &a[i], &b[i]);

   ll lo = 0, hi = 0;
   for(int i=0; i<n; i++) {
      ll mx = min(a[i], m);
      ll mn = m - min(b[i], m);
      hi += a[i] - b[i] + (m - mn) - mn;
      lo += a[i] - b[i] + (m - mx) - mx;
   }

   if(hi < 0) {
      printf("%lld\n", abs(hi));
      for(int i=0; i<n; i++) {
         int mn = m - min(b[i], m);
         printf("%d %d\n", mn, m - mn);
      }
   }
   else if(lo > 0) {
      printf("%lld\n", lo);
      for(int i=0; i<n; i++) {
         int mx = min(a[i], m);
         printf("%d %d\n", mx, m - mx);
      }
   }
   else {
      printf("%lld\n", hi & 1);
      for(int i=0; i<n; i++) {
         int mx = min(a[i], m);
         int mn = m - min(b[i], m);
         int d = min(hi / 2, (ll) mx - mn);
         hi -= d * 2, mn += d;
         printf("%d %d\n", mn, m - mn);
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}