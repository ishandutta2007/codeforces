#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int n, K;

int query(int x, int y) {
  printf("and %d %d\n", x, y);
  fflush(stdout);
  int a;
  scanf("%d", &a);
  printf("or %d %d\n", x, y);
  fflush(stdout);
  int b;
  scanf("%d", &b);
  return a + b;
}

std::pair<int, int> a[N];

void work() {
  scanf("%d%d", &n, &K);
  int a12 = query(1, 2);
  int a23 = query(2, 3);
  int a13 = query(1, 3);
  for (int i = 1; i <= n; ++i) {
    a[i].second = i;
  }
  int64 a123 = (0LL + a12 + a13 + a23) / 2;
  a[1].first = a123 - a23;
  a[2].first = a123 - a13;
  a[3].first = a123 - a12;
  for (int i = 4; i <= n; ++i) {
    int p = query(1, i);
    a[i].first = p - a[1].first;
  }
  sort(a + 1, a + n + 1);
  printf("finish %d\n", a[K].first);
  fflush(stdout);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}