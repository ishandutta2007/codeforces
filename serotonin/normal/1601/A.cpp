#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n, a[31] = {};
   scanf("%d", &n);
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      for(int i=0; i<30; i++) if(x & 1 << i) a[i]++;
   }
   int ans = n + 1;
   for(int i=0; i<30; i++) {
      if(!a[i]) continue;
      if(ans > n) ans = a[i];
      else ans = __gcd(ans, a[i]);
   }
   if(ans > n) {
      for(int i=1; i<=n; i++) printf("%d ", i); puts("");
   }
   else {
      for(int i=1; i<=n; i++) if(ans % i == 0) printf("%d ", i); puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}