#define MULTI_CASES 0
#define INTERACTIVE 0
#define USE_INT 1

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
  []<class... Ts_>(Ts_&&... xs_) -> decltype(FN(static_cast<Ts_&&>(xs_)...)) { \
    return FN(static_cast<Ts_&&>(xs_)...); \
  }

#define LAMBDA(...) \
  [&]<class T1_ = void*, class T2_ = void*>([[maybe_unused]] T1_&& _1 = nullptr, [[maybe_unused]] T2_&& _2 = nullptr) \
      -> decltype(__VA_ARGS__) { \
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

struct left_shift {
  template <class T1, class T2>
  auto operator()(T1&& x, T2&& y) const -> decltype(forward<T1>(x) << forward<T2>(y)) {
    return forward<T1>(x) << forward<T2>(y);
  }
};

struct right_shift {
  template <class T1, class T2>
  auto operator()(T1&& x, T2&& y) const -> decltype(forward<T1>(x) >> forward<T2>(y)) {
    return forward<T1>(x) >> forward<T2>(y);
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
auto const is_lambda_expr = is_placeholder_v<D> || is_bind_expression_v<D>;

#define UNARY_LAMBDA(OP, FN) \
  template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr> \
  auto operator OP(T&& x) { \
    return bind(FN(), ref_or_move<T>(x)); \
  }

#define BINARY_LAMBDA(OP, FN) \
  template <class T1, class T2, enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP(T1&& x, T2&& y) { \
    return bind(FN(), ref_or_move<T1>(x), ref_or_move<T2>(y)); \
  }

UNARY_LAMBDA(-, negate)
BINARY_LAMBDA(+, plus)
BINARY_LAMBDA(-, minus)
BINARY_LAMBDA(*, multiplies)
BINARY_LAMBDA(/, divides)
BINARY_LAMBDA(%, modulus)

UNARY_LAMBDA(~, bit_not)
BINARY_LAMBDA(&, bit_and)
BINARY_LAMBDA(|, bit_or)
BINARY_LAMBDA(^, bit_xor)
BINARY_LAMBDA(<<, left_shift)
BINARY_LAMBDA(>>, right_shift)

BINARY_LAMBDA(==, equal_to)
BINARY_LAMBDA(!=, not_equal_to)
BINARY_LAMBDA(<, less)
BINARY_LAMBDA(>, greater)
BINARY_LAMBDA(<=, less_equal)
BINARY_LAMBDA(>=, greater_equal)

UNARY_LAMBDA(!, logical_not)
BINARY_LAMBDA(&&, logical_and)
BINARY_LAMBDA(||, logical_or)

#undef UNARY_LAMBDA
#undef BINARY_LAMBDA

#define ASSIGN_LAMBDA(OP) \
  template <class T1, class T2, enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP##=(T1&& x, T2&& y) { \
    auto f = []<class T1_, class T2_>(T1_&& x_, T2_&& y_) -> decltype(forward<T1_>(x_) OP##= forward<T2_>(y_)) { \
      return forward<T1_>(x_) OP##= forward<T2_>(y_); \
    }; \
    return bind(move(f), ref_or_move<T1>(x), ref_or_move<T2>(y)); \
  }

ASSIGN_LAMBDA(+)
ASSIGN_LAMBDA(-)
ASSIGN_LAMBDA(*)
ASSIGN_LAMBDA(/)
ASSIGN_LAMBDA(%)
ASSIGN_LAMBDA(&)
ASSIGN_LAMBDA(|)
ASSIGN_LAMBDA(^)
ASSIGN_LAMBDA(<<)
ASSIGN_LAMBDA(>>)

#undef ASSIGN_LAMBDA

using namespace placeholders;

namespace scan_impl {

#if INTERACTIVE || LOCAL

bool scan(char& c) { return scanf(" %c", &c) != EOF; }

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  s = c;
  while (true) {
    c = char(getchar());
    if (' ' < c) {
      s += c;
    } else {
      ungetc(c, stdin);
      break;
    }
  }
  return true;
}

template <class T, enable_if_t<is_integral_v<T>>* = nullptr>
bool scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  auto u = make_unsigned_t<common_type_t<T, int>>((c == '-' ? getchar() : c) & 15);
  while (true) {
    if (auto t = getchar(); '0' <= t && t <= '9') {
      (u *= 10) += t & 15;
    } else {
      ungetc(t, stdin);
      break;
    }
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
bool scan(T& x) {
  if constexpr (is_same_v<T, float>) {
    return scanf("%f", &x) != EOF;
  } else if constexpr (is_same_v<T, double>) {
    return scanf("%lf", &x) != EOF;
  } else {
    return scanf("%Lf", &x) != EOF;
  }
}

#else

char buf[1 << 15];
auto ptr = buf;
auto last = buf;

bool scan(char& c) {
  while (true) {
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
    ++ptr;
  }
}

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  s = c;
  while (' ' < *ptr) {
    scan(c);
    s += c;
  }
  return true;
}

template <class T, enable_if_t<is_integral_v<T>>* = nullptr>
bool scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  auto u = make_unsigned_t<common_type_t<T, int>>((c == '-' ? *ptr++ : c) & 15);
  while ('0' <= *ptr && *ptr <= '9') { (u *= 10) += *ptr++ & 15; }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
bool scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  --ptr;
  if constexpr (is_same_v<T, float>) {
    x = strtof(ptr, &ptr);
  } else if constexpr (is_same_v<T, double>) {
    x = strtod(ptr, &ptr);
  } else {
    x = strtold(ptr, &ptr);
  }
  return true;
}

#endif

template <class T1, class T2>
bool scan(pair<T1, T2>&);

template <class... Ts>
bool scan(tuple<Ts...>&);

template <class R>
auto scan(R&& r) -> decltype(begin(r), end(r), true) {
  return all_of(begin(r), end(r), LIFT(scan));
}

template <class... Ts, enable_if_t<sizeof...(Ts) != 1>* = nullptr>
bool scan(Ts&&... xs) {
  return (... && scan(forward<Ts>(xs)));
}

template <class T1, class T2>
bool scan(pair<T1, T2>& p) {
  return scan(p.first, p.second);
}

template <class... Ts>
bool scan(tuple<Ts...>& t) {
  return apply(LIFT(scan), t);
}

}  // namespace scan_impl

