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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int res = 0;
    while (n--) {
      string s;
      cin >> s;
      for (auto [c, len] : rle(s)) {
        if (c == '*') continue;
        if (y < 2 * x) {
          res += y * (len / 2);
          if (len & 1) {
            res += x;
          }
        } else {
          res += x * len;
        }
      }
    }
    cout << res << '\n';
  }
}