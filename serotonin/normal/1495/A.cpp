#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz = 2e6+5;

ll a[sz], b[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1, j=0, k=0; i<=2*n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      if(!x) b[j++] = abs(y);
      else a[k++] = abs(x);
   }
   sort(a, a+n);
   sort(b, b+n);

   ld ans = 0;
   for(int i=0; i<n; i++) {
      ld now = a[i] * a[i] + b[i] * b[i];
      ans += sqrt(now);
   }
   printf("%.15f\n", (double)ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}