using scan_impl::scan;

template <class T = int, class... Args>
T input(Args&&... args) {
  auto ret = T(forward<Args>(args)...);
  [[maybe_unused]] auto res = scan(ret);
  assert(res);
  return ret;
}

namespace print_impl {

#if INTERACTIVE || LOCAL

template <char = 0>
void print(char c) {
  if (c) { putchar(c); }
  if (c == '\n') { fflush(stdout); }
}

template <char = 0, class T, enable_if_t<is_integral_v<T>>* = nullptr>
void print(T x) {
  char buf[64];
  auto ptr = to_chars(buf, end(buf), x).ptr;
  for_each(buf, ptr, LIFT(print));
}

template <char = 0, class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
void print(T x) {
  if constexpr (is_same_v<T, float>) {
    printf("%.6f", x);
  } else if constexpr (is_same_v<T, double>) {
    printf("%.15f", x);
  } else {
    printf("%.18Lf", x);
  }
}

#else

char buf[1 << 15];
auto ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) { abort(); }
  ptr = buf;
}

template <char = 0>
void print(char c) {
  if (end(buf) - ptr < 64) { flush(); }
  if (c) { *ptr++ = c; }
}

template <char = 0, class T, enable_if_t<is_integral_v<T>>* = nullptr>
void print(T x) {
  print('\0');
  ptr = to_chars(ptr, end(buf), x).ptr;
}

template <char = 0, class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
void print(T x) {
  print('\0');
  if constexpr (is_same_v<T, float>) {
    ptr += snprintf(ptr, end(buf) - ptr, "%.6f", x);
  } else if constexpr (is_same_v<T, double>) {
    ptr += snprintf(ptr, end(buf) - ptr, "%.15f", x);
  } else {
    ptr += snprintf(ptr, end(buf) - ptr, "%.18Lf", x);
  }
}

#endif

template <char Sep = ' ', class T1, class T2>
void print(pair<T1, T2> const&);

template <char Sep = ' ', class... Ts>
void print(tuple<Ts...> const&);

template <char Sep = ' ', class R>
auto print(R&& r) -> void_t<decltype(begin(r), end(r))> {
  [[maybe_unused]] auto c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) { print(exchange(c, Sep)); }
    print(e);
  }
}

template <char = 0>
void print(char const* s) {
  print(string_view(s));
}

template <char Sep = ' ', class... Ts, enable_if_t<sizeof...(Ts) != 1>* = nullptr>
void print(Ts&&... xs) {
  [[maybe_unused]] auto c = '\0';
  (..., (print(exchange(c, Sep)), print(forward<Ts>(xs))));
}

template <char Sep, class T1, class T2>
void print(pair<T1, T2> const& p) {
  print<Sep>(p.first, p.second);
}

