#include <bits/stdc++.h>
using int64 = long long;
const int N = 1005;
const int Q = 998244353;

int f[N], n, d[N];

int getf(int x) {
  return f[x] == x ? x : f[x] = getf(f[x]);
}
void merge(int x, int y) {
  x = getf(x);
  y = getf(y);
  if (x != y) {
    f[x] = y;
  }
}
int cnt;
int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int y;
  ++cnt;
  scanf("%d", &y);
  return y;
}

void work() {
  cnt = 0;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> w;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    f[i] = i;
    w.emplace_back(-d[i], i);
  }
  std::sort(w.begin(), w.end());
  std::vector<bool> ok(n + 1);
  for (auto &[_, x] : w) {
    if (ok[x]) continue;
    for (int i = 0 ; i < d[x] ; ++ i) {
      int y = query(x);
      merge(x, y);
      if (ok[y]) {
        break;
      }
      ok[y] = true;
    }
    ok[x] = true;
  }
  printf("! ");
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", getf(i), " \n"[i == n]);
  }
  fflush(stdout);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}