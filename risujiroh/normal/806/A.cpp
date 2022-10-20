#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  using ll = long long;
  while (tt--) {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == 0) {
      cout << (x == 0 ? 0 : -1) << '\n';
    } else if (p == q) {
      cout << (x == y ? 0 : -1) << '\n';
    } else {
      ll mx = max({(x + p - 1) / p, (y + q - 1) / q, (y - x + q - p - 1) / (q - p)});
      cout << mx * q - y << '\n';
    }
  }
}