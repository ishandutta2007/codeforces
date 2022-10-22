#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int n, m, d[505][505];

void work() {
  scanf("%d%d", &n, &m);
  std::vector<std::vector<int>> e(n + 1);
  std::vector<std::tuple<int, int, int>> E;
  memset(d, 0x3f, sizeof(d));
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    e[x].emplace_back(y);
    e[y].emplace_back(x);
    if (x > y) {
      std::swap(x, y);
    }
    E.emplace_back(x, y, z);
  }
  memset(d, -1, sizeof(d));
  d[1][n] = 1;
  std::queue<std::pair<int, int>> q;
  q.push({1, n});
  auto update = [&](int x, int y, int w) {
    if (x > y) {
      std::swap(x, y);
    }
    if (!~d[x][y]) {
      d[x][y] = w + 1;
      q.push({x, y});
    }
  };
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == y) {
      for (int z = 1; z <= n; ++z) {
        update(x, z, d[x][y]);
      }
    } else {
      for (auto &z : e[x]) {
        update(z, y, d[x][y]);
      }
      for (auto &z : e[y]) {
        update(x, z, d[x][y]);
      }
    }
  }
  // int x , y;
  // while (scanf("%d%d" , &x, &y)) {
  //   printf("%d\n", d[x][y]);
  // }
  int64 res = 1LL << 60;
  for (auto [x, y, z] : E) {
    if (d[x][y] != -1) {
      // printf("%d %d : %d %lld\n", x , y, d[x][y], 1LL * d[x][y] * z);
      res = std::min(res, 1LL * d[x][y] * z);
    }
  }
  printf("%lld\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}