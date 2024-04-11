#define NDEBUG

#include <unistd.h>
#include <x86intrin.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <charconv>
#include <map>
#include <queue>
#include <random>
#include <set>

using namespace std::literals;
using namespace std::placeholders;

template <class T> inline const auto inf_v = std::numeric_limits<T>::max() / 2;
inline const auto inf = inf_v<int>;

template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = std::forward<U>(b), true : false; }

#define DUMP(...) void(0)

namespace scan_impl {

char buf[1 << 15];
char* ptr = buf;
char* end = buf;

bool scan(char& c) {
  for (;; ++ptr) {
    if (end - ptr < 64) {
      end = std::move(ptr, end, buf);
      ptr = buf;
      end += read(STDIN_FILENO, end, std::end(buf) - end - 1);
      *end = '\0';
    }
    if (ptr == end) return false;
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}
bool scan(std::string& s) {
  char c;
  if (!scan(c)) return false;
  for (s = c; ' ' < *ptr; s += c) scan(c);
  return true;
}
template <class T> std::enable_if_t<std::is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  auto u = std::make_unsigned_t<std::common_type_t<T, int>>((c == '-' ? *ptr++ : c) & 15);
  while ('0' <= *ptr && *ptr <= '9') (u *= 10) += *ptr++ & 15;
  x = T(c == '-' ? -u : u);
  return true;
}
template <class T> std::enable_if_t<std::is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  --ptr;
  if constexpr (std::is_same_v<T, float>) x = std::strtof(ptr, &ptr);
  if constexpr (std::is_same_v<T, double>) x = std::strtod(ptr, &ptr);
  if constexpr (std::is_same_v<T, long double>) x = std::strtold(ptr, &ptr);
  return true;
}

bool scan(std::vector<bool>::reference r) {
  bool b;
  auto ret = scan(b);
  if (ret) r = b;
  return ret;
}
template <class T1, class T2> bool scan(std::pair<T1, T2>&);
template <class... Ts> bool scan(std::tuple<Ts...>&);
template <class R> auto scan(R&& r) -> decltype(std::begin(r), bool()) {
  return std::all_of(std::begin(r), std::end(r), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
}
template <class... Ts> std::enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(std::forward<Ts>(xs)));
}
template <class T1, class T2> bool scan(std::pair<T1, T2>& p) { return scan(p.first, p.second); }
template <class... Ts> bool scan(std::tuple<Ts...>& t) {
  return std::apply([](auto&... es) { return scan(es...); }, t);
}

} // namespace scan_impl

using scan_impl::scan;

template <class T = int, class... Args> T input(Args&&... args) {
  auto ret = T(std::forward<Args>(args)...);
  scan(ret);
  return ret;
}

namespace print_impl {

char buf[1 << 15];
char* ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) std::abort();
  ptr = buf;
}

template <char = 0> void print(char c) {
  if (std::end(buf) - ptr < 64) flush();
  if (c) *ptr++ = c;
}
template <char = 0, class T> std::enable_if_t<std::is_integral_v<T>> print(T x) {
  print('\0');
  ptr = std::to_chars(ptr, std::end(buf), std::common_type_t<T, int>(x)).ptr;
}
template <char = 0, class T> std::enable_if_t<std::is_floating_point_v<T>> print(T x) {
  print('\0');
  if constexpr (std::is_same_v<T, float>) ptr += std::snprintf(ptr, std::end(buf) - ptr, "%.6f", x);
  if constexpr (std::is_same_v<T, double>) ptr += std::snprintf(ptr, std::end(buf) - ptr, "%.15f", x);
  if constexpr (std::is_same_v<T, long double>) ptr += std::snprintf(ptr, std::end(buf) - ptr, "%.18Lf", x);
}

