#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    lint a, b, m; cin >> a >> b >> m;
    if (a == b) {
      cout << 1 << ' ' << a << '\n';
      continue;
    }
    bool ok = false;
    for (int i = 1; i < 50; ++i) {
      if (b < a + 1 << i - 1) break;
      lint c = b - (a + 1 << i - 1);
      V<lint> r(i);
      for (int j = 0; j < i; ++j) {
        r[j] = min(c >> max(i - 2 - j, 0), m - 1);
        c -= r[j] << max(i - 2 - j, 0);
      }
      if (c) continue;
      ok = true;
      V<lint> res{a};
      for (lint e : r) {
        res.push_back(accumulate(begin(res), end(res), 0LL) + e + 1);
      }
      assert(res.back() == b);
      cout << res.size();
      for (lint e : res) cout << ' ' << e;
      cout << '\n';
      break;
    }
    if (!ok) cout << -1 << '\n';
  }
}