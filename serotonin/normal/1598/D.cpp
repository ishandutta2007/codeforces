#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int n, a[sz], b[sz], acnt[sz], bcnt[sz];

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);

   for(int i=1; i<=n; i++) acnt[i] = bcnt[i] = 0;

   ll ans = (ll) n * (n - 1) * (n - 2) / 6;
   for(int i=1; i<=n; i++) acnt[a[i]]++, bcnt[b[i]]++;
   for(int i=1; i<=n; i++) {
      ans -= (acnt[a[i]] - 1LL) * (bcnt[b[i]] - 1LL);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}