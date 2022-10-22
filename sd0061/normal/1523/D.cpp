#include <bits/stdc++.h>

using int64 = long long;
const int N = 200005;

int n, m, p;
int64 a[N];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i < n; ++i) {
    static char s[100];
    scanf("%s", s);
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') {
        a[i] |= 1LL << j;
      }
    }
  }
  std::random_shuffle(a, a + n);
  std::pair<int, int64> res = {0, 0};
  for (int t = 0; t < 30; ++t) {
    int v = rand() % n;
    std::vector<int> h(1 << p);
    for (int i = 0; i < n; ++i) {
      int64 x = a[i] & a[v], y = 0;
      for (int j = 0, k = 0; j < m; ++j) {
        if (a[v] >> j & 1) {
          if (x >> j & 1) {
            y |= 1 << k;
          }
          ++k;
        }
      }
      h[y]++;
    }
    for (int j = 0; j < p; ++j) {
      for (int i = 0; i < 1 << p; ++i) {
        if (i >> j & 1) {
          h[i ^ (1 << j)] += h[i];
        }
      }
    }
    for (int i = 0; i < 1 << p; ++i) {
      if (h[i] >= (n + 1) / 2) {
        int cnt = 0;
        int64 mask = 0;
        for (int j = 0, k = 0; j < m; ++j) {
          if (a[v] >> j & 1) {
            if (i >> k & 1) {
              ++cnt;
              mask |= 1LL << j;
            }
            ++k;
          }
        }
        res = std::max(res, {cnt, mask});
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    printf("%d", res.second >> j & 1);
  }
  puts("");
}