template <char Sep, class... Ts>
void print(tuple<Ts...> const& t) {
  apply(LIFT(print<Sep>), t);
}

}  // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts>
void println(Ts&&... xs) {
  print<Sep>(forward<Ts>(xs)...);
  print(End);
}

#if USE_INT
using ptrdiff_t = int;
#endif

using i8 = signed char;
using u8 = unsigned char;
using i16 = short int;
using u16 = unsigned short int;
using i32 = int;
using u32 = unsigned int;
using i64 = long long int;
using u64 = unsigned long long int;
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

template <class T, int D = 1, enable_if_t<1 <= D>* = nullptr>
class vla {
  array<ptrdiff_t, D> len;
  T* dat;

 public:
  vla() = default;
  explicit vla(array<ptrdiff_t, D> n) : len(n) {
    partial_sum(rbegin(len), rend(len), rbegin(len), multiplies());
    dat = new T[len[0]];
  }
  explicit vla(array<ptrdiff_t, D> n, T const& val) : vla(n) { fill_n(dat, len[0], val); }
  vla(vla const& x) : len(x.len), dat(new T[len[0]]) { copy_n(x.dat, len[0], dat); }
  vla(vla&& x) noexcept : vla() { *this = move(x); }

  template <int D_ = D, enable_if_t<D_ == 1>* = nullptr>
  explicit vla(ptrdiff_t n) : vla(array{n}) {}

  template <int D_ = D, enable_if_t<D_ == 1>* = nullptr>
  explicit vla(ptrdiff_t n, T const& val) : vla(array{n}, val) {}

  vla& operator=(vla const& x) & { return *this = vla(x); }
  vla& operator=(vla&& x) & noexcept {
    swap(len, x.len);
    swap(dat, x.dat);
    return *this;
  }

  ~vla() { delete[] dat; }

  bool check(ptrdiff_t i) const { return 0 <= i && i < len[0]; }
  T& operator[](ptrdiff_t i) & {
    assert(check(i));
    return dat[i];
  }
  T const& operator[](ptrdiff_t i) const& {
    assert(check(i));
    return dat[i];
  }
  T operator[](ptrdiff_t i) && {
    assert(check(i));
    return move(dat[i]);
  }

  bool check(array<ptrdiff_t, D> i) const {
    for (auto d = 0; d + 1 < D; ++d) {
      if (i[d] < 0) { return false; }
      if (len[d] <= i[d] * len[d + 1]) { return false; }
    }
    return 0 <= i.back() && i.back() < len.back();
  }
  ptrdiff_t flatten(array<ptrdiff_t, D> i) const {
    assert(check(i));
    return inner_product(i.begin(), i.end() - 1, len.begin() + 1, i.back());
  }
  T& operator[](array<ptrdiff_t, D> i) & { return dat[flatten(i)]; }
  T const& operator[](array<ptrdiff_t, D> i) const& { return dat[flatten(i)]; }
  T operator[](array<ptrdiff_t, D> i) && { return move(dat[flatten(i)]); }

  T* begin() & { return dat; }
  T const* begin() const& { return dat; }
  T* end() & { return dat + len[0]; }
  T const* end() const& { return dat + len[0]; }
  ptrdiff_t size() const { return len[0]; }
};

template <class T>
auto operator++(T& x, int) -> decltype(++x, T(x)) {
  auto ret = x;
  ++x;
  return ret;
}

template <class T>
auto operator--(T& x, int) -> decltype(--x, T(x)) {
  auto ret = x;
  --x;
  return ret;
}

#define BINARY_ARITH_OP(OP) \
  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(declval<T&>() OP##= y, T(x)) { \
    auto ret = T(x); \
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
  D& derived() & { return static_cast<D&>(*this); }
  D const& derived() const& { return static_cast<D const&>(*this); }
  bool equal(D const& x) const { return derived().equal(x); }
  ptrdiff_t dist_to(D const& x) const { return derived().dist_to(x); }

 public:
  using iterator_category = C;
  using value_type = decay_t<R>;
  using difference_type = ptrdiff_t;
  using pointer = void;
  using reference = R;

#define REQUIRE(CATEGORY) template <class C_ = C, enable_if_t<is_convertible_v<C_, CATEGORY##_iterator_tag>>* = nullptr>

  R operator*() const { return derived().deref(); }
  REQUIRE(random_access) R operator[](ptrdiff_t n) const { return *(derived() + n); }

  D& operator++() & {
    derived().inc();
    return derived();
  }
  REQUIRE(bidirectional) D& operator--() & {
    derived().dec();
    return derived();
  }
  REQUIRE(random_access) D& operator+=(ptrdiff_t n) & {
    derived().advance(n);
    return derived();
  }
  REQUIRE(random_access) D& operator-=(ptrdiff_t n) & {
    derived().advance(-n);
    return derived();
  }

  REQUIRE(random_access) friend D operator+(D const& x, ptrdiff_t n) {
    auto ret = x;
    ret += n;
    return ret;
  }
  REQUIRE(random_access) friend D operator+(ptrdiff_t n, D const& x) { return x + n; }
  REQUIRE(random_access) friend D operator-(D const& x, ptrdiff_t n) {
    auto ret = x;
    ret -= n;
    return ret;
  }
  REQUIRE(random_access) friend ptrdiff_t operator-(D const& x, D const& y) {
    return static_cast<iter_base const&>(y).dist_to(x);
  }

  friend bool operator==(D const& x, D const& y) { return static_cast<iter_base const&>(x).equal(y); }
  REQUIRE(random_access) friend bool operator<(D const& x, D const& y) { return x - y < 0; }

#undef REQUIRE
};

