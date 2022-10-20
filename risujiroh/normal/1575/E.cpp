#ifndef LOCAL
#define DUMP(...) void()
#define NDEBUG
#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>
#endif

#include <cassert>
#include <numeric>
#include <type_traits>
#include <vector>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value, std::true_type, std::false_type>::type;

template <class T> using make_unsigned_int128 = __uint128_t;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value || is_signed_int128<T>::value || is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>, std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value, std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int = typename std::conditional<is_integral<T>::value && std::is_unsigned<T>::value, std::true_type,
                                                  std::false_type>::type;

template <class T>
using to_unsigned =
    typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>, std::common_type<T>>::type;

#endif

template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class T> struct fenwick_tree {
  using U = internal::to_unsigned_t<T>;

 public:
  fenwick_tree() : _n(0) {}
  explicit fenwick_tree(int n) : _n(n), data(n) {}

  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += U(x);
      p += p & -p;
    }
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

 private:
  int _n;
  std::vector<U> data;

  U sum(int r) {
    U s;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};

}  // namespace atcoder

#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#include <utility>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}

struct barrett {
  unsigned int _m;
  unsigned long long im;

  explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

  unsigned int umod() const { return _m; }

  unsigned int mul(unsigned int a, unsigned int b) const {
    unsigned long long z = a;
    z *= b;
#ifdef _MSC_VER
    unsigned long long x;
    _umul128(z, im, &x);
#else
    unsigned long long x = (unsigned long long)((__uint128_t(z) * im) >> 64);
#endif
    unsigned int v = (unsigned int)(z - x * _m);
    if (_m <= v) v += _m;
    return v;
  }
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
  if (m == 1) return 0;
  unsigned int _m = (unsigned int)(m);
  unsigned long long r = 1;
  unsigned long long y = safe_mod(x, m);
  while (n) {
    if (n & 1) r = (r * y) % _m;
    y = (y * y) % _m;
    n >>= 1;
  }
  return r;
}

constexpr bool is_prime_constexpr(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 7 || n == 61) return true;
  if (n % 2 == 0) return false;
  long long d = n - 1;
  while (d % 2 == 0) d /= 2;
  constexpr long long bases[3] = {2, 7, 61};
  for (long long a : bases) {
    long long t = d;
    long long y = pow_mod_constexpr(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && t % 2 == 0) {
      return false;
    }
  }
  return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
  a = safe_mod(a, b);
  if (a == 0) return {b, 0};

  long long s = b, t = a;
  long long m0 = 0, m1 = 1;

  while (t) {
    long long u = s / t;
    s -= t * u;
    m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  if (m0 < 0) m0 += b / s;
  return {s, m0};
}

