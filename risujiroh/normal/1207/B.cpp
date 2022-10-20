#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a(n, V<>(m));
  for (auto&& v : a) for (auto&& e : v) cin >> e;
  VV<> b(n, V<>(m));
  V< pair<int, int > > res;
  for (int i = 0; i < n - 1; ++i) for (int j = 0; j < m - 1; ++j) if (a[i][j]) {
    if (!a[i][j + 1]) continue;
    if (!a[i + 1][j]) continue;
    if (!a[i + 1][j + 1]) continue;
    res.emplace_back(i, j);
    b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
  }
  if (a != b) {
    return cout << -1 << '\n', 0;
  }
  cout << res.size() << '\n';
  for (auto e : res) {
    cout << e.first + 1 << ' ' << e.second + 1 << '\n';
  }
}