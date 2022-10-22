#include <bits/stdc++.h>
using int64 = long long;

const int N = 205;

int n, K, X[N], Y[N];
bool f[N];

void work() {
  scanf("%d%d", &n, &K);

  memset(f, 0, sizeof(f));
  for (int i = 0; i < K; ++i) {
    scanf("%d%d", X + i, Y + i);
    --X[i];
    --Y[i];
    f[X[i]] = f[Y[i]] = 1;
  }
  std::vector<int> w;
  for (int i = 0; i < n + n; ++i) {
    if (!f[i]) {
      w.emplace_back(i);
    }
  }
  int p = n - K;
  for (int i = 0; i < p; ++i) {
    X[K] = w[i];
    Y[K] = w[i + p];
    // printf("%d %d\n", X[K], Y[K]);
    ++K;
  }

  int res = 0;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < i; ++j) {
      int L = std::min(X[i], Y[i]);
      int R = std::max(X[i], Y[i]);
      int a = (L < X[j] && X[j] < R);
      int b = (L < Y[j] && Y[j] < R);
      res += (a ^ b);
    }
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}