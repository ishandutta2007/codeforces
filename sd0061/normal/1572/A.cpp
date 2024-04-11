#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int n, deg[N], f[N];
std::vector<int> e[N];
void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    e[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &deg[i]);
    for (int j = 0; j < deg[i]; ++j) {
      int x;
      scanf("%d", &x);
      --x;
      e[x].emplace_back(i);
      // printf("%d %d\n", deg[i], x);
    }
  }
  std::queue<int> q;
  std::fill(f, f + n, 0);
  for (int i = 0; i < n; ++i) {
    if (!deg[i]) {
      q.push(i);
      f[i] = 1;
    }
  }
  int num = 0, res = 0;
  while (!q.empty()) {
    int x = q.front();
    // printf("%d\n", x);
    q.pop();
    ++num;
    res = std::max(res, f[x]);
    for (auto &y : e[x]) {
      // printf("-> %d\n", y);
      if (x < y) {
        f[y] = std::max(f[y], f[x]);
      } else {
        f[y] = std::max(f[y], f[x] + 1);
      }
      if (!--deg[y]) {
        q.push(y);
      }
    }
  }
  // std::cout << num << ' ';
  if (num != n) {
    puts("-1");
  } else {
    printf("%d\n", res);
  }
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}