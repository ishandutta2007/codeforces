#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n, m; cin >> n >> m;
    V<string> s(n); for (auto&& e : s) cin >> e;
    V<> row(n), col(m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      row[i] += s[i][j] == '*';
      col[j] += s[i][j] == '*';
    }
    int res = 1e9;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') {
        res = min(res, n - row[i] + m - col[j]);
      } else {
        res = min(res, n - row[i] + m - col[j] - 1);
      }
    }
    cout << res << '\n';
  }
}