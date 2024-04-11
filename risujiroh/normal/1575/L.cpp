#ifndef LOCAL
#define DUMP(...) void()
#define NDEBUG
#include <bits/stdc++.h>
#include <unistd.h>
#include <x86intrin.h>
#endif

#include <algorithm>
#include <cassert>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#endif

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
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
 public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, f);
        if (r & 1) all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <bool (*g)(S)> int max_right(int l) {
    return max_right(l, [](S x) { return g(x); });
  }
  template <class G> int max_right(int l, G g) {
    assert(0 <= l && l <= _n);
    assert(g(e()));
    if (l == _n) return _n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!g(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (g(op(sm, d[l]))) {
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

  template <bool (*g)(S)> int min_left(int r) {
    return min_left(r, [](S x) { return g(x); });
  }
  template <class G> int min_left(int r, G g) {
    assert(0 <= r && r <= _n);
    assert(g(e()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!g(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (g(op(d[r], sm))) {
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
  std::vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size) lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};

}  // namespace atcoder

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

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
using F = int;
S mapping(F f, S x) { return x += f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
using Seg = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
  int n = input();
  auto a = input<vector<int>>(n) - 1;
  vector<vector<int>> v(n);
  for (int i : rep(n))
    if (a[i] <= i) v[a[i]].push_back(i - a[i]);
  int ans = 0;
  Seg seg(n);
  for (int x : rep(n)) {
    for (int i : v[x] | rev) {
      S t = seg.get(i);
      int j = seg.max_right(i, [&](S s) { return s <= t; });
      DUMP(x, i, j);
      seg.apply(i, j, 1);
    }
    chmax(ans, seg.get(n - 1 - x));
  }
  print(ans);
}