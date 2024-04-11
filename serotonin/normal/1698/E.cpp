#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mod = 998244353;

int a[sz], b[sz], w[sz], cnt[sz];

void solve() {
   int n, s;
   scanf("%d %d", &n, &s);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=n; i++) scanf("%d", &b[i]);

   for(int i=0; i<=n; i++) w[i] = cnt[i] = 0;

   vector <int> ara;
   for(int i=1; i<=n; i++) {
      if(~b[i]) w[b[i]] = i;
      else ara.push_back(a[i]);
   }
   sort(ara.begin(), ara.end());

   for(int i=1, j=i+s; i<=n; i++, j=min(n, j+1)) {
      if(w[i]) {
         if(a[w[i]] > j) {
            puts("0");
            return;
         }
      }
      else {
         int k = upper_bound(ara.begin(), ara.end(), j) - ara.begin();
         cnt[k]++;
      }
   }

   ll ans = 1;
   for(int i=ara.size(), j=0; i; i--) {
      j += cnt[i];
      ans = ans * j % mod;
      if(!j) break;
      j--;
   }
   printf("%lld\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}