#include <bits/stdc++.h>
using int64 = long long;

const int N = 500005;
const int Q = 998244353;

int n, X[N], Y[N], p[N];
int64 f[N], s[N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", X + i, Y + i, p + i);
  }
  int64 res = X[n - 1] + 1;

  for (int i = 0; i < n; ++i) {
    int x = X[i];
    int y = Y[i];
    int yid = std::lower_bound(X, X + n, y) - X;

    f[i] = X[i] - Y[i];
    f[i] += (s[i] - s[yid] + Q) % Q;
    f[i] %= Q;
    if (p[i]) {
      res += f[i];
    }
    s[i + 1] = (s[i] + f[i]) % Q;
  }
  printf("%lld\n", res % Q);
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}