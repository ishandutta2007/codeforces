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
    #ifdef __linux__ // ACCF
      return pow(P - 2);
    #else
      int a = v, b = P, x = 1, u = 0;
      while (b) {
        int q = a / b;
        swap(a -= q * b, b);
        swap(x -= q * u, u);
      }
      return x;
    #endif
  }
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
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

using Mint = ModInt<998244353>;

struct AddMonoidAct {
  using T = int;
  using U = int;
  static void ap(const U& f, T& x) { x += f; }
  static void cp(const U& g, U& f) { f += g; }
  static constexpr U id() { return 0; }
};

template<class MonoidAct> struct SegmentTree {
  using M = MonoidAct;
  using T = typename M::T;
  using U = typename M::U;

  const int n;

  SegmentTree(int n, const T& a) :
    n(n), val(n, a), laz(n, M::id()) {}
  template<class Itr> SegmentTree(Itr first, Itr last) :
    n(distance(first, last)), val(first, last), laz(n, M::id()) {}

  void push() {
    for (int i = 1; i < n; ++i) push(i);
  }

  T get(int i) {
    assert(0 <= i and i < n);
    for (int h = __lg(i += n); h > 0; --h) {
      push(i >> h);
    }
    return val[i - n];
  }

  void set(int l, int r, const U& f) {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return;
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) ap(f, i++);
      if (j & 1) ap(f, --j);
    }
  }
  void set(int i, const T& a) {
    assert(0 <= i and i < n);
    for (int h = __lg(i += n); h > 0; --h) {
      push(i >> h);
    }
    val[i - n] = a;
  }

private:
  V<T> val;
  V<U> laz;

  void ap(const U& f, int i) {
    if (i < n) M::cp(f, laz[i]);
    else M::ap(f, val[i - n]);
  }

  void push(int i) {
    ap(laz[i], 2 * i);
    ap(laz[i], 2 * i + 1);
    laz[i] = M::id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  map<int, int> l, r;
  for (int i = 0; i < n; ++i) {
    if (!l.count(a[i])) {
      l[a[i]] = i;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (!r.count(a[i])) {
      r[a[i]] = i;
    }
  }
  SegmentTree<AddMonoidAct> st(n - 1, 0);
  for (const auto& e : l) {
    st.set(e.second, r[e.first], 1);
  }
  int c = 0;
  for (int i = 0; i < n - 1; ++i) {
    c += !st.get(i);
  }
  Mint res = Mint(2).pow(c);
  cout << res << '\n';
}