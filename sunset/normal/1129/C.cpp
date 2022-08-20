#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

bool check(int a, int b, int c, int d) {
  int code = (a << 3) + (b << 2) + (c << 1) + (d << 0);
  return code != 3 && code != 5 && code != 14 && code != 15;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
    for (int j = i; j < n; ++j) {
      for (int k = 1; k <= 4; ++k) {
        if (j + k <= n && (k != 4 || check(a[j], a[j + 1], a[j + 2], a[j + 3]))) {
          add(dp[i][j + k], dp[i][j]);
        }
      }
    }
  }
  vector<vector<int>> lcs(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] == a[j]) {
        lcs[i][j] = (j ? lcs[i - 1][j - 1] : 0) + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int len = *max_element(lcs[i].begin(), lcs[i].end());
    for (int j = 0; i + 1 - j > len; ++j) {
      add(ans, dp[j][i + 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}