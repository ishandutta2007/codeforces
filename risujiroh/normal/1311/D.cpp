#include <bits/stdc++.h>
using namespace std;

auto chmin = [](auto&& l, auto r) { return r < l ? l = r, 1 : 0; };

constexpr int lim = 2e4, inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<vector<int>> ds(lim + 1);
  for (int d = 1; d <= lim; ++d) {
    for (int i = d; i <= lim; i += d) {
      ds[i].push_back(d);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int res = inf, ra = -1, rb = -1, rc = -1;
    for (int y = 1; y <= lim; ++y) {
      int cur = abs(y - b);

      int z = c / y * y;
      int zl = z ? abs(z - c) : inf, zr = abs((z + y) - c);
      cur += min(zl, zr);

      auto it = lower_bound(begin(ds[y]), end(ds[y]), a);
      int xl = it != end(ds[y]) ? abs(*it - a) : inf;
      int xr = it != begin(ds[y]) ? abs(*prev(it) - a) : inf;
      cur += min(xl, xr);

      if (chmin(res, cur)) {
        ra = xr < xl ? *prev(it) : *it;
        rb = y;
        rc = zr < zl ? z + y : z;
      }
    }
    cout << res << '\n';
    cout << ra << ' ' << rb << ' ' << rc << '\n';
  }
}