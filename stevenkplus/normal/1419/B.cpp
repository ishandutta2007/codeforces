#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
   int T;
   cin >> T;
   while (T--) {
      ll x;
      cin >> x;
      int ans = 0;
      for (int i = 1; i <= 30; ++i) {
         ll val = (1LL << i) - 1;
         val = val * (val + 1) / 2;
         if (x < val) break;
         x -= val;
         ++ans;
      }
      cout << ans << "\n";
   }
}