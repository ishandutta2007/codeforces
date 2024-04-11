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

namespace rj {

template <class T>
inline constexpr T inf = std::numeric_limits<T>::max() / 2;

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}

template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

namespace scan_impl {

char buf[1 << 15];
int l = sizeof(buf);
int r = l;

bool scan(char& c) {
  for (;; ++l) {
    if (int t = r - l; t < 64) {
      std::move(buf + l, buf + r, buf);
      l = 0;
      r = t + static_cast<int>(read(STDIN_FILENO, buf + t, sizeof(buf) - t - 1));
      buf[r] = 0;
    }
    if (l == r) return false;
    if (' ' < buf[l]) {
      c = buf[l++];
      return true;
    }
  }
}

bool scan(std::string& s) {
  char c;
  if (!scan(c)) return false;
  for (s = c; ' ' < buf[l]; s += c) scan(c);
  return true;
}

template <class T>
std::enable_if_t<std::is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  if constexpr (std::is_same_v<T, bool>) {
    assert(c == '0' || c == '1');
    x = c == '1';
  } else {
    l -= c != '-';
    assert('0' <= buf[l] && buf[l] <= '9');
    using U = std::make_unsigned_t<T>;
    U u = static_cast<U>(buf[l++] & 15);
    for (; '0' <= buf[l] && buf[l] <= '9'; ++l) (u *= 10) += static_cast<U>(buf[l] & 15);
    x = static_cast<T>(c == '-' ? -u : u);
  }
  return true;
}

template <class T>
std::enable_if_t<std::is_floating_point_v<T>, bool> scan(T& x) {
  char c, *ptr;
  if (!scan(c)) return false;
  if constexpr (std::is_same_v<T, float>) x = std::strtof(buf + (l - 1), &ptr);
  if constexpr (std::is_same_v<T, double>) x = std::strtod(buf + (l - 1), &ptr);
  if constexpr (std::is_same_v<T, long double>) x = std::strtold(buf + (l - 1), &ptr);
  l = static_cast<int>(ptr - buf);
  return true;
}

} // namespace scan_impl

using scan_impl::scan;

bool scan(std::vector<bool>::reference r) {
  bool b, ret = scan(b);
  r = b;
  return ret;
}

template <class T1, class T2>
bool scan(std::pair<T1, T2>&);

template <class... Ts>
bool scan(std::tuple<Ts...>&);

template <class R, class = decltype(std::begin(std::declval<R&>()))>
bool scan(R&& r) {
  return std::all_of(std::begin(r), std::end(r), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
}

template <class... Ts>
std::enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(std::forward<Ts>(xs)));
}

template <class T1, class T2>
bool scan(std::pair<T1, T2>& p) {
  return scan(p.first, p.second);
}

template <class... Ts>
bool scan(std::tuple<Ts...>& t) {
  return std::apply([](auto&... es) { return scan(es...); }, t);
}

namespace print_impl {

char buf[1 << 15];
int i;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, i) == -1) std::abort();
  i = 0;
}

template <char = 0>
void print(char c) {
  if (sizeof(buf) - i < 64) flush();
  if (c) buf[i++] = c;
}

template <char = 0, class T>
std::enable_if_t<std::is_integral_v<T>> print(T x) {
  print('\0');
  if constexpr (std::is_same_v<T, bool>)
    print("01"[x]);
  else
    i = static_cast<int>(std::to_chars(buf + i, std::end(buf), x).ptr - buf);
}

