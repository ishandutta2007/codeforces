#define NDEBUG
#define DUMP(...) void(0)

#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>

namespace rj {

using namespace std;

using uint = unsigned;
using i64 = long long;
using u64 = long long unsigned;
using i128 = __int128;
using u128 = __int128 unsigned;

void main(int);

template <class F> class fix {
  [[no_unique_address]] F f;

 public:
  constexpr explicit fix(F f) : f(move(f)) {}
  template <class... Ts>
  constexpr invoke_result_t<const F&, reference_wrapper<const fix>, Ts&&...> operator()(Ts&&... xs) const {
    return f(ref(*this), forward<Ts>(xs)...);
  }
};

template <class T> const T inf_v = numeric_limits<T>::max() / 2;
const auto inf = inf_v<int>;

namespace scan_impl {

char buf[1 << 15], *ptr = buf, *last = buf;
bool scan(char& c) {
  for (;; ++ptr) {
    if (last - ptr < 64) {
      last = move(ptr, last, buf);
      ptr = buf;
      last += read(STDIN_FILENO, last, end(buf) - last - 1);
      *last = '\0';
    }
    if (ptr == last) return false;
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}
bool scan(string& s) {
  char c;
  if (!scan(c)) return false;
  for (s = c; ' ' < *ptr; s += c) scan(c);
  return true;
}
template <class T> enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  auto u = make_unsigned_t<common_type_t<T, int>>((c == '-' ? *ptr++ : c) & 15);
  while ('0' <= *ptr && *ptr <= '9') (u *= 10) += *ptr++ & 15;
  x = T(c == '-' ? -u : u);
  return true;
}
template <class T> enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  --ptr;
  if constexpr (is_same_v<T, float>) x = strtof(ptr, &ptr);
  if constexpr (is_same_v<T, double>) x = strtod(ptr, &ptr);
  if constexpr (is_same_v<T, long double>) x = strtold(ptr, &ptr);
  return true;
}

bool scan(vector<bool>::reference r) {
  bool b;
  auto ret = scan(b);
  if (ret) r = b;
  return ret;
}
template <class T1, class T2> bool scan(pair<T1, T2>&);
template <class... Ts> bool scan(tuple<Ts...>&);
template <class R> auto scan(R&& r) -> decltype(begin(r), bool()) {
  return all_of(begin(r), end(r), [](auto&& e) { return scan(forward<decltype(e)>(e)); });
}
template <class... Ts> enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) { return (... && scan(forward<Ts>(xs))); }
template <class T1, class T2> bool scan(pair<T1, T2>& p) { return scan(p.first, p.second); }
template <class... Ts> bool scan(tuple<Ts...>& t) {
  return apply([](auto&... es) { return scan(es...); }, t);
}

} // namespace scan_impl

using scan_impl::scan;

template <class T = int, class... Args> T input(Args&&... args) {
  auto ret = T(forward<Args>(args)...);
  [[maybe_unused]] auto res = scan(ret);
  assert(res);
  return ret;
}

namespace print_impl {

char buf[1 << 15], *ptr = buf;
__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) abort();
  ptr = buf;
}
template <char = 0> void print(char c) {
  if (end(buf) - ptr < 64) flush();
  if (c) *ptr++ = c;
}
template <char = 0, class T> enable_if_t<is_integral_v<T>> print(T x) {
  print('\0');
  ptr = to_chars(ptr, end(buf), common_type_t<T, int>(x)).ptr;
}
template <char = 0, class T> enable_if_t<is_floating_point_v<T>> print(T x) {
  print('\0');
  if constexpr (is_same_v<T, float>) ptr += snprintf(ptr, end(buf) - ptr, "%.6f", x);
  if constexpr (is_same_v<T, double>) ptr += snprintf(ptr, end(buf) - ptr, "%.15f", x);
  if constexpr (is_same_v<T, long double>) ptr += snprintf(ptr, end(buf) - ptr, "%.18Lf", x);
}

