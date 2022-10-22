#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

template <typename T>
class FenwickTree {
 public:
  int n;
  std::vector<T> a;
  FenwickTree(int n) : n(n) {
    a.resize(n);
  }
  void add(int x, T w) {
    while (x < n) {
      a[x] += w;
      x |= (x + 1);
    }
  }
  T query(int x) {
    T res{};
    x = std::min(x, n - 1);
    while (x >= 0) {
      res += a[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};

int n, a[N], p[N], c[N];
void work() {
  scanf("%d", &n);
  int cnt[2] = {};
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i] & 1]++;
  }
  if (std::abs(cnt[0] - cnt[1]) > 1) {
    puts("-1");
    return;
  }
  int64 res = 1LL << 60;
  for (int k = 0; k < 2; ++k) {
    if (cnt[k] != (n + 1) / 2) {
      continue;
    }
    if (cnt[!k] != n / 2) {
      continue;
    }
    int x0 = 0, x1 = 1;

    FenwickTree<int> c(n);
    int64 sum = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == k) {
        p[i] = x0;
        x0 += 2;
      } else {
        p[i] = x1;
        x1 += 2;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      sum += c.query(p[i] - 1);
      c.add(p[i], 1);
    }
    res = std::min(res, sum);
  }
  printf("%lld\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}