static_assert(R"("

using i64 = long long;

void main(int) {
  int n, m;
  scan(n, m);
  string s;
  scan(s);

  vector<int> ans(n * m);
  vector<int> col(m);
  int gc = 0;

  for (int i : rep(n))
    for (int j : rep(m)) {
      int k = i * m + j;
      if (s[k] & 1) {
        gc += col[j]++ == 0;
      }
      ans[k] = gc;
    }

  vector<int> suff(n * m + 1);
  for (int k : rev(rep(n * m))) {
    suff[k] = (s[k] & 1) + suff[k + 1];
  }

  for (int j : rep(m)) {
    int cur = 0;
    for (int i : rep(n)) {
      int k = i * m + j;
      if (i == 0) {
        cur += 0 < suff[0] - suff[j + 1];
      } else {
        cur += 0 < suff[k - m + 1] - suff[k + 1];
      }
      ans[k] += cur;
    }
  }

  println(ans);
}

")");

#define MULTI_CASES 1
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

#define LIFT(FN)                                     \
  []<class... Ts_>(Ts_ && ... xs_)->decltype(auto) { \
    return FN(static_cast<Ts_&&>(xs_)...);           \
  }

#define LAMBDA(...)                          \
  [&]<class T1_ = void*, class T2_ = void*>( \
      [[maybe_unused]] T1_&& _1 = nullptr,   \
      [[maybe_unused]] T2_&& _2 = nullptr)   \
      ->decltype(auto) {                     \
    return __VA_ARGS__;                      \
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

#define UNARY_LAMBDA(OP)                                        \
  template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr> \
  auto operator OP(T&& x) {                                     \
    auto f = []<class T_>(T_&& x_) -> decltype(auto) {          \
      return OP forward<T_>(x_);                                \
    };                                                          \
    return bind(move(f), ref_or_move<T>(x));                    \
  }

#define BINARY_LAMBDA(OP)                                                     \
  template <class T1, class T2,                                               \
            enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP(T1&& x, T2&& y) {                                          \
    auto f = []<class T1_, class T2_>(T1_&& x_, T2_&& y_) -> decltype(auto) { \
      return forward<T1_>(x_) OP forward<T2_>(y_);                            \
    };                                                                        \
    return bind(move(f), ref_or_move<T1>(x), ref_or_move<T2>(y));             \
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

namespace scan_impl {

#if INTERACTIVE || LOCAL

bool scan(char& c) { return scanf(" %c", &c) != EOF; }

bool scan(string& s) {
  char c;
  if (!scan(c)) {
    return false;
  }
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
  if (!scan(c)) {
    return false;
  }
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
  return scanf(is_same_v<T, float>    ? "%f"
               : is_same_v<T, double> ? "%lf"
                                      : "%Lf",
               &x) != EOF;
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
    if (ptr == last) {
      return false;
    }
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}

bool scan(string& s) {
  char c;
  if (!scan(c)) {
    return false;
  }
  for (s = c; ' ' < *ptr; s += c) {
    scan(c);
  }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) {
    return false;
  }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? *ptr++ : c) & 15;
  while ('0' <= *ptr && *ptr <= '9') {
    (u *= 10) += *ptr++ & 15;
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) {
    return false;
  }
  int n;
  sscanf(--ptr,
         is_same_v<T, float>    ? "%f%n"
         : is_same_v<T, double> ? "%lf%n"
                                : "%Lf%n",
         &x, &n);
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
  if (c) {
    putchar(c);
  }
  if (c == '\n') {
    fflush(stdout);
  }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  char buf[64];
  char* ptr = to_chars(buf, end(buf), +x).ptr;
  for_each(buf, ptr, LIFT(print));
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  printf(is_same_v<T, float>    ? "%.6f"
         : is_same_v<T, double> ? "%.15f"
                                : "%.18Lf",
         x);
}

#else

char buf[1 << 15];
char* ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) {
    abort();
  }
  ptr = buf;
}

template <char = 0>
void print(char c) {
  if (end(buf) - ptr < 64) {
    flush();
  }
  if (c) {
    *ptr++ = c;
  }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  print('\0');
  ptr = to_chars(ptr, end(buf), +x).ptr;
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  print('\0');
  ptr += snprintf(ptr, end(buf) - ptr,
                  is_same_v<T, float>    ? "%.6f"
                  : is_same_v<T, double> ? "%.15f"
                                         : "%.18Lf",
                  x);
}

#endif

template <char = 0>
void print(char const*);

template <char Sep = ' ', class R>
auto print(R&& r) -> void_t<decltype(begin(r), end(r))> {
  [[maybe_unused]] char c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) {
      print(exchange(c, Sep));
    }
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

