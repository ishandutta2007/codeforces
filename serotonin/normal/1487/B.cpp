#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   if(n & 1) {
      int x = (k - 1) % n;
      int y = n / 2;
      x += k / y;
      if(k % y == 0) x--;
      printf("%d\n", x % n + 1);
   }
   else printf("%d\n", (k - 1) % n + 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}