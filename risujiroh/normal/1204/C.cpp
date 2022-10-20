#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> d(n, V<>(n, 1e9));
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    char c; cin >> c;
    if (c == '1') d[i][j] = 1;
  }
  for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }

  int m; cin >> m;
  V<> a(m); for (auto&& e : a) cin >> e, --e;
  V<> res{a[0]};
  int p = 0;
  for (int i = 1; i < m - 1; ++i) {
    if (d[a[p]][a[i + 1]] < i + 1 - p) {
      res.push_back(a[i]);
      p = i;
    }
  }
  res.push_back(a.back());

  int k = res.size();
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i] + 1 << " \n"[i == k - 1];
  }
}