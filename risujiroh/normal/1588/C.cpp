#include <bits/stdc++.h>
#include <unistd.h>

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {

    return __builtin_ctz(n);

}

}

}

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        return d[p + size];
    }

    S prod(int l, int r) const {
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

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

using ll = long long;

namespace segtree {

using S = ll;
S op(S x, S y) { return std::max(x, y); }
S e() { return -ll(1e18); }
using type = atcoder::segtree<S, op, e>;

}

int main() {
  input();
  for (int n; scan(n);) {
    auto a = input<std::vector<int>>(n);
    std::array<std::vector<ll>, 2> s;
    s.fill(std::vector<ll>(n + 1));
    for (int i : per(n)) {
      s[0][i] = (i & 1 ? -a[i] : a[i]) + s[0][i + 1];
      s[1][i] = (i & 1 ? a[i] : -a[i]) + s[1][i + 1];
    }
    std::array<std::array<segtree::type, 2>, 2> seg;
    for (int p : {0, 1}) {
      for (int q : {0, 1}) {
        seg[p][q] = segtree::type(n + 1);
        for (int i : rep(n + 1) | vw::filter([&](const auto& _) { return (_ & 1) == q; })) {
          seg[p][q].set(i, s[p][i]);
        }
      }
    }
    std::map<ll, std::vector<int>> mp;
    for (int i : rep(n + 1)) {
      mp[s[0][i]].push_back(i);
    }
    ll ans = 0;
    for (int l : rep(n)) {

      int r = n;
      r = std::min(r, seg[l & 1][~l & 1].max_right(l, [&](const auto& _) { return _ <= s[l & 1][l]; }));
      r = std::min(r, seg[~l & 1][l & 1].max_right(l, [&](const auto& _) { return _ <= s[~l & 1][l]; }));

      const auto& v = mp[s[0][l]];
      ans += rng::upper_bound(v, r) - rng::upper_bound(v, l);
    }
    println(ans);
  }
}