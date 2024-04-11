#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }
  vector<vector<int>> dp(n, vector<int> (n, n << 1));
  dp[0][0] = board[0][0] != 'a';
  int sum = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i || j) {
        dp[i][j] = (board[i][j] != 'a') + min(!i ? n << 1 : dp[i - 1][j], !j ? n << 1 : dp[i][j - 1]);
      }
      if (dp[i][j] <= m) {
        sum = max(sum, i + j);
      }
    }
  }
  for (int i = 0; i <= sum; ++i) {
    cout << 'a';
  }
  vector<pair<int, int>> available;
  if (!~sum) {
    cout << board[0][0];
    m = 1;
    sum = 0;
  }
  for (int i = 0; i < n; ++i) {
    int j = sum - i;
    if (j >= 0 && j < n && dp[i][j] <= m) {
      available.emplace_back(i, j);
    }
  }
  vector<vector<bool>> visit(n, vector<bool> (n));
  for (int i = sum + 1; i < (n << 1) - 1; ++i) {
    char minc = 'z';
    for (auto p : available) {
      if (p.first + 1 < n) {
        minc = min(minc, board[p.first + 1][p.second]);
      }
      if (p.second + 1 < n) {
        minc = min(minc, board[p.first][p.second + 1]);
      }
    }
    cout << minc;
    vector<pair<int, int>> next;
    for (auto p : available) {
      if (p.first + 1 < n && board[p.first + 1][p.second] == minc && !visit[p.first + 1][p.second]) {
        visit[p.first + 1][p.second] = true;
        next.emplace_back(p.first + 1, p.second);
      }
      if (p.second + 1 < n && board[p.first][p.second + 1] == minc && !visit[p.first][p.second + 1]) {
        visit[p.first][p.second + 1] = true;
        next.emplace_back(p.first, p.second + 1);
      }
    }
    available = next;
  }
  cout << endl;
  return 0;
}