template <class T>
class int_iter : public iter_base<int_iter<T>, random_access_iterator_tag, T> {
  friend class int_iter::iter_base;

  T v;

  T deref() const { return v; }
  bool equal(int_iter const& x) const { return v == x.v; }
  void inc() & { ++v; }
  void dec() & { --v; }
  void advance(ptrdiff_t n) & { v += T(n); }
  ptrdiff_t dist_to(int_iter const& x) const { return make_signed_t<T>(x.v - v); }

 public:
  int_iter() = default;
  explicit int_iter(T v) : v(v) {}
};

template <class R>
auto sz(R&& r) -> decltype(ptrdiff_t(size(forward<R>(r)))) {
  return ptrdiff_t(size(forward<R>(r)));
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
auto const inf_v = T(numeric_limits<T>::max() / 2);

auto const inf = inf_v<int>;

auto mt = mt19937_64(LOCAL ? 5489 : _rdtsc());

template <class T>
T rand(T a, T b) {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution(a, b)(mt);
  } else {
    return uniform_real_distribution(a, b)(mt);
  }
}

template <class>
class view_base;

template <class R>
using iter_t = decltype(begin(declval<R const&>()));

template <class R>
using range_cat = typename iterator_traits<iter_t<R>>::iterator_category;

template <class R>
using range_ref = typename iterator_traits<iter_t<R>>::reference;

#define REQUIRE(I, CATEGORY) \
  enable_if_t<is_convertible_v<typename iterator_traits<I>::iterator_category, CATEGORY##_iterator_tag>>* = nullptr

template <class R, class F, REQUIRE(iter_t<R>, input)>
class filtered : public view_base<filtered<R, F>> {
  friend class filtered::view_base;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, bidirectional_iterator_tag>, range_ref<R>> {
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
};

template <class R, class F>
filtered(R&&, F) -> filtered<R, F>;

template <class R, class F, REQUIRE(iter_t<R>, input)>
class mapped : public view_base<mapped<R, F>> {
  friend class mapped::view_base;

  using ref = invoke_result_t<F const&, range_ref<R>>;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, random_access_iterator_tag>, ref> {
    mapped const* p;
    iter_t<R> i;
    ref deref() const { return invoke(p->f, *i); }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & { ++i; }
    void dec() & { --i; }
    void advance(ptrdiff_t n) & { i += n; }
    auto dist_to(iter const& x) const { return ptrdiff_t(x.i - i); }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit mapped(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}

  auto size() const { return sz(r); }
};

template <class R, class F>
mapped(R&&, F) -> mapped<R, F>;

template <class R, REQUIRE(iter_t<R>, input)>
class taken : public view_base<taken<R>> {
  friend class taken::view_base;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, forward_iterator_tag>, range_ref<R>> {
    iter_t<R> i;
    ptrdiff_t n;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return n == x.n; }
    void inc() & {
      --n;
      if (n) { ++i; }
    }
  };

  static auto const is_rand = is_convertible_v<range_cat<R>, random_access_iterator_tag>;

  R r;
  ptrdiff_t n;

  auto b() const {
    if constexpr (is_rand) {
      return begin(r);
    } else {
      return iter{{}, begin(r), n};
    }
  }
  auto e() const {
    if constexpr (is_rand) {
      return begin(r) + size();
    } else {
      return iter{{}, end(r), 0};
    }
  }

 public:
  explicit taken(R&& r, ptrdiff_t n) : r(forward<R>(r)), n(max<ptrdiff_t>(n, 0)) { assert(0 <= n); }

