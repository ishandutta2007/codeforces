#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> constexpr bool is_prime(Int n) {
  if (n < 2 or n > 2 and ~n & 1) return false;
  for (Int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
  return true;
}
template<uint P> struct ModInt {
  static_assert(is_prime(P), "template argument must be a prime number");
  using M = ModInt;
  uint v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(uint v, int _) : v(v) {} // 
  static constexpr uint p() { return P; }
  M operator++(int) { M t = *this; if (++v == P) v = 0; return t; }
  M operator--(int) { M t = *this; v = (v ? v : P) - 1; return t; }
  M& operator++() { if (++v == P) v = 0; return *this; }
  M& operator--() { v = (v ? v : P) - 1; return *this; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !static_cast<bool>(*this); }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) { return v == rhs.v; }
  bool operator!=(M rhs) { return !(*this == rhs); }
  M& operator*=(M rhs) { v = (ulint) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
  M inv() const {
    assert(v);
    return pow(P - 2);
  }
  template<class Int> M pow(Int n) const {
    // n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n > 0; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Int> friend M operator*(Int lhs, M rhs) { return M(lhs) *= rhs; }
  template<class Int> friend M operator/(Int lhs, M rhs) { return M(lhs) /= rhs; }
  template<class Int> friend M operator+(Int lhs, M rhs) { return M(lhs) += rhs; }
  template<class Int> friend M operator-(Int lhs, M rhs) { return M(lhs) -= rhs; }
  friend ostream& operator<<(ostream& os, M rhs) { return os << rhs.v; }
  friend istream& operator>>(istream& is, M& rhs) { lint x; is >> x; rhs = x; return is; }
  template<class Int> friend bool operator==(Int lhs, M rhs) { return M(lhs) == rhs; }
  template<class Int> friend bool operator!=(Int lhs, M rhs) { return !(lhs == rhs); }
};
using Mint = ModInt<static_cast<uint>(1e9 + 7)>;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int n) : n(n), t(n + 1, 1) {}
  void mul(int i, T x) { for (++i; i <= n; i += i & -i) t[i] *= x; }
  T prod(int i) const {
    T s = 1;
    for (; i; i -= i & -i) s *= t[i];
    return s;
  }
  T prod(int l, int r) const { return prod(r) / prod(l); }
};
template<class T> struct MulProdTree {
  const int n;
  FenwickTree<T> d, e;
  MulProdTree(int n) : n(n), d(n), e(n) {}
  void mul(int l, int r, T x) {
    d.mul(l, x), e.mul(l, x.pow(l));
    if (r < n) d.mul(r, x.inv()), e.mul(r, x.pow(r).inv());
  }
  T prod(int i) const { return d.prod(i).pow(i) / e.prod(i); }
  T prod(int l, int r) const { return prod(r) / prod(l); }
};

constexpr int K = 62;
struct SegmentTree {
  using T = bitset<K>;
  static T op(const T& x, const T& y) { return x | y; }
  static constexpr T e() { return T(); }
  using U = T;
  static void ap(const U& f, T& x) { x |= f; }
  static void cp(const U& g, U& f) { f |= g; }
  static constexpr U id() { return U(); }

  const int n;
  V<T> t;
  V<U> u;
  SegmentTree(int n) : n(n), t(2 * n, e()), u(n, id()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  void push() { for (int i = 1; i < n; ++i) push(i); }
  void apply(const U& f, int i) {
    ap(f, t[i]);
    if (i < n) cp(f, u[i]);
  }
  void push(int i) {
    if (u[i] == id()) return;
    apply(u[i], 2 * i);
    apply(u[i], 2 * i + 1);
    u[i] = id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
  T acc(int l, int r) {
    push(l, r);
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  T get(int i) { return acc(i, i + 1); }
  void act(int l, int r, const U& f) {
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(f, i++);
      if (j & 1) apply(f, --j);
    }
    l = l + n >> __builtin_ctz(l + n);
    while (l >>= 1) t[l] = op(t[2 * l], t[2 * l + 1]);
    r = r + n >> __builtin_ctz(r + n);
    while (r >>= 1) t[r] = op(t[2 * r], t[2 * r + 1]);
  }
  void set(int i, const T& x) {
    push(i, i + 1);
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  MulProdTree<Mint> t(n);
  for (int i = 0; i < n; ++i) t.mul(i, i + 1, a[i]);

  V<> ps;
  for (int p = 2; p < 300; ++p) if (is_prime(p)) {
    ps.push_back(p);
  }
  assert(ps.size() == K);
  V< bitset<K> > mask(301);
  for (int x = 1; x <= 300; ++x) {
    for (int i = 0; i < K; ++i) if (x % ps[i] == 0) {
      mask[x][i] = true;
    }
  }
  SegmentTree st(n);
  for (int i = 0; i < n; ++i) st[i] = mask[a[i]];
  st.build();

  V<Mint> c(K);
  for (int i = 0; i < K; ++i) {
    c[i] = 1 - Mint(ps[i]).inv();
  }
  while (q--) {
    string s; cin >> s;
    int l, r; cin >> l >> r, --l;
    if (s.size() == 8) {
      int x; cin >> x;
      t.mul(l, r, x);
      st.act(l, r, mask[x]);
    } else {
      Mint res = t.prod(l, r);
      auto bs = st.acc(l, r);
      for (int i = 0; i < K; ++i) if (bs[i]) {
        res *= c[i];
      }
      cout << res << '\n';
    }
  }
}