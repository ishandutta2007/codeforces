#ifndef LOCAL
#define DUMP(...) void()
#define NDEBUG
#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>
#endif

using namespace std;
using i64 = long long;

#define ALL(r) ::begin(r), ::end(r)
#define UN(e) [&](auto&& $) { return e; }
#define BI(e) [&](auto&& $1, auto&& $2) { return e; }

#define TGT(s) __attribute__((target(#s)))
TGT(bmi) int bsf(i64 x) { return int(_tzcnt_u64(x)); }
TGT(lzcnt) int bsr(i64 x) { return 63 - int(_lzcnt_u64(x)); }
TGT(popcnt) int popcnt(i64 x) { return int(_mm_popcnt_u64(x)); }
TGT(bmi2) i64 bzhi(i64 x, int n) { return _bzhi_u64(x, n); }
TGT(bmi2) i64 pdep(i64 x, i64 mask) { return _pdep_u64(x, mask); }
TGT(bmi2) i64 pext(i64 x, i64 mask) { return _pext_u64(x, mask); }
#undef TGT

template <class T> bool is_pow2(T x) { return x >= 1 && (x & (x - 1)) == 0; }
template <class T> T floor_pow2(T x) { return assert(x >= 1), T(1) << bsr(x); }
template <class T> T ceil_pow2(T x) { return x <= 1 ? 1 : T(2) << bsr(x - 1); }
template <class T> T floor_div(T a, T b) { return assert(b), a / b - ((a ^ b) < 0 && a % b); }
template <class T> T ceil_div(T a, T b) { return assert(b), a / b + ((a ^ b) >= 0 && a % b); }

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = forward<U>(b), true : false; }

template <class T, class N, class Op> constexpr T power(T x, N n, Op op) {
  for (assert(n >= 1); ~n & 1; n >>= 1) x = op(x, x);
  T res = x;
  while (n >>= 1) x = op(x, x), n & 1 && (res = op(move(res), x), 0);
  return res;
}
template <class T, class N> constexpr T power(T x, N n) {
  return n ? power(n < 0 ? T(1) / x : x, abs(n), multiplies{}) : 1;
}

template <class F> struct Fix {
  F f_;
  Fix(F f) : f_(move(f)) {}
  template <class... Ts> decltype(auto) operator()(Ts&&... xs) const { return f_(ref(*this), forward<Ts>(xs)...); }
};

template <class T> struct rep {
  struct I : iterator<bidirectional_iterator_tag, T, T, void, T> {
    T i_, d_;
    operator T() const { return i_; }
    T operator*() const { return i_; }
    I& operator++() { return i_ += d_, *this; }
    I& operator--() { return i_ -= d_, *this; }
  } b_, e_;
  rep(T l, T r, T d = 1) : b_{{}, l, d}, e_{{}, l + max<T>(ceil_div(r - l, d), 0) * d, d} {}
  explicit rep(T n) : rep(0, n) {}
  I begin() const { return b_; }
  I end() const { return e_; }
};
struct Rev {
  template <class R> struct V {
    R r_;
    auto begin() const { return reverse_iterator(::end(r_)); }
    auto end() const { return reverse_iterator(::begin(r_)); }
  };
  template <class R> friend V<R> operator|(R&& r, Rev) { return {forward<R>(r)}; }
} rev;

template <class R> int sz(R&& r) { return int(size(forward<R>(r))); }
template <class I> int sz(I b, I e) { return int(distance(b, e)); }

template <class, class = void> struct IsRange : false_type {};
template <class T>
struct IsRange<T, enable_if_t<!__is_char<decay_t<decltype(*begin(declval<T&>()))>>::__value>> : true_type {};

