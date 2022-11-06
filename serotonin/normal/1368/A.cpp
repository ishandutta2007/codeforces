#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
   int t;
   cin >> t;
   while(t--) {
      ll a, b, n;
      scanf("%lld %lld %lld", &a, &b, &n);

      ll ans = 0;
      while(max(a, b) <= n) {
         if(a > b) b += a;
         else a += b;
         ans++;
      }

      printf("%lld\n", ans);
   }
}