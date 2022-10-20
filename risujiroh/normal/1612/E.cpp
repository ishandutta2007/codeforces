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
  decltype(auto) back() const { return *end(); }

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

struct reversed_t {
  template <class R>
  friend auto operator|(R&& r, reversed_t) {
    return subrange(std::reverse_iterator(std::end(r)), std::reverse_iterator(std::begin(r)));
  }
} constexpr reversed;

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
        base_ = std::find_if(++base_, parent_->r_.end(), parent_->pred_);
        return *this;
      }
      iterator& operator--() {
        for (--base_; !parent_->pred_(*base_);) --base_;
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
        while (r_ && !pred_(r_.front())) r_.advance(1);
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
    using category = std::common_type_t<typename Traits::iterator_category, std::random_access_iterator_tag>;
    class iterator : public iterator_base<iterator, I, category, std::invoke_result_t<F, typename Traits::reference>> {
     public:
      iterator() = default;
      iterator(I base, const view* parent) : base_(base), parent_(parent) {}

      I& base() { return base_; }
      const I& base() const { return base_; }

      decltype(auto) operator*() const { return parent_->f_(*base_); }

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

template <class T>
constexpr T inf = std::numeric_limits<T>::max() / 2;

template <class T, class U = T>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}

template <class T, class U = T>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

int main() {
  const int L = int(2e5);
  int n = input<int>();
  std::vector<int> m(n), k(n);
  for (int i : rep(n)) {
    scan(m[i], k[i]);
    --m[i];
  }
  using ld = long double;
  ld max = 0;
  std::vector<int> ans;
  for (int t : rep(1, 21)) {
    std::vector<int> s(L);
    for (int i : rep(n)) {
      s[m[i]] += std::min(k[i], t);
    }
    std::vector order(int_iterator(0), int_iterator(L));
    std::partial_sort(order.begin(), order.begin() + t, order.end(), [&](const auto& _1, const auto& _2) { return s[_1] > s[_2]; });
    ld cur = 0;
    for (int i : rep(t)) {
      cur += s[order[i]];
    }
    cur /= t;
    if (chmax(max, cur)) {
      order.resize(t);
      ans = std::move(order);
    }
  }
  println(int(ans.size()));
  println(++ans);
}