namespace std {

#define BINARY_OP(op) \
  template <class A, class B> enable_if_t<IsRange<A>{} && IsRange<B>{}, A>& operator op##=(A& a, const B& b) { \
    return assert(sz(a) == sz(b)), transform(ALL(a), begin(b), begin(a), BI($1 op## = $2)), a; \
  } \
  template <class A, class B> enable_if_t<IsRange<A>{} && !IsRange<B>{}, A>& operator op##=(A& a, const B& b) { \
    return for_each(ALL(a), UN($ op## = b)), a; \
  } \
  template <class A, class B> enable_if_t<IsRange<A>{}, A> operator op(const A& a, const B& b) { \
    A res = a; \
    res op## = b; \
    return res; \
  } \
  template <class A, class B> enable_if_t<!IsRange<A>{} && IsRange<B>{}, B> operator op(const A& a, const B& b) { \
    B res = b; \
    for (auto&& e : res) e = a op move(e); \
    return res; \
  }
BINARY_OP(+)
BINARY_OP(-)
BINARY_OP(*)
BINARY_OP(/)
BINARY_OP(%)
BINARY_OP(&)
BINARY_OP(|)
BINARY_OP(^)
BINARY_OP(<<)
BINARY_OP(>>)
#undef BINARY_OP

}  // namespace std

struct Scan {
  char b_[1 << 15], c_;
  int l_ = sz(b_), r_ = l_;
  bool go(char& c) {
    for (;; ++l_) {
      if (r_ - l_ < 64) r_ = (r_ - l_) + read(STDIN_FILENO, move(b_ + l_, b_ + r_, b_), sz(b_) - (r_ - l_)), l_ = 0;
      if (l_ == r_) return c = {}, false;
      if (b_[l_] > ' ') return c = b_[l_++], true;
    }
  }
  bool go(string& s) {
    if (!go(c_)) return s = {}, false;
    for (s = c_; b_[l_] > ' '; s += c_) go(c_);
    return true;
  }
  template <class T> enable_if_t<is_integral_v<T>, bool> go(T& x) {
    if (!go(c_)) return x = {}, false;
    make_unsigned_t<T> u = (c_ == '-' ? b_[l_++] : c_) & 15;
    for (; b_[l_] > ' '; ++l_) (u *= 10) += b_[l_] & 15;
    return x = c_ == '-' ? -u : u, true;
  }
  template <class T> enable_if_t<is_floating_point_v<T>, bool> go(T& x) {
    if (!go(c_)) return x = {}, false;
    char* p;
    if constexpr (is_same_v<T, float>) x = strtof(b_ + (l_ - 1), &p);
    if constexpr (is_same_v<T, double>) x = strtod(b_ + (l_ - 1), &p);
    if constexpr (is_same_v<T, long double>) x = strtold(b_ + (l_ - 1), &p);
    return l_ = sz(b_, p), true;
  }
  template <class C> auto go(C& c) -> decltype(ALL(c), true) {
    for (auto&& e : c)
      if (!go(e)) return c = {}, false;
    return true;
  }
  template <class... Ts> bool operator()(Ts&... xs) { return (... && go(xs)); }
} scan;
template <class T = int, class... Args> T input(Args&&... args) {
  T res(forward<Args>(args)...);
  scan(res);
  return res;
}
template <class... Ts> enable_if_t<sizeof...(Ts) >= 2, tuple<Ts...>> input() {
  tuple<Ts...> res;
  apply([](auto&... e) { (..., scan(e)); }, res);
  return res;
}
struct Print {
  char b_[1 << 15];
  int i_ = 0;
  void go(char c = '\0') {
    if (sz(b_) - i_ < 64 || c == -1) write(STDOUT_FILENO, b_, i_), i_ = 0;
    if (c > 0) b_[i_++] = c;
  }
  template <class T> enable_if_t<is_integral_v<T>> go(T x) { go(), i_ = sz(b_, to_chars(b_ + i_, end(b_), x).ptr); }
  template <class T> enable_if_t<is_floating_point_v<T>> go(T x) {
    go(), i_ += snprintf(b_ + i_, sz(b_) - i_, "%.20Lf", (long double)x);
  }
  template <class R> auto go(R&& r) -> decltype(ALL(r), void()) {
    char c = '\0';
    for (auto&& e : r) is_same_v<decay_t<decltype(e)>, char> || (go(exchange(c, ' ')), 0), go(e);
  }
  template <class... Ts> void operator()(Ts&&... xs) {
    char c = '\0';
    (..., (go(exchange(c, ' ')), go(forward<Ts>(xs)))), go('\n');
  }
  ~Print() { go(char(-1)); }
} print;

int main() {
  auto [n, m] = input<int, int>();
  auto [a, b] = input<string, string>();

  vector<array<int, 2>> to(m + 1);
  for (int x : rep(m + 1))
    for (int c : rep(2)) {
      auto t = char('0' + c) + b.substr(m - x);
      for (int z : rep(min(x + 1, m) + 1) | rev) {
        if (t.substr(0, z) == b.substr(m - z)) {
          to[x][c] = z;
          break;
        }
      }
    }

  vector f(m + 1, vector(n - m + 2, inf<int>));
  f[0][0] = 0;

  for (int i : rep(n) | rev) {
    vector nf(m + 1, vector(n - m + 2, inf<int>));
    for (int x : rep(m + 1))
      for (int y : rep(n - m + 2)) {
        if (f[x][y] == inf<int>) continue;
        for (int c : rep(2)) {
          int nx = to[x][c];
          int ny = y + (nx == m);
          chmin(nf[nx][ny], f[x][y] + (a[i] - '0' != c));
        }
      }
    f = move(nf);
  }

  for (int y : rep(n - m + 2)) {
    int ans = inf<int>;
    for (int x : rep(m + 1)) {
      chmin(ans, f[x][y]);
    }
    if (ans == inf<int>) ans = -1;
    print.go(ans);
    print.go(" \n"[y == n - m + 1]);
  }
}