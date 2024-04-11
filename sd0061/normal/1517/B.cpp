#include "bits/stdc++.h"

const int N = 105;
using int64 = long long;

int n, m, a[N][N], res[N][N];

void work() {
  scanf("%d%d", &n, &m);
  std::set<std::tuple<int, int, int>> v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
      v.insert({a[i][j], i, j});
    }
  }
  memcpy(res, a, sizeof(res));
  for (int i = 0; i < m; ++i) {
    auto [w, x, y] = *v.begin();
    v.erase(v.begin());
    if (i != y) {
      v.erase({res[x][i], x, i});
      std::swap(res[x][i], res[x][y]);
      v.insert({res[x][y], x, y});
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d%c", res[i][j], " \n"[j + 1 == m]);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
}