#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    if (__builtin_popcount(x + 1) == 1) {
      bool found = false;
      for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
          cout << x / i << "\n";
          found = true;
          break;
        }
      }
      if (!found) {
        cout << 1 << "\n";
      }
    } else {
      int ans = 1;
      while (ans <= x) {
        ans <<= 1;
      }
      cout << ans - 1 << "\n";
    }
  }
  return 0;
}