template <char = 0> void print(vector<bool>::reference r) { print(bool(r)); }
template <char Sep = ' ', class T1, class T2> void print(const pair<T1, T2>&);
template <char Sep = ' ', class... Ts> void print(const tuple<Ts...>&);
template <char Sep = ' ', class R> auto print(R&& r) -> decltype(begin(r), void()) {
  [[maybe_unused]] auto c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) print(exchange(c, Sep));
    print(e);
  }
}
template <char Sep = ' ', class... Ts> enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  [[maybe_unused]] auto c = '\0';
  (..., (print(exchange(c, Sep)), print(forward<Ts>(xs))));
}
template <char Sep, class T1, class T2> void print(const pair<T1, T2>& p) { print<Sep>(p.first, p.second); }
template <char Sep, class... Ts> void print(const tuple<Ts...>& t) {
  apply([](const auto&... es) { print<Sep>(es...); }, t);
}
template <char = 0> void print(const char* s) { print(string_view(s)); }

} // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts> void println(Ts&&... xs) {
  print<Sep>(forward<Ts>(xs)...);
  print(End);
}

auto mt = mt19937_64(_rdtsc());
template <class T1, class T2, class T = common_type_t<T1, T2>> T rand(T1 x, T2 y) {
  if constexpr (is_integral_v<T>) return uniform_int_distribution<T>(x, y)(mt);
  if constexpr (is_floating_point_v<T>) return uniform_real_distribution<T>(x, y)(mt);
}

#define DEF(OP) \
  template <class T> auto operator OP(T& x, int)->decltype(T(OP x)) { \
    auto r = x; \
    OP x; \
    return r; \
  }