  auto size() const { return min(n, sz(r)); }
};

template <class R>
taken(R&&, ptrdiff_t) -> taken<R>;

template <class R, class F, REQUIRE(iter_t<R>, input)>
class taken_while : public view_base<taken_while<R, F>> {
  friend class taken_while::view_base;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, forward_iterator_tag>, range_ref<R>> {
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

  iter b() const { return {{}, this, begin(r) != end(r) && invoke(f, *begin(r)) ? begin(r) : end(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit taken_while(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
};

template <class R, class F>
taken_while(R&&, F) -> taken_while<R, F>;

template <class R, REQUIRE(iter_t<R>, input)>
class dropped : public view_base<dropped<R>> {
  friend class dropped::view_base;

  R r;
  ptrdiff_t n;

  auto b() const {
    if constexpr (is_convertible_v<range_cat<R>, random_access_iterator_tag>) {
      return begin(r) + min(n, sz(r));
    } else {
      auto ret = begin(r);
      for (auto _ = n; _-- && ret != end(r);) { ++ret; }
      return ret;
    }
  }
  auto e() const { return end(r); }

 public:
  explicit dropped(R&& r, ptrdiff_t n) : r(forward<R>(r)), n(max<ptrdiff_t>(n, 0)) { assert(0 <= n); }

  auto size() const { return max(sz(r), n) - n; }
};

template <class R>
dropped(R&&, ptrdiff_t) -> dropped<R>;

template <class R, class F, REQUIRE(iter_t<R>, input)>
class dropped_while : public view_base<dropped_while<R, F>> {
  friend class dropped_while::view_base;

  R r;
  [[no_unique_address]] F f;

  auto b() const { return find_if_not(begin(r), end(r), ref(f)); }
  auto e() const { return end(r); }

 public:
  explicit dropped_while(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
};

template <class R, class F>
dropped_while(R&&, F) -> dropped_while<R, F>;

template <class R, REQUIRE(iter_t<R>, bidirectional)>
class reversed : public view_base<reversed<R>> {
  friend class reversed::view_base;

  R r;

  auto b() const { return make_reverse_iterator(end(r)); }
  auto e() const { return make_reverse_iterator(begin(r)); }

 public:
  explicit reversed(R&& r) : r(forward<R>(r)) {}

  auto size() const { return sz(r); }
};

template <class R>
reversed(R&&) -> reversed<R>;

template <class R>
reversed(reversed<R>&) -> reversed<reversed<R>&>;

template <class R>
reversed(reversed<R> const&) -> reversed<reversed<R> const&>;

template <class R>
reversed(reversed<R>&&) -> reversed<reversed<R>>;

template <class R, REQUIRE(iter_t<R>, forward), void_t<decltype(sz(declval<R const&>()))>* = nullptr>
class sliced : public view_base<sliced<R>> {
  friend class sliced::view_base;

  R r;
  ptrdiff_t start;
  ptrdiff_t stop;

  auto b() const { return next(begin(r), start); }
  auto e() const { return next(begin(r), stop); }

 public:
  explicit sliced(R&& r, ptrdiff_t start, ptrdiff_t stop) : r(forward<R>(r)) {
    auto n = sz(this->r);
    if (start < 0) { start += n; }
    if (stop < 0) { stop += n; }
    this->start = clamp<ptrdiff_t>(start, 0, n);
    this->stop = clamp(stop, this->start, n);
  }
};

template <class R>
sliced(R&&, ptrdiff_t, ptrdiff_t) -> sliced<R>;

template <class R, REQUIRE(iter_t<R>, input)>
class strided : public view_base<strided<R>> {
  friend class strided::view_base;

  struct iter : iter_base<iter, range_cat<R>, range_ref<R>> {
    strided const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      if constexpr (is_convertible_v<range_cat<R>, random_access_iterator_tag>) {
        i += min(p->s, ptrdiff_t(end(p->r) - i));
      } else {
        for (auto _ = p->s; _-- && i != end(p->r);) { ++i; }
      }
    }
    void dec() & {
      if (i == end(p->r)) {
        auto n = sz(p->r);
        std::advance(i, (n - 1) / p->s * p->s - n);
      } else {
        std::advance(i, -p->s);
      }
    }
    void advance(ptrdiff_t n) & {
      if (n < 0) {
        dec();
        ++n;
      }
      i += min(p->s * n, ptrdiff_t(end(p->r) - i));
    }
    auto dist_to(iter const& x) const {
      auto d = ptrdiff_t(x.i - i);
      return d < 0 ? div_floor(d, p->s) : div_ceil(d, p->s);
    }
  };

  R r;
  ptrdiff_t s;

  iter b() const { return {{}, this, begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit strided(R&& r, ptrdiff_t s) : r(forward<R>(r)), s(max<ptrdiff_t>(s, 1)) { assert(1 <= s); }

  auto size() const { return div_ceil(sz(r), s); }
};

template <class R>
strided(R&&, ptrdiff_t) -> strided<R>;

template <class R, class T, class Op, REQUIRE(iter_t<R>, input)>
class scanned : public view_base<scanned<R, T, Op>> {
  friend class scanned::view_base;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, forward_iterator_tag>, T> {
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

  auto size() const { return sz(r) + 1; }
};

template <class R, class T, class Op>
scanned(R&&, T, Op) -> scanned<R, T, Op>;

template <class R, REQUIRE(iter_t<R>, input), void_t<decltype(sz(declval<R const&>()))>* = nullptr>
class sampled : public view_base<sampled<R>> {
  friend class sampled::view_base;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, input_iterator_tag>, range_ref<R>> {
    iter_t<R> i;
    ptrdiff_t rest;
    ptrdiff_t n;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void skip() & {
      while (rest && n <= rand<ptrdiff_t>(0, --rest)) { ++i; }
      --n;
    }
    void inc() & {
      ++i;
      skip();
    }
  };

  R r;
  ptrdiff_t n;

  iter b() const {
    auto ret = iter{{}, begin(r), sz(r), n};
    ret.skip();
    return ret;
  }
  iter e() const { return {{}, end(r), 0, 0}; }

 public:
  explicit sampled(R&& r, ptrdiff_t n) : r(forward<R>(r)), n(clamp<ptrdiff_t>(n, 0, sz(this->r))) { assert(0 <= n); }

  auto size() const { return min(n, sz(r)); }
};

template <class R>
sampled(R&&, ptrdiff_t) -> sampled<R>;

template <class D>
class view_base {
  D const& derived() const { return static_cast<D const&>(*this); }

 public:
  auto begin() const { return derived().b(); }
  auto end() const { return derived().e(); }
  bool empty() const { return begin() == end(); }
  explicit operator bool() const { return begin() != end(); }
  auto size() const { return ptrdiff_t(end() - begin()); }
  decltype(auto) front() const { return *begin(); }
  decltype(auto) back() const { return *prev(end()); }
  decltype(auto) operator[](ptrdiff_t n) const { return begin()[n]; }

  template <class F>
  auto filter(F f) const& {
    return filtered(derived(), move(f));
  }

  template <class F>
  auto filter(F f) && {
    return filtered(static_cast<D&&>(*this), move(f));
  }

  template <class F>
  auto map(F f) const& {
    return mapped(derived(), move(f));
  }

  template <class F>
  auto map(F f) && {
    return mapped(static_cast<D&&>(*this), move(f));
  }

  template <ptrdiff_t N>
  auto elements() const& {
    return mapped(derived(), LIFT(get<N>));
  }

  template <ptrdiff_t N>
  auto elements() && {
    return mapped(static_cast<D&&>(*this), LIFT(get<N>));
  }

  auto keys() const& { return mapped(derived(), LIFT(get<0>)); }
  auto keys() && { return mapped(static_cast<D&&>(*this), LIFT(get<0>)); }

  auto values() const& { return mapped(derived(), LIFT(get<1>)); }
  auto values() && { return mapped(static_cast<D&&>(*this), LIFT(get<1>)); }

  auto take(ptrdiff_t n) const& { return taken(derived(), n); }
  auto take(ptrdiff_t n) && { return taken(static_cast<D&&>(*this), n); }

  template <class F>
  auto take_while(F f) const& {
    return taken_while(derived(), move(f));
  }

  template <class F>
  auto take_while(F f) && {
    return taken_while(static_cast<D&&>(*this), move(f));
  }

  auto drop(ptrdiff_t n) const& { return dropped(derived(), n); }
  auto drop(ptrdiff_t n) && { return dropped(static_cast<D&&>(*this), n); }

  template <class F>
  auto drop_while(F f) const& {
    return dropped_while(derived(), move(f));
  }

  template <class F>
  auto drop_while(F f) && {
    return dropped_while(static_cast<D&&>(*this), move(f));
  }

  auto rev() const& { return reversed(derived()); }
  auto rev() && { return reversed(static_cast<D&&>(*this)); }

  auto slice(ptrdiff_t l, ptrdiff_t r) const& { return sliced(derived(), l, r); }
  auto slice(ptrdiff_t l, ptrdiff_t r) && { return sliced(static_cast<D&&>(*this), l, r); }

  auto stride(ptrdiff_t s) const& { return strided(derived(), s); }
  auto stride(ptrdiff_t s) && { return strided(static_cast<D&&>(*this), s); }

  template <class T, class Op = plus<>>
  auto scan(T init, Op op = {}) const& {
    return scanned(derived(), move(init), move(op));
  }

  template <class T, class Op = plus<>>
  auto scan(T init, Op op = {}) && {
    return scanned(static_cast<D&&>(*this), move(init), move(op));
  }

  auto sample(ptrdiff_t n) const& { return sampled(derived(), n); }
  auto sample(ptrdiff_t n) && { return sampled(static_cast<D&&>(*this), n); }

  template <class F>
  bool all_of(F f) const {
    return std::all_of(begin(), end(), ref(f));
  }

  template <class F>
  bool any_of(F f) const {
    return std::any_of(begin(), end(), ref(f));
  }

  template <class F>
  D const& each(F f) const {
    for (auto&& e : derived()) {
      if constexpr (is_invocable_v<F&, decltype(e)>) {
        invoke(f, e);
      } else {
        invoke(f);
      }
    }
    return derived();
  }

  template <class F>
  auto find(F f) const {
    return ptrdiff_t(distance(begin(), find_if(begin(), end(), ref(f))));
  }

  template <class F>
  auto adjacent_find(F f) const {
    return ptrdiff_t(distance(begin(), std::adjacent_find(begin(), end(), ref(f))));
  }

  template <class F>
  auto count(F f) const {
    return ptrdiff_t(count_if(begin(), end(), ref(f)));
  }

  template <class F>
  D const& transform(F f) const {
    for (auto&& e : derived()) { e = invoke(f, e); }
    return derived();
  }

  template <class F>
  auto remove(F f) const {
    return ptrdiff_t(distance(begin(), remove_if(begin(), end(), ref(f))));
  }

  D const& reverse() const {
    std::reverse(begin(), end());
    return derived();
  }

  D const& shuffle() const {
    std::shuffle(begin(), end(), mt);
    return derived();
  }

  template <class C = equal_to<>>
  auto unique(C comp = {}) const {
    return ptrdiff_t(distance(begin(), std::unique(begin(), end(), ref(comp))));
  }

  template <class F>
  auto max_right(F f) const {
    return *prev(std::partition_point(next(begin()), end(), ref(f)));
  }

  template <class F>
  auto min_left(F f) const {
    return *std::partition_point(begin(), prev(end()), not_fn(ref(f)));
  }

  template <class C = less<>>
  D const& sort(C comp = {}) const {
    std::sort(begin(), end(), ref(comp));
    return derived();
  }

  template <class T, class C = less<>>
  auto lower_bound(T const& val, C comp = {}) const {
    return ptrdiff_t(distance(begin(), std::lower_bound(begin(), end(), val, ref(comp))));
  }

  template <class T, class C = less<>>
  auto upper_bound(T const& val, C comp = {}) const {
    return ptrdiff_t(distance(begin(), std::upper_bound(begin(), end(), val, ref(comp))));
  }

  template <class T>
  bool binary_search(T const& val) const {
    return std::binary_search(begin(), end(), val);
  }

  auto min() const { return *std::min_element(begin(), end()); }
  auto max() const { return *std::max_element(begin(), end()); }
  auto minmax() const {
    auto [mn, mx] = std::minmax_element(begin(), end());
    return pair(*mn, *mx);
  }
  auto min_element() const { return ptrdiff_t(distance(begin(), std::min_element(begin(), end()))); }
  auto max_element() const { return ptrdiff_t(distance(begin(), std::max_element(begin(), end()))); }
  auto minmax_element() const {
    auto [mn, mx] = std::minmax_element(begin(), end());
    return pair(ptrdiff_t(distance(begin(), mn)), ptrdiff_t(distance(begin(), mx)));
  }

  bool next_permutation() const { return std::next_permutation(begin(), end()); }
  bool prev_permutation() const { return std::prev_permutation(begin(), end()); }

  template <class T, class Op = plus<>>
  T fold(T init, Op op = {}) const {
    return accumulate(begin(), end(), move(init), ref(op));
  }

  template <class Op = plus<>>
  auto fold1(Op op = {}) const {
    return accumulate(next(begin()), end(), front(), ref(op));
  }

  template <template <class...> class C = vector>
  auto to() const {
    return C(begin(), end());
  }

  auto to_vla(bool reverse = false) const {
    auto ret = vla<decay_t<range_ref<D>>>(derived().size());
    if (reverse) {
      copy(begin(), end(), make_reverse_iterator(ret.end()));
    } else {
      copy(begin(), end(), ret.begin());
    }
    return ret;
  }
};

template <class D1, class D2>
bool operator==(view_base<D1> const& x, view_base<D2> const& y) {
  return equal(begin(x), end(x), begin(y), end(y));
}

template <class D1, class D2>
bool operator<(view_base<D1> const& x, view_base<D2> const& y) {
  return lexicographical_compare(begin(x), end(x), begin(y), end(y));
}

template <class R, REQUIRE(iter_t<R>, input)>
class all : public view_base<all<R>> {
  friend class all::view_base;

  R r;

  auto b() const { return begin(r); }
  auto e() const { return end(r); }

 public:
  explicit all(R&& r) : r(forward<R>(r)) {}

  auto size() const { return sz(r); }
};

template <class R>
all(R&&) -> all<R>;

template <class I, REQUIRE(I, input)>
class range : public view_base<range<I>> {
  friend class range::view_base;

  I first;
  I last;

  I b() const { return first; }
  I e() const { return last; }

 public:
  explicit range(I first, I last) : first(move(first)), last(move(last)) {}
};

#undef REQUIRE

template <class T>
auto rep(T l, T r) {
  return range(int_iter(min(l, r)), int_iter(r));
}

template <class T>
auto rep(T n) {
  return rep<T>(0, n);
}

template <class T>
auto rep1(T l, T r) {
  return rep(l, r + 1);
}

template <class T>
auto rep1(T n) {
  return rep1<T>(1, n);
}

template <class G>
class generation : public view_base<generation<G>> {
  friend class generation::view_base;

  using T = decay_t<invoke_result_t<G const&>>;

  struct iter : iter_base<iter, input_iterator_tag, T> {
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

  auto size() const { return numeric_limits<ptrdiff_t>::max(); }
};

template <class T>
auto repeat(T val) {
  return generation([val = move(val)] { return val; });
}

template <class T>
auto rand_view(T a, T b) {
  return generation([a, b] { return rand(a, b); });
}

template <class T, class F>
class iteration : public view_base<iteration<T, F>> {
  friend class iteration::view_base;

  struct iter : iter_base<iter, forward_iterator_tag, T> {
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

  auto size() const { return numeric_limits<ptrdiff_t>::max(); }
};

}  // namespace r7h

int main(int argc, char* argv[]) {
  if (LOCAL && 1 < argc) { r7h::mt.seed(std::stoull(argv[1])); }
  r7h::rep(MULTI_CASES ? r7h::input() : 1).each(r7h::main);
}

void r7h::main(int) {
#define let auto const
  static let di = array{1, 1, 0, -1, -1, -1, 0, 1};
  static let dj = array{0, 1, 1, 1, 0, -1, -1, -1};

  let h = input();
  let w = input();
  auto a = input<vla<int, 2>>(array{h, w});
  auto good = [&](int i, int j) -> bool {
    assert(0 <= i && i + 1 < h);
    assert(0 <= j && j + 1 < w);
    auto t = 0;
    for (let e : all(array{a[{i, j}], a[{i, j + 1}], a[{i + 1, j}], a[{i + 1, j + 1}]}).filter(0 < _1)) {
      if (t && e != t) { return false; }
      t = e;
    }
    return t;
  };
  auto q = queue<array<int, 2>>();
  auto vis = vla<bool, 2>({h, w}, false);
  for (let i : rep(h - 1)) {
    for (let j : rep(w - 1)) {
      if (good(i, j)) {
        vis[{i, j}] = true;
        q.push({i, j});
      }
    }
  }
  auto ans = basic_string<array<int, 3>>();
  while (!empty(q)) {
    let[i, j] = q.front();
    q.pop();
    let c = max({a[{i, j}], a[{i, j + 1}], a[{i + 1, j}], a[{i + 1, j + 1}]});
    if (c) {
      ans += {i + 1, j + 1, c};
      a[{i, j}] = 0;
      a[{i, j + 1}] = 0;
      a[{i + 1, j}] = 0;
      a[{i + 1, j + 1}] = 0;
    }
    for (let z : rep(8)) {
      let ni = i + di[z];
      let nj = j + dj[z];
      if (a.check({ni, nj}) && !vis[{ni, nj}] && a.check({ni + 1, nj + 1}) && good(ni, nj)) {
        vis[{ni, nj}] = true;
        q.push({ni, nj});
      }
    }
  }
  if (all(a).all_of(_1 == 0)) {
    println(sz(ans));
    println<'\n'>(all(ans).rev());
  } else {
    println(-1);
  }
}