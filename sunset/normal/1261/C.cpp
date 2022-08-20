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
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }
  vector<vector<int>> s(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + (board[i][j] == 'X');
    }
  }
  auto check = [&](int tt) {
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    int r = tt * 2 + 1;
    for (int i = 0; i <= n - r; ++i) {
      for (int j = 0; j <= m - r; ++j) {
        if (s[i + r][j + r] - s[i + r][j] - s[i][j + r] + s[i][j] == r * r) {
          t[i][j]++;
          t[i + r][j]--;
          t[i][j + r]--;
          t[i + r][j + r]++;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i) {
          t[i][j] += t[i - 1][j];
        }
        if (j) {
          t[i][j] += t[i][j - 1];
        }
        if (i && j) {
          t[i][j] -= t[i - 1][j - 1];
        }
        if (board[i][j] == 'X' && !t[i][j]) {
          return false;
        }
      }
    }
    return true;
  };
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
  vector<string> ans(n, string(m, '.'));
  r = l * 2 + 1;
  for (int i = 0; i <= n - r; ++i) {
    for (int j = 0; j <= m - r; ++j) {
      if (s[i + r][j + r] - s[i + r][j] - s[i][j + r] + s[i][j] == r * r) {
        ans[i + l][j + l] = 'X';
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}