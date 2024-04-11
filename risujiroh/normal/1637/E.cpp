#define MULTI_CASES 1
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

auto main(int) -> void;

}  // namespace r7h

#if LOCAL
#include <utility/dump.hpp>
#else
#define DUMP(...) void(0)
#endif

namespace r7h {

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

template <int>
struct signed_int;

template <int>
struct unsigned_int;

#define INT_TYPE(N) \
  template <> \
  struct signed_int<N> { \
    using type = i##N; \
  }; \
  template <> \
  struct unsigned_int<N> { \
    using type = u##N; \
  };

INT_TYPE(8)
INT_TYPE(16)
INT_TYPE(32)
INT_TYPE(64)
INT_TYPE(128)

#undef INT_TYPE

template <int N>
using signed_int_t = typename signed_int<N>::type;

template <int N>
using unsigned_int_t = typename unsigned_int<N>::type;

}  // namespace r7h

#define LIFT(...) \
  []<class... Ts_>(Ts_&&... xs_) -> decltype(__VA_ARGS__(::std::forward<Ts_>(xs_)...)) { \
    return __VA_ARGS__(::std::forward<Ts_>(xs_)...); \
  }

#define LAMBDA(...) \
  [&]<class T1_ = void*, class T2_ = void*>([[maybe_unused]] T1_&& _1 = nullptr, [[maybe_unused]] T2_&& _2 = nullptr) \
      -> decltype(__VA_ARGS__) { \
    return __VA_ARGS__; \
  }

namespace r7h {

template <class F>
class fix {
  [[no_unique_address]] F f;

 public:
  explicit fix(F f) : f(move(f)) {}

