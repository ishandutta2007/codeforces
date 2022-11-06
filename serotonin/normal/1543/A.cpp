#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7, mod = 1e9+7;

void solve() {
   ll a, b;
   scanf("%lld %lld", &a, &b);

   if(a == b) {
      puts("0 0");
      return;
   }

   ll d = abs(a - b);
   ll x = a / d;
   ll mv = min(abs(a - x * d), abs(a - (x + 1) * d));
   printf("%lld %lld\n", d, mv);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}