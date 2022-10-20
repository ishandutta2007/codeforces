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
#define FN(e) [&](auto&& $) { return e; }

__attribute__((target("bmi"))) int bsf(i64 x) { return int(_tzcnt_u64(x)); }
__attribute__((target("lzcnt"))) int bsr(i64 x) { return 63 - int(_lzcnt_u64(x)); }
__attribute__((target("popcnt"))) int popcnt(i64 x) { return int(_mm_popcnt_u64(x)); }
__attribute__((target("bmi2"))) i64 bzhi(i64 x, int n) { return _bzhi_u64(x, n); }
__attribute__((target("bmi2"))) i64 pdep(i64 x, i64 mask) { return _pdep_u64(x, mask); }
__attribute__((target("bmi2"))) i64 pext(i64 x, i64 mask) { return _pext_u64(x, mask); }

template <class T> bool is_pow2(T x) { return x >= 1 && (x & (x - 1)) == 0; }
template <class T> T floor_pow2(T x) { return assert(x >= 1), T(1) << bsr(x); }
template <class T> T ceil_pow2(T x) { return x <= 1 ? 1 : T(2) << bsr(x - 1); }
template <class T> T floor_div(T a, T b) { return assert(b), a / b - ((a ^ b) < 0 && a % b); }
template <class T> T ceil_div(T a, T b) { return assert(b), a / b + ((a ^ b) >= 0 && a % b); }

template <class T, class N, class Op> constexpr T power(T x, N n, Op op) {
  assert(n >= 1);
  for (; ~n & 1; n >>= 1) x = op(x, x);
  T res = x;
  while (n >>= 1) {
    x = op(x, x);
    if (n & 1) res = op(res, x);
  }
  return res;
}
template <class T, class N> constexpr T power(T x, N n) {
  if (n < 0) x = T(1) / x, n = -n;
  return n ? power(x, n, multiplies{}) : 1;
}

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = forward<U>(b), true : false; }

template <class F> struct Fix {
  F f_;
  Fix(F f) : f_(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const {
    return f_(ref(*this), forward<Args>(args)...);
  }
};

template <class T> struct rep {
  struct I : iterator<bidirectional_iterator_tag, T, T, void, T> {
    T i_;
    operator T() const { return i_; }
    T operator*() const { return i_; }
    I& operator++() { return ++i_, *this; }
    I& operator--() { return --i_, *this; }
  } b_, e_;
  rep(T l, T r) : b_{{}, l}, e_{{}, max(l, r)} {}
  rep(T n) : rep(0, n) {}
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

template <class T, class U = T> using if_tuple_t = enable_if_t<__is_tuple_like<T>{}, U>;

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
  template <class T> if_tuple_t<T, bool> go(T& t) {
    return apply([&](auto&... e) { return (... && go(e)); }, t);
  }
  template <class C, class = enable_if_t<!__is_tuple_like<C>{}>> auto go(C& c) -> decltype(ALL(c), true) {
    for (auto&& e : c)
      if (!go(e)) return c = {}, false;
    return true;
  }
  template <class... Args> bool operator()(Args&... args) { return (... && go(args)); }
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
  char b_[1 << 15], c_;
  int i_ = 0;
  void go(char c = '\0') {
    if (sz(b_) - i_ < 64 || c == -1) write(STDOUT_FILENO, b_, i_), i_ = 0;
    if (c > 0) b_[i_++] = c;
  }
  template <class T> enable_if_t<is_integral_v<T>> go(T x) { go(), i_ = sz(b_, to_chars(b_ + i_, end(b_), x).ptr); }
  template <class T> enable_if_t<is_floating_point_v<T>> go(T x) {
    go(), i_ += snprintf(b_ + i_, sz(b_) - i_, "%.20Lf", (long double)x);
  }
  template <class T> if_tuple_t<T, void> go(T&& t) {
    c_ = '\0', apply([&](auto&&... e) { (..., (go(exchange(c_, ' ')), go(forward<decltype(e)>(e)))); }, forward<T>(t));
  }
  template <class R, class = enable_if_t<!__is_tuple_like<R>{}>> auto go(R&& r) -> decltype(ALL(r), void()) {
    c_ = '\0', for_each(ALL(r), FN((is_same_v<decay_t<decltype($)>, char> ? void() : go(exchange(c_, ' ')), go($))));
  }
  template <class... Args> void operator()(Args&&... args) {
    c_ = '\0', (..., (go(exchange(c_, ' ')), go(forward<Args>(args)))), go('\n');
  }
  ~Print() { go(char(-1)); }
} print;

int main() {
  for (int tt = input(); tt--;) {
    auto [h, w] = input<int, int>();
    auto s = input<vector<string>>(h);

    vector suff(w, vector<int>(h + 1));
    for (int j : rep(w)) {
      for (int i : rep(h) | rev) {
        suff[j][i] = (s[i][j] & 1) + suff[j][i + 1];
      }
    }

    int ans = inf<int>;
    for (int l : rep(h)) {
      for (int r : rep(l + 5, h + 1)) {
        vector<int> a(w), b(w + 1);
        for (int j : rep(w) | rev) {
          a[j] = (r - l - 2) - (suff[j][l + 1] - suff[j][r - 1]);
          b[j] = b[j + 1];
          b[j] += s[l][j] == '0';
          b[j] += suff[j][l + 1] - suff[j][r - 1];
          b[j] += s[r - 1][j] == '0';
        }

        vector mn(w + 1, inf<int>);
        for (int j : rep(w) | rev) {
          mn[j] = min(a[j] - b[j], mn[j + 1]);
        }

        for (int x : rep(w - 3)) {
          // for (int y : rep(x + 3, w)) {
          //   chmin(ans, a[x] + (b[x + 1] - b[y]) + a[y]);
          // }
          chmin(ans, a[x] + b[x + 1] + mn[x + 3]);
        }
      }
    }
    print(ans);
  }
}