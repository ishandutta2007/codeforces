#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   ll a, b, c, d;
   scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
   a *= d, b *= c;
   if(a == b) puts("0");
   else if(!a or !b) puts("1");
   else {
      ll g = __gcd(a, b);
      a /= g, b /= g;
      if(a == 1 or b == 1) puts("1");
      else puts("2");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}