template <char = 0> void print(std::vector<bool>::reference r) { print(bool(r)); }
template <char Sep = ' ', class T1, class T2> void print(const std::pair<T1, T2>&);
template <char Sep = ' ', class... Ts> void print(const std::tuple<Ts...>&);
template <char Sep = ' ', class R> auto print(R&& r) -> decltype(std::begin(r), void()) {
  [[maybe_unused]] auto c = '\0';
  for (auto&& e : r) {
    if constexpr (!std::is_same_v<std::decay_t<decltype(e)>, char>) print(std::exchange(c, Sep));
    print(e);
  }
}
template <char Sep = ' ', class... Ts> std::enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  [[maybe_unused]] auto c = '\0';
  (..., (print(std::exchange(c, Sep)), print(std::forward<Ts>(xs))));
}
template <char Sep, class T1, class T2> void print(const std::pair<T1, T2>& p) { print<Sep>(p.first, p.second); }
template <char Sep, class... Ts> void print(const std::tuple<Ts...>& t) {
  std::apply([](const auto&... es) { print<Sep>(es...); }, t);
}
template <char = 0> void print(const char* s) { print(std::string_view(s)); }

} // namespace print_impl

using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts> void println(Ts&&... xs) {
  print<Sep>(std::forward<Ts>(xs)...);
  print(End);
}

template <class T> int sz(T&& x) { return int(std::size(std::forward<T>(x))); }

template <class T, class B> struct iter_base : std::iterator_traits<B> {
  using difference_type = int;
  T& t_() { return static_cast<T&>(*this); }
  const T& t_() const { return static_cast<const T&>(*this); }
  decltype(auto) operator*() const { return *t_().b_; }
  auto operator->() const { return std::addressof(*t_()); }
  T& operator++() { return t_().inc_(), t_(); }
  T& operator--() { return t_().dec_(), t_(); }
  T operator++(int) { return std::exchange(t_(), std::move(++T(t_()))); }
  T operator--(int) { return std::exchange(t_(), std::move(--T(t_()))); }
  T& operator+=(int n) { return t_().adv_(n), t_(); }
  T& operator-=(int n) { return t_().adv_(-n), t_(); }
  decltype(auto) operator[](int n) const { return *(t_() + n); }
  friend T operator+(T x, int n) { return std::move(x += n); }
  friend T operator-(T x, int n) { return std::move(x -= n); }
  friend T operator+(int n, const T& x) { return x + n; }
#define DEF(op) \
  friend bool operator op(const T& x, const T& y) { return x.b_ op y.b_; }
  DEF(==)
  DEF(!=)
  DEF(<)
  DEF(>)
  DEF(<=)
  DEF(>=)
#undef DEF
};

template <class R> using iter_t = decltype(std::begin(std::declval<R&>()));

template <class T> struct view_base {
  const T& t_() const { return static_cast<const T&>(*this); }
  bool empty() const { return t_().begin() == t_().end(); }
  explicit operator bool() const { return !empty(); }
  auto data() const { return std::addressof(*t_().begin()); }
  int size() const { return int(std::distance(t_().begin(), t_().end())); }
  decltype(auto) front() const { return *t_().begin(); }
  decltype(auto) back() const { return *std::prev(t_().end()); }
  decltype(auto) operator[](int n) const { return t_().begin()[n]; }
};

template <class, class = void> struct is_view : std::false_type {};
template <> struct is_view<std::string_view> : std::true_type {};
template <class T> struct is_view<T, std::enable_if_t<std::is_base_of_v<view_base<T>, T>>> : std::true_type {};

template <class F> struct adaptor : F {
  adaptor(F f) : F(std::move(f)) {}
  template <class R, class = iter_t<R>> friend auto operator|(R&& r, adaptor a) { return a(std::forward<R>(r)); }
};
template <class F1, class F2> auto operator|(adaptor<F1> x, adaptor<F2> y) {
  return adaptor([x = std::move(x), y = std::move(y)]<class R>(R&& r) mutable { return y(x(std::forward<R>(r))); });
}

