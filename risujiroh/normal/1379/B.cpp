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
    using ll = long long;
    ll l, r, m;
    cin >> l >> r >> m;
    ll lb = m - r + l, ub = m - l + r;
    for (ll a = l; a <= r; ++a) {
      if (ub / a * a >= lb) {
        ll d = m - ub / a * a;
        ll b, c;
        for (int x = l; x <= r; ++x) {
          b = x, c = b - d;
          if (l <= c and c <= r) break;
        }
        cout << a << ' ' << b << ' ' << c << '\n';
        break;
      }
    }
  }
}