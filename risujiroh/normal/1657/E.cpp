static_assert(R"("

using fp = atcoder::modint998244353;

int const L = 1000;

void main(int) {
  vector<fp> fact(L + 1, 1);
  for (int i : rep1(L)) { fact[i] = fact[i - 1] * i; }
  vector<fp> ifact(L + 1, 1 / fact[L]);
  for (int i : rev(rep1(L))) { ifact[i - 1] = ifact[i] * i; }
  auto binom = [&](int n, int k) -> fp {
    assert(0 <= n && n <= L);
    return 0 <= k && k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0;
  };
  int n, k;
  scan(n, k);
  --n;
  vector<fp> f(n + 1);
  vector<fp> g(n + 1);
  f[0] = 1;
  g[0] = 1;
  for (int val : rev(rep1(k))) {
    vector<fp> nf(n + 1);
    vector<fp> ng(n + 1);
    for (int x : rep1(0, n)) {
      for (int nx : rep1(x, n)) {
        int dx = nx - x;
        nf[nx] += f[x] * binom(n - x, dx);
        ng[nx] += (g[x] * power(fp(val), (binom(nx, 2) - binom(x, 2)).val()) * binom(n - x, dx));
      }
    }
    f = move(nf);
    g = move(ng);
    DUMP(f);
    DUMP(g);
  }
  println(g[n].val());
}

")");

#define MULTI_CASES 0
#define INTERACTIVE 0

#ifndef LOCAL
#define LOCAL 0
#endif

#if !LOCAL
#define NDEBUG
#endif

#ifndef __GLIBCXX_TYPE_INT_N_0
#define __GLIBCXX_TYPE_INT_N_0 __int128
#endif

#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>

namespace r7h {

using namespace std;

void main(int);

}  // namespace r7h

#if LOCAL
#include <utility/dump.hpp>
#else
#define DUMP(...) void(0)
#endif

#define LIFT(FN) \
  []<class... Ts_>(Ts_&&... xs_) -> decltype(auto) { return FN(static_cast<Ts_&&>(xs_)...); }

#define LAMBDA(...) \
  [&]<class T1_ = void*, class T2_ = void*>([[maybe_unused]] T1_&& _1 = nullptr, [[maybe_unused]] T2_&& _2 = nullptr) \
      -> decltype(auto) { \
    return __VA_ARGS__; \
  }

namespace r7h {

template <class F>
class fix : F {
 public:
  explicit fix(F f) : F(move(f)) {}

