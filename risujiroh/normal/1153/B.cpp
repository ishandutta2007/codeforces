#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, h; cin >> n >> m >> h;
  V<> a(m); for (auto&& e : a) cin >> e;
  V<> b(n); for (auto&& e : b) cin >> e;
  VV<> c(n, V<>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> c[i][j];
  VV<> res(n, V<>(m));
  for (int j = 0; j < m; ++j) if (a[j]) {
    V<> is;
    for (int i = 0; i < n; ++i) if (c[i][j]) is.push_back(i);
    int mx = -1, mi = -1;
    for (int i : is) {
      if (b[i] > mx) {
        mx = b[i];
        mi = i;
      }
    }
    res[mi][j] = a[j];
  }
  for (int i = 0; i < n; ++i) if (b[i]) {
    V<> js;
    for (int j = 0; j < m; ++j) if (c[i][j]) js.push_back(j);
    int mx = -1, mj = -1;
    for (int j : js) {
      if (a[j] > mx) {
        mx = a[j];
        mj = j;
      }
    }
    res[i][mj] = b[i];
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    res[i][j] = max(res[i][j], c[i][j]);
    cout << res[i][j] << " \n"[j == m - 1];
  }
}