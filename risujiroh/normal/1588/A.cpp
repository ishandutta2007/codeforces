#include <bits/stdc++.h>
#include <unistd.h>

namespace scan_impl {

char buf[1 << 15];
int l = sizeof(buf);
int r = l;

bool scan(char& c) {
  for (;; ++l) {
    if (int t = r - l; t < 64) {
      std::move(buf + l, buf + r, buf);
      l = 0;
      r = t + read(STDIN_FILENO, buf + t, int(sizeof(buf)) - t);
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
    x = c - '0';
  } else {
    std::make_unsigned_t<T> u = (c == '-' ? buf[l++] : c) & 15;
    for (; buf[l] > ' '; ++l) (u *= 10) += buf[l] & 15;
    x = c == '-' ? -u : u;
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
  l = int(ptr - buf);
  return true;
}

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
    i = int(std::to_chars(buf + i, std::end(buf), x).ptr - buf);
}
template <char = 0, class T>
std::enable_if_t<std::is_floating_point_v<T>> print(T x) {
  print();
  if constexpr (std::is_same_v<T, float>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.7f", x);
  if constexpr (std::is_same_v<T, double>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.16f", x);
  if constexpr (std::is_same_v<T, long double>) i += std::snprintf(buf + i, sizeof(buf) - i, "%.19Lf", x);
}

}

using scan_impl::scan, print_impl::print;

template <class Tuple>
std::enable_if_t<std::__is_tuple_like<Tuple>{}, bool> scan(Tuple&);
bool scan(std::vector<bool>::reference r) {
  bool b, ret = scan(b);
  r = b;
  return ret;
}
template <class T>
bool scan(std::vector<T>& v) {
  return std::all_of(v.begin(), v.end(), [](auto&& e) { return scan(std::forward<decltype(e)>(e)); });
}
template <class... Args>
std::enable_if_t<sizeof...(Args) >= 2, bool> scan(Args&&... args) {
  return (... && scan(std::forward<Args>(args)));
}
template <class Tuple>
std::enable_if_t<std::__is_tuple_like<Tuple>{}, bool> scan(Tuple& t) {
  return std::apply([](auto&... es) { return scan(es...); }, t);
}

template <char Sep = ' ', class Tuple>
std::enable_if_t<std::__is_tuple_like<Tuple>{}> print(const Tuple&);
template <char = 0>
void print(std::string_view s) {
  for (char c : s) print(c);
}
template <char Sep = ' ', class T>
void print(const std::vector<T>& v) {
  char c = 0;
  for (const T& e : v) {
    print(std::exchange(c, Sep));
    print(e);
  }
}
template <char Sep = ' ', class... Args>
std::enable_if_t<sizeof...(Args) >= 2> print(Args&&... args) {
  char c = 0;
  (..., (print(std::exchange(c, Sep)), print(std::forward<Args>(args))));
}
template <char Sep, class Tuple>
std::enable_if_t<std::__is_tuple_like<Tuple>{}> print(const Tuple& t) {
  std::apply([](const auto&... es) { print<Sep>(es...); }, t);
}

template <class T = int, class... Args>
T input(Args&&... args) {
  T r(std::forward<Args>(args)...);
  scan(r);
  return r;
}
template <class... Ts, class = std::enable_if_t<sizeof...(Ts) >= 2>>
auto input() {
  return input<std::tuple<Ts...>>();
}

template <char Sep = ' ', char End = '\n', class... Args>
void println(Args&&... args) {
  print<Sep>(std::forward<Args>(args)...);
  print(End);
}

template <class T>
std::vector<T>& operator++(std::vector<T>& v) {
  for (T& e : v) ++e;
  return v;
}
template <class T>
std::vector<T> operator++(std::vector<T>&& v) {
  return std::move(++v);
}
template <class Tuple, class = std::enable_if_t<std::__is_tuple_like<Tuple>{}>>
decltype(auto) operator++(Tuple&& t) {
  std::apply([](auto&... es) { (..., ++es); }, t);
  return std::forward<Tuple>(t);
}

template <class T>
std::vector<T>& operator--(std::vector<T>& v) {
  for (T& e : v) --e;
  return v;
}
template <class T>
std::vector<T> operator--(std::vector<T>&& v) {
  return std::move(--v);
}
template <class Tuple, class = std::enable_if_t<std::__is_tuple_like<Tuple>{}>>
decltype(auto) operator--(Tuple&& t) {
  std::apply([](auto&... es) { (..., --es); }, t);
  return std::forward<Tuple>(t);
}

template <class Derived, class Base, class C = typename std::iterator_traits<Base>::iterator_category,
          class R = typename std::iterator_traits<Base>::reference,
          class D = typename std::iterator_traits<Base>::difference_type>
class iterator_base {
  Derived& derived() { return static_cast<Derived&>(*this); }
  const Derived& derived() const { return static_cast<const Derived&>(*this); }

 public:
  using iterator_category = C;
  using value_type = std::__remove_cvref_t<R>;
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

  friend Derived operator++(Derived& x, int) { return std::exchange(x, ++Derived(x)); }
  friend Derived operator--(Derived& x, int) { return std::exchange(x, --Derived(x)); }
  friend Derived operator+(const Derived& x, difference_type n) { return Derived(x) += n; }
  friend Derived operator+(difference_type n, const Derived& x) { return x + n; }
  friend Derived operator-(const Derived& x, difference_type n) { return Derived(x) -= n; }
  friend bool operator!=(const Derived& x, const Derived& y) { return !(x == y); }
  friend bool operator<(const Derived& x, const Derived& y) { return x - y < 0; }
  friend bool operator>(const Derived& x, const Derived& y) { return x - y > 0; }
  friend bool operator<=(const Derived& x, const Derived& y) { return x - y <= 0; }
  friend bool operator>=(const Derived& x, const Derived& y) { return x - y >= 0; }
};

template <class T>
class int_iterator : public iterator_base<int_iterator<T>, T, std::random_access_iterator_tag, T, T> {
  static_assert(std::is_integral_v<T>);

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

namespace rng = std::ranges;
namespace vw = rng::views;

template <class T>
auto rep(T l, T r) {
  return rng::subrange(int_iterator(l), int_iterator(std::max(l, r)));
}
template <class T>
auto rep(T n) {
  return rep<T>(0, n);
}

template <class T>
auto per(T l, T r) {
  return rep(l, r) | vw::reverse;
}
template <class T>
auto per(T n) {
  return per<T>(0, n);
}

int main() {
  input();
  for (int n; scan(n);) {
    auto a = input<std::vector<int>>(n);
    auto b = input<std::vector<int>>(n);
    rng::sort(a);
    rng::sort(b);
    println(rng::all_of(rep(n), [&](const auto& _) { return a[_] == b[_] || a[_] + 1 == b[_]; }) ? "YES" : "NO");
  }
}