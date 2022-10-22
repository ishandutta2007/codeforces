#include <bits/stdc++.h>
using int64 = long long;
const int N = 1000005;
const int Q = 1e9 + 7;
const int inv = (Q + 1) / 2;

int p[N], I[N];

int f[N];

template <typename T> class FenwickTree {
 public:
  int n;
  std::vector<T> a;
  FenwickTree(int n) : n(n) {
    a.resize(n);
  }
  void add(int x, T w) {
    while (x < n) {
      a[x] += w;
      a[x] %= Q;
      x |= (x + 1);
    }
  }
  T query(int x) {
    T res{};
    x = std::min(x, n - 1);
    while (x >= 0) {
      res += a[x];
      res %= Q;
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  std::pair<int, T> kth(T k) {
    int x = -1;
    assert(k > 0);
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


void work() {
  int n;
  scanf("%d" , &n);
  FenwickTree<int> c(n + 1);
  f[n - 1] = 1;
  c.add(n - 1, 1);
  for (int i = n - 2 ; i >= 0 ; -- i) {
    f[i] = c.query(i + i);
    c.add(i, f[i]);
  }
  for (int i = 0 ; i < n ; ++ i) {
    f[i] = 1LL * f[i] * p[(i + 1) / 2 + 1] % Q;
    f[i] = 1LL * I[n] * f[i] % Q;
  }

  for (int i = 0 ; i < n ; ++ i) {
    printf("%d\n" , f[i]);
  }


}

int main() {
  p[0] = I[0] = 1;
  for (int i = 1; i < N; ++i) {
    p[i] = 1LL * p[i - 1] * 2 % Q;
    I[i] = 1LL * I[i - 1] * inv % Q;
  }

  int T = 1;
  scanf("%d", &T);
  while (T--) {
    static int ca = 0;
    work();
  }
  return 0;
}