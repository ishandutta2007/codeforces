#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string a, b;
  cin >> n >> a >> b;
  vector<int> dp(n + 1);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + (a[i - 1] != b[i - 1]);
    if (i >= 2 && a[i - 2] == b[i - 1] && a[i - 1] == b[i - 2]) {
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}