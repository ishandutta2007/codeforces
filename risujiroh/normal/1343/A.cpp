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
    for (int k = 2; k <= 30; ++k) {
      int x = ~(-1u << k);
      if (n % x == 0) {
        cout << n / x << '\n';
        break;
      }
    }
  }
}