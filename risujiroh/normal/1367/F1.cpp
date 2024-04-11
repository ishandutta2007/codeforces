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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      v[i] = {a[i], i};
    }
    sort(begin(v), end(v));
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      int x = lower_bound(begin(v), end(v), make_pair(a[i], i)) - begin(v);
      p[x] = i;
    }
    string s;
    for (int i = 1; i < n; ++i) {
      s += '0' + (p[i - 1] < p[i]);
    }
    int res = 1;
    for (auto [c, len] : rle(s)) {
      if (c == '0') continue;
      res = max(res, len + 1);
    }
    res = n - res;
    cout << res << '\n';
  }
}