  template <class... Ts>
  auto operator()(Ts&&... xs) const -> decltype(invoke(f, ref(*this), forward<Ts>(xs)...)) {
    return invoke(f, ref(*this), forward<Ts>(xs)...);
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
auto decay_copy(T&& x) -> decay_t<T> {
  return forward<T>(x);
}

template <class T>
auto ref_or_move(remove_reference_t<T>& x) -> auto {
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
  auto operator OP(T&& x) -> auto { \
    return bind(FN(), ref_or_move<T>(x)); \
  }

#define BINARY_LAMBDA(OP, FN) \
  template <class T1, class T2, enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP(T1&& x, T2&& y) -> auto { \
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

template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr>
auto operator+(T&& x) -> auto {
  return bind([]<class T_>(T_&& x_) -> decltype(+forward<T_>(x_)) { return +forward<T_>(x_); }, ref_or_move<T>(x));
}

template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr>
auto operator++(T&& x) -> auto {
  return bind([]<class T_>(T_&& x_) -> decltype(++forward<T_>(x_)) { return ++forward<T_>(x_); }, ref_or_move<T>(x));
}

template <class T, enable_if_t<is_lambda_expr<T>>* = nullptr>
auto operator--(T&& x) -> auto {
  return bind([]<class T_>(T_&& x_) -> decltype(--forward<T_>(x_)) { return --forward<T_>(x_); }, ref_or_move<T>(x));
}

#define ASSIGN_LAMBDA(OP) \
  template <class T1, class T2, enable_if_t<is_lambda_expr<T1> || is_lambda_expr<T2>>* = nullptr> \
  auto operator OP##=(T1&& x, T2&& y) -> auto { \
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

}  // namespace r7h

namespace r7h {

namespace scan_impl {

#if INTERACTIVE || LOCAL

auto scan(char& c) -> bool { return scanf(" %c", &c) != EOF; }

auto scan(string& s) -> bool {
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
auto scan(T& x) -> bool {
  char c;
  if (!scan(c)) { return false; }
  auto u = make_unsigned_t<common_type_t<T, int>>((c == '-' ? getchar() : c) & 15);
  while (true) {
    if (auto t = getchar(); '0' <= t && t <= '9') {
      u *= 10;
      u += t & 15;
    } else {
      ungetc(t, stdin);
      break;
    }
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
auto scan(T& x) -> bool {
  if constexpr (is_same_v<T, float>) {
    return scanf("%f", &x) != EOF;
  } else if constexpr (is_same_v<T, double>) {
    return scanf("%lf", &x) != EOF;
  } else if constexpr (is_same_v<T, long double>) {
    return scanf("%Lf", &x) != EOF;
  } else {
    static_assert(LAMBDA(false)());
  }
}

#else

char buf[1 << 15];
auto ptr = buf;
auto last = buf;

auto scan(char& c) -> bool {
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

auto scan(string& s) -> bool {
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
auto scan(T& x) -> bool {
  char c;
  if (!scan(c)) { return false; }
  auto u = make_unsigned_t<common_type_t<T, int>>((c == '-' ? *ptr++ : c) & 15);
  while ('0' <= *ptr && *ptr <= '9') {
    u *= 10;
    u += *ptr++ & 15;
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
auto scan(T& x) -> bool {
  char c;
  if (!scan(c)) { return false; }
  --ptr;
  if constexpr (is_same_v<T, float>) {
    x = strtof(ptr, &ptr);
  } else if constexpr (is_same_v<T, double>) {
    x = strtod(ptr, &ptr);
  } else if constexpr (is_same_v<T, long double>) {
    x = strtold(ptr, &ptr);
  } else {
    static_assert(LAMBDA(false)());
  }
  return true;
}

#endif

template <class T1, class T2>
auto scan(pair<T1, T2>&) -> bool;

template <class... Ts>
auto scan(tuple<Ts...>&) -> bool;

template <class R>
auto scan(R&& r) -> decltype(begin(r), end(r), true) {
  return all_of(begin(r), end(r), LIFT(scan));
}

template <class... Ts, enable_if_t<sizeof...(Ts) != 1>* = nullptr>
auto scan(Ts&&... xs) -> bool {
  return (... && scan(forward<Ts>(xs)));
}

template <class T1, class T2>
auto scan(pair<T1, T2>& p) -> bool {
  return scan(p.first, p.second);
}

template <class... Ts>
auto scan(tuple<Ts...>& t) -> bool {
  return apply(LIFT(scan), t);
}

}  // namespace scan_impl

using scan_impl::scan;

template <class T = int, class... Args>
auto input(Args&&... args) -> T {
  auto ret = T(forward<Args>(args)...);
  [[maybe_unused]] auto res = scan(ret);
  assert(res);
  return ret;
}

namespace print_impl {

#if INTERACTIVE || LOCAL

template <char = 0>
auto print(char c) -> void {
  if (c) { putchar(c); }
  if (c == '\n') { fflush(stdout); }
}

template <char = 0, class T, enable_if_t<is_integral_v<T>>* = nullptr>
auto print(T x) -> void {
  char buf[64];
  auto ptr = to_chars(buf, end(buf), x).ptr;
  for_each(buf, ptr, LIFT(print));
}

template <char = 0, class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
auto print(T x) -> void {
  if constexpr (is_same_v<T, float>) {
    printf("%.6f", x);
  } else if constexpr (is_same_v<T, double>) {
    printf("%.15f", x);
  } else if constexpr (is_same_v<T, long double>) {
    printf("%.18Lf", x);
  } else {
    static_assert(LAMBDA(false)());
  }
}

#else

char buf[1 << 15];
auto ptr = buf;

__attribute__((destructor)) auto flush() -> void {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) { abort(); }
  ptr = buf;
}

template <char = 0>
auto print(char c) -> void {
  if (end(buf) - ptr < 64) { flush(); }
  if (c) { *ptr++ = c; }
}

template <char = 0, class T, enable_if_t<is_integral_v<T>>* = nullptr>
auto print(T x) -> void {
  print('\0');
  ptr = to_chars(ptr, end(buf), x).ptr;
}

template <char = 0, class T, enable_if_t<is_floating_point_v<T>>* = nullptr>
auto print(T x) -> void {
  print('\0');
  if constexpr (is_same_v<T, float>) {
    ptr += snprintf(ptr, end(buf) - ptr, "%.6f", x);
  } else if constexpr (is_same_v<T, double>) {
    ptr += snprintf(ptr, end(buf) - ptr, "%.15f", x);
  } else if constexpr (is_same_v<T, long double>) {
    ptr += snprintf(ptr, end(buf) - ptr, "%.18Lf", x);
  } else {
    static_assert(LAMBDA(false)());
  }
}

#endif

template <char Sep = ' ', class T1, class T2>
auto print(pair<T1, T2> const&) -> void;

template <char Sep = ' ', class... Ts>
auto print(tuple<Ts...> const&) -> void;

template <char Sep = ' ', class R>
auto print(R&& r) -> void_t<decltype(begin(r), end(r))> {
  [[maybe_unused]] auto c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) { print(exchange(c, Sep)); }
    print(e);
  }
}

template <char = 0>
auto print(char const* s) -> void {
  print(string_view(s));
}

template <char Sep = ' ', class... Ts, enable_if_t<sizeof...(Ts) != 1>* = nullptr>
auto print(Ts&&... xs) -> void {
  [[maybe_unused]] auto c = '\0';
  (..., (print(exchange(c, Sep)), print(forward<Ts>(xs))));
}

template <char Sep, class T1, class T2>
auto print(pair<T1, T2> const& p) -> void {
  print<Sep>(p.first, p.second);
}

template <char Sep, class... Ts>
auto print(tuple<Ts...> const& t) -> void {
  apply(LIFT(print<Sep>), t);
}

}  // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts>
auto println(Ts&&... xs) -> void {
  print<Sep>(forward<Ts>(xs)...);
  print(End);
}

}  // namespace r7h

namespace r7h {

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
  explicit vla(ptrdiff_t n) : vla(array{n}) {}
  explicit vla(array<ptrdiff_t, D> n, T const& val) : vla(n) { fill_n(dat, len[0], val); }
  explicit vla(ptrdiff_t n, T const& val) : vla(array{n}, val) {}
  vla(vla const& x) : len(x.len), dat(new T[len[0]]) { copy_n(x.dat, len[0], dat); }
  vla(vla&& x) noexcept : vla() { *this = move(x); }

  auto operator=(vla const& x) & -> vla& { return *this = vla(x); }
  auto operator=(vla&& x) & noexcept -> vla& {
    swap(len, x.len);
    swap(dat, x.dat);
    return *this;
  }

  ~vla() { delete[] dat; }

  auto check(ptrdiff_t i) const -> bool { return 0 <= i && i < len[0]; }
  auto operator[](ptrdiff_t i) & -> T& {
    assert(check(i));
    return dat[i];
  }
  auto operator[](ptrdiff_t i) const& -> T const& {
    assert(check(i));
    return dat[i];
  }
  auto operator[](ptrdiff_t i) && -> T {
    assert(check(i));
    return move(dat[i]);
  }

  auto check(array<ptrdiff_t, D> i) const -> bool {
    for (auto d = 0; d + 1 < D; ++d) {
      if (i[d] < 0) { return false; }
      if (len[d] <= i[d] * len[d + 1]) { return false; }
    }
    return 0 <= i.back() && i.back() < len.back();
  }
  auto flatten(array<ptrdiff_t, D> i) const -> ptrdiff_t {
    assert(check(i));
    return inner_product(i.begin(), i.end() - 1, len.begin() + 1, i.back());
  }
  auto operator[](array<ptrdiff_t, D> i) & -> T& { return dat[flatten(i)]; }
  auto operator[](array<ptrdiff_t, D> i) const& -> T const& { return dat[flatten(i)]; }
  auto operator[](array<ptrdiff_t, D> i) && -> T { return move(dat[flatten(i)]); }

  auto begin() & -> T* { return dat; }
  auto begin() const& -> T const* { return dat; }
  auto end() & -> T* { return dat + len[0]; }
  auto end() const& -> T const* { return dat + len[0]; }
  auto size() const -> ptrdiff_t { return len[0]; }
};

}  // namespace r7h

namespace r7h {

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

}  // namespace r7h

namespace r7h {

template <class D, class C, class R>
class iter_base {
  auto derived() & -> D& { return static_cast<D&>(*this); }
  auto derived() const& -> D const& { return static_cast<D const&>(*this); }
  auto equal(D const& x) const -> bool { return derived().equal(x); }
  auto dist_to(D const& x) const -> ptrdiff_t { return derived().dist_to(x); }

 public:
  using iterator_category = C;
  using value_type = decay_t<R>;
  using difference_type = ptrdiff_t;
  using pointer = void;
  using reference = R;

#define REQUIRE(CATEGORY) template <class C_ = C, enable_if_t<is_convertible_v<C_, CATEGORY##_iterator_tag>>* = nullptr>

  auto operator*() const -> R { return derived().deref(); }
  REQUIRE(random_access) auto operator[](ptrdiff_t n) const -> R { return *(derived() + n); }

  auto operator++() & -> D& {
    derived().inc();
    return derived();
  }
  REQUIRE(bidirectional) auto operator--() & -> D& {
    derived().dec();
    return derived();
  }
  REQUIRE(random_access) auto operator+=(ptrdiff_t n) & -> D& {
    derived().advance(n);
    return derived();
  }
  REQUIRE(random_access) auto operator-=(ptrdiff_t n) & -> D& {
    derived().advance(-n);
    return derived();
  }

  REQUIRE(random_access) friend auto operator+(D const& x, ptrdiff_t n) -> D {
    auto ret = x;
    ret += n;
    return ret;
  }
  REQUIRE(random_access) friend auto operator+(ptrdiff_t n, D const& x) -> D { return x + n; }
  REQUIRE(random_access) friend auto operator-(D const& x, ptrdiff_t n) -> D {
    auto ret = x;
    ret -= n;
    return ret;
  }
  REQUIRE(random_access) friend auto operator-(D const& x, D const& y) -> ptrdiff_t {
    return static_cast<iter_base const&>(y).dist_to(x);
  }

  friend auto operator==(D const& x, D const& y) -> bool { return static_cast<iter_base const&>(x).equal(y); }
  REQUIRE(random_access) friend auto operator<(D const& x, D const& y) -> bool { return x - y < 0; }

#undef REQUIRE
};

template <class T, enable_if_t<is_integral_v<T>>* = nullptr>
class int_iter : public iter_base<int_iter<T>, random_access_iterator_tag, T> {
  friend class int_iter::iter_base;

  T v;

  auto deref() const -> T { return v; }
  auto equal(int_iter const& x) const -> bool { return v == x.v; }
  auto inc() & -> void { ++v; }
  auto dec() & -> void { --v; }
  auto advance(ptrdiff_t n) & -> void { v += T(n); }
  auto dist_to(int_iter const& x) const -> ptrdiff_t { return make_signed_t<T>(x.v - v); }

 public:
  int_iter() = default;
  explicit int_iter(T v) : v(v) {}
};

template <class R>
auto sz(R&& r) -> decltype(ptrdiff_t(size(forward<R>(r)))) {
  return ptrdiff_t(size(forward<R>(r)));
}

}  // namespace r7h

namespace r7h {

template <class T, enable_if_t<is_integral_v<T>>* = nullptr>
auto div_floor(T x, T y) -> T {
  return T(x / y - ((x ^ y) < 0 && x % y));
}

template <class T, enable_if_t<is_integral_v<T>>* = nullptr>
auto div_ceil(T x, T y) -> T {
  return T(x / y + (0 <= (x ^ y) && x % y));
}

template <class T, class U = T>
auto chmin(T& x, U&& y) -> decltype(x = forward<U>(y), bool(y < x)) {
  if (y < x) {
    x = forward<U>(y);
    return true;
  } else {
    return false;
  }
}

template <class T, class U = T>
auto chmax(T& x, U&& y) -> decltype(x = forward<U>(y), bool(x < y)) {
  if (x < y) {
    x = forward<U>(y);
    return true;
  } else {
    return false;
  }
}

template <class T, enable_if_t<is_arithmetic_v<T>>* = nullptr>
auto const inf_v = T(numeric_limits<T>::max() / 2);

auto const inf = inf_v<int>;

}  // namespace r7h

namespace r7h {

auto mt = mt19937_64(LOCAL ? 5489 : _rdtsc());

template <class T, enable_if_t<is_arithmetic_v<T>>* = nullptr>
auto rand(T a, T b) -> T {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution(a, b)(mt);
  } else {
    return uniform_real_distribution(a, b)(mt);
  }
}

}  // namespace r7h

namespace r7h {

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

  class iter : public iter_base<iter, common_type_t<range_cat<R>, bidirectional_iterator_tag>, range_ref<R>> {
    friend class iter::iter_base;

    filtered const* p;
    iter_t<R> i;

    auto deref() const -> range_ref<R> { return *i; }
    auto equal(iter const& x) const -> bool { return i == x.i; }
    auto inc() & -> void {
      do { ++i; } while (i != end(p->r) && !invoke(p->f, *i));
    }
    auto dec() & -> void {
      do { --i; } while (!invoke(p->f, *i));
    }

   public:
    iter() = default;
    explicit iter(filtered const* p, iter_t<R> i) : p(p), i(move(i)) {}
  };

  R r;
  [[no_unique_address]] F f;

  auto b() const -> iter { return iter(this, find_if(begin(r), end(r), ref(f))); }
  auto e() const -> iter { return iter(this, end(r)); }

 public:
  explicit filtered(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
};

template <class R, class F>
filtered(R&&, F) -> filtered<R, F>;

template <class R, class F, REQUIRE(iter_t<R>, input)>
class mapped : public view_base<mapped<R, F>> {
  friend class mapped::view_base;

  using ref = invoke_result_t<F const&, range_ref<R>>;

  class iter : public iter_base<iter, common_type_t<range_cat<R>, random_access_iterator_tag>, ref> {
    friend class iter::iter_base;

    mapped const* p;
    iter_t<R> i;

    auto deref() const -> ref { return invoke(p->f, *i); }
    auto equal(iter const& x) const -> bool { return i == x.i; }
    auto inc() & -> void { ++i; }
    auto dec() & -> void { --i; }
    auto advance(ptrdiff_t n) & -> void { i += n; }
    auto dist_to(iter const& x) const -> ptrdiff_t { return x.i - i; }

   public:
    iter() = default;
    explicit iter(mapped const* p, iter_t<R> i) : p(p), i(move(i)) {}
  };

  R r;
  [[no_unique_address]] F f;

  auto b() const -> iter { return iter(this, begin(r)); }
  auto e() const -> iter { return iter(this, end(r)); }

 public:
  explicit mapped(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}

  auto size() const -> ptrdiff_t { return sz(r); }
};

template <class R, class F>
mapped(R&&, F) -> mapped<R, F>;

template <class R, REQUIRE(iter_t<R>, input)>
class taken : public view_base<taken<R>> {
  friend class taken::view_base;

  class iter : public iter_base<iter, range_cat<R>, range_ref<R>> {
    friend class iter::iter_base;

    taken const* p;
    iter_t<R> i;
    ptrdiff_t pos;

    auto deref() const -> range_ref<R> { return *i; }
    auto equal(iter const& x) const -> bool { return i == x.i; }
    auto inc() & -> void {
      ++i;
      ++pos;
      if (pos == p->n) { i = end(p->r); }
    }
    auto dec() & -> void {
      --i;
      --pos;
    }

   public:
    iter() = default;
    explicit iter(taken const* p, iter_t<R> i, ptrdiff_t pos) : p(p), i(pos == p->n ? end(p->r) : move(i)), pos(pos) {}
  };

  static auto const is_rand = is_convertible_v<range_cat<R>, random_access_iterator_tag>;

  R r;
  ptrdiff_t n;

  auto b() const -> conditional_t<is_rand, iter_t<R>, iter> {
    if constexpr (is_rand) {
      return begin(r);
    } else {
      return iter(this, begin(r), 0);
    }
  }
  auto e() const -> conditional_t<is_rand, iter_t<R>, iter> {
    if constexpr (is_rand) {
      return begin(r) + size();
    } else {
      return iter(this, end(r), -1);
    }
  }

 public:
  explicit taken(R&& r, ptrdiff_t n) : r(forward<R>(r)), n(max(n, ptrdiff_t(0))) { assert(0 <= n); }

  auto size() const -> ptrdiff_t { return min(n, sz(r)); }
};

template <class R>
taken(R&&, ptrdiff_t) -> taken<R>;

template <class R, REQUIRE(iter_t<R>, input)>
class dropped : public view_base<dropped<R>> {
  friend class dropped::view_base;

  R r;
  ptrdiff_t n;

  auto b() const -> iter_t<R> {
    if constexpr (is_convertible_v<range_cat<R>, random_access_iterator_tag>) {
      return begin(r) + min(n, sz(r));
    } else {
      auto ret = begin(r);
      for (auto _ = n; _-- && ret != end(r);) { ++ret; }
      return ret;
    }
  }
  auto e() const -> iter_t<R> { return end(r); }

 public:
  explicit dropped(R&& r, ptrdiff_t n) : r(forward<R>(r)), n(max(n, ptrdiff_t(0))) { assert(0 <= n); }

  auto size() const -> ptrdiff_t { return max(sz(r), n) - n; }
};

template <class R>
dropped(R&&, ptrdiff_t) -> dropped<R>;

template <class R, REQUIRE(iter_t<R>, bidirectional)>
class reversed : public view_base<reversed<R>> {
  friend class reversed::view_base;

  R r;

  auto b() const -> reverse_iterator<iter_t<R>> { return make_reverse_iterator(end(r)); }
  auto e() const -> reverse_iterator<iter_t<R>> { return make_reverse_iterator(begin(r)); }

 public:
  explicit reversed(R&& r) : r(forward<R>(r)) {}

  auto size() const -> ptrdiff_t { return sz(r); }
};

template <class R>
reversed(R&&) -> reversed<R>;

template <class R>
reversed(reversed<R>&) -> reversed<reversed<R>&>;

template <class R>
reversed(reversed<R> const&) -> reversed<reversed<R> const&>;

template <class R>
reversed(reversed<R>&&) -> reversed<reversed<R>>;

template <class R, REQUIRE(iter_t<R>, input)>
class strided : public view_base<strided<R>> {
  friend class strided::view_base;

  class iter : public iter_base<iter, range_cat<R>, range_ref<R>> {
    friend class iter::iter_base;

    strided const* p;
    iter_t<R> i;

    auto deref() const -> range_ref<R> { return *i; }
    auto equal(iter const& x) const -> bool { return i == x.i; }
    auto inc() & -> void {
      if constexpr (is_convertible_v<range_cat<R>, random_access_iterator_tag>) {
        i += min(p->s, ptrdiff_t(end(p->r) - i));
      } else {
        for (auto _ = p->s; _-- && i != end(p->r);) { ++i; }
      }
    }
    auto dec() & -> void {
      if (i == end(p->r)) {
        auto n = sz(p->r);
        std::advance(i, (n - 1) / p->s * p->s - n);
      } else {
        std::advance(i, -p->s);
      }
    }
    auto advance(ptrdiff_t n) & -> void {
      if (n < 0) {
        dec();
        ++n;
      }
      i += min(p->s * n, ptrdiff_t(end(p->r) - i));
    }
    auto dist_to(iter const& x) const -> ptrdiff_t {
      auto d = ptrdiff_t(x.i - i);
      return d < 0 ? div_floor(d, p->s) : div_ceil(d, p->s);
    }

   public:
    iter() = default;
    explicit iter(strided const* p, iter_t<R> i) : p(p), i(move(i)) {}
  };

  R r;
  ptrdiff_t s;

  auto b() const -> iter { return iter(this, begin(r)); }
  auto e() const -> iter { return iter(this, end(r)); }

 public:
  explicit strided(R&& r, ptrdiff_t s) : r(forward<R>(r)), s(max(s, ptrdiff_t(1))) { assert(1 <= s); }

  auto size() const -> ptrdiff_t { return div_ceil(sz(r), s); }
};

template <class R>
strided(R&&, ptrdiff_t) -> strided<R>;

template <class R, class T, class Op, REQUIRE(iter_t<R>, input)>
class scanned : public view_base<scanned<R, T, Op>> {
  friend class scanned::view_base;

  class iter : public iter_base<iter, common_type_t<range_cat<R>, forward_iterator_tag>, T> {
    friend class iter::iter_base;

    scanned const* p;
    T v;
    iter_t<R> i;
    bool past;

    auto deref() const -> T { return v; }
    auto equal(iter const& x) const -> bool { return i == x.i && past == x.past; }
    auto inc() & -> void {
      if (i == end(p->r)) {
        past = true;
      } else {
        v = invoke(p->op, move(v), *i);
        ++i;
      }
    }

   public:
    iter() = default;
    explicit iter(scanned const* p, T v, iter_t<R> i, bool past) : p(p), v(move(v)), i(move(i)), past(past) {}
  };

  R r;
  T init;
  [[no_unique_address]] Op op;

  auto b() const -> iter { return iter(this, init, begin(r), false); }
  auto e() const -> iter { return iter(this, T(), end(r), true); }

 public:
  explicit scanned(R&& r, T init, Op op) : r(forward<R>(r)), init(move(init)), op(move(op)) {}

  auto size() const -> ptrdiff_t { return sz(r) + 1; }
};

template <class R, class T, class Op>
scanned(R&&, T, Op) -> scanned<R, T, Op>;

template <class D>
class view_base {
  auto derived() const -> D const& { return static_cast<D const&>(*this); }

 public:
  auto begin() const -> auto { return derived().b(); }
  auto end() const -> auto { return derived().e(); }
  auto empty() const -> bool { return begin() == end(); }
  explicit operator bool() const { return begin() != end(); }
  auto size() const -> ptrdiff_t { return ptrdiff_t(end() - begin()); }
  auto front() const -> decltype(auto) { return *begin(); }
  auto back() const -> decltype(auto) { return *prev(end()); }
  auto operator[](ptrdiff_t n) const -> decltype(auto) { return begin()[n]; }

  template <class F>
  auto filter(F f) const& -> auto {
    return filtered(derived(), move(f));
  }

  template <class F>
  auto filter(F f) && -> auto {
    return filtered(static_cast<D&&>(*this), move(f));
  }

  template <class F>
  auto map(F f) const& -> auto {
    return mapped(derived(), move(f));
  }

  template <class F>
  auto map(F f) && -> auto {
    return mapped(static_cast<D&&>(*this), move(f));
  }

  template <ptrdiff_t N>
  auto elements() const& -> auto {
    return mapped(derived(), LIFT(get<N>));
  }

  template <ptrdiff_t N>
  auto elements() && -> auto {
    return mapped(static_cast<D&&>(*this), LIFT(get<N>));
  }

  auto keys() const& -> auto { return mapped(derived(), LIFT(get<0>)); }
  auto keys() && -> auto { return mapped(static_cast<D&&>(*this), LIFT(get<0>)); }

  auto values() const& -> auto { return mapped(derived(), LIFT(get<1>)); }
  auto values() && -> auto { return mapped(static_cast<D&&>(*this), LIFT(get<1>)); }

  auto take(ptrdiff_t n) const& -> auto { return taken(derived(), n); }
  auto take(ptrdiff_t n) && -> auto { return taken(static_cast<D&&>(*this), n); }

  auto drop(ptrdiff_t n) const& -> auto { return dropped(derived(), n); }
  auto drop(ptrdiff_t n) && -> auto { return dropped(static_cast<D&&>(*this), n); }

  auto rev() const& -> auto { return reversed(derived()); }
  auto rev() && -> auto { return reversed(static_cast<D&&>(*this)); }

  auto stride(ptrdiff_t s) const& -> auto { return strided(derived(), s); }
  auto stride(ptrdiff_t s) && -> auto { return strided(static_cast<D&&>(*this), s); }

  template <class T, class Op = plus<>>
  auto scan(T init, Op op = {}) const& -> auto {
    return scanned(derived(), move(init), move(op));
  }

  template <class T, class Op = plus<>>
  auto scan(T init, Op op = {}) && -> auto {
    return scanned(static_cast<D&&>(*this), move(init), move(op));
  }

  template <class F>
  auto all_of(F f) const -> bool {
    return std::all_of(begin(), end(), ref(f));
  }

  template <class F>
  auto any_of(F f) const -> bool {
    return std::any_of(begin(), end(), ref(f));
  }

  template <class F>
  auto each(F f) const -> D const& {
    for (auto&& e : derived()) { invoke(f, e); }
    return derived();
  }

  template <class F>
  auto find(F f) const -> ptrdiff_t {
    return ptrdiff_t(distance(begin(), find_if(begin(), end(), ref(f))));
  }

  template <class F>
  auto adjacent_find(F f) const -> ptrdiff_t {
    return ptrdiff_t(distance(begin(), std::adjacent_find(begin(), end(), ref(f))));
  }

  template <class F>
  auto count(F f) const -> ptrdiff_t {
    return ptrdiff_t(count_if(begin(), end(), ref(f)));
  }

  template <class F>
  auto transform(F f) const -> D const& {
    for (auto&& e : derived()) { e = invoke(f, e); }
    return derived();
  }

  template <class F>
  auto remove(F f) const -> ptrdiff_t {
    return ptrdiff_t(distance(begin(), remove_if(begin(), end(), ref(f))));
  }

  auto reverse() const -> D const& {
    std::reverse(begin(), end());
    return derived();
  }

  auto shuffle() const -> D const& {
    std::shuffle(begin(), end(), mt);
    return derived();
  }

  template <class C = equal_to<>>
  auto unique(C comp = {}) const -> ptrdiff_t {
    return ptrdiff_t(distance(begin(), std::unique(begin(), end(), ref(comp))));
  }

  template <class F>
  auto max_right(F f) const -> auto {
    return *prev(std::partition_point(next(begin()), end(), ref(f)));
  }

  template <class F>
  auto min_left(F f) const -> auto {
    return *std::partition_point(begin(), prev(end()), not_fn(ref(f)));
  }

  template <class C = less<>>
  auto sort(C comp = {}) const -> D const& {
    std::sort(begin(), end(), ref(comp));
    return derived();
  }

  template <class T, class C = less<>>
  auto lower_bound(T const& val, C comp = {}) const -> ptrdiff_t {
    return ptrdiff_t(distance(begin(), std::lower_bound(begin(), end(), val, ref(comp))));
  }

  template <class T, class C = less<>>
  auto upper_bound(T const& val, C comp = {}) const -> ptrdiff_t {
    return ptrdiff_t(distance(begin(), std::upper_bound(begin(), end(), val, ref(comp))));
  }

  template <class T>
  auto binary_search(T const& val) const -> bool {
    return std::binary_search(begin(), end(), val);
  }

  auto min() const -> auto { return *std::min_element(begin(), end()); }
  auto max() const -> auto { return *std::max_element(begin(), end()); }
  auto minmax() const -> auto {
    auto [mn, mx] = std::minmax_element(begin(), end());
    return pair(*mn, *mx);
  }
  auto min_element() const -> ptrdiff_t { return ptrdiff_t(distance(begin(), std::min_element(begin(), end()))); }
  auto max_element() const -> ptrdiff_t { return ptrdiff_t(distance(begin(), std::max_element(begin(), end()))); }
  auto minmax_element() const -> pair<ptrdiff_t, ptrdiff_t> {
    auto [mn, mx] = std::minmax_element(begin(), end());
    return pair(ptrdiff_t(distance(begin(), mn)), ptrdiff_t(distance(begin(), mx)));
  }

  auto next_permutation() const -> bool { return std::next_permutation(begin(), end()); }
  auto prev_permutation() const -> bool { return std::prev_permutation(begin(), end()); }

  template <class T, class Op = plus<>>
  auto fold(T init, Op op = {}) const -> T {
    return accumulate(begin(), end(), move(init), ref(op));
  }

  template <class Op = plus<>>
  auto fold1(Op op = {}) const -> auto {
    return accumulate(next(begin()), end(), front(), ref(op));
  }

  template <template <class...> class C = vector>
  auto to() const -> auto {
    return C(begin(), end());
  }

  auto to_vla(bool reverse = false) const -> auto {
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
auto operator==(view_base<D1> const& x, view_base<D2> const& y) -> decltype(bool(*begin(x) == *begin(y))) {
  return equal(begin(x), end(x), begin(y), end(y));
}

template <class D1, class D2>
auto operator<(view_base<D1> const& x, view_base<D2> const& y)
    -> decltype(bool(*begin(x) < *begin(y)), bool(*begin(y) < *begin(x))) {
  return lexicographical_compare(begin(x), end(x), begin(y), end(y));
}

template <class R, REQUIRE(iter_t<R>, input)>
class all : public view_base<all<R>> {
  friend class all::view_base;

  R r;

  auto b() const -> iter_t<R> { return begin(r); }
  auto e() const -> iter_t<R> { return end(r); }

 public:
  explicit all(R&& r) : r(forward<R>(r)) {}

  auto size() const -> ptrdiff_t { return sz(r); }
};

template <class R>
all(R&&) -> all<R>;

template <class I, REQUIRE(I, input)>
class range : public view_base<range<I>> {
  friend class range::view_base;

  I first;
  I last;

  auto b() const -> I { return first; }
  auto e() const -> I { return last; }

 public:
  explicit range(I first, I last) : first(move(first)), last(move(last)) {}
};

#undef REQUIRE

template <class T>
auto rep(T l, T r) -> range<int_iter<T>> {
  return range(int_iter(min(l, r)), int_iter(r));
}

template <class T>
auto rep(T n) -> range<int_iter<T>> {
  return rep<T>(0, n);
}

template <class G>
class generator : public view_base<generator<G>> {
  friend class generator::view_base;

  using T = decay_t<invoke_result_t<G const&>>;

  class iter : public iter_base<iter, input_iterator_tag, T> {
    friend class iter::iter_base;

    generator const* p;
    T v;
    ptrdiff_t i;

    auto deref() const -> T { return v; }
    auto equal(iter const& x) const -> bool { return i == x.i; }
    auto inc() & -> void {
      ++i;
      if (i < p->n) { v = invoke(p->gen); }
    }

   public:
    iter() = default;
    explicit iter(generator const* p, ptrdiff_t i) : p(p), v(i < p->n ? invoke(p->gen) : T()), i(i) {}
  };

  [[no_unique_address]] G gen;
  ptrdiff_t n;

  auto b() const -> iter { return iter(this, 0); }
  auto e() const -> iter { return iter(this, n); }

 public:
  explicit generator(G gen, ptrdiff_t n = inf_v<ptrdiff_t>) : gen(move(gen)), n(n) {}

  auto size() const -> ptrdiff_t { return n; }
};

template <class T>
auto repeat(T val, ptrdiff_t n = inf_v<ptrdiff_t>) -> auto {
  return generator([val = move(val)] { return val; }, n);
}

template <class T, enable_if_t<is_arithmetic_v<T>>* = nullptr>
auto rand_view(T a, T b, ptrdiff_t n = inf_v<ptrdiff_t>) -> auto {
  return generator([a, b] { return rand(a, b); }, n);
}

}  // namespace r7h

auto main(int argc, char* argv[]) -> int {
  if (1 < argc) { r7h::mt.seed(std::stoull(argv[1])); }
  r7h::rep(MULTI_CASES ? r7h::input() : 1).each(r7h::main);
}

auto r7h::main(int) -> void {
#define let auto const
  let n = input();
  let m = input();
  let a = input<vla<int>>(n);
  auto vs = all(a).to();
  vs.resize(all(vs).sort().unique());
  auto cnt = vla<int>(sz(vs), 0);
  all(a).each(LAMBDA(++cnt[all(vs).lower_bound(_1)]));
  auto vs_cnt = all(cnt).to();
  vs_cnt.resize(all(vs_cnt).sort().unique());
  auto xss = vector<vector<int>>(sz(vs_cnt));
  for (let x : vs) { xss[all(vs_cnt).lower_bound(cnt[all(vs).lower_bound(x)])].push_back(x); }
  auto bad = vector<vector<int>>(sz(vs));
  for (auto _ = m; _--;) {
    let x = input();
    let y = input();
    bad[all(vs).lower_bound(y)].push_back(x);
  }
  all(bad).each(LAMBDA(all(_1).sort()));
  auto ans = 0ll;
  for (let y : reversed(vs)) {
    let cnt_y = cnt[all(vs).lower_bound(y)];
    auto it2 = begin(vs_cnt);
    let& t = bad[all(vs).lower_bound(y)];
    for (auto&& xs : xss) {
      let cnt_x = *it2++;
      // auto it = begin(t);
      while (!empty(xs) && y <= xs.back()) { xs.pop_back(); }
      for (let x : reversed(xs)) {
        // while (it != end(t) && x < *it) { ++it; }
        // if (it != end(t) && *it == x) { continue; }
        if (all(t).binary_search(x)) { continue; }
        chmax(ans, (cnt_x + cnt_y) * i64(x + y));
        break;
      }
    }
  }
  println(ans);
}