DEF(++)
DEF(--)
#undef DEF
#define DEF(OP) \
  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator OP(const T1& x, const T2& y)->decltype(T(declval<T&>() OP## = y)) { \
    auto r = T(x); \
    r OP## = y; \
    return r; \
  }
DEF(+)
DEF(-)
DEF(*)
DEF(/)
DEF(%)
DEF(&)
DEF(|)
DEF(^)
DEF(<<)
DEF(>>)
#undef DEF
#define DEF(OP, E) \
  template <class T1, class T2> auto operator OP(const T1& x, const T2& y)->decltype(E) { return E; }
DEF(!=, !(x == y))
DEF(>, y < x)
DEF(<=, !(y < x))
DEF(>=, !(x < y))
#undef DEF

template <class F> class pipe {
  template <class T> static constexpr auto fwd(remove_reference_t<T>& x) {
    if constexpr (is_reference_v<T>)
      return ref(x);
    else
      return move(x);
  }
  [[no_unique_address]] F f;

 public:
  constexpr explicit pipe(F f) : f(move(f)) {}
  template <class... Ts> constexpr decltype(auto) operator()(Ts&&... xs) const {
    if constexpr (is_invocable_v<const F&, Ts&&...>)
      return f(forward<Ts>(xs)...);
    else
      return rj::pipe(bind(ref(*this), placeholders::_1, fwd<Ts>(xs)...));
  }
  template <class T> friend constexpr invoke_result_t<const F&, T&&> operator|(T&& x, const pipe& p) {
    return p.f(forward<T>(x));
  }
  template <class T> friend constexpr auto operator|=(T& x, const pipe& p) -> decltype(x = move(x) | p) {
    return x = move(x) | p;
  }
};

template <class R> using iter_t = decltype(begin(declval<R&>()));
#define DEF(X, Y) template <class R> using X = typename iterator_traits<iter_t<R>>::Y;
DEF(iter_cat, iterator_category)
DEF(range_diff_t, difference_type)
DEF(range_val_t, value_type)
DEF(range_ref_t, reference)
#undef DEF

const auto size = pipe([]<class R>(R&& r) -> range_diff_t<R> { return std::size(forward<R>(r)); });

template <class T, class B, class D = typename iterator_traits<B>::difference_type>
class iter_base : public iterator_traits<B> {
  T& t() { return static_cast<T&>(*this); }
  const T& t() const { return static_cast<const T&>(*this); }

 public:
  using difference_type = D;
  const B& base() const { return t().b; }
  decltype(auto) operator*() const { return *t().b; }
  auto operator->() const { return &*t(); }
  T& operator++() { return t().inc(), t(); }
  T& operator--() { return t().dec(), t(); }
  T& operator+=(D n) { return t().adv(n), t(); }
  T& operator-=(D n) { return t().adv(-n), t(); }
  decltype(auto) operator[](D n) const { return *(t() + n); }
  friend T operator+(T x, D n) { return move(x += n); }
  friend T operator-(T x, D n) { return move(x -= n); }
  friend T operator+(D n, const T& x) { return x + n; }
  friend D operator-(const iter_base& x, const iter_base& y) { return D(x.base() - y.base()); }
  friend bool operator==(const iter_base& x, const iter_base& y) { return x.base() == y.base(); }
  friend bool operator<(const iter_base& x, const iter_base& y) { return x.base() < y.base(); }
};

template <class T> class int_iter : public iter_base<int_iter<T>, T, make_signed_t<T>> {
  T b;
  void inc() { ++b; }
  void dec() { --b; }
  void adv(make_signed_t<T> n) { b += n; }
  friend class int_iter::iter_base;

 public:
  using iterator_category = random_access_iterator_tag;
  using value_type = T;
  using reference = T;
  using pointer = void;
  int_iter(T b = 0) : b(b) {}
  T operator*() const { return b; }
};

template <class T> class view_base {
  const T& t() const { return static_cast<const T&>(*this); }

 public:
  bool empty() const { return t().begin() == t().end(); }
  explicit operator bool() const { return !empty(); }
  auto data() const { return &*t().begin(); }
  auto size() const { return distance(t().begin(), t().end()); }
  decltype(auto) front() const { return *t().begin(); }
  decltype(auto) back() const { return *prev(t().end()); }
  decltype(auto) operator[](auto n) const { return t().begin()[n]; }
};

template <class, class = void> const auto is_view = false;
template <> const auto is_view<string_view> = true;
template <class T> const auto is_view<T, enable_if_t<is_base_of_v<view_base<T>, T>>> = true;

template <class I> class subrange : public view_base<subrange<I>> {
  I b, e;

 public:
  subrange(I first, I last) : b(move(first)), e(move(last)) {}
  I begin() const { return b; }
  I end() const { return e; }
};

template <class F> class gen_view : public view_base<gen_view<F>> {
  class iter : public iter_base<iter, nullptr_t, int> {
    using T = invoke_result_t<F>;
    mutable int i;
    mutable T cache;
    const gen_view* p;
    void inc() { **this, ++i; }
    friend class iter::iter_base;

   public:
    using iterator_category = input_iterator_tag;
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;
    iter(int i = 0, const gen_view* p = {}) : i(i), cache(), p(p) {}
    iter(iter&&) = default;
    iter& operator=(iter&&) = default;
    reference operator*() const {
      if (~i & 1) ++i, cache = invoke(p->f);
      return cache;
    }
    friend bool operator==(const iter& x, const iter& y) { return x.i >> 1 == y.i >> 1; }
  };
  int n;
  [[no_unique_address]] F f;

 public:
  gen_view(int n, F f) : n(n), f(move(f)) {}
  auto begin() const { return iter(0, this); }
  auto end() const { return iter(n << 1, this); }
  auto size() const { return n; }
};

template <class T = int> auto iview(int n) {
  return gen_view(n, [] { return input<T>(); });
}

template <class R> class ref_view : public view_base<ref_view<R>> {
  R* r;

 public:
  ref_view(R& r) : r(&r) {}
#define DEF(f) \
  auto f() const { \
    using rj::f; \
    return f(*r); \
  }
  DEF(begin)
  DEF(end)
  DEF(size)
#undef DEF
};
template <class R> class owning_view : public view_base<owning_view<R>> {
  R r;

 public:
  owning_view(R&& r) : r(move(r)) {}
  owning_view(owning_view&&) = default;
  owning_view& operator=(owning_view&&) = default;
#define DEF(f) \
  auto f() const { \
    using rj::f; \
    return f(r); \
  }
  DEF(begin)
  DEF(end)
  DEF(size)
#undef DEF
};
const auto all = pipe([]<class R>(R&& r) {
  if constexpr (is_view<decay_t<R>>)
    return forward<R>(r);
  else if constexpr (is_reference_v<R>)
    return ref_view<remove_reference_t<R>>(r);
  else
    return owning_view<R>(move(r));
});
template <class R> using all_t = decltype(all(declval<R>()));

template <class R> class taken_view : public view_base<taken_view<R>> {
  class iter : public iter_base<iter, iter_t<R>> {
    iter_t<R> b;
    range_diff_t<R> i;
    const taken_view* p;
    void inc() {
      ++b, ++i;
      if (i == p->n) b = p->r.end();
    }
    void dec() { --b, --i; }
    friend class iter::iter_base;

   public:
    iter(iter_t<R> b = {}, range_diff_t<R> i = 0, const taken_view* p = {}) : b(move(b)), i(i), p(p) {}
  };
  R r;
  range_diff_t<R> n;

 public:
  taken_view(R r, range_diff_t<R> n) : r(move(r)), n(n) { assert(0 <= n); }
  auto begin() const {
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
      return r.begin();
    else
      return iter(r.begin(), 0, this);
  }
  auto end() const {
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
      return r.begin() + size();
    else
      return iter(r.end(), -1, this);
  }
  auto size() const { return min(n, r.size()); }
};
template <class R> taken_view(R&&, auto) -> taken_view<all_t<R>>;
const auto taken = pipe([]<class R>(R&& r, auto n) { return taken_view(forward<R>(r), n); });

template <class R> class dropped_view : public view_base<dropped_view<R>> {
  R r;
  range_diff_t<R> n;

 public:
  dropped_view(R r, range_diff_t<R> n) : r(move(r)), n(n) { assert(0 <= n); }
  auto begin() const {
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>) {
      return r.begin() + min(n, r.size());
    } else {
      auto ret = r.begin();
      for (auto _ = n; _-- && ret != r.end();) ++ret;
      return ret;
    }
  }
  auto end() const { return r.end(); }
  auto size() const { return max(r.size(), n) - n; }
};
template <class R> dropped_view(R&&, auto) -> dropped_view<all_t<R>>;
const auto dropped = pipe([]<class R>(R&& r, auto n) { return dropped_view(forward<R>(r), n); });

