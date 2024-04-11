static_assert(R"("
  int n, q;
  scan(n, q);
  vla<int> x(n), w(n);
  for (int i : rep(n)) { scan(x[i], w[i]); }

  auto order = rep(n).to_vla();
  all(order).stable_sort(LAMBDA(w[_1] < w[_2]));

  vla nxt(n, n);
  {
    basic_string<int> s;
    for (int i : rep(n).rev()) {
      while (!empty(s) && !(w[s.back()] < w[i])) { s.pop_back(); }
      if (!empty(s)) { nxt[i] = s.back(); }
      s += i;
    }
  }

  vla prv(n, -1);
  {
    basic_string<int> s;
    for (int i : rep(n)) {
      while (!empty(s) && !(w[s.back()] < w[i])) { s.pop_back(); }
      if (!empty(s)) { prv[i] = s.back(); }
      s += i;
    }
  }

  set<int> se{-1, n};
  vla<basic_string<int>> cand(n);
  for (int i : order) {
    {
      int l = *prev(se.lower_bound(i));
      for (int j = i - 1; l < j; j = prv[j]) { cand[i] += j; }
    }
    {
      int r = *se.upper_bound(i);
      for (int j = i + 1; j < r; j = nxt[j]) { cand[j] += i; }
    }
    se.insert(i);
  }

  vla<int> l(q), r(q);
  vla<basic_string<int>> lst(n + 1);
  for (int t : rep(q)) {
    scan(l[t], r[t]);
    --l[t];
    lst[r[t]] += t;
  }

  segtree::type seg(n);
  vla<i64> ans(q);
  for (int cur_r : rep1(n)) {
    for (int i : cand[cur_r - 1]) {
      int j = cur_r - 1;
      seg.set(i, min(seg.get(i), i64(x[j] - x[i]) * (w[i] + w[j])));
    }
    for (int t : lst[cur_r]) { ans[t] = seg.prod(l[t], n); }
  }
  println<'\n'>(ans);
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
    return bind( \
        []<class T1_, class T2_>(T1_&& x_, T2_&& y_) -> decltype(auto) { return forward<T1_>(x_) OP forward<T2_>(y_); }, \
        ref_or_move<T1>(x), ref_or_move<T2>(y)); \
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

struct identity_int {
  int operator()(int x) const { return x; }
};

template <class T, class F = identity_int>
class vla {
  int n;
  T* a;
  [[no_unique_address]] F f;

 public:
  vla() = default;
  explicit vla(int n, F f = {}) : n(n), a(new T[n]), f(move(f)) {}
  explicit vla(int n, T const& val, F f = {}) : vla(n, move(f)) { fill_n(a, n, val); }
  vla(vla const& x) : vla(x.n, x.f) { copy_n(x.a, n, a); }
  vla(vla&& x) noexcept { *this = move(x); }
  ~vla() { delete[] a; }

  vla& operator=(vla const& x) & { return *this = vla(x); }
  vla& operator=(vla&& x) & noexcept {
    swap(n, x.n);
    swap(a, x.a);
    swap(f, x.f);
    return *this;
  }

  T& operator[](int i) & { return a[i]; }
  T const& operator[](int i) const& { return a[i]; }
  T operator[](int i) && { return move(a[i]); }

  template <class... Ts>
  T& operator()(Ts&&... xs) & {
    return a[f(forward<Ts>(xs)...)];
  }
  template <class... Ts>
  T const& operator()(Ts&&... xs) const& {
    return a[f(forward<Ts>(xs)...)];
  }
  template <class... Ts>
  T operator()(Ts&&... xs) && {
    return move(a[f(forward<Ts>(xs)...)]);
  }

  T* begin() & { return a; }
  T const* begin() const& { return a; }
  T* end() & { return a + n; }
  T const* end() const& { return a + n; }
  int size() const { return n; }
};

template <class T, class F>
auto make_vla(int n, F f) {
  return vla<T, F>(n, move(f));
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
  if (n < 0) { return T{1} / power1(move(x), -n, multiplies()); }
  return power1(move(x), n, multiplies());
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

#define TC(...) template <class __VA_ARGS__>
#define IIT input_iterator_tag
#define FIT forward_iterator_tag
#define BIT bidirectional_iterator_tag
#define RAIT random_access_iterator_tag

TC(D, class C, class R) class iter_base {
  D& derived() & { return static_cast<D&>(*this); }
  D const& derived() const& { return static_cast<D const&>(*this); }

 public:
  using iterator_category = C;
  using value_type = decay_t<R>;
  using difference_type = int;
  using pointer = void;
  using reference = R;

#define REQUIRE(IT) TC(C_ = C, enable_if_t<is_convertible_v<C_, IT>>* = nullptr)

  R operator*() const { return derived().deref(); }
  REQUIRE(RAIT) R operator[](int n) const { return *(derived() + n); }

  D& operator++() & {
    derived().inc();
    return derived();
  }
  REQUIRE(BIT) D& operator--() & {
    derived().dec();
    return derived();
  }
  REQUIRE(RAIT) D& operator+=(int n) & {
    derived().advance(n);
    return derived();
  }
  REQUIRE(RAIT) D& operator-=(int n) & {
    derived().advance(-n);
    return derived();
  }

  REQUIRE(RAIT) friend D operator+(D const& x, int n) {
    D ret = x;
    ret += n;
    return ret;
  }
  REQUIRE(RAIT) friend D operator+(int n, D const& x) { return x + n; }
  REQUIRE(RAIT) friend D operator-(D const& x, int n) {
    D ret = x;
    ret -= n;
    return ret;
  }
  REQUIRE(RAIT) friend int operator-(D const& x, D const& y) { return y.dist_to(x); }

  friend bool operator==(D const& x, D const& y) { return x.equal(y); }
  REQUIRE(RAIT) friend bool operator<(D const& x, D const& y) { return x - y < 0; }

#undef REQUIRE
};

struct int_iter : iter_base<int_iter, RAIT, int> {
  int v;
  int_iter() = default;
  int_iter(int v) : v(v) {}
  int deref() const { return v; }
  bool equal(int_iter const& x) const { return v == x.v; }
  void inc() & { ++v; }
  void dec() & { --v; }
  void advance(int n) & { v += n; }
  int dist_to(int_iter const& x) const { return x.v - v; }
};

template <class R>
auto sz(R&& r) -> decltype(int(size(forward<R>(r)))) {
  return int(size(forward<R>(r)));
}

TC(R) using iter_t = decltype(begin(declval<R const&>()));
TC(R) using range_cat = typename iterator_traits<iter_t<R>>::iterator_category;
TC(R) using range_ref = typename iterator_traits<iter_t<R>>::reference;

TC() class view_base;

#define VIEW(CLS, ...) \
  class CLS : public view_base<CLS<__VA_ARGS__>> { \
    friend class CLS::view_base;
#define VIEW_END(...) \
  __VA_OPT__(int size() const { return __VA_ARGS__; }) \
  };

TC(R, class F)
VIEW(filtered, R, F)
  struct iter : iter_base<iter, common_type_t<range_cat<R>, BIT>, range_ref<R>> {
    filtered const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      do { ++i; } while (i != end(p->r) && !invoke(p->f, *i));
    }
    void dec() & {
      do { --i; } while (!invoke(p->f, *i));
    }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, find_if(begin(r), end(r), ref(f))}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit filtered(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END()

TC(R, class F) filtered(R&&, F) -> filtered<R, F>;

TC(R, class F)
VIEW(mapped, R, F)
  using ref = invoke_result_t<F const&, range_ref<R>>;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, RAIT>, ref> {
    mapped const* p;
    iter_t<R> i;
    ref deref() const { return invoke(p->f, *i); }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & { ++i; }
    void dec() & { --i; }
    void advance(int n) & { i += n; }
    int dist_to(iter const& x) const { return int(x.i - i); }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit mapped(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END(sz(r))

TC(R, class F) mapped(R&&, F) -> mapped<R, F>;

TC(R)
VIEW(taken, R)
  struct iter : iter_base<iter, common_type_t<range_cat<R>, FIT>, range_ref<R>> {
    iter_t<R> i;
    int n;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return n == x.n; }
    void inc() & {
      --n;
      if (n) { ++i; }
    }
  };

  R r;
  int n;

  auto b() const {
    if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
      return begin(r);
    } else {
      return iter{{}, n ? begin(r) : end(r), n};
    }
  }
  auto e() const {
    if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
      return begin(r) + size();
    } else {
      return iter{{}, end(r), 0};
    }
  }

 public:
  explicit taken(R&& r, int n) : r(forward<R>(r)), n(max<int>(n, 0)) { assert(0 <= n); }
VIEW_END(min(n, sz(r)))

TC(R) taken(R&&, int) -> taken<R>;

TC(R, class F)
VIEW(taken_while, R, F)
  static_assert(is_convertible_v<range_cat<R>, FIT>);

  struct iter : iter_base<iter, common_type_t<range_cat<R>, FIT>, range_ref<R>> {
    taken_while const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      ++i;
      if (i != end(p->r) && !invoke(p->f, *i)) { i = end(p->r); }
    }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, begin(r) == end(r) || !invoke(f, *begin(r)) ? end(r) : begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit taken_while(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END()

TC(R, class F) taken_while(R&&, F) -> taken_while<R, F>;

TC(R)
VIEW(dropped, R)
  R r;
  int n;

  auto b() const {
    if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
      return begin(r) + min(n, sz(r));
    } else {
      auto ret = begin(r);
      for (int _ = n; _-- && ret != end(r);) { ++ret; }
      return ret;
    }
  }
  auto e() const { return end(r); }

 public:
  explicit dropped(R&& r, int n) : r(forward<R>(r)), n(max<int>(n, 0)) { assert(0 <= n); }
VIEW_END(max(sz(r), n) - n)

TC(R) dropped(R&&, int) -> dropped<R>;

TC(R, class F)
VIEW(dropped_while, R, F)
  R r;
  [[no_unique_address]] F f;

  auto b() const { return find_if_not(begin(r), end(r), ref(f)); }
  auto e() const { return end(r); }

 public:
  explicit dropped_while(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END()

TC(R, class F) dropped_while(R&&, F) -> dropped_while<R, F>;

TC(R)
VIEW(joined, R)
  using IR = range_ref<R>;
  static_assert(is_convertible_v<range_cat<R>, FIT> && is_convertible_v<range_cat<IR>, FIT>);

  struct iter : iter_base<iter, common_type<range_cat<R>, range_cat<IR>, FIT>, range_ref<IR>> {
    joined const* p;
    iter_t<R> o;
    iter_t<IR> i;
    range_ref<IR> deref() const { return *i; }
    bool equal(iter const& x) const { return o == x.o && i == x.i; }
    void inc() & {
      for (++i; i == end(*o); i = begin(*o)) {
        if (++o == end(p->r)) {
          i = {};
          return;
        }
      }
    }
  };

  R r;

  iter b() const { return {{}, this, begin(r), begin(r) == end(r) ? iter_t<IR>() : begin(*begin(r))}; }
  iter e() const { return {{}, this, end(r), {}}; }

 public:
  explicit joined(R&& r) : r(forward<R>(r)) {}
VIEW_END()

TC(R) joined(R&&) -> joined<R>;

TC(R)
VIEW(reversed, R)
  R r;

  auto b() const { return make_reverse_iterator(end(r)); }
  auto e() const { return make_reverse_iterator(begin(r)); }

 public:
  explicit reversed(R&& r) : r(forward<R>(r)) {}
VIEW_END(sz(r))

TC(R) reversed(R&&) -> reversed<R>;
TC(R) reversed(reversed<R>&) -> reversed<reversed<R>&>;
TC(R) reversed(reversed<R> const&) -> reversed<reversed<R> const&>;
TC(R) reversed(reversed<R>&&) -> reversed<reversed<R>>;

TC(R)
VIEW(sliced, R)
  static_assert(is_convertible_v<range_cat<R>, FIT>);

  R r;
  int start;
  int stop;

  auto b() const { return next(begin(r), start); }
  auto e() const { return next(begin(r), stop); }

 public:
  explicit sliced(R&& r, int start, int stop) : r(forward<R>(r)) {
    int n = sz(this->r);
    if (start < 0) { start += n; }
    if (stop < 0) { stop += n; }
    this->start = clamp<int>(start, 0, n);
    this->stop = clamp(stop, this->start, n);
  }
VIEW_END(stop - start)

TC(R) sliced(R&&, int, int) -> sliced<R>;

TC(R)
VIEW(strided, R)
  struct iter : iter_base<iter, range_cat<R>, range_ref<R>> {
    strided const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
        i += min(p->s, int(end(p->r) - i));
      } else {
        for (int _ = p->s; _-- && i != end(p->r);) { ++i; }
      }
    }
    void dec() & {
      if (i == end(p->r)) {
        int n = sz(p->r);
        std::advance(i, (n - 1) / p->s * p->s - n);
      } else {
        std::advance(i, -p->s);
      }
    }
    void advance(int n) & {
      if (n < 0) {
        dec();
        ++n;
      }
      i += min(p->s * n, int(end(p->r) - i));
    }
    int dist_to(iter const& x) const {
      int d = int(x.i - i);
      return d < 0 ? div_floor(d, p->s) : div_ceil(d, p->s);
    }
  };

  R r;
  int s;

  iter b() const { return {{}, this, begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit strided(R&& r, int s) : r(forward<R>(r)), s(max<int>(s, 1)) { assert(1 <= s); }
VIEW_END(div_ceil(sz(r), s))

TC(R) strided(R&&, int) -> strided<R>;

TC(R, class T, class Op)
VIEW(scanned, R, T, Op)
  static_assert(is_convertible_v<range_cat<R>, FIT>);

  struct iter : iter_base<iter, common_type_t<range_cat<R>, FIT>, T> {
    scanned const* p;
    T v;
    iter_t<R> i;
    T deref() const { return v; }
    bool equal(iter const& x) const { return i == x.i && p == x.p; }
    void inc() & {
      if (i == end(p->r)) {
        p = nullptr;
      } else {
        v = invoke(p->op, move(v), *i);
        ++i;
      }
    }
  };

  R r;
  T init;
  [[no_unique_address]] Op op;

  iter b() const { return {{}, this, init, begin(r)}; }
  iter e() const { return {{}, nullptr, {}, end(r)}; }

 public:
  explicit scanned(R&& r, T init, Op op) : r(forward<R>(r)), init(move(init)), op(move(op)) {}
VIEW_END(sz(r) + 1)

TC(R, class T, class Op) scanned(R&&, T, Op) -> scanned<R, T, Op>;

TC(R)
VIEW(sampled, R)
  struct iter : iter_base<iter, common_type_t<range_cat<R>, IIT>, range_ref<R>> {
    iter_t<R> i;
    int rest;
    int n;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void skip() & {
      while (rest && n <= rand<int>(0, --rest)) { ++i; }
      --n;
    }
    void inc() & {
      ++i;
      skip();
    }
  };

  R r;
  int n;

  iter b() const {
    iter ret{{}, begin(r), sz(r), n};
    ret.skip();
    return ret;
  }
  iter e() const { return {{}, end(r), 0, 0}; }

 public:
  explicit sampled(R&& r, int n) : r(forward<R>(r)), n(clamp<int>(n, 0, sz(this->r))) { assert(0 <= n); }
VIEW_END(min(n, sz(r)))

TC(R) sampled(R&&, int) -> sampled<R>;

TC(D) class view_base {
  D const& derived() const { return static_cast<D const&>(*this); }

 public:
  auto begin() const { return derived().b(); }
  auto end() const { return derived().e(); }
  bool empty() const { return begin() == end(); }
  explicit operator bool() const { return begin() != end(); }
  int size() const { return int(end() - begin()); }
  decltype(auto) front() const { return *begin(); }
  decltype(auto) back() const { return *prev(end()); }
  decltype(auto) operator[](int n) const { return begin()[n]; }

#define WRAP(SIG, CLS, ...) \
  SIG const& { return CLS(derived() __VA_OPT__(,) __VA_ARGS__); } \
  SIG && { return CLS(static_cast<D&&>(*this) __VA_OPT__(,) __VA_ARGS__); }

  WRAP(TC(F) auto filter(F f), filtered, move(f))
  WRAP(TC(F) auto map(F f), mapped, move(f))
  WRAP(template <int N> auto elements(), mapped, LIFT(get<N>))
  WRAP(auto keys(), mapped, LIFT(get<0>))
  WRAP(auto values(), mapped, LIFT(get<1>))
  WRAP(auto take(int n), taken, n)
  WRAP(TC(F) auto take_while(F f), taken_while, move(f))
  WRAP(auto drop(int n), dropped, n)
  WRAP(TC(F) auto drop_while(F f), dropped_while, move(f))
  WRAP(auto join(), joined)
  WRAP(auto rev(), reversed)
  WRAP(auto slice(int l, int r), sliced, l, r)
  WRAP(auto stride(int s), strided, s)
  WRAP(TC(T, class Op = plus<>) auto scan(T init, Op op = {}), scanned, move(init), move(op))
  WRAP(auto sample(int n), sampled, n)

#undef WRAP

#define WRAP(SIG, FN, ...) \
  SIG const { \
    using Res = decltype(std::FN(begin(), end() __VA_OPT__(,) __VA_ARGS__)); \
    if constexpr (is_void_v<Res>) { \
      std::FN(begin(), end() __VA_OPT__(,) __VA_ARGS__); \
      return derived(); \
    } else { \
      auto res = std::FN(begin(), end() __VA_OPT__(,) __VA_ARGS__); \
      if constexpr (is_same_v<decltype(res), iter_t<D>>) { \
        return int(distance(begin(), move(res))); \
      } else { \
        return res; \
      } \
    } \
  }

  WRAP(TC(F) bool all_of(F f), all_of, ref(f))
  WRAP(TC(F) bool any_of(F f), any_of, ref(f))
  WRAP(TC(F) int count(F f), count_if, ref(f))
  WRAP(TC(F) int find(F f), find_if, ref(f))
  WRAP(TC(F) int adjacent_find(F f), adjacent_find, ref(f))

  WRAP(TC(F) int remove(F f), remove_if, ref(f))
  WRAP(D const& reverse(), reverse)
  WRAP(D const& shuffle(), shuffle, mt)
  WRAP(TC(C = equal_to<>) int unique(C comp = {}), unique, ref(comp))

  WRAP(TC(F) bool is_partitioned(F f), is_partitioned, ref(f))
  WRAP(TC(F) int partition(F f), partition, ref(f))
  WRAP(TC(F) int stable_partition(F f), stable_partition, ref(f))
  WRAP(TC(F) int partition_point(F f), partition_point, ref(f))

  WRAP(TC(C = less<>) bool is_sorted(C comp = {}), is_sorted, ref(comp))
  WRAP(TC(C = less<>) int is_sorted_until(C comp = {}), is_sorted_until, ref(comp))
  WRAP(TC(C = less<>) D const& sort(C comp = {}), sort, ref(comp))
  WRAP(TC(C = less<>) D const& stable_sort(C comp = {}), stable_sort, ref(comp))

  WRAP(TC(T, class C = less<>) int lower_bound(T const& val, C comp = {}), lower_bound, val, ref(comp))
  WRAP(TC(T, class C = less<>) int upper_bound(T const& val, C comp = {}), upper_bound, val, ref(comp))
  WRAP(TC(T) bool binary_search(T const& val), binary_search, val)

  WRAP(int min_element(), min_element)
  WRAP(int max_element(), max_element)

  WRAP(bool next_permutation(), next_permutation)
  WRAP(bool prev_permutation(), prev_permutation)

  WRAP(TC(T, class Op = plus<>) T fold(T init, Op op = {}), accumulate, move(init), ref(op))

#undef WRAP

  TC(F) D const& each(F f) const {
    for (auto&& e : derived()) {
      if constexpr (is_invocable_v<F&, decltype(e)>) {
        invoke(f, e);
      } else {
        invoke(f);
      }
    }
    return derived();
  }

  TC(F) auto max_right(F f) const { return *prev(std::partition_point(next(begin()), end(), ref(f))); }
  TC(F) auto min_left(F f) const { return *std::partition_point(begin(), prev(end()), not_fn(ref(f))); }

  TC(Op = plus<>)
  auto fold1(Op op = {}) const { return accumulate(next(begin()), end(), front(), ref(op)); }

  template <TC(...) class C = vector>
  auto to() const {
    return C(begin(), end());
  }

  TC(C) auto to() const { return C(begin(), end()); }

  auto to_vla(bool reverse = false) const {
    vla<decay_t<range_ref<D>>> ret(sz(derived()));
    if (reverse) {
      copy(begin(), end(), make_reverse_iterator(ret.end()));
    } else {
      copy(begin(), end(), ret.begin());
    }
    return ret;
  }
};

TC(D1, class D2) bool operator==(view_base<D1> const& x, view_base<D2> const& y) {
  return equal(begin(x), end(x), begin(y), end(y));
}

TC(D1, class D2) bool operator<(view_base<D1> const& x, view_base<D2> const& y) {
  return lexicographical_compare(begin(x), end(x), begin(y), end(y));
}

TC(R)
VIEW(all, R)
  R r;

  auto b() const { return begin(r); }
  auto e() const { return end(r); }

 public:
  explicit all(R&& r) : r(forward<R>(r)) {}
VIEW_END(sz(r))

TC(R) all(R&&) -> all<R>;
TC(T) all(initializer_list<T>) -> all<initializer_list<T>>;

TC(I)
VIEW(range, I)
  I first;
  I last;

  I b() const { return first; }
  I e() const { return last; }

 public:
  explicit range(I first, I last) : first(move(first)), last(move(last)) {}
VIEW_END()

auto rep(int l, int r) { return range<int_iter>(min(l, r), r); }

auto rep(int n) { return rep(0, n); }

auto rep1(int l, int r) { return rep(l, r + 1); }

auto rep1(int n) { return rep(1, n + 1); }

TC(G)
VIEW(generation, G)
  using T = decay_t<invoke_result_t<G const&>>;

  struct iter : iter_base<iter, IIT, T> {
    generation const* p;
    T v;
    T deref() const { return v; }
    bool equal(iter const& x) const { return p == x.p; }
    void inc() & { v = invoke(p->gen); }
  };

  [[no_unique_address]] G gen;

  iter b() const { return {{}, this, invoke(gen)}; }
  iter e() const { return {{}, nullptr, {}}; }

 public:
  explicit generation(G gen) : gen(move(gen)) {}
VIEW_END(numeric_limits<int>::max())

TC(T) auto repeat(T val) {
  return generation([val = move(val)] { return val; });
}

TC(T) auto rand_view(T a, T b) {
  return generation([a, b] { return rand(a, b); });
}

TC(T, class F)
VIEW(iteration, T, F)
  struct iter : iter_base<iter, FIT, T> {
    iteration const* p;
    T v;
    T deref() const { return v; }
    bool equal(iter const& x) const { return p == x.p; }
    void inc() & { v = invoke(p->f, move(v)); }
  };

  T init;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, init}; }
  iter e() const { return {{}, nullptr, {}}; }

 public:
  explicit iteration(T init, F f) : init(move(init)), f(move(f)) {}
