#include <bits/stdc++.h>
using namespace std;
#define M 200010
int a[M], n, dp[M];
vector <int> prv[M];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i), prv[a[i]].push_back(i);
    dp[i] = n + 1;
  }
  dp[1] = 0;
  int bf = 1;
  while (bf) {
    bf = 0;
    int pos = 1;
    for (int i = 2; i <= n; i++) {
      if (dp[i] > dp[pos] - pos + i) dp[i] = dp[pos] - pos + i, bf = 1;
      for (int j = 0; j < prv[i].size(); j++) {
        int u = prv[i][j];
        if (dp[i] > dp[u] + 1) dp[i] = dp[u] + 1, bf = 1;
      }
      if (dp[i] - i < dp[pos] - pos) pos = i;
    }
    pos = n;
    for (int i = n; i; i--) {
      if (dp[i] > dp[pos] + pos - i) dp[i] = dp[pos] + pos - i, bf = 1;
      if (dp[i] + i < dp[pos] + pos) pos = i;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", dp[i]);
}