#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto&& e : s) {
    cin >> e;
  }
  vector< vector<int> > cum(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = m - 1; j >= 0; --j) {
      cum[i][j] = (s[i][j] == 'X') + cum[i][j + 1];
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = n - 1; i >= 0; --i) {
      cum[i][j] += cum[i + 1][j];
    }
  }
  auto chk = [&](int k) -> bool {
    vector< vector<int> > imos(n + 1, vector<int>(m + 1));
    for (int i = 0; i + k <= n; ++i) {
      for (int j = 0; j + k <= m; ++j) {
        int sum = cum[i][j] - cum[i][j + k] - cum[i + k][j] + cum[i + k][j + k];
        if (sum == k * k) {
          ++imos[i][j];
          --imos[i][j + k];
          --imos[i + k][j];
          ++imos[i + k][j + k];
        }
      }
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        imos[i][j + 1] += imos[i][j];
      }
    }
    for (int j = 0; j <= m; ++j) {
      for (int i = 0; i < n; ++i) {
        imos[i + 1][j] += imos[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'X' and imos[i][j] == 0) {
          return false;
        }
        if (s[i][j] == '.' and imos[i][j]) {
          return false;
        }
      }
    }
    return true;
  };
  int ok = 0, ng = (min(n, m) + 1) / 2;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(2 * mid + 1) ? ok : ng) = mid;
  }
  cout << ok << '\n';
  vector<string> res(n, string(m, '.'));
  int k = 2 * ok + 1;
  for (int i = 0; i + k <= n; ++i) {
    for (int j = 0; j + k <= m; ++j) {
      int sum = cum[i][j] - cum[i][j + k] - cum[i + k][j] + cum[i + k][j + k];
      if (sum == k * k) {
        res[i + ok][j + ok] = 'X';
      }
    }
  }
  for (const auto& e : res) {
    cout << e << '\n';
  }
}