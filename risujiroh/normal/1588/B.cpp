#include <bits/stdc++.h>
#include <unistd.h>

bool scan(char& c) { return std::scanf(" %c", &c) != EOF; }
bool scan(std::string& s) {
  char c;
  if (!scan(c)) return false;
  for (s = c; (c = char(std::getchar())) > ' ';) s += c;
  return true;
}
template <class T>
std::enable_if_t<std::is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) return false;
  if constexpr (std::is_same_v<T, bool>) {
    x = c - '0';
  } else {
    std::make_unsigned_t<T> u = (c == '-' ? std::getchar() : c) & 15;
    for (char t; (t = char(std::getchar())) > ' ';) (u *= 10) += t & 15;
    x = c == '-' ? -u : u;
  }
  return true;
}
template <class T>
std::enable_if_t<std::is_floating_point_v<T>, bool> scan(T& x) {
  if constexpr (std::is_same_v<T, float>) return std::scanf("%f", &x) != EOF;
  if constexpr (std::is_same_v<T, double>) return std::scanf("%lf", &x) != EOF;
  if constexpr (std::is_same_v<T, long double>) return std::scanf("%Lf", &x) != EOF;
}

template <char = 0>
void print(char c = 0) {
  if (c) std::putchar(c);
  if (c == '\n') std::fflush(stdout);
}
template <char = 0, class T>
std::enable_if_t<std::is_integral_v<T>> print(T x) {
  if constexpr (std::is_same_v<T, bool>) {
    print("01"[x]);
  } else {
    char buf[64];
    std::for_each(buf, std::to_chars(buf, std::end(buf), x).ptr, [](char c) { print(c); });
  }
}
template <char = 0, class T>
std::enable_if_t<std::is_floating_point_v<T>> print(T x) {
  if constexpr (std::is_same_v<T, float>) std::printf("%.7f", x);
  if constexpr (std::is_same_v<T, double>) std::printf("%.16f", x);
  if constexpr (std::is_same_v<T, long double>) std::printf("%.19Lf", x);
}

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

    using ll = long long;
    int i = 0, j = 0, k = 0;
    auto query = [&](int l, int r) -> ll {
      println('?', l, r);

      return input<ll>();
    };
    auto go = [&](ll x) -> int {
      if (x <= 0) return -1;
      ll ret = *rng::partition_point(rep(2, n - 1), [&](const auto& _) { return _ * ll(_ - 1) / 2 <= x; }) - 1;
      return ret * (ret - 1) / 2 == x ? int(ret) : -1;
    };
    j = *rng::partition_point(rep(2, n - 1), [&](int m) -> bool {
      ll x = query(1, m);
      if (x == 0) return true;
      int len = go(x);
      if (len == -1) return false;
      if (i) {
        return len == m - i + 1;
      } else {
        if (query(m - len + 1, m) == x) {
          i = m - len + 1;
          return true;
        } else {
          return false;
        }
      }
    });
    k = j + go(query(j, n)) - 1;
    println('!', i, j, k);
  }
}