#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;
int n, m, q;
int d[N], cnt;

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) {
      std::swap(x, y);
    }
    ++d[x];
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 0) {
      ++cnt;
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int o;
    scanf("%d", &o);
    if (o == 3) {
      printf("%d\n", cnt);
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x > y) {
        std::swap(x, y);
      }
      if (d[x] == 0) {
        --cnt;
      }
      d[x] += o == 1 ? 1 : -1;
      if (d[x] == 0) {
        ++cnt;
      }
    }
  }
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}