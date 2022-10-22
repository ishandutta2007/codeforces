#include <bits/stdc++.h>
using int64 = long long;

const int N = 1000005;

bool ff[N];
int prime[N], tot, fac[N];
std::vector<int> factors[N];
void init(int n) {
  int i, j, x;
  for (i = 2; i <= n; ++i) {
    if (!ff[i]) {
      prime[tot++] = i;
      fac[i] = i;
    }
    for (j = 0; j < tot; ++j) {
      x = i * prime[j];
      if (x > n)
        break;
      ff[x] = 1;
      fac[x] = prime[j];
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int x = i;
    int last = -1;
    while (x > 1) {
      int y = fac[x];
      if (y != last) {
        factors[i].emplace_back(y);
        last = y;
      }
      x /= y;
    }
  }
}
int n, m, a[N], res[N];
int f[N + N];
int getf(int x) {
  return f[x] == x ? x : f[x] = getf(f[x]);
}

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n + N; ++i) {
    f[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (auto &x : factors[a[i]]) {
      f[getf(n + x)] = getf(i);
    }
  }
  std::unordered_set<long long> wtf;
  for (int i = 1; i <= n; ++i) {
    int y = a[i] + 1;
    std::set<int> u;
    for (auto &x : factors[y]) {
      // printf("%d : %d\n", y, x);
      u.insert(getf(n + x));
    }

    y = a[i];
    for (auto &x : factors[y]) {
      // printf("%d : %d\n", y, x);
      u.insert(getf(n + x));
    }
    for (auto &x : u) {
      for (auto &y : u) {
        // printf("%d %d\n", x, y);
        wtf.insert(1LL * x * (N + n + 1) + y);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = getf(x);
    y = getf(y);
    if (x == y) {
      puts("0");
    } else {
      // printf("? %d %d\n", x, y);
      long long w = 1LL * x * (N + n + 1) + y;
      puts(wtf.count(w) ? "1" : "2");
    }
  }
}

int main() {
  int T = 1;
  while (T--) {
    init(N - 1);
    work();
  }
  return 0;
}