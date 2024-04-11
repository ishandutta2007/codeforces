#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }

    if ((n + m - 1) & 1) {
      cout << "NO\n";
      continue;
    }

    vector f_min(n, vector<int>(m, numeric_limits<int>::max()));
    vector f_max(n, vector<int>(m, numeric_limits<int>::min()));

    f_min[0][0] = a[0][0];
    f_max[0][0] = a[0][0];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i) {
          f_min[i][j] = min(f_min[i][j], f_min[i - 1][j] + a[i][j]);
          f_max[i][j] = max(f_max[i][j], f_max[i - 1][j] + a[i][j]);
        }
        if (j) {
          f_min[i][j] = min(f_min[i][j], f_min[i][j - 1] + a[i][j]);
          f_max[i][j] = max(f_max[i][j], f_max[i][j - 1] + a[i][j]);
        }
      }
    }

    if (f_min[n - 1][m - 1] <= 0 && 0 <= f_max[n - 1][m - 1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}