VIEW_END(numeric_limits<int>::max())

#undef TC
#undef IIT
#undef FIT
#undef BIT
#undef RAIT
#undef VIEW
#undef VIEW_END

}  // namespace r7h

int main() {
  int t = 1;
  if (MULTI_CASES) { r7h::scan(t); }
  r7h::rep(t).each(r7h::main);
}

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

namespace r7h::segtree {

i64 op(i64 x, i64 y) { return min(x, y); }
i64 e() { return inf_v<i64>; }
using type = atcoder::segtree<i64, op, e>;

}  // namespace r7h::segtree

void r7h::main(int) {
  int n, q;
  scan(n, q);
  vla<int> x(n), w(n);
  for (int i : rep(n)) { scan(x[i], w[i]); }

  auto order = rep(n).to_vla();
  all(order).stable_sort(LAMBDA(w[_1] < w[_2]));

  vla nxt(n, n);
  {
    basic_string<int> s;
    for (int i : rep(n).rev()) {
      while (!empty(s) && !(w[s.back()] < w[i])) { s.pop_back(); }
      if (!empty(s)) { nxt[i] = s.back(); }
      s += i;
    }
  }

  vla prv(n, -1);
  {
    basic_string<int> s;
    for (int i : rep(n)) {
      while (!empty(s) && !(w[s.back()] < w[i])) { s.pop_back(); }
      if (!empty(s)) { prv[i] = s.back(); }
      s += i;
    }
  }

  set<int> se{-1, n};
  vla<basic_string<int>> cand(n);
  for (int i : order) {
    {
      int l = *prev(se.lower_bound(i));
      for (int j = i - 1; l < j; j = prv[j]) { cand[i] += j; }
    }
    {
      int r = *se.upper_bound(i);
      for (int j = i + 1; j < r; j = nxt[j]) { cand[j] += i; }
    }
    se.insert(i);
  }

  vla<int> l(q), r(q);
  vla<basic_string<int>> lst(n + 1);
  for (int t : rep(q)) {
    scan(l[t], r[t]);
    --l[t];
    lst[r[t]] += t;
  }

  segtree::type seg(n);
  vla<i64> ans(q);
  for (int cur_r : rep1(n)) {
    for (int i : cand[cur_r - 1]) {
      int j = cur_r - 1;
      seg.set(i, min(seg.get(i), i64(x[j] - x[i]) * (w[i] + w[j])));
    }
    for (int t : lst[cur_r]) { ans[t] = seg.prod(l[t], n); }
  }
  println<'\n'>(ans);
}