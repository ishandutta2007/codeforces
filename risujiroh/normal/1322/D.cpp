#include <bits/stdc++.h>
using namespace std;

template <class T, class Op = function<T(T, T)>> struct segtree {
  const Op op;
  const T e = T();
  const int n = 0;
  vector<T> t;
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T fold(int l, int r) const {
    T a = e, b = e;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};
template <class T, class Op> auto make_segtree(int n, Op op, T e) {
  return segtree<T, Op>{op, e, n, vector<T>(2 * n, e)};
}

auto maximum = [](auto a, auto b) { return a < b ? b : a; };

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> l(n);
  for (auto&& e : l) {
    cin >> e;
    --e;
  }
  vector<int> s(n);
  for (auto&& e : s) {
    cin >> e;
  }
  vector<int> c(n + m);
  for (auto&& e : c) {
    cin >> e;
  }
  vector<segtree<int, decltype(maximum)>> dp(m, make_segtree(n + 1, maximum, -inf));
  for (int x = 0; x < m; ++x) {
    dp[x].set(0, 0);
  }
  for (int i = n; i--; ) {
    for (int j = n; j--; ) {
      int cur = dp[l[i]][j];
      for (int k = l[i]; k <= l[i] + __builtin_ctz(j + 1); ++k) {
        cur += c[k];
      }
      cur -= s[i];
      dp[l[i]].set(j + 1, max(dp[l[i]][j + 1], cur));
    }
    for (int x = 0; x < l[i]; ++x) {
      int w = 1 << min(l[i] - x, 11);
      for (int j = 0; j < n; j += w) {
        int nj = (j >> min(l[i] - x, 11)) + 1;
        int cur = dp[x].fold(j, min(j + w, n + 1));
        for (int k = l[i]; k <= l[i] + __builtin_ctz(nj); ++k) {
          cur += c[k];
        }
        cur -= s[i];
        dp[l[i]].set(nj, max(dp[l[i]][nj], cur));
      }
    }
  }
  int res = -inf;
  for (const auto& e : dp) {
    res = max(res, e.fold(0, n + 1));
  }
  cout << res << '\n';
}