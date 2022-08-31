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
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int d = 0;
        if (i) {
          d++;
        }
        if (i + 1 < n) {
          d++;
        }
        if (j) {
          d++;
        }
        if (j + 1 < m) {
          d++;
        }
        if (a[i][j] > d) {
          valid = false;
        }
        a[i][j] = d;
      }
    }
    if (valid) {
      cout << "YES" << "\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (j) {
            cout << " ";
          }
          cout << a[i][j];
        }
        cout << "\n";
      }
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}