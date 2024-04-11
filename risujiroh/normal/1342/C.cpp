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
    int a, b, q;
    cin >> a >> b >> q;
    vector<int> c(a * b + 1);
    for (int x = a * b; x--; ) {
      c[x] = (x % a % b != x % b % a) + c[x + 1];
    }
    int k = a * b;
    while (q--) {
      long long l, r;
      cin >> l >> r;
      ++r;
      auto res = 0LL;
      if (l % k) {
        auto nl = min((l + k - 1) / k * k, r);
        res += c[l % k] - c[nl % k ? nl % k : k];
        l = nl;
      }
      if (r % k) {
        auto nr = max(r / k * k, l);
        res += c[nr % k] - c[r % k];
        r = nr;
      }
      res += (r - l) / (a * b) * c[0];
      cout << res << " \n"[q == 0];
    }
  }
}