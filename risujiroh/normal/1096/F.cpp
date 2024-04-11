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

struct SumMonoid {
  using T = pair<Mint, int>;
  static T op(const T& lhs, const T& rhs) { return {lhs.first + rhs.first, lhs.second + rhs.second}; }
  static constexpr T e() { return {{0, 0}, 0}; }
};

template<class Monoid> struct AddMonoidAct {
  using T = Mint;
  static void ap(const T& act, typename Monoid::T& val, int len) { val.first += act * val.second; }
  static void cp(const T& lhs, T& rhs) { rhs += lhs; }
  static constexpr T id() { return {0, 0}; }
};

template<class Monoid, class MonoidAct> struct SegmentTree {
  using M = Monoid;
  using MA = MonoidAct;
  using Tv = typename M::T;
  using Ta = typename MA::T;

  const int n;

  SegmentTree(int n, const Tv& a = M::e()) :
    n(n), val(2 * n, a), act(n, MA::id()), len(2 * n, 1) {
    build();
    for (int i = n - 1; i > 0; --i) {
      len[i] = len[2 * i] + len[2 * i + 1];
    }
  }
  template<class Itr> SegmentTree(Itr first, Itr last) :
    n(distance(first, last)), val(2 * n, M::e()), act(n, MA::id()), len(2 * n, 1) {
    copy(first, last, next(begin(val), n));
    build();
    for (int i = n - 1; i > 0; --i){
      len[i] = len[2 * i] + len[2 * i + 1];
    }
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      val[i] = M::op(val[2 * i], val[2 * i + 1]);
    }
  }

  void push() {
    for (int i = 1; i < n; ++i) push(i);
  }

  Tv get(int l, int r) {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return M::e();
    push(l, r);
    Tv resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, val[l++]);
      if (r & 1) resr = M::op(val[--r], resr);
    }
    return M::op(resl, resr);
  }
  Tv get(int i) { return get(i, i + 1); }

  void set(int l, int r, const Ta& f) {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return;
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) ap(f, i++);
      if (j & 1) ap(f, --j);
    }
    for (l += n; !(l & 1); l >>= 1);
    while ((l >>= 1) > 0) val[l] = M::op(val[2 * l], val[2 * l + 1]);
    for (r += n; !(r & 1); r >>= 1);
    while ((r >>= 1) > 0) val[r] = M::op(val[2 * r], val[2 * r + 1]);
  }
  void set(int i, const Tv& a) {
    assert(0 <= i and i < n);
    push(i, i + 1);
    for (val[i += n] = a, i >>= 1; i > 0; i >>= 1) {
      val[i] = M::op(val[2 * i], val[2 * i + 1]);
    }
  }

private:
  V<Tv> val;
  V<Ta> act;
  V<> len;

  void ap(const Ta& f, int i) {
    MA::ap(f, val[i], len[i]);
    if (i < n) MA::cp(f, act[i]);
  }

  void push(int i) {
    ap(act[i], 2 * i);
    ap(act[i], 2 * i + 1);
    act[i] = MA::id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
};

using ST = SegmentTree< SumMonoid, AddMonoidAct<SumMonoid> >;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (p[i] != -1) --p[i];
  }
  Mint res = 0;
  {
    ST st(n, {0, 1});
    for (int i = 0; i < n; ++i) if (p[i] != -1) {
      res += st.get(p[i]).first;
      st.set(0, p[i], 1);
    }
  }
  {
    Mint c = count(begin(p), end(p), -1);
    res += c * (c - 1) / 4;
  }
  {
    ST st(n, {0, 1});
    for (int i = 0; i < n; ++i) if (p[i] != -1) {
      st.set(p[i], {0, 0});
    }
    for (int i = 0; i < n; ++i) {
      if (p[i] == -1) {
        res += st.get(0, n).first / st.get(0, n).second;
      } else {
        st.set(0, p[i], 1);
      }
    }
  }
  {
    ST st(n, {0, 1});
    for (int i = 0; i < n; ++i) if (p[i] != -1) {
      st.set(p[i], {0, 0});
    }
    for (int i = n - 1; i >= 0; --i) {
      if (p[i] == -1) {
        res += st.get(0, n).first / st.get(0, n).second;
      } else {
        st.set(p[i], n, 1);
      }
    }
  }
  cout << res << '\n';
}