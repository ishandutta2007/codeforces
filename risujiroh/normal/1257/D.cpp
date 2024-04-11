#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  using T = int;
  static T op(const T& a, const T& b) { return max(a, b); }
  static constexpr T e() { return -1; }

  const int n;
  V<T> t;
  SegmentTree(int _n) : n(_n), t(2 * n, e()) {}
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
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    SegmentTree st(n);
    for (int i = 0; i < n; ++i) {
      cin >> st[i];
    }
    st.build();
    int m; cin >> m;
    V<> mx(n + 1);
    while (m--) {
      int p, s; cin >> p >> s;
      mx[s] = max(mx[s], p);
    }
    for (int i = n - 1; i >= 1; --i) {
      mx[i] = max(mx[i], mx[i + 1]);
    }
    int res = 0;
    int i = 0;
    while (i < n) {
      auto chk = [&](int x) -> bool {
        return mx[x] >= st.acc(i, i + x);
      };
      int ok = 0, ng = n - i + 1;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        (chk(mid) ? ok : ng) = mid;
      }
      if (ok == 0) {
        res = -1;
        break;
      }
      i += ok;
      ++res;
    }
    cout << res << '\n';
  }
}