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
  vector<bool> a(1 << n);
  while (m--) {
    int x;
    cin >> x;
    a[--x] = true;
  }
  vector<vector<int>> dp(1 << (n + 1), vector<int>(4, -1));
  auto merge = [&](int x, int l, int r) {
    for (int i = 0; i < 4; ++i) {
      if (dp[l][i] == -1) {
        continue;
      }
      for (int j = 0; j < 4; ++j) {
        if (dp[r][j] == -1) {
          continue;
        }
        int w1 = i / 2, w2 = j / 2;
        int l1 = i % 2, l2 = j % 2;
        dp[x][w1 * 2 + max(w2, max(l1, l2))] = max(dp[x][w1 * 2 + max(w2, max(l1, l2))], dp[l][i] + dp[r][j] + max(w1, w2) + max(l1, l2) + max(w2, max(l1, l2)));
        swap(w1, w2);
        dp[x][w1 * 2 + max(w2, max(l1, l2))] = max(dp[x][w1 * 2 + max(w2, max(l1, l2))], dp[l][i] + dp[r][j] + max(w1, w2) + max(l1, l2) + max(w2, max(l1, l2)));
      }
    }
  };
  function<void(int, int, int)> solve = [&](int x, int l, int r) {
    if (r - l == 2) {
      if (!a[l] && !a[l + 1]) {
        dp[x][0] = 0;
      } else if (a[l] && a[l + 1]) {
        dp[x][3] = 1;
      } else {
        dp[x][1] = dp[x][2] = 1;
      }
    } else {
      int y = (l + r) >> 1, z = x + ((y - l) << 1);
      solve(x + 1, l, y);
      solve(z, y, r);
      merge(x, x + 1, z);
    }
  };
  solve(0, 0, 1 << n);
  cout << max(dp[0][0], max(dp[0][1] + 1, max(dp[0][2] + 1, dp[0][3] + 1))) << "\n";
  return 0;
}