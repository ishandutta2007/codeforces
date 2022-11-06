#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

ll a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);
   ll mx = 0, sum = a[0];
   for(int i=1; i<n; i++) {
//      a[i] / (sum + x) <= k / 100
      ll x = (a[i] * 100 + k - 1) / k - sum;
      mx = max(mx, x);
      sum += a[i];
   }
   printf("%lld\n", mx);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}