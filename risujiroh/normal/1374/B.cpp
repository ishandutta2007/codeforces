#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int res = 0;
    while (n > 1) {
      ++res;
      if (n % 6 == 0) {
        n /= 6;
      } else if (n % 3 == 0) {
        n *= 2;
      } else {
        res = -1;
        break;
      }
    }
    cout << res << '\n';
  }
}