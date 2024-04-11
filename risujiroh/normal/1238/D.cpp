#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Itr> auto rle(Itr first, Itr last) {
  V< pair<decltype(*first), int> > res;
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  lint res = (lint)n * (n - 1) / 2;
  auto v = rle(begin(s), end(s));
  int m = v.size();
  for (int i = 0; i < m - 1; ++i) {
    res -= v[i].second + v[i + 1].second - 1;
  }
  cout << res << '\n';
}