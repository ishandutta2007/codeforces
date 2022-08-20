#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> row_less(n, vector<int>(m));
  vector<vector<int>> row_more(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    vector<int> b = a[i];
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int j = 0; j < m; ++j) {
      row_less[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
      row_more[i][j] = b.size() - 1 - row_less[i][j];
    }
  }
  vector<vector<int>> col_less(n, vector<int>(m));
  vector<vector<int>> col_more(n, vector<int>(m));
  for (int i = 0; i < m; ++i) {
    vector<int> b(n);
    for (int j = 0; j < n; ++j) {
      b[j] = a[j][i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int j = 0; j < n; ++j) {
      col_less[j][i] = lower_bound(b.begin(), b.end(), a[j][i]) - b.begin();
      col_more[j][i] = b.size() - 1 - col_less[j][i];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j) {
        cout << " ";
      }
      cout << 1 + max(row_less[i][j], col_less[i][j]) + max(row_more[i][j], col_more[i][j]);
    }
    cout << "\n";
  }
  return 0;
}