template <class R> struct ref_view : view_base<ref_view<R>> {
  R* r_;
  ref_view(R& r) : r_(std::addressof(r)) {}
  auto begin() const { return std::begin(*r_); }
  auto end() const { return std::end(*r_); }
  int size() const { return sz(*r_); }
};
template <class R> struct owning_view : view_base<owning_view<R>> {
  R r_;
  owning_view(R r) : r_(std::move(r)) {}
  owning_view(owning_view&&) = default;
  owning_view& operator=(owning_view&&) = default;
  auto begin() const { return std::begin(r_); }
  auto end() const { return std::end(r_); }
  int size() const { return sz(r_); }
};
inline const auto all = adaptor([]<class R>(R&& r) {
  if constexpr (is_view<std::decay_t<R>>())
    return std::forward<R>(r);
  else if constexpr (std::is_reference_v<R>)
    return ref_view<std::remove_reference_t<R>>(r);
  else
    return owning_view<R>(std::move(r));
});
template <class R> using all_t = decltype(all(std::declval<R>()));

template <class R, class F> struct filtered_view : view_base<filtered_view<R, F>> {
  struct iter : iter_base<iter, iter_t<R>> {
    using iterator_category = std::common_type_t<typename iter::iterator_category, std::bidirectional_iterator_tag>;
    iter_t<R> b_;
    const filtered_view* p_;
    void inc_() {
      do ++b_;
      while (b_ != p_->r_.end() && !std::invoke(p_->f_, *b_));
    }
    void dec_() {
      do --b_;
      while (!std::invoke(p_->f_, *b_));
    }
  };
  R r_;
  [[no_unique_address]] F f_;
  iter begin() const { return {{}, std::find_if(r_.begin(), r_.end(), std::ref(f_)), this}; }
  iter end() const { return {{}, r_.end(), this}; }
};
template <class F> auto filtered(F f) {
  return adaptor([f = std::move(f)]<class R>(R&& r) mutable {
    return filtered_view<all_t<R>, F>{{}, std::forward<R>(r), std::move(f)};
  });
}

template <class R, class F> struct mapped_view : view_base<mapped_view<R, F>> {
  struct iter : iter_base<iter, iter_t<R>> {
    using res_t = std::invoke_result_t<F, typename iter::reference>;
    using value_type = std::decay_t<res_t>;
    using reference = res_t;
    using pointer = value_type*;
    iter_t<R> b_;
    const mapped_view* p_;
    reference operator*() const { return std::invoke(p_->f_, *b_); }
    void inc_() { ++b_; }
    void dec_() { --b_; }
    void adv_(int n) { b_ += n; }
    friend int operator-(const iter& x, const iter& y) { return int(x.b_ - y.b_); }
  };
  R r_;
  [[no_unique_address]] F f_;
  iter begin() const { return {{}, r_.begin(), this}; }
  iter end() const { return {{}, r_.end(), this}; }
  int size() const { return sz(r_); }
};
template <class F> auto mapped(F f) {
  return adaptor([f = std::move(f)]<class R>(R&& r) mutable {
    return mapped_view<all_t<R>, F>{{}, std::forward<R>(r), std::move(f)};
  });
}

template <int... I>
inline const auto elements = adaptor([]<class R>(R&& r) {
  auto f = [](auto&& e) -> decltype(auto) {
    if constexpr (sizeof...(I) == 1) {
      if constexpr (std::is_lvalue_reference_v<decltype(e)>)
        return (..., std::get<I>(e));
      else
        return (..., std::decay_t<decltype(std::get<I>(e))>(std::get<I>(std::move(e))));
    } else {
      if constexpr (std::is_lvalue_reference_v<decltype(e)>)
        return std::forward_as_tuple(std::get<I>(e)...);
      else
        return std::forward_as_tuple(std::decay_t<decltype(std::get<I>(e))>(std::get<I>(std::move(e)))...);
    }
  };
  return mapped_view<all_t<R>, decltype(f)>{{}, std::forward<R>(r), std::move(f)};
});
inline const auto keys = elements<0>;
inline const auto values = elements<1>;

