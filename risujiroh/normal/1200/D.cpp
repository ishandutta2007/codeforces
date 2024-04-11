#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<string> s(n); for (auto&& e : s) cin >> e;
  
  V<> cr(n + 1), cc(n + 1);
  for (int i = 0; i < n; ++i) {
    cr[i] = 1;
    for (int j = 0; j < n; ++j) if (s[i][j] == 'B') {
      cr[i] = 0;
      break;
    }
  }
  for (int j = 0; j < n; ++j) {
    cc[j] = 1;
    for (int i = 0; i < n; ++i) if (s[i][j] == 'B') {
      cc[j] = 0;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    cr[i] += cr[i + 1];
    cc[i] += cc[i + 1];
  }

  VV<> nr(n, V<>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      nr[i][j] = s[i][j] == 'B';
    }
    for (int j = n - 1; j >= 0; --j) {
      nr[i][j] += nr[i][j + 1];
    }
  }
  VV<> nc(n, V<>(n + 1));
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      nc[j][i] = s[i][j] == 'B';
    }
    for (int i = n - 1; i >= 0; --i) {
      nc[j][i] += nc[j][i + 1];
    }
  }

  VV<> col(n - k + 1, V<>(n - k + 1));
  for (int i = 0; i + k <= n; ++i) {
    V<> c(n + 1);
    for (int j = 0; j < n; ++j) {
      c[j] = !(nc[j][0] - nc[j][i] + nc[j][i + k] - nc[j][n]);
    }
    for (int j = n - 1; j >= 0; --j) {
      c[j] += c[j + 1];
    }
    for (int j = 0; j + k <= n; ++j) {
      col[i][j] = cc[0] - cc[j] + cc[j + k] - cc[n];
      col[i][j] += c[j] - c[j + k];
    }
  }

  VV<> row(n - k + 1, V<>(n - k + 1));
  for (int j = 0; j + k <= n; ++j) {
    V<> c(n + 1);
    for (int i = 0; i < n; ++i) {
      c[i] = !(nr[i][0] - nr[i][j] + nr[i][j + k] - nr[i][n]);
    }
    for (int i = n - 1; i >= 0; --i) {
      c[i] += c[i + 1];
    }
    for (int i = 0; i + k <= n; ++i) {
      row[i][j] = cr[0] - cr[i] + cr[i + k] - cr[n];
      row[i][j] += c[i] - c[i + k];
    }
  }

  int res = 0;
  for (int i = 0; i + k <= n; ++i) for (int j = 0; j + k <= n; ++j) {
    res = max(res, row[i][j] + col[i][j]);
  }
  cout << res << '\n';
}