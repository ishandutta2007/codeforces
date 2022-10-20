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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto v = rle(s);
    int m = size(v);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      if (v[i].first == '1') continue;
      int len = v[i].second;
      if (i == 0 and i == m - 1) {
        res += (len + k) / (k + 1);
      } else if (i == 0 or i == m - 1) {
        res += len / (k + 1);
      } else {
        res += max(len - k, 0) / (k + 1);
      }
    }
    cout << res << '\n';
  }
}