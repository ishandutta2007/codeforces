#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class S> auto rle(const S& s) {
  vector<decltype(make_pair(s[0], 1))> res;
  for (auto c : s)
    if (empty(res) or res.back().first != c) res.emplace_back(c, 1);
    else ++res.back().second;
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    using ll = long long;
    ll h, c, t;
    cin >> h >> c >> t;
    if (2 * t <= c + h) {
      cout << "2\n";
      continue;
    }
    ll ok = 0, ng = 3e6;
    while (ng - ok > 1) {
      ll mid = (ok + ng) / 2;
      (mid * c + (mid + 1) * h >= (2 * mid + 1) * t ? ok : ng) = mid;
    }
    if (2 * t * (2 * ok + 1) * (2 * ok + 3) < (ok * c + (ok + 1) * h) * (2 * ok + 3) + ((ok + 1) * c + (ok + 2) * h) * (2 * ok + 1)) {
      cout << 2 * ng + 1 << '\n';
    } else {
      cout << 2 * ok + 1 << '\n';
    }
  }
}