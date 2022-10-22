#include <bits/stdc++.h>
using int64 = long long;
const int N = 2025;
int n, a[N];

std::vector<int> res;
void reverse(int x, int& pa, int& pb) {
  res.emplace_back(x);
  assert(x % 2 == 1);
  std::reverse(a + 1, a + x + 1);
  if (pa <= x) {
    pa = x + 1 - pa;
  }
  if (pb <= x) {
    pb = x + 1 - pb;
  }
}

void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if ((a[i] & 1) != (i & 1)) {
      puts("-1");
      return;
    }
  }
  int m = n;
  res.clear();
  while (n > 1) {
    int pa = 0, pb = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == n) {
        pa = i;
      }
      if (a[i] == n - 1) {
        pb = i;
      }
    }
    if (pa != 1) {
      reverse(pa, pa, pb);
    }
    if (pb != 2) {
      reverse(pb - 1, pa, pb);
    }
    reverse(n, pa, pb);
    reverse(pa, pa, pb);
    reverse(n, pa, pb);
    n -= 2;
  }
  for (int i = 1; i <= m; ++i) {
    assert(a[i] == i);
  }
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d%c", res[i], " \n"[i + 1 == res.size()]);
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