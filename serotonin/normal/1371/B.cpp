#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

inline ll fnc(ll n) {
   return n * (n + 1) >> 1;
}

int main()
{
   int t;
   cin >> t;
   while(t--) {
      ll n, r;
      cin >> n >> r;
      ll ans = fnc(min(n-1, r));
      if(n <= r) ans++;
      printf("%lld\n", ans);
   }
}