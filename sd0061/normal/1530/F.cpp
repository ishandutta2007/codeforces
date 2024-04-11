#include <bits/stdc++.h>
const int N = 21;
const int Q = 31607;

int inverse(int x) {
  return x == 1 ? 1 : (Q - Q / x) * inverse(Q % x) % Q;
}

const int inv = inverse(10000);

int n, a[N][N], b[N][N], c[N], r[N], ba[N][N], bb[N][N], ans;

// double fa[N][N], bfa[N][N], fc[N], fr[N], fans;

void dfs(int k, int p, int sign) {
  if (k == n) {
    int delta = p;
    // double fdelta = 1;
    for (int i = 0; i < n; ++i) {
      delta = delta * (Q + 1 - c[i]) % Q;
      // fdelta *= (1 - fc[i]);
    }
    ans += sign * delta + Q;
    ans %= Q;
    // fans += sign * fdelta;
  } else {
    dfs(k + 1, p, sign);
    for (int i = 0; i < n; ++i) {
      c[i] = c[i] * b[k][i] % Q;
      // fc[i] = fc[i] / fa[k][i];
    }
    dfs(k + 1, p * r[k] % Q, -sign);
    for (int i = 0; i < n; ++i) {
      c[i] = c[i] * a[k][i] % Q;
      // fc[i] = fc[i] * fa[k][i];
    }
  }
}

int cal(int master, int sub) {
  memcpy(ba, a, sizeof(ba));
  memcpy(bb, b, sizeof(bb));
  // memcpy(bfa, fa, sizeof(bfa));

  int qem = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((master && i == j) || (sub && i + j == n - 1)) {
        qem = qem * a[i][j] % Q;
        a[i][j] = b[i][j] = 1;
      }
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     printf("%d%c", a[i][j], " \n"[j + 1 == n]);
  //   }
  // }

  for (int i = 0; i < n; ++i) {
    c[i] = r[i] = 1;
    // fc[i] = fr[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      r[i] = r[i] * a[i][j] % Q;
      c[j] = c[j] * a[i][j] % Q;
      // fr[i] *= fa[i][j];
      // fc[j] *= fa[i][j];
    }
  }

  ans = 0;
  dfs(0, 1, 1);

  // printf("%d %d : %d %f\n", master, sub, ans, fans);

  memcpy(a, ba, sizeof(ba));
  memcpy(b, bb, sizeof(bb));
  // memcpy(fa, bfa, sizeof(bfa));
  return qem * ans % Q;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      a[i][j] *= inv;
      a[i][j] %= Q;
      b[i][j] = inverse(a[i][j]);
    }
  }
  // printf("%d\n", a[0][0]);
  int res = 0;
  for (int k = 0; k < 4; ++k) {
    if (k == 0 || k == 3) {
      res += cal(k % 2, k / 2);
    } else {
      res += Q - cal(k % 2, k / 2);
    }
  }
  // printf("%d\n", res % Q);
  printf("%d\n", (1 - res % Q + Q) % Q);

  return 0;
}