  template <class... Ts>
  decltype(auto) operator()(Ts&&... xs) const {
    return F::operator()(ref(*this), forward<Ts>(xs)...);
  }
};

template <class T>
decay_t<T> decay_copy(T&& x) {
  return forward<T>(x);
}

template <class T>
auto ref_or_move(remove_reference_t<T>& x) {
  if constexpr (is_reference_v<T> && !is_placeholder_v<decay_t<T>>) {
    return ref(x);
  } else {
    return move(x);
  }
}

template <class T, class D = decay_t<T>>
bool const is_lambda_expr = is_placeholder_v<D> || is_bind_expression_v<D>;

#define UNARY_LAMBDA(OP) \
  template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr> \
  auto operator OP(T&& x) { \
    return bind([]<class T_>(T_&& x_) -> decltype(auto) { return OP forward<T_>(x_); }, ref_or_move<T>(x)); \
  }

#define BINARY_LAMBDA(OP) \
  template <class T1, class T2, enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP(T1&& x, T2&& y) { \
    auto f = []<class T1_, class T2_>(T1_&& x_, T2_&& y_) -> decltype(auto) { \
      return forward<T1_>(x_) OP forward<T2_>(y_); \
    }; \
    return bind(move(f), ref_or_move<T1>(x), ref_or_move<T2>(y)); \
  }

BINARY_LAMBDA(+=)
BINARY_LAMBDA(-=)
BINARY_LAMBDA(*=)
BINARY_LAMBDA(/=)
BINARY_LAMBDA(%=)
BINARY_LAMBDA(&=)
BINARY_LAMBDA(|=)
BINARY_LAMBDA(^=)
BINARY_LAMBDA(<<=)
BINARY_LAMBDA(>>=)

UNARY_LAMBDA(++)
UNARY_LAMBDA(--)

UNARY_LAMBDA(+)
UNARY_LAMBDA(-)
BINARY_LAMBDA(+)
BINARY_LAMBDA(-)
BINARY_LAMBDA(*)
BINARY_LAMBDA(/)
BINARY_LAMBDA(%)

UNARY_LAMBDA(~)
BINARY_LAMBDA(&)
BINARY_LAMBDA(|)
BINARY_LAMBDA(^)
BINARY_LAMBDA(<<)
BINARY_LAMBDA(>>)

BINARY_LAMBDA(==)
BINARY_LAMBDA(!=)
BINARY_LAMBDA(<)
BINARY_LAMBDA(>)
BINARY_LAMBDA(<=)
BINARY_LAMBDA(>=)

UNARY_LAMBDA(!)
BINARY_LAMBDA(&&)
BINARY_LAMBDA(||)

#undef UNARY_LAMBDA
#undef BINARY_LAMBDA

using namespace placeholders;

using i8 = signed char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

template <int> struct signed_int;
template <int> struct unsigned_int;

#define INT_TYPE(N) \
  template <> struct signed_int<N> { using type = i##N; }; \
  template <> struct unsigned_int<N> { using type = u##N; };

INT_TYPE(8)
INT_TYPE(16)
INT_TYPE(32)
INT_TYPE(64)
INT_TYPE(128)

#undef INT_TYPE

template <int N> using signed_int_t = typename signed_int<N>::type;
template <int N> using unsigned_int_t = typename unsigned_int<N>::type;

namespace scan_impl {

#if INTERACTIVE || LOCAL

bool scan(char& c) { return scanf(" %c", &c) != EOF; }

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  for (s = c;; s += c) {
    c = char(getchar());
    if (c <= ' ') {
      ungetc(c, stdin);
      break;
    }
  }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? getchar() : c) & 15;
  while (true) {
    if (int t = getchar(); '0' <= t && t <= '9') {
      (u *= 10) += t & 15;
    } else {
      ungetc(t, stdin);
      break;
    }
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  return scanf(is_same_v<T, float> ? "%f" : is_same_v<T, double> ? "%lf" : "%Lf", &x) != EOF;
}

#else

char buf[1 << 15];
char* ptr = buf;
char* last = buf;

bool scan(char& c) {
  for (;; ++ptr) {
    if (last - ptr < 64) {
      last = move(ptr, last, buf);
      ptr = buf;
      last += read(STDIN_FILENO, last, end(buf) - last - 1);
      *last = '\0';
    }
    if (ptr == last) { return false; }
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  for (s = c; ' ' < *ptr; s += c) { scan(c); }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? *ptr++ : c) & 15;
  while ('0' <= *ptr && *ptr <= '9') { (u *= 10) += *ptr++ & 15; }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  int n;
  sscanf(--ptr, is_same_v<T, float> ? "%f%n" : is_same_v<T, double> ? "%lf%n" : "%Lf%n", &x, &n);
  ptr += n;
  return true;
}

#endif

template <class R>
auto scan(R&& r) -> decltype(begin(r), end(r), true) {
  return all_of(begin(r), end(r), LIFT(scan));
}

template <class... Ts>
enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(forward<Ts>(xs)));
}

}  // namespace scan_impl

using scan_impl::scan;

namespace print_impl {

#if INTERACTIVE || LOCAL

template <char = 0>
void print(char c) {
  if (c) { putchar(c); }
  if (c == '\n') { fflush(stdout); }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  char buf[64];
  char* ptr = to_chars(buf, end(buf), +x).ptr;
  for_each(buf, ptr, LIFT(print));
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  printf(is_same_v<T, float> ? "%.6f" : is_same_v<T, double> ? "%.15f" : "%.18Lf", x);
}

#else

char buf[1 << 15];
char* ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) { abort(); }
  ptr = buf;
}

