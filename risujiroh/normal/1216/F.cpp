#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  using T = lint;
  static T op(const T& a, const T& b) { return min(a, b); }
  static constexpr T e() { return 1e18; }

  const int n;
  V<T> t;
  SegmentTree(int n) : n(n), t(2 * n, e()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T acc(int l, int r) const {
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  void set(int i, const T& a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  void chmin(int i, const T& a) {
    if (a >= (*this)[i]) return;
    set(i, a);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  bitset<200000> bs; cin >> bs;

  SegmentTree dp(n + 1);
  dp.chmin(0, 0);
  for (int i = 0; i < n; ++i) {
    dp.chmin(i + 1, dp[i] + n - i);
    if (i >= k and bs[i - k]) {
      dp.chmin(i + 1, dp.acc(max(i - 2 * k, 0), i + 1) + n - (i - k));
    }
    if (i == n - 1) {
      for (int j = max(n - 1 - k, 0); j < n; ++j) if (bs[j]) {
        dp.chmin(n, dp.acc(max(j - k, 0), n) + n - j);
      }
    }
  }
  cout << dp[n] << '\n';
}