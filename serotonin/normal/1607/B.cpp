#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

void solve() {
   ll x, n;
   scanf("%lld %lld", &x, &n);
   ll z = n / 4 * 4 + 1;
   while(z <= n) {
      if(x & 1) x += z;
      else x -= z;
      z++;
   }
   printf("%lld\n", x);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}