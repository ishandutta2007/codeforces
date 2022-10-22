#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

std::set<int> res;
std::pair<int, int> go(int a, int b, int x, int y) {
  int n = a + b;
  int mx = std::min(a, x) + std::min(b, y);
  int mn = n - std::min(a, y) - std::min(b, x);
  for (int i = mn; i <= mx; i += 2) {
    res.insert(i);
  }
  return {mn, mx};
}

void work() {
  int a, b;
  scanf("%d%d", &a, &b);
  int n = a + b;
  int p = n / 2, q = n - p;
  res.clear();
  go(a, b, p, q);
  go(a, b, q, p);
  printf("%d\n", res.size());
  for (auto &x : res) {
    printf("%d ", x);
  }
  puts("");
  // printf("%d %d : %d %d\n",  , )
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}