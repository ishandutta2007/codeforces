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

#define DUMP(...) static_cast<void>(0)

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
    if (buf[l] > ' ') {
      c = buf[l++];
      return true;
    }
  }
}

bool scan(std::string& s) {
  char c;
  if (!scan(c)) return false;
  for (s = c; buf[l] > ' '; s += c) scan(c);
  return true;
}

template <class T>
std::enable_if_t<std::is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  if constexpr (std::is_same_v<T, bool>) {
    x = c != '0';
  } else {
    using U = std::make_unsigned_t<T>;
    U u = static_cast<U>((c == '-' ? buf[l++] : c) & 15);
    for (; buf[l] > ' '; ++l) (u *= 10) += static_cast<U>(buf[l] & 15);
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

template <class T>
bool scan(std::vector<T>&);

template <class T, std::size_t N>
bool scan(std::array<T, N>&);

template <class T1, class T2>
bool scan(std::pair<T1, T2>&);

template <class... Ts>
bool scan(std::tuple<Ts...>&);

template <class... Ts>
std::enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(std::forward<Ts>(xs)));
}

template <class T>
bool scan(std::vector<T>& v) {
  return std::all_of(v.begin(), v.end(), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
}

template <class T, std::size_t N>
bool scan(std::array<T, N>& a) {
  return std::all_of(a.begin(), a.end(), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
}

template <class T1, class T2>
bool scan(std::pair<T1, T2>& p) {
  return scan(p.first, p.second);
}

template <class... Ts>
bool scan(std::tuple<Ts...>& t) {
  return std::apply([](auto&... es) { return scan(es...); }, t);
}

template <class T, class... Args>
T input(Args&&... args) {
  T ret(std::forward<Args>(args)...);
  scan(ret);
  return ret;
}

namespace print_impl {

char buf[1 << 15];
int i;

__attribute__((destructor)) void dtor() {
  if (write(STDOUT_FILENO, buf, i) == -1) std::abort();
}

template <char = 0>
void print(char c = 0) {
  if (sizeof(buf) - i < 64) {
    if (write(STDOUT_FILENO, buf, i) == -1) std::abort();
    i = 0;
  }
  if (c) buf[i++] = c;
}

template <char = 0, class T>
std::enable_if_t<std::is_integral_v<T>> print(T x) {
  print();
  if constexpr (std::is_same_v<T, bool>)
    print("01"[x]);
  else
    i = static_cast<int>(std::to_chars(buf + i, std::end(buf), x).ptr - buf);
}

template <char = 0, class T>
std::enable_if_t<std::is_floating_point_v<T>> print(T x) {
  print();
  if constexpr (std::is_same_v<T, float>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.6f", x);
  if constexpr (std::is_same_v<T, double>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.15f", x);
  if constexpr (std::is_same_v<T, long double>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.18Lf", x);
}

} // namespace print_impl

using print_impl::print;

template <char = 0>
void print(std::string_view s) {
  for (char c : s) print(c);
}

template <char = 0>
void print(std::vector<bool>::reference r) {
  print(static_cast<bool>(r));
}

template <char Sep = ' ', class T>
void print(const std::vector<T>&);

template <char Sep = ' ', class T, std::size_t N>
void print(const std::array<T, N>&);

template <char Sep = ' ', class T1, class T2>
void print(const std::pair<T1, T2>&);

template <char Sep = ' ', class... Ts>
void print(const std::tuple<Ts...>&);

template <char Sep = ' ', class... Ts>
std::enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  char c = 0;
  (..., (print(std::exchange(c, Sep)), print(std::forward<Ts>(xs))));
}

template <char Sep, class T>
void print(const std::vector<T>& v) {
  char c = 0;
  for (const T& e : v) {
    print(std::exchange(c, Sep));
    print(e);
  }
}

template <char Sep, class T, std::size_t N>
void print(const std::array<T, N>& a) {
  for (int i = 0; i < static_cast<int>(N); ++i) {
    if (i) print(Sep);
    print(a[i]);
  }
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

template <class T, std::size_t N>
std::array<T, N>& operator++(std::array<T, N>&);

template <class T1, class T2>
std::pair<T1, T2>& operator++(std::pair<T1, T2>&);

template <class... Ts>
std::tuple<Ts...>& operator++(std::tuple<Ts...>&);

template <class T>
std::vector<T>& operator++(std::vector<T>& v) {
  for (T& e : v) ++e;
  return v;
}

template <class T>
std::vector<T> operator++(std::vector<T>&& v) {
  return std::move(++v);
}

template <class T, std::size_t N>
std::array<T, N>& operator++(std::array<T, N>& a) {
  for (T& e : a) ++e;
  return a;
}

template <class T, std::size_t N>
std::array<T, N> operator++(std::array<T, N>&& a) {
  return std::move(++a);
}

template <class T1, class T2>
std::pair<T1, T2>& operator++(std::pair<T1, T2>& p) {
  ++p.first, ++p.second;
  return p;
}

template <class T1, class T2>
std::pair<T1, T2> operator++(std::pair<T1, T2>&& p) {
  std::move(++p);
}

template <class... Ts>
std::tuple<Ts...>& operator++(std::tuple<Ts...>& t) {
  std::apply([](auto&... es) { (..., ++es); }, t);
  return t;
}

template <class... Ts>
std::tuple<Ts...> operator++(std::tuple<Ts...>&& t) {
  return std::move(++t);
}

template <class T, std::size_t N>
std::array<T, N>& operator--(std::array<T, N>&);

template <class T1, class T2>
std::pair<T1, T2>& operator--(std::pair<T1, T2>&);

template <class... Ts>
std::tuple<Ts...>& operator--(std::tuple<Ts...>&);

template <class T>
std::vector<T>& operator--(std::vector<T>& v) {
  for (T& e : v) --e;
  return v;
}

template <class T>
std::vector<T> operator--(std::vector<T>&& v) {
  return std::move(--v);
}

template <class T, std::size_t N>
std::array<T, N>& operator--(std::array<T, N>& a) {
  for (T& e : a) --e;
  return a;
}

template <class T, std::size_t N>
std::array<T, N> operator--(std::array<T, N>&& a) {
  return std::move(--a);
}

template <class T1, class T2>
std::pair<T1, T2>& operator--(std::pair<T1, T2>& p) {
  --p.first, --p.second;
  return p;
}

template <class T1, class T2>
std::pair<T1, T2> operator--(std::pair<T1, T2>&& p) {
  std::move(--p);
}

template <class... Ts>
std::tuple<Ts...>& operator--(std::tuple<Ts...>& t) {
  std::apply([](auto&... es) { (..., --es); }, t);
  return t;
}

template <class... Ts>
std::tuple<Ts...> operator--(std::tuple<Ts...>&& t) {
  return std::move(--t);
}

template <class Derived, class Base, class C = typename std::iterator_traits<Base>::iterator_category,
          class R = typename std::iterator_traits<Base>::reference,
          class D = typename std::iterator_traits<Base>::difference_type>
class iterator_base {
  Derived& derived() { return static_cast<Derived&>(*this); }
  const Derived& derived() const { return static_cast<const Derived&>(*this); }

 public:
  using iterator_category = C;
  using value_type = std::decay_t<R>;
  using difference_type = D;
  using reference = R;
  using pointer = void;

  reference operator*() const { return *derived().base(); }

  Derived& operator++() {
    ++derived().base();
    return derived();
  }
  Derived& operator--() {
    --derived().base();
    return derived();
  }

  Derived& operator+=(difference_type n) {
    derived().base() += n;
    return derived();
  }
  Derived& operator-=(difference_type n) {
    derived().base() -= n;
    return derived();
  }

  reference operator[](difference_type n) const { return *(derived() + n); }

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

  friend Derived operator+(const Derived& x, difference_type n) {
    Derived ret = x;
    ret += n;
    return ret;
  }
  friend Derived operator+(difference_type n, const Derived& x) { return x + n; }

  friend Derived operator-(const Derived& x, difference_type n) {
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

template <class Derived, class Diff>
class view_base {
  auto begin() const { return static_cast<const Derived&>(*this).begin(); }
  auto end() const { return static_cast<const Derived&>(*this).end(); }

 public:
  bool empty() const { return begin() == end(); }
  explicit operator bool() const { return !empty(); }

  auto size() const { return std::distance(begin(), end()); }

  decltype(auto) front() const { return *begin(); }
  decltype(auto) back() const { return *std::prev(end()); }

  decltype(auto) operator[](Diff n) const { return begin()[n]; }

  friend bool scan(Derived x) {
    return std::all_of(x.begin(), x.end(), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
  }

  template <char Sep = ' '>
  friend void print(Derived x) {
    char c = 0;
    for (const auto& e : x) {
      print(std::exchange(c, Sep));
      print(e);
    }
  }
};

template <class I, class Diff = typename std::iterator_traits<I>::difference_type>
class subrange : public view_base<subrange<I>, Diff> {
 public:
  subrange(I first, I last) : begin_(first), end_(last) {}
  template <class R>
  subrange(R&& r) : subrange(std::begin(r), std::end(r)) {}

  I begin() const { return begin_; }
  I end() const { return end_; }

  subrange& advance(Diff n) {
    std::advance(begin_, std::min(n, this->size()));
    return *this;
  }

  subrange next(Diff n = 1) const {
    subrange ret = *this;
    ret.advance(n);
    return ret;
  }
  subrange prev(Diff n = 1) const { return next(-n); }

 private:
  I begin_;
  I end_;
};

template <class R>
subrange(R&& r) -> subrange<decltype(std::begin(r))>;

template <class Pred>
class filtered {
  template <class I, class Traits = std::iterator_traits<I>>
  class view : public view_base<view<I>, typename Traits::difference_type> {
    using category = std::common_type_t<typename Traits::iterator_category, std::bidirectional_iterator_tag>;
    class iterator : public iterator_base<iterator, I, category> {
     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(base), parent_(parent) {}

      I& base() { return base_; }
      const I& base() const { return base_; }

      iterator& operator++() {
        ++base_;
        while (base_ != parent_->r_.end() && !std::invoke(parent_->pred_, *base_)) ++base_;
        return *this;
      }
      iterator& operator--() {
        --base_;
        while (!std::invoke(parent_->pred_, *base_)) --base_;
        return *this;
      }

      friend bool operator==(const iterator& x, const iterator& y) { return x.base_ == y.base_; }

     private:
      I base_;
      const view* parent_;
    };

   public:
    view(Pred pred, subrange<I> r) : pred_(pred), r_(r), cached_(false) {}

    auto begin() const {
      if (!std::exchange(cached_, true))
        while (r_ && !std::invoke(pred_, r_.front())) r_.advance(1);
      return iterator(r_.begin(), this);
    }
    auto end() const { return iterator(r_.end(), this); }

   private:
    Pred pred_;
    mutable subrange<I> r_;
    mutable bool cached_;
  };

 public:
  explicit filtered(Pred pred) : pred_(pred) {}

  template <class R>
  friend auto operator|(R&& r, filtered f) {
    return view<decltype(std::begin(r))>(f.pred_, std::forward<R>(r));
  }

 private:
  Pred pred_;
};

template <class F>
class mapped {
  template <class I, class Traits = std::iterator_traits<I>>
  class view : public view_base<view<I>, typename Traits::difference_type> {
    class iterator : public iterator_base<iterator, I, typename Traits::iterator_category,
                                          std::invoke_result_t<F, typename Traits::reference>> {
     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(base), parent_(parent) {}

      I& base() { return base_; }
      const I& base() const { return base_; }

      decltype(auto) operator*() const { return std::invoke(parent_->f_, *base_); }

      friend bool operator==(const iterator& x, const iterator& y) { return x.base_ == y.base_; }

      friend auto operator-(const iterator& x, const iterator& y) { return x.base_ - y.base_; }

     private:
      I base_;
      const view* parent_;
    };

   public:
    view(F f, subrange<I> r) : f_(f), r_(r) {}

    auto begin() const { return iterator(r_.begin(), this); }
    auto end() const { return iterator(r_.end(), this); }

   private:
    F f_;
    subrange<I> r_;
  };

 public:
  explicit mapped(F f) : f_(f) {}

  template <class R>
  friend auto operator|(R&& r, mapped m) {
    return view<decltype(std::begin(r))>(m.f_, std::forward<R>(r));
  }

 private:
  F f_;
};

template <class T>
class strided {
  static_assert(std::is_integral_v<T>);
  static_assert(!std::is_same_v<T, bool>);

  template <class I, class Traits = std::iterator_traits<I>>
  class view : public view_base<view<I>, typename Traits::difference_type> {
    class iterator : public iterator_base<iterator, I> {
      auto stride() const { return static_cast<typename Traits::difference_type>(parent_->n_); }

     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(base), parent_(parent) {}

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

      iterator& operator+=(typename Traits::difference_type n) {
        if (n < 0) return *this -= -n;
        base_ += std::min(stride() * n, std::distance(base_, parent_->r_.end()));
        return *this;
      }
      iterator& operator-=(typename Traits::difference_type n) {
        if (n <= 0) return *this += -n;
        if (base_ == parent_->r_.end()) {
          base_ -= (parent_->r_.size() - 1) / stride() * stride() - parent_->r_.size();
          --n;
        }
        base_ -= stride() * n;
        return *this;
      }

      friend bool operator==(const iterator& x, const iterator& y) { return x.base_ == y.base_; }

      friend typename Traits::difference_type operator-(const iterator& x, const iterator& y) {
        if (x.base_ < y.base_) return -(y - x);
        return ((x.base_ - y.base_) + (x.stride() - 1)) / x.stride();
      }

     private:
      I base_;
      const view* parent_;
    };

   public:
    view(T n, subrange<I> r) : n_(n), r_(r) {}

    auto begin() const { return iterator(r_.begin(), this); }
    auto end() const { return iterator(r_.end(), this); }

   private:
    T n_;
    subrange<I> r_;
  };

 public:
  explicit strided(T n) : n_(n) { assert(1 <= n); }

  template <class R>
  friend auto operator|(R&& r, strided s) {
    return view<decltype(std::begin(r))>(s.n_, std::forward<R>(r));
  }

 private:
  T n_;
};

template <int N>
struct elements_t {
  template <class R>
  friend auto operator|(R&& r, elements_t) {
    return std::forward<R>(r) | mapped([](auto&& e) -> decltype(auto) { return std::get<N>(std::forward<decltype(e)>(e)); });
  }
};

template <int N>
inline constexpr elements_t<N> elements;

struct reversed_t {
  template <class R>
  friend auto operator|(R&& r, reversed_t) {
    return subrange(std::make_reverse_iterator(std::end(r)), std::make_reverse_iterator(std::begin(r)));
  }
} inline constexpr reversed;

struct to_vector_t {
  template <class R>
  friend auto operator|(R&& r, to_vector_t) {
    return std::vector(std::begin(r), std::end(r));
  }
} inline constexpr to_vector;

template <class T>
class int_iterator : public iterator_base<int_iterator<T>, T, std::random_access_iterator_tag, T, T> {
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

        unsigned long long x =
            (unsigned long long)(((__uint128_t)(z)*im) >> 64);

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
        m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b

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

} // namespace internal

} // namespace atcoder

namespace atcoder {

namespace internal {

template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =__uint128_t;

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

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

} // namespace internal

} // namespace atcoder

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

} // namespace internal

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

} // namespace internal

} // namespace atcoder

namespace rj {

void main() {
  using Fp = atcoder::modint1000000007;
  const int max_n = int(2e5);
  std::vector<Fp> p2(max_n + 1);
  p2[0] = 1;
  for (int i : rep(max_n)) p2[i + 1] = p2[i] * 2;

  for (int n; scan(n);) {
    std::vector<int> c(30);
    for ([[maybe_unused]] int i : rep(n)) {
      ++c[__builtin_ctz(input<int>())];
    }
    std::vector<int> sc(31);
    for (int i : per(30)) sc[i] = c[i] + sc[i + 1];
    Fp ans = (p2[c[0]] - 1) * p2[n - c[0]];
    for (int x : rep(1, 30) | filtered([&](const auto& _) { return 2 <= c[_]; })) {
      ans += (p2[c[x] - 1] - 1) * p2[sc[x + 1]];
    }
    println(ans.val());
  }
}

} // namespace rj