template <class R> struct reversed_view : view_base<reversed_view<R>> {
  R r_;
  auto begin() const { return std::make_reverse_iterator(r_.end()); }
  auto end() const { return std::make_reverse_iterator(r_.begin()); }
};
inline const auto reversed = adaptor([]<class R>(R&& r) { return reversed_view<all_t<R>>{{}, std::forward<R>(r)}; });

template <class R> struct rle_view : view_base<rle_view<R>> {
  struct iter : iter_base<iter, iter_t<R>> {
    using iterator_category = std::common_type_t<typename iter::iterator_category, std::forward_iterator_tag>;
    using value_type = std::pair<typename iter::value_type, int>;
    using reference = std::pair<typename iter::reference, int>;
    using pointer = void;
    iter_t<R> b_, next_;
    const rle_view* p_;
    reference operator*() const { return {*b_, std::distance(b_, next_)}; }
    void inc_() {
      b_ = next_;
      while (next_ != p_->r_.end() && (next_ == b_ || *next_ == *b_)) ++next_;
    }
  };
  R r_;
  iter begin() const {
    auto next = r_.begin();
    while (next != r_.end() && (next == r_.begin() || *next == r_.front())) ++next;
    return {{}, r_.begin(), std::move(next), this};
  }
  iter end() const { return {{}, r_.end(), r_.end(), this}; }
};
inline const auto rle = adaptor([]<class R>(R&& r) { return rle_view<all_t<R>>{{}, std::forward<R>(r)}; });

template <class R> struct strided_view : view_base<strided_view<R>> {
  struct iter : iter_base<iter, iter_t<R>> {
    iter_t<R> b_;
    const strided_view* p_;
    void inc_() {
      if constexpr (std::is_base_of_v<std::random_access_iterator_tag, typename iter::iterator_category>)
        b_ += std::min(p_->n_, int(p_->r_.end() - b_));
      else
        for (auto _ = n_; _-- && b_ != p_->r_.end();) ++b_;
    }
    void dec_() { std::advance(b_, b_ == p_->r_.end() ? (sz(p_->r_) - 1) / p_->n_ * p_->n_ - sz(p_->r_) : -p_->n_); }
    void adv_(int n) {
      if (n < 0) dec_(), ++n;
      b_ += std::min(p_->n_ * n, int(p_->r_.end() - b_));
    }
    friend int operator-(const iter& x, const iter& y) { return (int(x.b_ - y.b_) + (x.p_->n_ - 1)) / x.p_->n_; }
  };
  R r_;
  int n_;
  iter begin() const { return {{}, r_.begin(), this}; }
  iter end() const { return {{}, r_.end(), this}; }
  int size() const { return (sz(r_) + (n_ - 1)) / n_; }
};
auto strided(int n) {
  return adaptor([n]<class R>(R&& r) { return strided_view<all_t<R>>{{}, std::forward<R>(r), n}; });
}

template <class T, class F> auto folded(T init, F f) {
  return adaptor([init = std::move(init), f = std::move(f)]<class R>(R&& r) mutable {
    return std::accumulate(std::begin(r), std::end(r), std::move(init), std::move(f));
  });
}

inline const auto to_vector = adaptor([]<class R>(R&& r) { return std::vector(std::begin(r), std::end(r)); });

template <class I> struct subrange : view_base<subrange<I>> {
  I b_, e_;
  subrange(I first, I last) : b_(std::move(first)), e_(std::move(last)) {}
  I begin() const { return b_; }
  I end() const { return e_; }
};

