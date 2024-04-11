#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  V<string> s(h); for (auto&& e : s) cin >> e;
  int tt = 0;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
    tt += s[i][j] == '*';
  }
  VV<> l(h, V<>(w)), r(h, V<>(w));
  for (int i = 0; i < h; ++i) {
    int t = 0;
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '*') ++t;
      else t = 0;
      l[i][j] = t;
    }
    t = 0;
    for (int j = w - 1; j >= 0; --j) {
      if (s[i][j] == '*') ++t;
      else t = 0;
      r[i][j] = t;
    }
  }
  VV<> u(h, V<>(w)), d(h, V<>(w));
  for (int j = 0; j < w; ++j) {
    int t = 0;
    for (int i = 0; i < h; ++i) {
      if (s[i][j] == '*') ++t;
      else t = 0;
      u[i][j] = t;
    }
    t = 0;
    for (int i = h - 1; i >= 0; --i) {
      if (s[i][j] == '*') ++t;
      else t = 0;
      d[i][j] = t;
    }
  }
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (s[i][j] == '*') {
    if (l[i][j] < 2) continue;
    if (r[i][j] < 2) continue;
    if (u[i][j] < 2) continue;
    if (d[i][j] < 2) continue;
    if (l[i][j] + r[i][j] + u[i][j] + d[i][j] == tt + 3) return cout << "YES" << '\n', 0;
  }
  cout << "NO" << '\n';
}