#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a(n, V<>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
  VV<> b(n, V<>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
  VV<> c(n, V<>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    c[i][j] = a[i][j] ^ b[i][j];
  }
  V<> row(n), col(m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    row[i] += c[i][j];
    col[j] += c[i][j];
  }
  for (int i = 0; i < n; ++i) if (row[i] & 1) {
    return cout << "No" << '\n', 0;
  }
  for (int j = 0; j < m; ++j) if (col[j] & 1) {
    return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
}