#include <bits/stdc++.h>
using namespace std;

template <class It> auto rle(It first, It last) {
  vector<pair<decltype(*first), int>> res;
  for (; first != last; ++first) {
    if (res.empty() or res.back().first != *first) {
      res.emplace_back(*first, 1);
    } else {
      ++res.back().second;
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    auto v = rle(begin(s), end(s));
    int n = v.size(), res = 0;
    for (int i = 1; i < n - 1; ++i) {
      if (v[i].first == '0') {
        res += v[i].second;
      }
    }
    cout << res << '\n';
  }
}