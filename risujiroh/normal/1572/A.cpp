#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <unistd.h>
#include <x86intrin.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <charconv>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <deque>
#include <experimental/type_traits>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifndef DUMP
#define DUMP(...) void(0)
#endif

namespace cp {

using namespace std;

struct identity {
  template <class T> constexpr T&& operator()(T&& t) const { return forward<T>(t); }
};
template <class T> struct type_identity { using type = T; };
template <class T> using type_identity_t = typename type_identity<T>::type;

template <class F> struct y_combinator_result {
  F f_;
  template <class T> explicit y_combinator_result(T&& f) : f_(forward<T>(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) { return f_(ref(*this), forward<Args>(args)...); }
};
template <class F> decltype(auto) y_combinator(F&& f) { return y_combinator_result<decay_t<F>>(forward<F>(f)); }

__attribute__((target("popcnt"))) int popcnt(uint64_t x) { return int(_mm_popcnt_u64(x)); }
__attribute__((target("bmi"))) int bsf(uint64_t x) { return int(_tzcnt_u64(x)); }
__attribute__((target("lzcnt"))) int bsr(uint64_t x) { return 63 - int(_lzcnt_u64(x)); }
__attribute__((target("bmi2"))) uint64_t pdep(uint64_t x, uint64_t mask) { return _pdep_u64(x, mask); }
__attribute__((target("bmi2"))) uint64_t pext(uint64_t x, uint64_t mask) { return _pext_u64(x, mask); }
template <class T> bool has_single_bit(T x) { return x && (x & (x - 1)) == 0; }
template <class T> T bit_width(T x) {
  assert(x >= 0);
  return bsr(x) + 1;
}
template <class T> T bit_floor(T x) {
  assert(x >= 1);
  return T(1) << bsr(x);
}
template <class T> T bit_ceil(T x) { return x <= 1 ? 1 : T(1) << bit_width(x - 1); }

template <class T, class N> constexpr T power(T x, N n) {
  if (n == 0) return 1;
  for (; ~n & 1; n >>= 1) x *= x;
  if (n < 0) x = T(1) / x, n = -n;
  T res = x;
  while (n >>= 1) {
    x *= x;
    if (n & 1) res *= x;
  }
  return res;
}
template <class T, class N, class Op> T power(T x, N n, Op op) {
  assert(n >= 1);
  for (; ~n & 1; n >>= 1) x = op(x, x);
  T res = x;
  while (n >>= 1) {
    x = op(x, x);
    if (n & 1) res = op(res, x);
  }
  return res;
}

template <class T> using Size = decltype(declval<T>().size());
template <class R, class = decltype(declval<R>().begin())> constexpr auto len(R&& r) {
  if constexpr (experimental::is_detected_v<Size, R>)
    return int(r.size());
  else
    return distance(r.begin(), r.end());
}
template <class T, int N> constexpr int len(const T (&)[N]) { return N; }

template <class I, class Category, class T, class Distance, class Reference> struct IterBase {
  using iterator_category = Category;
  using value_type = T;
  using difference_type = Distance;
  using pointer = void;
  using reference = Reference;
  T operator[](Distance n) const { return *(*(const I*)(this) + n); }
  friend I operator++(I& a, int) { return exchange(a, ++I(a)); }
  friend I operator--(I& a, int) { return exchange(a, --I(a)); }
  friend I operator+(I a, Distance n) { return a += n; }
  friend I operator+(Distance n, I a) { return a += n; }
  friend I operator-(I a, Distance n) { return a -= n; }
  friend bool operator!=(I a, I b) { return !(a == b); }
  friend bool operator>(I a, I b) { return b < a; }
  friend bool operator<=(I a, I b) { return !(b < a); }
  friend bool operator>=(I a, I b) { return !(a < b); }
};

template <class T> struct Range {
  static_assert(is_integral_v<T>);
  struct Iter : IterBase<Iter, random_access_iterator_tag, T, T, T> {
    T v_;
    explicit Iter(T v = 0) : v_(v) {}
    T operator*() const { return v_; }
    Iter& operator++() { return ++v_, *this; }
    Iter& operator--() { return --v_, *this; }
    Iter& operator+=(T n) { return v_ += n, *this; }
    Iter& operator-=(T n) { return v_ -= n, *this; }
    friend T operator-(Iter a, Iter b) { return *a - *b; }
    friend bool operator==(Iter a, Iter b) { return *a == *b; }
    friend bool operator<(Iter a, Iter b) { return *a < *b; }
  } begin_, end_;
  Range(type_identity_t<T> l, T r) : begin_(min(l, r)), end_(r) {}
  explicit Range(T n = 0) : Range(0, n) {}
  Iter begin() const { return begin_; }
  Iter end() const { return end_; }
};

template <class T> vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T> vector<T>& operator++(vector<T>& a) {
  for (auto&& e : a) ++e;
  return a;
}
template <class T> vector<T>& operator--(vector<T>& a) {
  for (auto&& e : a) --e;
  return a;
}
template <class T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  if (len(a) < len(b)) a.reserve(len(b)), a.resize(len(b));
  for (auto&& i : Range(len(b))) a[i] += b[i];
  return a;
}
template <class T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  if (len(a) < len(b)) a.reserve(len(b)), a.resize(len(b));
  for (auto&& i : Range(len(b))) a[i] -= b[i];
  return a;
}
template <class T> vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  assert(len(a) == len(b));
  for (auto&& i : Range(len(a))) a[i] *= b[i];
  return a;
}
template <class T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  assert(len(a) == len(b));
  for (auto&& i : Range(len(a))) a[i] /= b[i];
  return a;
}
#define GO(op) \
  template <class T, class U> vector<T>& operator op##=(vector<T>& a, const U& b) { \
    for (auto&& e : a) e op## = b; \
    return a; \
  } \
  template <class T> vector<T> operator op(vector<T> a, const vector<T>& b) { return move(a op## = b); } \
  template <class T, class U> vector<T> operator op(vector<T> a, const U& b) { return move(a op## = b); } \
  template <class T, class U> vector<T> operator op(const U& a, vector<T> b) { \
    for (auto&& e : b) e = a op e; \
    return b; \
  }
GO(+)
GO(-)
GO(*)
GO(/)
#undef GO

template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class U = T> bool chmin(T& a, U&& b) { return b < a ? a = forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T& a, U&& b) { return a < b ? a = forward<U>(b), true : false; }

#ifdef NDEBUG
mt19937_64 rng(_rdtsc());
#else
mt19937_64 rng;
#endif

struct Scan {
  char buf[1 << 15], temp;
  int l = len(buf), r = l;
  bool go(char& c) {
    for (;; ++l) {
      if (r - l < 64) r = (r - l) + read(STDIN_FILENO, move(buf + l, buf + r, buf), len(buf) - (r - l)), l = 0;
      if (l == r) return c = {}, false;
      if (buf[l] > ' ') return c = buf[l++], true;
    }
  }
  bool go(string& s) {
    if (!go(temp)) return s = {}, false;
    for (s = temp; buf[l] > ' '; s += temp) go(temp);
    return true;
  }
  template <class T, enable_if_t<is_integral_v<T>, int> = 0> bool go(T& x) {
    if (!go(temp)) return x = {}, false;
    make_unsigned_t<T> u = (temp == '-' ? buf[l++] : temp) & 15;
    for (; buf[l] > ' '; ++l) (u *= 10) += buf[l] & 15;
    return x = temp == '-' ? -u : u, true;
  }
  template <class T, enable_if_t<is_floating_point_v<T>, int> = 0> bool go(T& x) {
    if (!go(temp)) return x = {}, false;
    char* endptr;
    if constexpr (is_same_v<T, float>) x = strtof(buf + (l - 1), &endptr);
    if constexpr (is_same_v<T, double>) x = strtod(buf + (l - 1), &endptr);
    if constexpr (is_same_v<T, long double>) x = strtold(buf + (l - 1), &endptr);
    return l = int(endptr - buf), true;
  }
  template <class C, enable_if_t<!is_same_v<typename C::value_type, char>, int> = 0> bool go(C& c) {
    for (auto&& e : c)
      if (!go(e)) return c = {}, false;
    return true;
  }
  template <class... Args> bool operator()(Args&... args) { return (..., go(args)); }
} scan;
struct Print {
  char buf[1 << 15], temp;
  int p = 0;
  void go(char c = '\0') {
    if (len(buf) - p < 64 || c == -1) write(STDOUT_FILENO, buf, p), p = 0;
    if (c > 0) buf[p++] = c;
  }
  void go(string_view sv) {
    for (char c : sv) go(c);
  }
  template <class T, enable_if_t<is_integral_v<T>, int> = 0> void go(T x) {
    go(), p = int(to_chars(buf + p, end(buf), x).ptr - buf);
  }
  template <class T, enable_if_t<is_floating_point_v<T>, int> = 0> void go(T x) {
    go(), p += snprintf(buf + p, len(buf) - p, "%.20Lf", (long double)(x));
  }
  template <class R, enable_if_t<!is_same_v<decay_t<decltype(*begin(declval<R>()))>, char>, int> = 0> void go(R&& r) {
    temp = '\0';
    for (auto&& e : r) go(exchange(temp, ' ')), go(e);
  }
  template <class... Args> void operator()(Args&&... args) {
    temp = '\0', (..., (go(exchange(temp, ' ')), go(forward<Args>(args)))), go('\n');
  }
  ~Print() { go(char(-1)); }
} print;

void main();

}  // namespace cp

int main() { cp::main(); }

#undef NDEBUG
#include <cassert>

namespace cp {

void main() {
  int tt;
  scan(tt);
  while (tt--) {
    int n;
    scan(n);
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int v : Range(n)) {
      int k;
      scan(k);
      while (k--) {
        int u;
        scan(u);
        --u;
        g[u].push_back(v);
        ++deg[v];
      }
    }

    set<int> se;
    for (int v : Range(n)) {
      if (deg[v] == 0) {
        se.insert(v);
      }
    }

    int cnt = 0;
    int ans = 1;
    int t = 0;
    while (len(se)) {
      auto it = se.lower_bound(t);
      if (it == end(se)) {
        t = 0;
        ++ans;
        continue;
      }
      int v = *it;
      t = v;
      ++cnt;
      se.erase(it);
      for (int u : g[v]) {
        --deg[u];
        if (deg[u] == 0) {
          se.insert(u);
        }
      }
    }

    if (cnt < n) {
      print(-1);
    } else {
      print(ans);
    }
  }
}

}  // namespace cp