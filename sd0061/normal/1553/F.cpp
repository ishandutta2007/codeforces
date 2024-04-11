#include <bits/stdc++.h>
using int64 = long long;

const int N = 300005;

int n, a[N];

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
  std::pair<int, T> kth(T k) {
    int x = -1;
    for (int i = 20; i >= 0; --i) {
      int y = x + (1 << i);
      if (y < n && a[y] < k) {
        k -= a[y];
        x = y;
      }
    }
    return {x + 1, k};
  }
};

int64 res[N];

void work() {
  scanf("%d", &n);
  int64 sum = 0;
  FenwickTree<int64> c(N), d(N);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    res[i] = 1LL * i * a[i] + c.query(a[i]) + sum;
    for (int j = a[i]; j < N; j += a[i]) {
      res[i] -=
          1LL * a[i] * (j / a[i]) * (d.query(j + a[i] - 1) - d.query(j - 1));
      c.add(j, -a[i]);
    }
    d.add(a[i], 1);
    sum += a[i];
  }
  for (int i = 1; i < n; ++i) {
    res[i] += res[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", res[i], " \n"[i + 1 == n]);
  }
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}