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
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (2 * a <= b) {
      cout << (x + y) * a << '\n';
    } else {
      if (x > y) {
        swap(x, y);
      }
      cout << x * b + (y - x) * a << '\n';
    }
  }
}