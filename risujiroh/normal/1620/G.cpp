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

using ll = long long;

template <class T> inline const auto inf_v = std::numeric_limits<T>::max() / 2;
inline const auto inf = inf_v<ll>;

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

template <class T = ll, class... Args> T input(Args&&... args) {
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

template <class T> ll sz(T&& x) { return ll(std::size(std::forward<T>(x))); }

template <class T, class B> struct iter_base : std::iterator_traits<B> {
  using difference_type = ll;
  T& t_() { return static_cast<T&>(*this); }
  const T& t_() const { return static_cast<const T&>(*this); }
  decltype(auto) operator*() const { return *t_().b_; }
  auto operator->() const { return std::addressof(*t_()); }
  T& operator++() { return t_().inc_(), t_(); }
  T& operator--() { return t_().dec_(), t_(); }
  T operator++(int) { return std::exchange(t_(), std::move(++T(t_()))); }
  T operator--(int) { return std::exchange(t_(), std::move(--T(t_()))); }
  T& operator+=(ll n) { return t_().adv_(n), t_(); }
  T& operator-=(ll n) { return t_().adv_(-n), t_(); }
  decltype(auto) operator[](ll n) const { return *(t_() + n); }
  friend T operator+(T x, ll n) { return std::move(x += n); }
  friend T operator-(T x, ll n) { return std::move(x -= n); }
  friend T operator+(ll n, const T& x) { return x + n; }
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
  ll size() const { return ll(std::distance(t_().begin(), t_().end())); }
  decltype(auto) front() const { return *t_().begin(); }
  decltype(auto) back() const { return *std::prev(t_().end()); }
  decltype(auto) operator[](ll n) const { return t_().begin()[n]; }
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
  ll size() const { return sz(*r_); }
};
template <class R> struct owning_view : view_base<owning_view<R>> {
  R r_;
  owning_view(R r) : r_(std::move(r)) {}
  owning_view(owning_view&&) = default;
  owning_view& operator=(owning_view&&) = default;
  auto begin() const { return std::begin(r_); }
  auto end() const { return std::end(r_); }
  ll size() const { return sz(r_); }
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
    void adv_(ll n) { b_ += n; }
    friend ll operator-(const iter& x, const iter& y) { return ll(x.b_ - y.b_); }
  };
  R r_;
  [[no_unique_address]] F f_;
  iter begin() const { return {{}, r_.begin(), this}; }
  iter end() const { return {{}, r_.end(), this}; }
  ll size() const { return sz(r_); }
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
    using value_type = std::pair<typename iter::value_type, ll>;
    using reference = std::pair<typename iter::reference, ll>;
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
        b_ += std::min(p_->n_, ll(p_->r_.end() - b_));
      else
        for (auto _ = n_; _-- && b_ != p_->r_.end();) ++b_;
    }
    void dec_() { std::advance(b_, b_ == p_->r_.end() ? (sz(p_->r_) - 1) / p_->n_ * p_->n_ - sz(p_->r_) : -p_->n_); }
    void adv_(ll n) {
      if (n < 0) dec_(), ++n;
      b_ += std::min(p_->n_ * n, ll(p_->r_.end() - b_));
    }
    friend ll operator-(const iter& x, const iter& y) { return (ll(x.b_ - y.b_) + (x.p_->n_ - 1)) / x.p_->n_; }
  };
  R r_;
  ll n_;
  iter begin() const { return {{}, r_.begin(), this}; }
  iter end() const { return {{}, r_.end(), this}; }
  ll size() const { return (sz(r_) + (n_ - 1)) / n_; }
};
auto strided(ll n) {
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

struct int_iter : iter_base<int_iter, ll> {
  using iterator_category = std::random_access_iterator_tag;
  using value_type = ll;
  using reference = ll;
  using pointer = void;
  ll b_;
  int_iter(ll b) : b_(b) {}
  ll operator*() const { return b_; }
  void inc_() { ++b_; }
  void dec_() { --b_; }
  void adv_(ll n) { b_ += n; }
  friend ll operator-(const int_iter& x, const int_iter& y) { return x.b_ - y.b_; }
};

subrange<int_iter> rep(ll l, ll r) { return {std::min(l, r), r}; }
auto rep(ll n) { return rep(0, n); }
auto rep(ll l, ll r, ll d) { return rep(l, r) | strided(d); }
template <class... Args> auto per(Args... args) { return rep(args...) | reversed; }

template <int D> struct mdrep : view_base<mdrep<D>> {
  struct iter : iter_base<iter, std::array<ll, D>> {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = std::array<ll, D>;
    using reference = std::array<ll, D>;
    using pointer = void;
    std::array<ll, D> b_;
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
    void adv_(ll n) { b_ = (*p_)[(*p_)(b_) + n]; }
    friend ll operator-(const iter& x, const iter& y) { return (*x.p_)(x.b_) - (*y.p_)(y.b_); }
  };
  std::array<ll, D> l_, r_;
  mdrep(const std::array<ll, D>& l, const std::array<ll, D>& r) : l_(l), r_(r) {
    for (auto d = 0; d < D; ++d) assert(l[d] < r[d]);
  }
  explicit mdrep(const std::array<ll, D>& n) : mdrep({}, n) {}
  ll operator()(const std::array<ll, D>& n) const {
    auto ret = n[0] - l_[0];
    for (auto d = 1; d < D; ++d) (ret *= r_[d] - l_[d]) += n[d] - l_[d];
    return ret;
  }
  auto operator[](ll n) const {
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

void solve(ll);

int main() { solve(0); }

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

#define ALL(f, r, ...) [&](auto _v_) { return f(_v_.begin(), _v_.end(), ##__VA_ARGS__); }(r | all)
#define ALL2(f, r1, r2, ...) [&](auto _v2_) { return ALL(f, r1, _v2_.begin(), _v2_.end(), ##__VA_ARGS__); }(r2 | all)
#define LAMBDA(...) [&]([[maybe_unused]] const auto& _) { return __VA_ARGS__; }
#define LAMBDA2(...) [&](const auto& _1, const auto& _2) { return __VA_ARGS__; }
#define EACH(r, ...) ALL(std::for_each, r, [&](auto&& _) { __VA_ARGS__; })
#define IF(...) filtered(LAMBDA(__VA_ARGS__))
#define MAP(...) mapped(LAMBDA(__VA_ARGS__))
#define FOLD(init, ...) folded(init, LAMBDA2(__VA_ARGS__))

using fp = atcoder::modint998244353;

void solve(ll) {
  auto n = input();
  auto c = std::vector<std::array<int, 26>>(n);
  for (auto i : rep(n)) {
    EACH(input<std::string>(), ++c[i][_ - 'a']);
  }
  auto ans = std::vector<fp>(1 << n);
  auto a = std::vector<std::array<int, 26>>(1 << n);
  a[0].fill(inf_v<int>);
  for (auto mask : rep(1, 1 << n)) {
    a[mask] = a[mask & (mask - 1)];
    auto i = ll(__builtin_ctz(mask));
    for (auto x : rep(26)) {
      chmin(a[mask][x], c[i][x]);
    }
    ans[mask] = a[mask] | FOLD(fp(1), _1 * (_2 + 1));
    if (__builtin_parity(mask) == 0) {
      ans[mask] = -ans[mask];
    }
  }
  DUMP(ans);
  for (auto i : rep(n)) {
    for (auto mask : rep(1 << n) | IF(~_ >> i & 1)) {
      ans[mask | 1 << i] += ans[mask];
    }
  }
  DUMP(ans);
  auto hashed = ll(0);
  for (auto mask : rep(1 << n)) {
    hashed ^= ll(ans[mask].val()) * __builtin_popcount(mask) * (rep(n) | IF(mask >> _ & 1) | FOLD(ll(0), _1 + (_2 + 1)));
  }
  println(hashed);
}