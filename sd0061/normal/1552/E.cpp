#include <bits/stdc++.h>
using int64 = long long;

const int N = 105;

int n, K, a[N * N];
std::vector<int> p[N];
int cnt[N * N], res[N][2], nxt[N * N];
bool f[N];
void work() {
  scanf("%d%d", &n, &K);
  for (int i = 0; i < n * K; ++i) {
    int x;
    scanf("%d", &x);
    // x = i % n + 1;
    a[i] = x;
    p[x].emplace_back(i);
  }
  // std::random_shuffle(a, a + n * K);
  memset(nxt, -1, sizeof(nxt));
  std::vector<std::tuple<int, int, int>> v;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j + 1 < p[i].size(); ++j) {
      nxt[p[i][j]] = p[i][j + 1];
      v.emplace_back(p[i][j + 1], p[i][j], i);
    }
  }
  std::sort(v.begin(), v.end());
  int T = (n + K - 2) / (K - 1);
  for (auto [R, L, x] : v) {
    if (!f[x]) {
      bool ok = true;
      for (int j = L; j <= R; ++j) {
        if (cnt[j] == T) {
          ok = false;
          break;
        }
      }
      if (ok) {
        f[x] = 1;
        res[x][0] = L + 1;
        res[x][1] = R + 1;
        for (int j = L; j <= R; ++j) {
          ++cnt[j];
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    assert(res[i][0] > 0);
    printf("%d %d\n", res[i][0], res[i][1]);
  }
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}