#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

void solve() {
   ll n;
   scanf("%lld", &n);
   if(n & 1) {
      puts("-1");
      return;
   }
   n >>= 1;

   if(n & 1) {
      n -= 3;
      if(n < 0) {
         puts("-1");
         return;
      }
      ll mx = n >> 1;
      ll mn = n / 6 * 2;
      n %= 6;
      mn += n >> 1;
      printf("%lld %lld\n", mn + 1, mx + 1);
   }
   else {
      ll mx = n >> 1;
      ll mn = n / 6 * 2;
      n %= 6;
      mn += n >> 1;
      printf("%lld %lld\n", mn, mx);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}