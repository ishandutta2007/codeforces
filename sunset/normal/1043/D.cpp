#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(m, vector<int> (n)), p(m, vector<int> (n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
      p[i][a[i][j]] = j;
    }
  }
  vector<vector<int>> dp(n, vector<int> (m));
  for (int i = n - 1; ~i; --i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = (i + 1 < n && p[j][a[0][i]] == p[j][a[0][i + 1]] - 1 ? dp[i + 1][j] : 0) + 1;
    }
  }
  long long answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += *min_element(dp[i].begin(), dp[i].end());
  }
  printf("%lld\n", answer);
  return 0;
}