template <char = 0, class T>
std::enable_if_t<std::is_floating_point_v<T>> print(T x) {
  print('\0');
  if constexpr (std::is_same_v<T, float>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.6f", x);
  if constexpr (std::is_same_v<T, double>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.15f", x);
  if constexpr (std::is_same_v<T, long double>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.18Lf", x);
}

} // namespace print_impl

using print_impl::print;

template <char Sep = ' ', class T1, class T2>
void print(const std::pair<T1, T2>&);

template <char Sep = ' ', class... Ts>
void print(const std::tuple<Ts...>&);

template <char Sep = ' ', class R, class I = decltype(std::begin(std::declval<R&>()))>
void print(R&& r) {
  using T = typename std::iterator_traits<I>::value_type;
  [[maybe_unused]] char c = 0;
  for (const T& e : r) {
    if constexpr (!std::is_same_v<T, char>) print(std::exchange(c, Sep));
    print(e);
  }
}

template <char Sep = ' ', class... Ts>
std::enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  char c = 0;
  (..., (print(std::exchange(c, Sep)), print(std::forward<Ts>(xs))));
}

template <char Sep, class T1, class T2>
void print(const std::pair<T1, T2>& p) {
  print<Sep>(p.first, p.second);
}

template <char Sep, class... Ts>
void print(const std::tuple<Ts...>& t) {
  std::apply([](const auto&... es) { print<Sep>(es...); }, t);
}

template <char Sep = ' ', char End = '\n', class... Ts>
void println(Ts&&... xs) {
  print<Sep>(std::forward<Ts>(xs)...);
  print(End);
}

template <class Derived, class Base, class C = typename std::iterator_traits<Base>::iterator_category,
          class T = typename std::iterator_traits<Base>::value_type, class R = typename std::iterator_traits<Base>::reference,
          class D = typename std::iterator_traits<Base>::difference_type>
class iterator_base : public std::iterator<C, T, D, void, R> {
  Derived& derived() { return static_cast<Derived&>(*this); }
  const Derived& derived() const { return static_cast<const Derived&>(*this); }

 public:
  R operator*() const { return *derived().base(); }

  Derived& operator++() {
    ++derived().base();
    return derived();
  }
  Derived& operator--() {
    --derived().base();
    return derived();
  }

  Derived& operator+=(D n) {
    derived().base() += n;
    return derived();
  }
  Derived& operator-=(D n) {
    derived().base() -= n;
    return derived();
  }

  R operator[](D n) const { return *(derived() + n); }

  friend Derived operator++(Derived& x, int) {
    Derived ret = x;
    ++x;
    return ret;
  }
  friend Derived operator--(Derived& x, int) {
    Derived ret = x;
    --x;
    return ret;
  }

  friend Derived operator+(const Derived& x, D n) {
    Derived ret = x;
    ret += n;
    return ret;
  }
  friend Derived operator+(D n, const Derived& x) { return x + n; }

  friend Derived operator-(const Derived& x, D n) {
    Derived ret = x;
    ret -= n;
    return ret;
  }

  friend bool operator!=(const Derived& x, const Derived& y) { return !(x == y); }

  friend bool operator<(const Derived& x, const Derived& y) { return x - y < 0; }
  friend bool operator>(const Derived& x, const Derived& y) { return x - y > 0; }
  friend bool operator<=(const Derived& x, const Derived& y) { return x - y <= 0; }
  friend bool operator>=(const Derived& x, const Derived& y) { return x - y >= 0; }
};

template <class Derived>
class view_base {
  auto begin() const { return static_cast<const Derived&>(*this).begin(); }
  auto end() const { return static_cast<const Derived&>(*this).end(); }

 public:
  bool empty() const { return begin() == end(); }
  explicit operator bool() const { return !empty(); }

  auto size() const { return std::distance(begin(), end()); }

  decltype(auto) front() const { return *begin(); }
  decltype(auto) back() const { return *std::prev(end()); }

  template <class D>
  decltype(auto) operator[](D n) const {
    return begin()[n];
  }
};

template <class, class = void>
struct is_view : std::false_type {};

template <class CharT>
struct is_view<std::basic_string_view<CharT>> : std::true_type {};

template <class T>
struct is_view<T, std::enable_if_t<std::is_base_of_v<view_base<T>, T>>> : std::true_type {};

template <class T1, class T2, class = std::enable_if_t<is_view<T1>{} && is_view<T2>{}>>
bool operator==(T1 x, T2 y) {
  return (x.size() - y.size()) == 0 && std::equal(x.begin(), x.end(), y.begin(), y.end());
}

template <class T1, class T2, class = std::enable_if_t<is_view<T1>{} && is_view<T2>{}>>
bool operator!=(T1 x, T2 y) {
  return !(std::move(x) == std::move(y));
}

template <class T1, class T2, class = std::enable_if_t<is_view<T1>{} && is_view<T2>{}>>
bool operator<(T1 x, T2 y) {
  return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T1, class T2, class = std::enable_if_t<is_view<T1>{} && is_view<T2>{}>>
bool operator>(T1 x, T2 y) {
  return std::move(y) < std::move(x);
}

template <class T1, class T2, class = std::enable_if_t<is_view<T1>{} && is_view<T2>{}>>
bool operator<=(T1 x, T2 y) {
  return !(std::move(y) < std::move(x));
}

template <class T1, class T2, class = std::enable_if_t<is_view<T1>{} && is_view<T2>{}>>
bool operator>=(T1 x, T2 y) {
  return !(std::move(x) < std::move(y));
}

class all_t {
  template <class R, class I>
  class view : public view_base<view<R, I>> {
   public:
    using iterator = I;

    explicit view(R& r) : r_(&r) {}

    I begin() const { return std::begin(*r_); }
    I end() const { return std::end(*r_); }
    auto size() const { return std::size(*r_); }

   private:
    R* r_;
  };

 public:
  template <class R>
  friend auto operator|(R&& r, all_t) {
    if constexpr (is_view<std::decay_t<R>>{})
      return r;
    else
      return view<std::remove_reference_t<R>, decltype(std::begin(r))>(std::forward<R>(r));
  }
} inline constexpr all;

template <class Pred>
class filtered {
  template <class R, class I = typename R::iterator>
  class view : public view_base<view<R>> {
    using C = std::common_type_t<typename std::iterator_traits<I>::iterator_category, std::bidirectional_iterator_tag>;

   public:
    class iterator : public iterator_base<iterator, I, C> {
     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(std::move(base)), parent_(parent) {}

      I& base() { return base_; }
      const I& base() const { return base_; }

      iterator& operator++() {
        base_ = std::find_if(std::move(++base_), parent_->r_.end(), std::ref(parent_->pred_));
        return *this;
      }
      iterator& operator--() {
        for (--base_; !std::invoke(parent_->pred_, *base_);) --base_;
        return *this;
      }

      friend bool operator==(const iterator& x, const iterator& y) { return x.base_ == y.base_; }

     private:
      I base_;
      const view* parent_;
    };

    view(Pred pred, R r, I begin) : pred_(std::move(pred)), r_(std::move(r)), begin_(std::move(begin)) {}

    auto begin() const { return iterator(begin_, this); }
    auto end() const { return iterator(r_.end(), this); }

   private:
    Pred pred_;
    R r_;
    I begin_;
  };

 public:
  explicit filtered(Pred pred) : pred_(std::move(pred)) {}

  template <class R>
  friend auto operator|(R&& r, filtered f) {
    auto v = std::forward<R>(r) | all;
    auto begin = std::find_if(v.begin(), v.end(), std::ref(f.pred_));
    return view<decltype(v)>(std::move(f.pred_), std::move(v), std::move(begin));
  }

 private:
  Pred pred_;
};

template <class F>
class mapped {
  template <class R, class I = typename R::iterator>
  class view : public view_base<view<R>> {
    using Traits = std::iterator_traits<I>;
    using Ref = std::invoke_result_t<F, typename Traits::reference>;

   public:
    class iterator : public iterator_base<iterator, I, typename Traits::iterator_category, std::decay_t<Ref>, Ref> {
     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(std::move(base)), parent_(parent) {}

      I& base() { return base_; }
      const I& base() const { return base_; }

      Ref operator*() const { return std::invoke(parent_->f_, *base_); }

      friend bool operator==(const iterator& x, const iterator& y) { return x.base_ == y.base_; }

      friend auto operator-(const iterator& x, const iterator& y) { return x.base_ - y.base_; }

     private:
      I base_;
      const view* parent_;
    };

    view(F f, R r) : f_(std::move(f)), r_(std::move(r)) {}

    auto begin() const { return iterator(r_.begin(), this); }
    auto end() const { return iterator(r_.end(), this); }

   private:
    F f_;
    R r_;
  };

 public:
  explicit mapped(F f) : f_(std::move(f)) {}

  template <class R>
  friend auto operator|(R&& r, mapped m) {
    auto v = std::forward<R>(r) | all;
    return view<decltype(v)>(std::move(m.f_), std::move(v));
  }

 private:
  F f_;
};

template <int N>
struct elements_t {
  template <class R>
  friend auto operator|(R&& r, elements_t) {
    return std::forward<R>(r) | mapped([](auto&& e) { return std::get<N>(std::forward<decltype(e)>(e)); });
  }
};

template <int N>
inline constexpr elements_t<N> elements;

class reversed_t {
  template <class R>
  class view : public view_base<view<R>> {
   public:
    using iterator = std::reverse_iterator<typename R::iterator>;

    explicit view(R r) : r_(std::move(r)) {}

    auto begin() const { return std::make_reverse_iterator(r_.end()); }
    auto end() const { return std::make_reverse_iterator(r_.begin()); }

   private:
    R r_;
  };

 public:
  template <class R>
  friend auto operator|(R&& r, reversed_t) {
    auto v = std::forward<R>(r) | all;
    return view<decltype(v)>(std::move(v));
  }
} inline constexpr reversed;

template <class T>
class sliced {
  static_assert(std::is_integral_v<T>);
  static_assert(!std::is_same_v<T, bool>);

  template <class R>
  class view : public view_base<view<R>> {
   public:
    using iterator = typename R::iterator;

    view(R r, iterator begin, iterator end) : r_(std::move(r)), begin_(std::move(begin)), end_(std::move(end)) {}

    auto begin() const { return begin_; }
    auto end() const { return end_; }

   private:
    R r_;
    iterator begin_;
    iterator end_;
  };

 public:
  explicit sliced(T start, T stop) : start_(start), stop_(stop) {}

  template <class R>
  friend auto operator|(R&& r, sliced s) {
    auto v = std::forward<R>(r) | all;
    using D = typename std::iterator_traits<typename decltype(v)::iterator>::difference_type;
    D n = static_cast<D>(v.size());
    D start = std::clamp(static_cast<D>(s.start_), -n, n);
    if (start < 0) start += n;
    D stop = std::clamp(static_cast<D>(s.stop_), -n, n);
    if (stop < 0) stop += n;
    if (stop < start) start = stop;
    return view<decltype(v)>(std::move(v), std::next(v.begin(), start), std::next(v.begin(), stop));
  }

 private:
  T start_;
  T stop_;
};

template <class T>
class strided {
  static_assert(std::is_integral_v<T>);
  static_assert(!std::is_same_v<T, bool>);

  template <class R, class I = typename R::iterator, class D = typename std::iterator_traits<I>::difference_type>
  class view : public view_base<view<R>> {
   public:
    class iterator : public iterator_base<iterator, I> {
      D stride() const { return static_cast<D>(parent_->n_); }

     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(std::move(base)), parent_(parent) {}

      I& base() { return base_; }
      const I& base() const { return base_; }

      iterator& operator++() {
        std::advance(base_, std::min(stride(), std::distance(base_, parent_->r_.end())));
        return *this;
      }
      iterator& operator--() {
        if (base_ == parent_->r_.end())
          std::advance(base_, (parent_->r_.size() - 1) / stride() * stride() - parent_->r_.size());
        else
          std::advance(base_, -stride());
        return *this;
      }

      iterator& operator+=(D n) {
        if (n < 0) return *this -= -n;
        base_ += std::min(stride() * n, std::distance(base_, parent_->r_.end()));
        return *this;
      }
      iterator& operator-=(D n) {
        if (n <= 0) return *this += -n;
        if (base_ == parent_->r_.end()) --*this, --n;
        base_ -= stride() * n;
        return *this;
      }

      friend bool operator==(const iterator& x, const iterator& y) { return x.base_ == y.base_; }

      friend D operator-(const iterator& x, const iterator& y) {
        if (x.base_ < y.base_) return -(y - x);
        return ((x.base_ - y.base_) + (x.stride() - 1)) / x.stride();
      }

     private:
      I base_;
      const view* parent_;
    };

    view(T n, R r) : n_(n), r_(std::move(r)) {}

    auto begin() const { return iterator(r_.begin(), this); }
    auto end() const { return iterator(r_.end(), this); }

   private:
    T n_;
    R r_;
  };

 public:
  explicit strided(T n) : n_(n) { assert(1 <= n); }

  template <class R>
  friend auto operator|(R&& r, strided s) {
    auto v = std::forward<R>(r) | all;
    return view<decltype(v)>(s.n_, std::move(v));
  }

 private:
  T n_;
};

template <class BinaryOp>
class folded {
 public:
  explicit folded(BinaryOp binary_op) : binary_op_(std::move(binary_op)) {}

  template <class R>
  friend auto operator|(R&& r, folded f) {
    assert(!std::empty(r));
    return std::accumulate(std::next(std::begin(r)), std::end(r), *std::begin(r), std::ref(f.binary_op_));
  }

 private:
  BinaryOp binary_op_;
};

struct to_vector_t {
  template <class R>
  friend auto operator|(R&& r, to_vector_t) {
    return std::vector(std::begin(r), std::end(r));
  }
} inline constexpr to_vector;

template <class I>
class subrange : public view_base<subrange<I>> {
 public:
  using iterator = I;

  subrange(I first, I last) : begin_(std::move(first)), end_(std::move(last)) {}

  I begin() const { return begin_; }
  I end() const { return end_; }

 private:
  I begin_;
  I end_;
};

template <class T>
class int_iterator : public iterator_base<int_iterator<T>, T, std::random_access_iterator_tag, T, T, T> {
  static_assert(std::is_integral_v<T>);
  static_assert(!std::is_same_v<T, bool>);

 public:
  int_iterator() = default;
  explicit int_iterator(T base) : base_(base) {}

  T& base() { return base_; }
  const T& base() const { return base_; }

  T operator*() const { return base_; }

  friend bool operator==(const int_iterator& x, const int_iterator& y) { return x.base_ == y.base_; }

  friend T operator-(const int_iterator& x, const int_iterator& y) { return x.base_ - y.base_; }

 private:
  T base_;
};

template <class T>
auto rep(T l, T r) {
  return subrange(int_iterator(std::min(l, r)), int_iterator(r));
}

template <class T>
auto rep(T n) {
  return rep<T>(0, n);
}

template <class T>
auto per(T l, T r) {
  return rep(l, r) | reversed;
}

template <class T>
auto per(T n) {
  return per<T>(0, n);
}

void main();

} // namespace rj

int main() { rj::main(); }

namespace rj {

#define DUMP(...) static_cast<void>(0)

#define LAMBDA(...) [&](const auto& _) { return __VA_ARGS__; }
#define LAMBDA2(...) [&](const auto& _1, const auto& _2) { return __VA_ARGS__; }
#define IF(...) filtered(LAMBDA(__VA_ARGS__))
#define MAP(...) mapped(LAMBDA(__VA_ARGS__))
#define FOLD(...) folded(LAMBDA2(__VA_ARGS__))

void solve() {
  long long u, v;
  scan(u, v);
  println(u * u, -v * v);
}

void main() {
  int t;
  scan(t);
  while (t--) solve();
}

} // namespace rj