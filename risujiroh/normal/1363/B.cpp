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
    string s;
    cin >> s;
    int n = size(s);
    vector<int> c(n + 1);
    for (int i = n; i--; ) {
      c[i] = (s[i] == '1') + c[i + 1];
    }
    auto one = [&](int l, int r) { return c[l] - c[r]; };
    auto zero = [&](int l, int r) { return (r - l) - one(l, r); };
    int res = 1e9;
    for (int m = 0; m <= n; ++m) {
      res = min(res, zero(0, m) + one(m, n));
      res = min(res, one(0, m) + zero(m, n));
    }
    cout << res << '\n';
  }
}