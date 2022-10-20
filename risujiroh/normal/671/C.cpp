#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

constexpr int lim = 2e5;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<vector<int>> divisors(lim + 1);
  for (int d = 1; d <= lim; ++d) {
    for (int i = d; i <= lim; i += d) {
      divisors[i].push_back(d);
    }
  }
  int n;
  cin >> n;
  vector<vector<int>> pos(lim + 1);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int d : divisors[a]) {
      pos[d].push_back(i);
    }
  }
  auto cur = 0LL;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[i] = i;
  }
  mp[n] = n + 1;
  auto update = [&](int l, int x) {
    auto it = prev(mp.upper_bound(l));
    if (it->second >= x) return;
    mp[l] = it->second;
    for (it = mp.lower_bound(l); it->second <= x; ) {
      cur += (long long)(next(it)->first - it->first) * (x - it->second);
      if (it->first == l) {
        it->second = x;
        ++it;
      } else {
        it = mp.erase(it);
      }
    }
  };
  auto res = 0LL;
  for (int d = lim; d; --d) {
    int m = size(pos[d]);
    if (m >= 2) {
      update(0, pos[d][m - 2]);
      update(pos[d][0] + 1, pos[d][m - 1]);
      update(pos[d][1] + 1, n);
    }
    res += cur;
  }
  cout << res << '\n';
}