#define BINARY_ARITH_OP(OP)                                      \
  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator OP(T1 const& x, T2 const& y)                     \
      ->decltype(declval<T&>() OP## = y, T(x)) {                 \
    T ret = T(x);                                                \
    ret OP## = y;                                                \
    return ret;                                                  \
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

#define COMPARISON_OP(OP, E)                                \
  template <class T1, class T2>                             \
  auto operator OP(T1 const& x, T2 const& y)->decltype(E) { \
    return E;                                               \
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

#define REQUIRE(CAT)      \
  template <class C_ = C, \
            enable_if_t<is_convertible_v<C_, CAT##_iterator_tag>>* = nullptr>

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
  REQUIRE(random_access) friend int operator-(D const& x, D const& y) {
    return y.dist_to(x);
  }

  friend bool operator==(D const& x, D const& y) { return x.eq(y); }
  REQUIRE(random_access) friend bool operator<(D const& x, D const& y) {
    return x - y < 0;
  }

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

template <class I, class F>
struct map_iter
    : iter_base<
          map_iter<I, F>, typename iterator_traits<I>::iterator_category,
          invoke_result_t<F const&, typename iterator_traits<I>::reference>> {
  I i;
  [[no_unique_address]] F f;
  explicit map_iter(I i, F f) : i(move(i)), f(move(f)) {}
  decltype(auto) deref() const { return invoke(f, *i); }
  bool eq(map_iter const& x) const { return i == x.i; }
  void inc() { ++i; }
  void dec() { --i; }
  void adv(int n) { i += n; }
  int dist_to(map_iter const& x) const { return int(x.i - i); }
};

template <class I, class F>
struct filter_iter
    : iter_base<filter_iter<I, F>,
                common_type_t<typename iterator_traits<I>::iterator_category,
                              bidirectional_iterator_tag>,
                typename iterator_traits<I>::reference> {
  I i, e;
  [[no_unique_address]] F f;
  explicit filter_iter(I i, I e, F f) : i(move(i)), e(move(e)), f(move(f)) {}
  decltype(auto) deref() const { return *i; }
  bool eq(filter_iter const& x) const { return i == x.i; }
  void inc() {
    do {
      ++i;
    } while (i != e && !invoke(f, *i));
  }
  void dec() {
    do {
      --i;
    } while (!invoke(f, *i));
  }
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

template <class R, class F>
auto mapped(R& r, F f) {
  return range(map_iter(begin(r), f), map_iter(end(r), f));
}

template <class I, class F>
auto mapped(range<I>&& r, F f) {
  return mapped(r, move(f));
}

template <int N, class R>
auto elements(R&& r) {
  return mapped(forward<R>(r), []<class T>(T&& x) -> decltype(auto) {
    if constexpr (is_reference_v<T>) {
      return get<N>(x);
    } else {
      return static_cast<remove_cv_t<tuple_element_t<N, T>>>(get<N>(x));
    }
  });
}

template <class R, class F>
auto filtered(R& r, F f) {
  auto i = begin(r);
  while (i != end(r) && !invoke(f, *i)) {
    ++i;
  }
  return range(filter_iter(move(i), end(r), f), filter_iter(end(r), end(r), f));
}

template <class I, class F>
auto filtered(range<I>&& r, F f) {
  return filtered(r, move(f));
}

template <class R>
auto rev(R& r) {
  return range(make_reverse_iterator(end(r)), make_reverse_iterator(begin(r)));
}

template <class I>
auto rev(range<I>&& r) {
  return rev(r);
}

template <class R>
auto sz(R&& r) -> decltype(int(size(forward<R>(r)))) {
  return int(size(forward<R>(r)));
}

auto div_floor = [](auto x, auto y) { return x / y - ((x ^ y) < 0 && x % y); };
auto div_ceil = [](auto x, auto y) { return x / y + (0 <= (x ^ y) && x % y); };

template <class T, class N, class Op>
T power1(T x, N n, Op op) {
  assert(1 <= n);
  for (; ~n & 1; n >>= 1) {
    x = op(x, x);
  }
  T ret = x;
  while (n >>= 1) {
    x = op(x, x);
    if (n & 1) {
      ret = op(move(ret), x);
    }
  }
  return ret;
}

template <class T, class N>
T power(T x, N n) {
  if (n == 0) {
    return 1;
  }
  if (n < 0) {
    return 1 / power1(move(x), -n, multiplies{});
  }
  return power1(move(x), n, multiplies{});
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
  if (MULTI_CASES) {
    r7h::scan(t);
  }
  for (int i : r7h::rep(t)) {
    r7h::main(i);
  }
  assert(!r7h::scan(t));
}

#define ALL(c) begin(c), end(c)

namespace r7h {

using i64 = long long;

void main(int) {
  int n, m;
  scan(n, m);
  string s;
  scan(s);

  vector<int> ans(n * m);
  vector<int> col(m);
  int gc = 0;

  for (int i : rep(n))
    for (int j : rep(m)) {
      int k = i * m + j;
      if (s[k] & 1) {
        gc += col[j]++ == 0;
      }
      ans[k] = gc;
    }

  vector<int> suff(n * m + 1);
  for (int k : rev(rep(n * m))) {
    suff[k] = (s[k] & 1) + suff[k + 1];
  }

  for (int j : rep(m)) {
    int cur = 0;
    for (int i : rep(n)) {
      int k = i * m + j;
      if (i == 0) {
        cur += 0 < suff[0] - suff[j + 1];
      } else {
        cur += 0 < suff[k - m + 1] - suff[k + 1];
      }
      ans[k] += cur;
    }
  }

  println(ans);
}

}  // namespace r7h