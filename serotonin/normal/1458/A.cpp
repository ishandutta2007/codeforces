#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

ll a[sz], b[sz];

int main() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);
   for(int i=0; i<m; i++) scanf("%lld", &b[i]);

   if(n == 1) {
      for(int i=0; i<m; i++) printf("%lld ", b[i] + a[0]);
      return 0;
   }

   sort(a, a+n);
   ll x = a[1] - a[0];
   for(int i=1; i<n-1; i++) x = __gcd(x, a[i+1] - a[i]);

   for(int i=0; i<m; i++) {
      ll y = b[i] + a[0];
      printf("%lld ", __gcd(x, y));
   }
}