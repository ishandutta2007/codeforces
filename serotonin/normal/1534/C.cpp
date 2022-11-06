#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7, mod = 1e9+7;

int a[sz], b[sz], w[sz];
bool done[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), w[a[i]] = i;
   for(int i=1; i<=n; i++) scanf("%d", &b[i]);
   for(int i=1; i<=n; i++) done[i] = 0;

   int ans = 1;
   for(int i=1; i<=n; i++) {
      if(done[a[i]]) continue;
      int j = i;
      while(!done[a[j]]) {
         done[a[j]] = 1;
         int x = b[j];
         j = w[x];
      }
      ans = (ans << 1) % mod;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}