#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = *max_element(a.begin(), a.end());
  vector<int> c(m + 1);
  for (auto x : a) {
    ++c[x];
  }
  int diff = 0;
  int cnt = 0;
  int sum = 0;
  vector<vector<int>> dp(n + 1, vector<int> (n * m + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    if (c[i]) {
      for (int j = cnt; ~j; --j) {
        for (int k = 0; k <= sum; ++k) {
          if (dp[j][k]) {
            for (int l = 1; l <= c[i]; ++l) {
              dp[j + l][k + l * i] = min(2, dp[j + l][k + l * i] + dp[j][k]);
            }
          }
        }
      }
      diff += 1;
      cnt += c[i];
      sum += c[i] * i;
    }
  }
  if (diff <= 2) {
    printf("%d\n", n);
    return 0;
  }
  int answer = 0;
  for (int i = 1; i <= m; ++i) {
    while (answer < c[i] && dp[answer + 1][(answer + 1) * i] == 1) {
      ++answer;
    }
  }
  printf("%d\n", answer);
  return 0;
}