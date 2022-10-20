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
    ll m, d, w;
    cin >> m >> d >> w;
    if (d == 1) {
      cout << "0\n";
      continue;
    }
    ll a = w / gcd(d - 1, w), b = min(m, d);
    if (b - a <= 0) {
      cout << "0\n";
      continue;
    }
    ll x = b - a, y = b % a;
    ll res = (x + y) * ((x - y) / a + 1) / 2;
    cout << res << '\n';
  }
}