#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a(n, V<>(m));
  VV<> r(n, V<>(m));
  VV<> c(m, V<>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    cin >> a[i][j];
    r[i][j] = c[j][i] = a[i][j];
  }
  for (int i = 0; i < n; ++i) {
    sort(begin(r[i]), end(r[i]));
    r[i].erase(unique(begin(r[i]), end(r[i])), end(r[i]));
  }
  for (int j = 0; j < m; ++j) {
    sort(begin(c[j]), end(c[j]));
    c[j].erase(unique(begin(c[j]), end(c[j])), end(c[j]));
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    int x = lower_bound(begin(r[i]), end(r[i]), a[i][j]) - begin(r[i]);
    int y = lower_bound(begin(c[j]), end(c[j]), a[i][j]) - begin(c[j]);
    int res = max(x, y) + max((int) r[i].size() - x, (int) c[j].size() - y);
    cout << res << " \n"[j == m - 1];
  }
}