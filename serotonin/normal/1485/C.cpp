#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int main() {
   int t;
   cin >> t;
   while(t--) {
      int x, y;
      scanf("%d %d", &x, &y);
      ll ans = 0;
      for(int i=1; i<min(y, 500000); i++) {
         ans += max(0, min(x / i - 1, y) - i);
      }
      printf("%lld\n", ans);
   }
}