#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 0 << "\n";
    return 0;
  }
  vector<vector<int>> ans(n, vector<int>(m));
  if (n == 1) {
    for (int i = 0; i < m; ++i) {
      ans[0][i] = i + 2;
    }
  } else if (m == 1) {
    for (int i = 0; i < n; ++i) {
      ans[i][0] = i + 2;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans[i][j] = (i + 1) * (j + n + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j) {
        cout << " ";
      }
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}