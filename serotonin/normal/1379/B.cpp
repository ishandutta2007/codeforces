#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   ll l, r, m;
   scanf("%lld %lld %lld", &l, &r, &m);
   ll smol = LLONG_MAX, smol2 = LLONG_MAX, wa = 0, wa2 = 0;
   for(ll i=l; i<=min(m,r); i++) {
      ll x = m % i;
      if(x <= smol) smol = x, wa = i;
      ll y = i - x;
      if(y <= smol2) smol2 = y, wa2 = i;
   }
   if(smol <= r - l) {
      ll b = r, c = b - smol;
      printf("%lld %lld %lld\n", wa, b, c);
      return;
   }
   if(smol2 <= r - l) {
      ll b = l, c = b + smol2;
      printf("%lld %lld %lld\n", wa2, b, c);
      return;
   }
   ll a = l;
   ll b = l, c = a + b - m;
   printf("%lld %lld %lld\n", a, b, c);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}