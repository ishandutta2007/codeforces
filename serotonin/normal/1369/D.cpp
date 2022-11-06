#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5, mod = 1e9+7;

ll a[sz], ans[sz];

void solve()
{
   int n;
   scanf("%d", &n);
   printf("%lld\n", ans[n] * 4 % mod);
}

void prec()
{
   a[1] = a[2] = 1;
   for(int i=3; i<sz; i++) {
      a[i] = a[i-2] * 2 + a[i-1];
      a[i] %= mod;

      ans[i] = a[i-2];
      if(i>=3) ans[i] += ans[i-3];
      ans[i] %= mod;
   }
}

int main()
{
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}