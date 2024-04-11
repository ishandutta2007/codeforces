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

template <class F> class fix {
  [[no_unique_address]] F f;

 public:
  explicit fix(F f) : f(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const { return f(ref(*this), forward<Args>(args)...); }
};

template <class T1, class T2> auto div_floor(T1 x, T2 y) { return x / y - ((x ^ y) < 0 && x % y); }
template <class T1, class T2> auto div_ceil(T1 x, T2 y) { return x / y + (0 <= (x ^ y) && x % y); }
template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

template <class T> const T inf_v = numeric_limits<T>::max() / 2;
const auto inf = inf_v<int>;

auto mt = mt19937_64(_rdtsc());
template <class T1, class T2> auto rand(T1 x, T2 y) {
  using T = common_type_t<T1, T2>;
  if constexpr (is_integral_v<T>) return uniform_int_distribution<T>(x, y)(mt);
  if constexpr (is_floating_point_v<T>) return uniform_real_distribution<T>(x, y)(mt);
}

void main(int);

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
  scan(ret);
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

#define DEF(op) \
  template <class T> auto operator op(T& x, int)->decltype(T(op x)) { \
    auto r = x; \
    op x; \
    return r; \
  }
DEF(++)
DEF(--)
#undef DEF
#define DEF(op) \
  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator op(const T1& x, const T2& y)->decltype(T(T(x) op## = y)) { \
    auto r = T(x); \
    r op## = y; \
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
#define DEF(op, e) \
  template <class T1, class T2> auto operator op(const T1& x, const T2& y)->decltype(e) { return e; }
DEF(!=, !(x == y))
DEF(>, y < x)
DEF(<=, !(y < x))
DEF(>=, !(x < y))
#undef DEF

template <class R> using iter_t = decltype(begin(declval<R&>()));
#define DEF(x, y) template <class R> using x = typename iterator_traits<iter_t<R>>::y;
DEF(iter_cat, iterator_category)
DEF(range_diff_t, difference_type)
DEF(range_val_t, value_type)
DEF(range_ref_t, reference)
#undef DEF

auto size = []<class R>(R&& r) {
  using std::size;
  return range_diff_t<R>(size(forward<R>(r)));
};

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

template <class, class = void> struct is_view : false_type {};
template <> struct is_view<string_view> : true_type {};
template <class T> struct is_view<T, enable_if_t<is_base_of_v<view_base<T>, T>>> : true_type {};

template <class I> class subrange : public view_base<subrange<I>> {
  I b, e;

 public:
  subrange(I first, I last) : b(move(first)), e(move(last)) {}
  I begin() const { return b; }
  I end() const { return e; }
};

template <class F> class generating_view : public view_base<generating_view<F>> {
  class iter : public iter_base<iter, nullptr_t, ptrdiff_t> {
    using res_t = invoke_result_t<F>;
    mutable ptrdiff_t i;
    mutable res_t cache;
    const generating_view* p;
    void inc() { **this, ++i; }
    friend class iter::iter_base;

   public:
    using iterator_category = input_iterator_tag;
    using value_type = res_t;
    using reference = const res_t&;
    using pointer = res_t*;
    iter() : i(-1), cache(), p() {}
    explicit iter(const generating_view* p) : i(0), cache(), p(p) {}
    reference operator*() const {
      if (~i & 1) ++i, cache = invoke(p->f);
      return cache;
    }
    friend bool operator==(const iter& x, const iter& y) { return x.i >> 1 == y.i >> 1; }
  };
  [[no_unique_address]] F f;

 public:
  explicit generating_view(F f) : f(move(f)) {}
  auto begin() const { return iter(this); }
  auto end() const { return iter(); }
  auto size() const { return ptrdiff_t(-1); }
};

template <class F> class adaptor : public F {
 public:
  adaptor(F f) : F(move(f)) {}
  template <class R, class = iter_t<R>> friend auto operator|(R&& r, adaptor a) { return a(forward<R>(r)); }
};
template <class F1, class F2> auto operator|(adaptor<F1> x, adaptor<F2> y) {
  return adaptor([x = move(x), y = move(y)]<class R>(R&& r) mutable { return y(x(forward<R>(r))); });
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
auto all = adaptor([]<class R>(R&& r) {
  if constexpr (is_view<decay_t<R>>())
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
    void inc() { ++b, ++i; }
    void dec() { --b, --i; }
    friend class iter::iter_base;

   public:
    iter(iter_t<R> b = {}, range_diff_t<R> i = 0) : b(move(b)), i(i) {}
    friend bool operator==(const iter& x, const iter& y) { return x.i == y.i; }
  };
  R r;
  range_diff_t<R> n;

 public:
  taken_view(R r, range_diff_t<R> n) : r(move(r)), n(n) { assert(0 <= n); }
  auto begin() const {
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
      return r.begin();
    else
      return iter(r.begin(), 0);
  }
  auto end() const {
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
      return r.begin() + size();
    else
      return iter({}, size());
  }
  auto size() const {
    auto s = r.size();
    return s < 0 ? n : min(n, s);
  }
};
template <class R> taken_view(R&&, auto) -> taken_view<all_t<R>>;
auto taken(auto n) {
  return adaptor([n]<class R>(R&& r) { return taken_view(forward<R>(r), n); });
}

template <class R> class dropped_view : public view_base<dropped_view<R>> {
  class iter : public iter_base<iter, iter_t<R>> {
    iter_t<R> b;
    range_diff_t<R> i;
    void inc() { ++b, ++i; }
    void dec() { --b, --i; }
    friend class iter::iter_base;

   public:
    iter(iter_t<R> b = {}, range_diff_t<R> i = 0) : b(move(b)), i(i) {}
    friend bool operator==(const iter& x, const iter& y) { return x.i == y.i; }
  };
  R r;
  range_diff_t<R> n;

 public:
  dropped_view(R r, range_diff_t<R> n) : r(move(r)), n(n) { assert(0 <= n); }
  auto begin() const {
    auto s = r.size();
    s = s < 0 ? n : min(n, s);
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
      return r.begin() + s;
    else
      return iter(next(r.begin(), s), s);
  }
  auto end() const {
    if constexpr (is_base_of_v<random_access_iterator_tag, iter_cat<R>>)
      return r.end();
    else
      return iter({}, r.size());
  }
  auto size() const {
    auto s = r.size();
    return s < 0 ? s : s - min(n, s);
  }
};
template <class R> dropped_view(R&&, auto) -> dropped_view<all_t<R>>;
auto dropped(auto n) {
  return adaptor([n]<class R>(R&& r) { return dropped_view(forward<R>(r), n); });
}

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
    auto i = r.begin();
    while (i != r.end() && !invoke(f, *i)) ++i;
    return iter(move(i), this);
  }
  auto end() const { return iter(r.end(), this); }
  auto size() const {
    auto s = r.size();
    return s < 0 ? s : count_if(r.begin(), r.end(), ref(f));
  }
};
template <class R, class F> filtered_view(R&&, F) -> filtered_view<all_t<R>, F>;
template <class F> auto filtered(F f) {
  return adaptor([f = move(f)]<class R>(R&& r) mutable { return filtered_view(forward<R>(r), move(f)); });
}

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
template <class F> auto mapped(F f) {
  return adaptor([f = move(f)]<class R>(R&& r) mutable { return mapped_view(forward<R>(r), move(f)); });
}

template <int... I>
auto elements = adaptor([]<class R>(R&& r) {
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
  return mapped_view<all_t<R>, decltype(f)>{{}, forward<R>(r), move(f)};
});
auto keys = elements<0>;
auto values = elements<1>;

template <class R> class reversed_view : public view_base<reversed_view<R>> {
  R r;

 public:
  explicit reversed_view(R r) : r(move(r)) {}
  auto begin() const { return make_reverse_iterator(r.end()); }
  auto end() const { return make_reverse_iterator(r.begin()); }
  auto size() const { return r.size(); }
};
template <class R> reversed_view(R&&) -> reversed_view<all_t<R>>;
auto reversed = adaptor([]<class R>(R&& r) { return reversed_view<all_t<R>>(forward<R>(r)); });

template <class R> class rle_view : public view_base<rle_view<R>> {
  static_assert(is_base_of_v<forward_iterator_tag, iter_cat<R>>);
  class iter : public iter_base<iter, iter_t<R>> {
    iter_t<R> b, next;
    const rle_view* p;
    void inc() {
      b = next;
      if (next != p->r.end()) {
        do ++next;
        while (next != p->r.end() && *next == *b);
      }
    }
    friend class iter::iter_base;

   public:
    using iterator_category = common_type_t<iter_cat<R>, forward_iterator_tag>;
    using value_type = pair<range_val_t<R>, range_diff_t<R>>;
    using reference = pair<range_ref_t<R>, range_diff_t<R>>;
    using pointer = void;
    iter(iter_t<R> b = {}, iter_t<R> next = {}, const rle_view* p = {}) : b(b), next(next), p(p) {}
    reference operator*() const { return {*b, distance(b, next)}; }
  };
  R r;

 public:
  explicit rle_view(R r) : r(move(r)) {}
  auto begin() const {
    auto next = r.begin();
    if (next != r.end()) {
      do ++next;
      while (next != r.end() && *next == r.front());
    }
    return iter(r.begin(), move(next), this);
  }
  auto end() const { return iter(r.end(), r.end(), this); }
  auto size() const {
    auto s = r.size();
    return s < 0 ? s : distance(begin(), end());
  }
};
template <class R> rle_view(R&&) -> rle_view<all_t<R>>;
auto rle = adaptor([]<class R>(R&& r) { return rle_view<all_t<R>>(forward<R>(r)); });

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
    iter(iter_t<R> b = {}, const strided_view* p = {}) : b(b), p(p) {}
    friend auto operator-(const iter& x, const iter& y) { return div_ceil(x.b - y.b, x.p->step()); }
  };
  R r;
  range_diff_t<R> n;

 public:
  strided_view(R r, range_diff_t<R> n) : r(move(r)), n(n) { assert(1 <= n); }
  auto step() const { return n; }
  auto begin() const { return iter(r.begin(), this); }
  auto end() const { return iter(r.end(), this); }
  auto size() const {
    auto s = r.size();
    return s < 0 ? s : div_ceil(s, n);
  }
};
template <class R> strided_view(R&&, auto) -> strided_view<all_t<R>>;
auto strided(auto n) {
  return adaptor([n]<class R>(R&& r) { return strided_view(forward<R>(r), n); });
}

