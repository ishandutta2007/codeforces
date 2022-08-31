#include <bits/stdc++.h>

using namespace std;

const int N = 400;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt, md;
  scanf("%d %d", &tt, &md);
  auto add = [&](int &x, int y) {
    x += y;
    if (x >= md) {
      x -= md;
    }
  };
  auto sub = [&](int &x, int y) {
    x -= y;
    if (x < 0) {
      x += md;
    }
  };
  auto mul = [&](int x, int y) {
    return (long long)x * y % md;
  };
  vector<int> fact(N + 1);
  fact[0] = 1;
  for (int i = 0; i < N; ++i) {
    fact[i + 1] = mul(fact[i], i + 1);
  }
  vector<int> ways(N + 1);
  for (int i = 1; i <= N; ++i) {
    ways[i] = fact[i];
    for (int j = 1; j < i; ++j) {
      sub(ways[i], mul(ways[j], fact[i - j]));
    }
  }
  vector<vector<int>> dp(N + 1, vector<int> (N + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k <= i; ++k) {
        add(dp[i][j], mul(dp[i - k][j - 1], fact[k]));
      }
    }
  }
  vector<int> f(N + 1);
  for (int i = 1; i <= N; ++i) {
    f[i] = fact[i];
    for (int j = 1; j < i; ++j) {
      sub(f[i], mul(2, mul(ways[j], fact[i - j])));
    }
    for (int j = 3; j < i; ++j) {
      sub(f[i], mul(dp[i][j], f[j]));
    }
  }
  f[2] = 2;
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", f[n]);
  }
  return 0;
}