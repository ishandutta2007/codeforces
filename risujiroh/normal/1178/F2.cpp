#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  ModInt(auto x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool)*this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t)v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  M pow(auto n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  friend M operator*(auto l, M r) { return M(l) *= r; }
  friend M operator/(auto l, M r) { return M(l) /= r; }
  friend M operator+(auto l, M r) { return M(l) += r; }
  friend M operator-(auto l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  friend bool operator==(auto l, M r) { return M(l) == r; }
  friend bool operator!=(auto l, M r) { return !(l == r); }
};
using Mint = ModInt<998244353>;

struct SegmentTree {
  using T = int;
  static T op(const T& x, const T& y) { return min(x, y); }
  static constexpr T e() { return numeric_limits<T>::max(); }

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
  void set(int i, const T& x) {
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> c(m); for (auto&& e : c) cin >> e, --e;
  {
    SegmentTree st(m);
    for (int i = 0; i < m; ++i) st[i] = c[i];
    st.build();
    V<> l(n, m), r(n, -1);
    for (int i = 0; i < m; ++i) {
      l[c[i]] = min(l[c[i]], i);
      r[c[i]] = max(r[c[i]], i);
    }
    for (int i = 0; i < n; ++i) {
      if (st.acc(l[i], r[i] + 1) < i) {
        return cout << 0 << '\n', 0;
      }
    }
    V<> nc;
    for (int i = 0; i < m; ++i) if (!i or c[i] != c[i - 1]) {
      nc.push_back(c[i]);
    }
    swap(c, nc);
  }
  m = c.size();
  VV<Mint> dp(m, V<Mint>(m, 1));
  for (int i = m - 1; i >= 0; --i) for (int j = i; j < m; ++j) {
    int mn = *min_element(begin(c) + i, begin(c) + j + 1);
    int kl = m, kr = -1;
    for (int k = i; k <= j; ++k) if (c[k] == mn) {
      kl = min(kl, k);
      kr = max(kr, k);
    }

    bool ok = true;
    for (int k = 0; k < kl; ++k) if (c[k] == mn) {
      ok = false;
      break;
    }
    for (int k = kr + 1; k < m; ++k) if (c[k] == mn) {
      ok = false;
      break;
    }
    if (!ok) {
      dp[i][j] = 0;
      continue;
    }

    Mint sr;
    for (int r = kr; r <= j; ++r) {
      sr += (kr + 1 < m ? dp[kr + 1][r] : 1) * (r + 1 < m ? dp[r + 1][j] : 1);
    }
    Mint sl;
    for (int l = kl; l >= i; --l) {
      sl += (l ? dp[i][l - 1] : 1) * (kl ? dp[l][kl - 1] : 1);
    }
    Mint sm = 1;
    int l = kl;
    for (int r = kl + 1; r <= kr; ++r) if (c[r] == mn) {
      sm *= dp[l + 1][r - 1];
      l = r;
    }
    dp[i][j] = sl * sm * sr;
  }
  cout << dp[0].back() << '\n';
}