template <class R, class F> class filtered_view : public view_base<filtered_view<R, F>> {
  class iter : public iter_base<iter, iter_t<R>> {
   public:
    iter_t<R> b;
    const filtered_view* p;
    void inc() {
      do ++b;
      while (b != p->r.end() && !invoke(p->f, *b));
    }
    void dec() {
      do --b;
      while (!invoke(p->f, *b));
    }
    friend class iter::iter_base;

   public:
    using iterator_category = common_type_t<iter_cat<R>, bidirectional_iterator_tag>;
    iter(iter_t<R> b = {}, const filtered_view* p = {}) : b(move(b)), p(p) {}
  };
  R r;
  [[no_unique_address]] F f;

 public:
  filtered_view(R r, F f) : r(move(r)), f(move(f)) {}
  auto begin() const {
    auto b = r.begin();
    while (b != r.end() && !invoke(f, *b)) ++b;
    return iter(move(b), this);
  }
  auto end() const { return iter(r.end(), this); }
  auto size() const {
    auto ret = r.size();
    for (auto&& e : r) ret -= !invoke(f, e);
    return ret;
  }
};
template <class R, class F> filtered_view(R&&, F) -> filtered_view<all_t<R>, F>;
const auto filtered = pipe([]<class R>(R&& r, auto f) { return filtered_view(forward<R>(r), move(f)); });

template <class R, class F> class mapped_view : public view_base<mapped_view<R, F>> {
  class iter : public iter_base<iter, iter_t<R>> {
    using res_t = invoke_result_t<F, range_ref_t<R>>;
    iter_t<R> b;
    const mapped_view* p;
    void inc() { ++b; }
    void dec() { --b; }
    void adv(range_diff_t<R> n) { b += n; }
    friend class iter::iter_base;

   public:
    using value_type = decay_t<res_t>;
    using reference = res_t;
    using pointer = value_type*;
    iter(iter_t<R> b = {}, const mapped_view* p = {}) : b(move(b)), p(p) {}
    reference operator*() const { return invoke(p->f, *b); }
  };
  R r;
  [[no_unique_address]] F f;

 public:
  mapped_view(R r, F f) : r(move(r)), f(move(f)) {}
  auto begin() const { return iter(r.begin(), this); }
  auto end() const { return iter(r.end(), this); }
  auto size() const { return r.size(); }
};
template <class R, class F> mapped_view(R&&, F) -> mapped_view<all_t<R>, F>;
const auto mapped = pipe([]<class R>(R&& r, auto f) { return mapped_view(forward<R>(r), move(f)); });

template <int... I>
const auto elements = pipe([]<class R>(R&& r) {
  auto f = [](auto&& e) -> decltype(auto) {
    if constexpr (sizeof...(I) == 1) {
      if constexpr (is_lvalue_reference_v<decltype(e)>)
        return (..., get<I>(e));
      else
        return (..., decay_t<decltype(get<I>(e))>(get<I>(move(e))));
    } else {
      if constexpr (is_lvalue_reference_v<decltype(e)>)
        return forward_as_tuple(get<I>(e)...);
      else
        return forward_as_tuple(decay_t<decltype(get<I>(e))>(get<I>(move(e)))...);
    }
  };
  return mapped_view(forward<R>(r), move(f));
});
const auto keys = elements<0>;
const auto values = elements<1>;

