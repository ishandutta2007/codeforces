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
    ll n, k;
    cin >> n >> k;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll x = max<ll>(min(r1, r2) - max(l1, l2), 0);
    k -= x * n;
    if (k <= 0) {
      cout << "0\n";
      continue;
    }
    ll a = x > 0 or min(r1, r2) == max(l1, l2) ? 0 : min(abs(l1 - r2), abs(r1 - l2));
    ll len = max(r1, r2) - min(l1, l2);
    ll b = a + min(len, 2 * len - (r1 - l1) - (r2 - l2));
    if (2 * (b - a) > b) {
      if (k <= (b - a) * n) {
        ll q = k / (b - a), r = k % (b - a);
        if (q == 0) {
          cout << a + r << '\n';
        } else {
          cout << b * q + min(2 * r, a + r) << '\n';
        }
      } else {
        k -= (b - a) * n;
        cout << b * n + 2 * k << '\n';
      }
    } else {
      if (k <= b - a) {
        cout << a + k << '\n';
      } else {
        k -= b - a;
        cout << b + 2 * k << '\n';
      }
    }
  }
}