template <class T, class F = plus<>> auto folded(T init, F f = {}) {
  return adaptor(
      [init = move(init), f = move(f)]<class R>(R&& r) mutable { return accumulate(begin(r), end(r), move(init), move(f)); });
}

auto to_vector = adaptor([]<class R>(R&& r) {
  auto ret = vector<range_val_t<R>>();
  ret.reserve(size(r));
  ret.assign(begin(r), end(r));
  return ret;
});

template <class T1, class T2> subrange<int_iter<common_type_t<T1, T2>>> rep(T1 l, T2 r) { return {l, r}; }
template <class T> auto rep(T n) { return rep(0, n); }
template <class T1, class T2, class D> auto rep(T1 l, T2 r, D d) { return rep(l, r) | strided(d); }
template <class... Ts> auto per(Ts... xs) { return rep(xs...) | reversed; }

} // namespace rj

int main() {
  for (auto i : rj::rep(rj::input())) rj::main(i);
}

#define lambda(...) [&]<class T1 = int, class T2 = int>([[maybe_unused]] T1&& $1 = 0, [[maybe_unused]] T2&& $2 = 0) { return __VA_ARGS__; }
#define ALL(f, r, ...) [&](auto _v_) { return f(begin(_v_), end(_v_), ##__VA_ARGS__); }(r | all)
#define ALL2(f, r1, r2, ...) [&](auto _v2_) { return ALL(f, r1, begin(_v2_), end(_v2_), ##__VA_ARGS__); }(r2 | all)
#define IF(...) filtered(lambda(__VA_ARGS__))

void rj::main(int) {
  auto n = input();
  auto a = input<vector<int>>(n);
  auto ans = inf;
  for (auto l : rep(n)) {
    for (auto r : rep(l + 1, n)) {
      chmin(ans, n - size(rep(n) | IF((a[$1] - a[l]) * (r - l) == (a[r] - a[l]) * ($1 - l))));
    }
  }
  if (n == 1) ans = 0;
  println(ans);
}