template <char = 0>
void print(char c) {
  if (end(buf) - ptr < 64) { flush(); }
  if (c) { *ptr++ = c; }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  print('\0');
  ptr = to_chars(ptr, end(buf), +x).ptr;
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  print('\0');
  ptr += snprintf(ptr, end(buf) - ptr, is_same_v<T, float> ? "%.6f" : is_same_v<T, double> ? "%.15f" : "%.18Lf", x);
}

#endif

template <char = 0>
void print(char const*);

template <char Sep = ' ', class R>
auto print(R&& r) -> void_t<decltype(begin(r), end(r))> {
  [[maybe_unused]] char c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) { print(exchange(c, Sep)); }
    print(e);
  }
}

template <char = 0>
void print(char const* s) {
  print(string_view(s));
}

template <char Sep = ' ', class... Ts>
enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  [[maybe_unused]] char c = '\0';
  (..., (print(exchange(c, Sep)), print(forward<Ts>(xs))));
}

}  // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts>
void println(Ts&&... xs) {
  print<Sep>(forward<Ts>(xs)...);
  print(End);
}

template <class T>
auto operator++(T& x, int) -> decltype(++x, T(x)) {
  T ret = x;
  ++x;
  return ret;
}

template <class T>
auto operator--(T& x, int) -> decltype(--x, T(x)) {
  T ret = x;
  --x;
  return ret;
}

#define BINARY_ARITH_OP(OP) \
  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(declval<T&>() OP##= y, T(x)) { \
    T ret = T(x); \
    ret OP##= y; \
    return ret; \
  }

BINARY_ARITH_OP(+)
BINARY_ARITH_OP(-)
BINARY_ARITH_OP(*)
BINARY_ARITH_OP(/)
BINARY_ARITH_OP(%)
BINARY_ARITH_OP(&)
BINARY_ARITH_OP(|)
BINARY_ARITH_OP(^)
BINARY_ARITH_OP(<<)
BINARY_ARITH_OP(>>)

#undef BINARY_ARITH_OP

#define COMPARISON_OP(OP, E) \
  template <class T1, class T2> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(E) { \
    return E; \
  }

COMPARISON_OP(!=, !(x == y))
COMPARISON_OP(>, y < x)
COMPARISON_OP(<=, !(y < x))
COMPARISON_OP(>=, !(x < y))

#undef COMPARISON_OP

template <class D, class C, class R>
class iter_base {
  D& derived() { return static_cast<D&>(*this); }
  D const& derived() const { return static_cast<D const&>(*this); }

 public:
  using iterator_category = C;
  using value_type = decay_t<R>;
  using difference_type = int;
  using pointer = void;
  using reference = R;

#define REQUIRE(CAT) template <class C_ = C, enable_if_t<is_convertible_v<C_, CAT##_iterator_tag>>* = nullptr>

  R operator*() const { return derived().deref(); }
  REQUIRE(random_access) R operator[](int n) const { return *(derived() + n); }

  D& operator++() & {
    derived().inc();
    return derived();
  }
  REQUIRE(bidirectional) D& operator--() & {
    derived().dec();
    return derived();
  }
  REQUIRE(random_access) D& operator+=(int n) & {
    derived().adv(n);
    return derived();
  }
  REQUIRE(random_access) D& operator-=(int n) & {
    derived().adv(-n);
    return derived();
  }

  REQUIRE(random_access) friend D operator+(D const& x, int n) {
    D ret = x;
    ret += n;
    return ret;
  }
  REQUIRE(random_access) friend D operator+(int n, D const& x) { return x + n; }
  REQUIRE(random_access) friend D operator-(D const& x, int n) {
    D ret = x;
    ret -= n;
    return ret;
  }
  REQUIRE(random_access) friend int operator-(D const& x, D const& y) { return y.dist_to(x); }

  friend bool operator==(D const& x, D const& y) { return x.eq(y); }
  REQUIRE(random_access) friend bool operator<(D const& x, D const& y) { return x - y < 0; }

#undef REQUIRE
};

struct int_iter : iter_base<int_iter, random_access_iterator_tag, int> {
  int v;
  int_iter() = default;
  int_iter(int v) : v(v) {}
  int deref() const { return v; }
  bool eq(int_iter const& x) const { return v == x.v; }
  void inc() { ++v; }
  void dec() { --v; }
  void adv(int n) { v += n; }
  int dist_to(int_iter const& x) const { return x.v - v; }
};

