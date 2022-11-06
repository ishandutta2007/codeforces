#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, mod = 998244353;

int a[sz], b[sz];

int main()
{
   int n, m;
   cin >> n >> m;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=m; i++) scanf("%d", &b[i]);

   ll ans = 1;
   for(int i=n, k=m; k; k--) {
      int x = 0, y = 0;
      for(int j=i; j; j--) {
         if(a[j] < b[k]) {
            x = j;
            break;
         }
         if(a[j] == b[k] && !y) y = j;
      }
      if(!y) ans = 0;
      if(k > 1) {
         ans *= y - x;
         ans %= mod;
      }
      else if(x) ans = 0;
      i = x;
   }

   printf("%lld\n", ans);
}