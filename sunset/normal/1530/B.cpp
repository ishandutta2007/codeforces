#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    auto check = [&](int i, int j) { 
      for (int ii = i - 1; ii <= i + 1; ++ii) {
        for (int jj = j - 1; jj <= j + 1; ++jj) {
          if (ii >= 0 && ii < n && jj >= 0 && jj < m && a[ii][jj]) {
            return;
          }
        }
      }
      a[i][j] = 1;
    };
    for (int i = 0; i < m - 1; ++i) {
      check(0, i);
    }
    for (int i = 0; i < n - 1; ++i) {
      check(i, m - 1);
    }
    for (int i = m - 1; i; --i) {
      check(n - 1, i);
    }
    for (int i = n - 1; i; --i) {
      check(i, 0);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}