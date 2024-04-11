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
    string s;
    cin >> s;
    auto v = rle(s);
    string res;
    if (v[0].first == '0') {
      res = string(v[0].second, v[0].first);
      v.erase(begin(v));
    }
    string t;
    if (not empty(v) and v.back().first == '1') {
      t = string(v.back().second, v.back().first);
      v.pop_back();
    }
    if (not empty(v)) {
      res += "0";
    }
    res += t;
    cout << res << '\n';
  }
}