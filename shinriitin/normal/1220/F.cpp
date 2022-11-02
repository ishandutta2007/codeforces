#include <bits/stdc++.h>

template <typename T> inline void read(T *x) {
  int c;
  while (!isdigit(c = getchar())) {
  }
  *x = c - '0';
  while (isdigit(c = getchar())) {
    (*x *= 10) += c - '0';
  }
}

const int max_N = (int)2e5 + 21;

int n, Q[max_N], rk[max_N];

int ans1, ans2, dep[2][max_N];

int dp[max_N], st[max_N], top;

void solve(int *dep) {
  memset(dp, 0, sizeof dp);
  top = 0;
  for (int i = 1; i <= n; ++i) {
    dp[Q[i]] = 0;
    while (top && st[top] > Q[i]) {
      dp[Q[i]] = std::max(dp[Q[i]], dp[st[top--]] + 1);
    }
    st[++top] = Q[i];
    dp[Q[i]] = std::max(top, dp[Q[i]]);
    dep[i] = std::max(dep[i - 1], dp[Q[i]]);
  }
}

int main() {
  read(&n);
  for (int i = 1; i <= n; ++i) {
    read(&Q[i]);
    rk[Q[i]] = i;
  }
  std::rotate(Q + 1, std::find(Q + 1, Q + 1 + n, 1), Q + 1 + n);
  solve(dep[0]);
  std::reverse(Q + 1, Q + 1 + n);
  std::rotate(Q + 1, Q + n, Q + 1 + n);
  solve(dep[1]);
  ans1 = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    int depth = std::max(dep[0][i], dep[1][n - i + 1]);
    int head = Q[n - i + 1];
    if (depth < ans1) {
      ans1 = depth;
      ans2 = rk[head] - 1;
    }
  }
  printf("%d %d\n", ans1, ans2);
}
/*
10
1 9 10 5 8 7 4 2 6 3
 */