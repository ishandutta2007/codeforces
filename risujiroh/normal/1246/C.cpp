#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  constexpr ModInt() : v(0) {}
  constexpr ModInt(unsigned _v, int) : v(_v) {}
  template<class Z> ModInt(const Z& a) : v((a < 0 ? P - -a % P : a) % P) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool)*this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  friend M operator*(M l, M r) { return M(l) *= r; }
  friend M operator/(M l, M r) { return M(l) /= r; }
  friend M operator+(M l, M r) { return M(l) += r; }
  friend M operator-(M l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend bool operator==(M l, M r) { return l.v == r.v; }
  friend bool operator!=(M l, M r) { return !(l == r); }
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
  template<class Z> M pow(Z n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
};
using Mint = ModInt<(unsigned)1e9 + 7>;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<string> s(n); for (auto&& e : s) cin >> e;
  VV<> cr(n, V<>(m + 1)), cd(n + 1, V<>(m));
  for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) {
    cr[i][j] = (s[i][j] == 'R') + cr[i][j + 1];
    cd[i][j] = (s[i][j] == 'R') + cd[i + 1][j];
  }
  VV<Mint> fr(n, V<Mint>(m)), fd(n, V<Mint>(m));
  V< FenwickTree<Mint> > row(n, FenwickTree<Mint>(m)), col(m, FenwickTree<Mint>(n));
  for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) {
    if (i == n - 1) {
      fr[i][j] = cr[i][j] == 0;
    } else if (j == m - 1) {
      fd[i][j] = cd[i][j] == 0;
    } else {
      fr[i][j] = row[i].sum(j + 1, m - cr[i][j + 1]);
      fd[i][j] = col[j].sum(i + 1, n - cd[i + 1][j]);
    }
    row[i].add(j, fd[i][j]);
    col[j].add(i, fr[i][j]);
  }
  cout << fr[0][0] + fd[0][0] << '\n';
}