#include <bits/stdc++.h>
using int64 = long long;
const int N = 300005;

template <typename T>
class FenwickTree {
 public:
  int n;
  std::vector<T> a;
  FenwickTree(int n = 0) : n(n) {
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

int n, m, a[N];

int main() {
  std::mt19937 rnd;
  int num = 0;
  std::unordered_map<int, int> S;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (!S.count(a[i])) {
      S[a[i]] = num++;
    }
    a[i] = S[a[i]];
  }
  std::vector<std::tuple<int, int, int, int>> q;
  for (int i = 0; i < m; ++i) {
    int o, l, r, k;
    scanf("%d%d%d", &o, &l, &r);
    if (o == 2) {
      scanf("%d", &k);
      --l;
      --r;
      q.emplace_back(o, l, r, k);
    } else {
      --l;
      if (!S.count(r)) {
        S[r] = num++;
      }
      r = S[r];
      q.emplace_back(o, l, r, 0);
    }
  }
  const int K = 30;
  std::vector<std::vector<bool>> w(30, std::vector<bool>(num));
  FenwickTree<int> c[K];
  for (int i = 0; i < K; ++i) {
    c[i] = FenwickTree<int>(n);
    for (int j = 0; j < num; ++j) {
      w[i][j] = rnd() & 1;
    }
    for (int j = 0; j < n; ++j) {
      if (w[i][a[j]]) {
        c[i].add(j, 1);
      }
    }
  }
  for (auto &[o, l, r, k] : q) {
    if (o == 1) {
      for (int i = 0; i < K; ++i) {
        if (w[i][a[l]]) {
          c[i].add(l, -1);
        }
      }
      a[l] = r;
      for (int i = 0; i < K; ++i) {
        if (w[i][a[l]]) {
          c[i].add(l, 1);
        }
      }
    } else {
      bool ok = true;
      for (int i = 0; i < K && ok; ++i) {
        int v = c[i].query(r) - c[i].query(l - 1);
        if (v % k != 0) {
          ok = false;
        }
      }
      puts(ok ? "YES" : "NO");
    }
  }

  return 0;
}