#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 2e11+7;

ll prime[15];

ll dig(ll x) {
   ll y = 0;
   while(x) x /= 10, y++;
   return y;
}

void solve() {
   int a, b, c;
   scanf("%d %d %d", &a, &b, &c);

   ll z = prime[c], x = z, y = z;
   while(dig(x) < a) x *= 2;
   while(dig(y) < b) y *= 3;
   printf("%lld %lld\n", x, y);
}

int main() {
   ll x = 1;
   while(x < sz) {
      x *= 5;
      prime[dig(x)] = x;
   }
   int t;
   cin >> t;
   while(t--) solve();
}