struct int_iter : iter_base<int_iter, int> {
  using iterator_category = std::random_access_iterator_tag;
  using value_type = int;
  using reference = int;
  using pointer = void;
  int b_;
  int_iter(int b) : b_(b) {}
  int operator*() const { return b_; }
  void inc_() { ++b_; }
  void dec_() { --b_; }
  void adv_(int n) { b_ += n; }
  friend int operator-(const int_iter& x, const int_iter& y) { return x.b_ - y.b_; }
};

subrange<int_iter> rep(int l, int r) { return {std::min(l, r), r}; }
auto rep(int n) { return rep(0, n); }
auto rep(int l, int r, int d) { return rep(l, r) | strided(d); }
template <class... Args> auto per(Args... args) { return rep(args...) | reversed; }

template <int D> struct mdrep : view_base<mdrep<D>> {
  struct iter : iter_base<iter, std::array<int, D>> {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = std::array<int, D>;
    using reference = std::array<int, D>;
    using pointer = void;
    std::array<int, D> b_;
    const mdrep* p_;
    reference operator*() const { return b_; }
    void inc_() {
      for (auto d = D; d--;)
        if (++b_[d] == p_->r_[d] && d)
          b_[d] = p_->l_[d];
        else
          break;
    }
    void dec_() {
      for (auto d = D; d--;)
        if (b_[d]-- == p_->l_[d])
          b_[d] = p_->r_[d] - 1;
        else
          break;
    }
    void adv_(int n) { b_ = (*p_)[(*p_)(b_) + n]; }
    friend int operator-(const iter& x, const iter& y) { return (*x.p_)(x.b_) - (*y.p_)(y.b_); }
  };
  std::array<int, D> l_, r_;
  mdrep(const std::array<int, D>& l, const std::array<int, D>& r) : l_(l), r_(r) {
    for (auto d = 0; d < D; ++d) assert(l[d] < r[d]);
  }
  explicit mdrep(const std::array<int, D>& n) : mdrep({}, n) {}
  int operator()(const std::array<int, D>& n) const {
    auto ret = n[0] - l_[0];
    for (auto d = 1; d < D; ++d) (ret *= r_[d] - l_[d]) += n[d] - l_[d];
    return ret;
  }
  auto operator[](int n) const {
    auto ret = l_;
    for (auto d = D; d--;) {
      auto q = n / (r_[d] - l_[d]);
      ret[d] += n - q * (r_[d] - l_[d]);
      n = q;
    }
    return ret;
  }
  iter begin() const { return {{}, l_, this}; }
  iter end() const {
    auto b = l_;
    b[0] = r_[0];
    return {{}, b, this};
  }
};

void solve(int);

int main() {
  for (auto i : rep(input())) solve(i);
}

#define ALL(f, r, ...) [&](auto _v_) { return f(_v_.begin(), _v_.end(), ##__VA_ARGS__); }(r | all)
#define ALL2(f, r1, r2, ...) [&](auto _v2_) { return ALL(f, r1, _v2_.begin(), _v2_.end(), ##__VA_ARGS__); }(r2 | all)
#define LAMBDA(...) [&]([[maybe_unused]] const auto& _) { return __VA_ARGS__; }
#define LAMBDA2(...) [&](const auto& _1, const auto& _2) { return __VA_ARGS__; }

#define IF(...) filtered(LAMBDA(__VA_ARGS__))
#define MAP(...) mapped(LAMBDA(__VA_ARGS__))
#define FOLD(init, ...) folded(init, LAMBDA2(__VA_ARGS__))

void solve(int) {
  auto count = std::array<int, 26>();
  ALL(std::for_each, input<std::string>(), [&](auto&& _) { ++count[_ - 'a']; });
  auto order = rep(26) | to_vector;
  if (input<std::string>() == "abc" && sz(rep(3) | IF(count[_])) == 3) {
    std::swap(order[1], order[2]);
  }
  ALL(std::for_each, order, [&](auto&& _) { print(std::string(count[_], char('a' + _))); });
  println();
}