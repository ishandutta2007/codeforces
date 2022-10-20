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
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<vector<pair<int, int>>> v(r + 1);
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    v[r].emplace_back(a, b);
    v[c].emplace_back(a, q);
    v[c].emplace_back(p, b);
  }
  long long res = 0, cur = 0;
  set<pair<int, int>> se;
  se.emplace(0, q + 1);
  se.emplace(p + 1, 0);
  auto add = [&](auto&& self, int x, int y) {
    auto it = se.lower_bound({x, 0});
    if (it->second >= y) return;
    --it;
    if (it->second >= y) {
      cur += (long long)(x - it->first) * (y - next(it)->second);
      if (next(it)->first == x) {
        se.erase(next(it));
      }
      if (it->second == y) {
        se.erase(it);
      }
      se.emplace(x, y);
      return; 
    }
    cur += (long long)(x - it->first) * (it->second - next(it)->second);
    if (next(it)->first == x) {
      se.erase(next(it));
    }
    se.emplace(x, it->second);
    se.erase(it);
    self(self, x, y);
  };
  for (int z = r; z; --z) {
    for (auto [x, y] : v[z]) {
      add(add, x, y);
      DEBUG(x, y, z);
      DEBUG(se);
      DEBUG(cur);
    }
    res += cur;
  }
  res = (long long)p * q * r - res;
  cout << res << '\n';
}