template <class R> class reversed_view : public view_base<reversed_view<R>> {
  R r;

 public:
  explicit reversed_view(R r) : r(move(r)) {}
  auto begin() const { return make_reverse_iterator(r.end()); }
  auto end() const { return make_reverse_iterator(r.begin()); }
  auto size() const { return r.size(); }
};
template <class R> reversed_view(R&&) -> reversed_view<all_t<R>>;
const auto reversed = pipe([]<class R>(R&& r) { return reversed_view<all_t<R>>(forward<R>(r)); });

template <class R> class strided_view : public view_base<strided_view<R>> {
  class iter : public iter_base<iter, iter_t<R>> {
    iter_t<R> b;
    const strided_view* p;
    void inc() {
      if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
        b += min(p->step(), p->r.end() - b);
      else
        for (auto _ = p->step(); _-- && b != p->r.end();) ++b;
    }
    void dec() { advance(b, b == p->r.end() ? (p->r.size() - 1) / p->step() * p->step() - p->r.size() : -p->step()); }
    void adv(range_diff_t<R> n) {
      if (n < 0) dec(), ++n;
      b += min(p->step() * n, p->r.end() - b);
    }
    friend class iter::iter_base;

   public:
    iter(iter_t<R> b = {}, const strided_view* p = {}) : b(move(b)), p(p) {}
    friend auto operator-(const iter& x, const iter& y) { return div_ceil(x.b - y.b, x.p->step()); }
  };
  R r;
  range_diff_t<R> n;

 public:
  strided_view(R r, range_diff_t<R> n) : r(move(r)), n(n) { assert(1 <= n); }
  auto step() const { return n; }
  auto begin() const { return iter(r.begin(), this); }
  auto end() const { return iter(r.end(), this); }
  auto size() const { return div_ceil(r.size(), n); }
};
template <class R> strided_view(R&&, auto) -> strided_view<all_t<R>>;
const auto strided = pipe([]<class R>(R&& r, auto n) { return strided_view(forward<R>(r), n); });

auto to_vector = pipe([]<class R>(R&& r) {
  auto ret = vector<range_val_t<R>>();
  ret.reserve(size(r));
  for (auto&& e : r) ret.push_back(e);
  return ret;
});

template <class T1, class T2, class T = common_type_t<T1, T2>> subrange<int_iter<T>> rep(T1 l, T2 r) {
  return {min<T>(l, r), r};
}
template <class T> auto rep(T n) { return rep(0, n); }
template <class T1, class T2, class D> auto rep(T1 l, T2 r, D d) { return rep(l, r) | strided(d); }
template <class... Ts> auto per(Ts... xs) { return rep(xs...) | reversed; }

template <class T1, class T2> auto div_floor(T1 x, T2 y) { return x / y - ((x ^ y) < 0 && x % y); }
template <class T1, class T2> auto div_ceil(T1 x, T2 y) { return x / y + (0 <= (x ^ y) && x % y); }
template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

} // namespace rj

int main() {
  for (auto i : rj::rep(rj::input())) rj::main(i);
}

#define lambda(...) \
  [&]<class T1 = const nullopt_t&, class T2 = const nullopt_t&>([[maybe_unused]] T1&& $1 = nullopt, \
                                                                [[maybe_unused]] T2&& $2 = nullopt) { \
    return __VA_ARGS__; \
  }
#define ALL(f, r, ...) [&](auto _v_) { return f(begin(_v_), end(_v_), ##__VA_ARGS__); }(r | all)
#define ALL2(f, r1, r2, ...) [&](auto _v2_) { return ALL(f, r1, begin(_v2_), end(_v2_), ##__VA_ARGS__); }(r2 | all)
#define IF(...) filtered(lambda(__VA_ARGS__))

void rj::main(int) {
  const auto n = input();
  const auto k = input();
  if (n <= 2 * (k - 1)) {
    return println(-1);
  }
  for (const auto i : rep(n)) {
    auto ans = string(n, '.');
    if (~i & 1 && i / 2 < k) {
      ans[i] = 'R';
    }
    println(ans);
  }
}