constexpr int primitive_root_constexpr(int m) {
  if (m == 2) return 1;
  if (m == 167772161) return 3;
  if (m == 469762049) return 3;
  if (m == 754974721) return 11;
  if (m == 998244353) return 3;
  int divs[20] = {};
  divs[0] = 2;
  int cnt = 1;
  int x = (m - 1) / 2;
  while (x % 2 == 0) x /= 2;
  for (int i = 3; (long long)(i)*i <= x; i += 2) {
    if (x % i == 0) {
      divs[cnt++] = i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    divs[cnt++] = x;
  }
  for (int g = 2;; g++) {
    bool ok = true;
    for (int i = 0; i < cnt; i++) {
      if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) return g;
  }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

unsigned long long floor_sum_unsigned(unsigned long long n, unsigned long long m, unsigned long long a,
                                      unsigned long long b) {
  unsigned long long ans = 0;
  while (true) {
    if (a >= m) {
      ans += n * (n - 1) / 2 * (a / m);
      a %= m;
    }
    if (b >= m) {
      ans += n * (b / m);
      b %= m;
    }

    unsigned long long y_max = a * n + b;
    if (y_max < m) break;
    n = y_max / m;
    b = y_max % m;
    std::swap(m, a);
  }
  return ans;
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr> struct static_modint : internal::static_modint_base {
  using mint = static_modint;

 public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  static_modint() : _v(0) {}
  template <class T, internal::is_signed_int_t<T>* = nullptr> static_modint(T v) {
    long long x = (long long)(v % (long long)(umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T>* = nullptr> static_modint(T v) { _v = (unsigned int)(v % umod()); }

  unsigned int val() const { return _v; }

  mint& operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }

  mint& operator+=(const mint& rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }

  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() const {
    if (prime) {
      assert(_v);
      return pow(umod() - 2);
    } else {
      auto eg = internal::inv_gcd(_v, m);
      assert(eg.first == 1);
      return eg.second;
    }
  }

  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

 private:
  unsigned int _v;
  static constexpr unsigned int umod() { return m; }
  static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
  using mint = dynamic_modint;

 public:
  static int mod() { return (int)(bt.umod()); }
  static void set_mod(int m) {
    assert(1 <= m);
    bt = internal::barrett(m);
  }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  dynamic_modint() : _v(0) {}
  template <class T, internal::is_signed_int_t<T>* = nullptr> dynamic_modint(T v) {
    long long x = (long long)(v % (long long)(mod()));
    if (x < 0) x += mod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T>* = nullptr> dynamic_modint(T v) { _v = (unsigned int)(v % mod()); }

  unsigned int val() const { return _v; }

  mint& operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }

  mint& operator+=(const mint& rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v += mod() - rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    _v = bt.mul(_v, rhs._v);
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }

  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() const {
    auto eg = internal::inv_gcd(_v, mod());
    assert(eg.first == 1);
    return eg.second;
  }

  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

 private:
  unsigned int _v;
  static internal::barrett bt;
  static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T> using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T> using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id> struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T> using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder

using namespace std;
using i64 = long long;

#define ALL(r) ::begin(r), ::end(r)
#define UN(e) [&](auto&& $) { return e; }
#define BI(e) [&](auto&& $1, auto&& $2) { return e; }

#define TGT(s) __attribute__((target(#s)))
TGT(bmi) int bsf(i64 x) { return int(_tzcnt_u64(x)); }
TGT(lzcnt) int bsr(i64 x) { return 63 - int(_lzcnt_u64(x)); }
TGT(popcnt) int popcnt(i64 x) { return int(_mm_popcnt_u64(x)); }
TGT(bmi2) i64 bzhi(i64 x, int n) { return _bzhi_u64(x, n); }
TGT(bmi2) i64 pdep(i64 x, i64 mask) { return _pdep_u64(x, mask); }
TGT(bmi2) i64 pext(i64 x, i64 mask) { return _pext_u64(x, mask); }
#undef TGT

template <class T> bool is_pow2(T x) { return x >= 1 && (x & (x - 1)) == 0; }
template <class T> T floor_pow2(T x) { return assert(x >= 1), T(1) << bsr(x); }
template <class T> T ceil_pow2(T x) { return x <= 1 ? 1 : T(2) << bsr(x - 1); }
template <class T> T floor_div(T a, T b) { return assert(b), a / b - ((a ^ b) < 0 && a % b); }
template <class T> T ceil_div(T a, T b) { return assert(b), a / b + ((a ^ b) >= 0 && a % b); }

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = forward<U>(b), true : false; }

template <class T, class N, class Op> constexpr T power(T x, N n, Op op) {
  for (assert(n >= 1); ~n & 1; n >>= 1) x = op(x, x);
  T res = x;
  while (n >>= 1) x = op(x, x), n & 1 && (res = op(move(res), x), 0);
  return res;
}
template <class T, class N> constexpr T power(T x, N n) {
  return n ? power(n < 0 ? T(1) / x : x, abs(n), multiplies{}) : 1;
}

template <class F> struct Fix {
  F f_;
  Fix(F f) : f_(move(f)) {}
  template <class... Ts> decltype(auto) operator()(Ts&&... xs) const { return f_(ref(*this), forward<Ts>(xs)...); }
};

template <class T> struct rep {
  struct I : iterator<bidirectional_iterator_tag, T, T, void, T> {
    T i_, d_;
    operator T() const { return i_; }
    T operator*() const { return i_; }
    I& operator++() { return i_ += d_, *this; }
    I& operator--() { return i_ -= d_, *this; }
  } b_, e_;
  rep(T l, T r, T d = 1) : b_{{}, l, d}, e_{{}, l + max<T>(ceil_div(r - l, d), 0) * d, d} {}
  explicit rep(T n) : rep(0, n) {}
  I begin() const { return b_; }
  I end() const { return e_; }
};
struct Rev {
  template <class R> struct V {
    R r_;
    auto begin() const { return reverse_iterator(::end(r_)); }
    auto end() const { return reverse_iterator(::begin(r_)); }
  };
  template <class R> friend V<R> operator|(R&& r, Rev) { return {forward<R>(r)}; }
} rev;

template <class R> int sz(R&& r) { return int(size(forward<R>(r))); }
template <class I> int sz(I b, I e) { return int(distance(b, e)); }

template <class, class = void> struct IsRange : false_type {};
template <class T>
struct IsRange<T, enable_if_t<!__is_char<decay_t<decltype(*begin(declval<T&>()))>>::__value>> : true_type {};

namespace std {

#define BINARY_OP(op) \
  template <class A, class B> enable_if_t<IsRange<A>{} && IsRange<B>{}, A>& operator op##=(A& a, const B& b) { \
    return assert(sz(a) == sz(b)), transform(ALL(a), begin(b), begin(a), BI($1 op## = $2)), a; \
  } \
  template <class A, class B> enable_if_t<IsRange<A>{} && !IsRange<B>{}, A>& operator op##=(A& a, const B& b) { \
    return for_each(ALL(a), UN($ op## = b)), a; \
  } \
  template <class A, class B> enable_if_t<IsRange<A>{}, A> operator op(const A& a, const B& b) { \
    A res = a; \
    res op## = b; \
    return res; \
  } \
  template <class A, class B> enable_if_t<!IsRange<A>{} && IsRange<B>{}, B> operator op(const A& a, const B& b) { \
    B res = b; \
    for (auto&& e : res) e = a op move(e); \
    return res; \
  }
BINARY_OP(+)
BINARY_OP(-)
BINARY_OP(*)
BINARY_OP(/)
BINARY_OP(%)
BINARY_OP(&)
BINARY_OP(|)
BINARY_OP(^)
BINARY_OP(<<)
BINARY_OP(>>)
#undef BINARY_OP

}  // namespace std

struct Scan {
  char b_[1 << 15], c_;
  int l_ = sz(b_), r_ = l_;
  bool go(char& c) {
    for (;; ++l_) {
      if (r_ - l_ < 64) r_ = (r_ - l_) + read(STDIN_FILENO, move(b_ + l_, b_ + r_, b_), sz(b_) - (r_ - l_)), l_ = 0;
      if (l_ == r_) return c = {}, false;
      if (b_[l_] > ' ') return c = b_[l_++], true;
    }
  }
  bool go(string& s) {
    if (!go(c_)) return s = {}, false;
    for (s = c_; b_[l_] > ' '; s += c_) go(c_);
    return true;
  }
  template <class T> enable_if_t<is_integral_v<T>, bool> go(T& x) {
    if (!go(c_)) return x = {}, false;
    make_unsigned_t<T> u = (c_ == '-' ? b_[l_++] : c_) & 15;
    for (; b_[l_] > ' '; ++l_) (u *= 10) += b_[l_] & 15;
    return x = c_ == '-' ? -u : u, true;
  }
  template <class T> enable_if_t<is_floating_point_v<T>, bool> go(T& x) {
    if (!go(c_)) return x = {}, false;
    char* p;
    if constexpr (is_same_v<T, float>) x = strtof(b_ + (l_ - 1), &p);
    if constexpr (is_same_v<T, double>) x = strtod(b_ + (l_ - 1), &p);
    if constexpr (is_same_v<T, long double>) x = strtold(b_ + (l_ - 1), &p);
    return l_ = sz(b_, p), true;
  }
  template <class C> auto go(C& c) -> decltype(ALL(c), true) {
    for (auto&& e : c)
      if (!go(e)) return c = {}, false;
    return true;
  }
  template <class... Ts> bool operator()(Ts&... xs) { return (... && go(xs)); }
} scan;
template <class T = int, class... Args> T input(Args&&... args) {
  T res(forward<Args>(args)...);
  scan(res);
  return res;
}
template <class... Ts> enable_if_t<sizeof...(Ts) >= 2, tuple<Ts...>> input() {
  tuple<Ts...> res;
  apply([](auto&... e) { (..., scan(e)); }, res);
  return res;
}
struct Print {
  char b_[1 << 15];
  int i_ = 0;
  void go(char c = '\0') {
    if (sz(b_) - i_ < 64 || c == -1) write(STDOUT_FILENO, b_, i_), i_ = 0;
    if (c > 0) b_[i_++] = c;
  }
  template <class T> enable_if_t<is_integral_v<T>> go(T x) { go(), i_ = sz(b_, to_chars(b_ + i_, end(b_), x).ptr); }
  template <class T> enable_if_t<is_floating_point_v<T>> go(T x) {
    go(), i_ += snprintf(b_ + i_, sz(b_) - i_, "%.20Lf", (long double)x);
  }
  template <class R> auto go(R&& r) -> decltype(ALL(r), void()) {
    char c = '\0';
    for (auto&& e : r) is_same_v<decay_t<decltype(e)>, char> || (go(exchange(c, ' ')), 0), go(e);
  }
  template <class... Ts> void operator()(Ts&&... xs) {
    char c = '\0';
    (..., (go(exchange(c, ' ')), go(forward<Ts>(xs)))), go('\n');
  }
  ~Print() { go(char(-1)); }
} print;

struct Graph {
  std::vector<std::array<int, 2>> edges;
  struct Pair_ : std::pair<int, int> {
    using std::pair<int, int>::pair;
    operator int() const { return first; }
  };
  std::vector<Pair_> adj_;
  std::vector<int> pos_;
  Graph() {}
  Graph(int n, int m) : pos_(n + 1) { edges.reserve(m); }
  int n() const { return pos_.size() - 1; }
  int m() const { return edges.size(); }
  void build() {
    for (auto&& [u, v] : edges) ++pos_[u], ++pos_[v];
    std::partial_sum(pos_.begin(), pos_.end(), pos_.begin()), adj_.resize(pos_[n()]);
    for (int e = m(); e--;) adj_[--pos_[edges[e][0]]] = {edges[e][1], e}, adj_[--pos_[edges[e][1]]] = {edges[e][0], e};
  }
  template <class T> struct View_ {
    T *first, *last;
    int size() const { return last - first; }
    T& operator[](int i) const { return *(first + i); }
    T* begin() const { return first; }
    T* end() const { return last; }
  };
  View_<Pair_> operator[](int v) { return {adj_.data() + pos_[v], adj_.data() + pos_[v + 1]}; }
  View_<const Pair_> operator[](int v) const { return {adj_.data() + pos_[v], adj_.data() + pos_[v + 1]}; }
};

int main() {
  auto [n, k] = input<int, int>();
  auto a = input<vector<int>>(n);
  Graph g(n, n - 1);
  vector<int> col(n - 1);
  for (int e : rep(n - 1)) {
    g.edges.push_back(input<array<int, 2>>() - 1);
    scan(col[e]);
  }
  g.build();

  vector alive(n, true);

  vector<int> sub(n), nxt(n);
  Fix dfs_aux = [&](auto self, int v, int p) -> void {
    sub[v] = 1, nxt[v] = -1;
    for (int u : g[v]) {
      if (!alive[u] || u == p) continue;
      self(u, v);
      sub[v] += sub[u];
      if (nxt[v] == -1 || sub[u] > sub[nxt[v]]) nxt[v] = u;
    }
  };

  auto find_centroid = [&](int v) {
    dfs_aux(v, -1);
    for (int half = sub[v] / 2; ~nxt[v] && sub[nxt[v]] > half;) v = nxt[v];
    return v;
  };

  vector<pair<int, i64>> cur;
  Fix dfs = [&](auto self, int v, int pe, int cnt, i64 sum) -> void {
    cur.emplace_back(cnt, sum);
    for (auto [u, e] : g[v]) {
      if (!alive[u] || e == pe) continue;
      self(u, e, cnt + (col[e] != col[pe]), sum + a[u]);
    }
  };

  using Fp = atcoder::modint1000000007;
  vector f(2, atcoder::fenwick_tree<array<Fp, 2>>(n));

  Fp ans = accumulate(ALL(a), 0ll);
  Fix solve = [&](auto self, int c) -> void {
    for (auto [r, e] : g[c]) {
      if (!alive[r]) continue;
      cur.clear();
      dfs(r, e, 0, a[r]);

      for (auto [cnt, sum] : cur) {
        if (cnt <= k) {
          ans += a[c] + sum;
        }
        {
          auto s = f[col[e]].sum(0, max(k - cnt + 1, 0));
          ans += s[0] * (a[c] + sum) + s[1];
        }
        {
          auto s = f[col[e] ^ 1].sum(0, max(k - cnt, 0));
          ans += s[0] * (a[c] + sum) + s[1];
        }
      }

      for (auto [cnt, sum] : cur) {
        f[col[e]].add(cnt, {1, sum});
      }
    }

    for (auto [r, e] : g[c]) {
      if (!alive[r]) continue;
      cur.clear();
      dfs(r, e, 0, a[r]);
      for (auto [cnt, sum] : cur) {
        f[col[e]].add(cnt, {-1, -sum});
      }
    }

    alive[c] = false;
    for (int r : g[c]) {
      if (!alive[r]) continue;
      self(find_centroid(r));
    }
  };
  solve(find_centroid(0));
  print(ans.val());
}