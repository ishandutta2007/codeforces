#include <bits/stdc++.h>

const int N = 1005;
const int K = 4;
using int64 = long long;

int n, m, a[N][N], delta[N];
int64 sum[N];
int64 s2[N];

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      sum[i] += a[i][j];
      s2[i] += 1LL * a[i][j] * a[i][j];
    }
  }
  std::map<int, int> delta_cnt;
  for (int i = 1; i < m; ++i) {
    delta[i - 1] = sum[i] - sum[i - 1];
    delta_cnt[delta[i - 1]]++;
  }
  std::pair<int, int> max_occured = {-1, -1};
  for (auto it : delta_cnt) {
    max_occured = std::max(max_occured, std::make_pair(it.second, it.first));
  }
  int modified_row = -1;
  int liner_delta = 0;
  for (int i = 0; i + 1 < m; ++i) {
    if (delta[i] != max_occured.second) {
      modified_row = i + 1;
      liner_delta = delta[i] - max_occured.second;
      break;
    }
  }
  assert(modified_row != -1);

  std::vector<int> rows;
  for (int i = 0; i < m && rows.size() < 3; ++i) {
    if (i != modified_row) {
      rows.emplace_back(i);
    }
  }
  int x = rows[0];
  int y = rows[1];
  int z = rows[2];
  int aims = modified_row;

  int64 g = 1;
  int64 lx = g * (aims - y) * (aims - z) * s2[x];
  int dx = (x - y) * (x - z);
  int64 ly = g * (aims - x) * (aims - z) * s2[y];
  int dy = (y - x) * (y - z);
  int64 lz = g * (aims - x) * (aims - y) * s2[z];
  int dz = (z - x) * (z - y);

  int64 aimed_s2 = (lx / dx + ly / dy + lz / dz) / g;
  int64 square_delta = s2[aims] - aimed_s2;
  int64 res =
      (square_delta - 1LL * liner_delta * liner_delta) / 2 / liner_delta;

  printf("%d %lld\n", modified_row, res);

  fflush(stdout);
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}