template <class I>
class range {
  I b, e;

 public:
  explicit range(I first, I last) : b(move(first)), e(move(last)) {}
  I begin() const { return b; }
  I end() const { return e; }
};

auto rep(int l, int r) { return range<int_iter>(min(l, r), r); }

auto rep(int n) { return rep(0, n); }

auto rep1(int l, int r) { return rep(l, r + 1); }

auto rep1(int n) { return rep(1, n + 1); }

template <class R>
auto rev(R&& r) {
  return range(make_reverse_iterator(end(r)), make_reverse_iterator(begin(r)));
}

template <class R>
auto sz(R&& r) -> decltype(int(size(forward<R>(r)))) {
  return int(size(forward<R>(r)));
}

template <class T, class N, class Op>
T power1(T x, N n, Op op) {
  assert(1 <= n);
  for (; ~n & 1; n >>= 1) { x = op(x, x); }
  T ret = x;
  while (n >>= 1) {
    x = op(x, x);
    if (n & 1) { ret = op(move(ret), x); }
  }
  return ret;
}

template <class T, class N>
T power(T x, N n) {
  if (n == 0) { return T{1}; }
  if (n < 0) { return T{1} / power1(move(x), -n, multiplies{}); }
  return power1(move(x), n, multiplies{});
}

template <class T>
T div_floor(T x, T y) {
  return T(x / y - ((x ^ y) < 0 && x % y));
}

template <class T>
T div_ceil(T x, T y) {
  return T(x / y + (0 <= (x ^ y) && x % y));
}

template <class T, class U = T>
bool chmin(T& x, U&& y) {
  return y < x ? x = forward<U>(y), true : false;
}

template <class T, class U = T>
bool chmax(T& x, U&& y) {
  return x < y ? x = forward<U>(y), true : false;
}

template <class T>
T const inf_v = numeric_limits<T>::max() / 2;

int const inf = inf_v<int>;

mt19937_64 mt(_rdtsc());

template <class T>
T rand(T a, T b) {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution(a, b)(mt);
  } else {
    return uniform_real_distribution(a, b)(mt);
  }
}

}  // namespace r7h

int main() {
  int t = 1;
  if (MULTI_CASES) { r7h::scan(t); }
  for (int i : r7h::rep(t)) { r7h::main(i); }
  assert(!r7h::scan(t));
}

#ifdef _MSC_VER
#include <intrin.h>
#endif

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m < 2^31`
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
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

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
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

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
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

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
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
        // y_max < m * (n + 1)
        // floor(y_max / m) <= n
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

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

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

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
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

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

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

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

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder

#define all(c) begin(c), end(c)

namespace r7h {

using fp = atcoder::modint998244353;

int const L = 1000;

void main(int) {
  vector<fp> fact(L + 1, 1);
  for (int i : rep1(L)) { fact[i] = fact[i - 1] * i; }
  vector<fp> ifact(L + 1, 1 / fact[L]);
  for (int i : rev(rep1(L))) { ifact[i - 1] = ifact[i] * i; }
  auto binom = [&](int n, int k) -> fp {
    assert(0 <= n && n <= L);
    return 0 <= k && k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0;
  };
  int n, k;
  scan(n, k);
  --n;
  vector<fp> f(n + 1);
  vector<fp> g(n + 1);
  f[0] = 1;
  g[0] = 1;
  for (int val : rev(rep1(k))) {
    vector<fp> nf(n + 1);
    vector<fp> ng(n + 1);
    for (int x : rep1(0, n)) {
      for (int nx : rep1(x, n)) {
        int dx = nx - x;
        nf[nx] += f[x] * binom(n - x, dx);
        ng[nx] += (g[x] * power(fp(val), (binom(nx, 2) - binom(x, 2)).val()) * binom(n - x, dx));
      }
    }
    f = move(nf);
    g = move(ng);
    DUMP(f);
    DUMP(g);
  }
  println(g[n].val());
}

}  // namespace r7h