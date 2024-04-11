#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e9+7;

void solve() {
   int n;
   scanf("%d", &n);
   if(n & 1) {
      int x = n >> 1, y = x;
      while(__gcd(x, y) > 1) x++, y--;
      printf("%d %d 1\n", x, y, 1);
   }
   else printf("%d %d 1\n", n / 2, n / 2 - 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}