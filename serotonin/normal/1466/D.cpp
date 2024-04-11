#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, a[sz], w[sz];

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &w[i]), a[i] = 0;
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      a[u]++, a[v]++;
   }
   ll ans = 0;
   vector <ll> ara;
   for(int i=1; i<=n; i++) {
      a[i]--;
      ans += w[i];
      while(a[i]--) ara.push_back(w[i]);
   }
   sort(ara.begin(), ara.end());
   reverse(ara.begin(), ara.end());

   printf("%lld", ans);
   for(ll x : ara) ans += x, printf(" %lld", ans);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}