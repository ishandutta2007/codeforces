#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, ndvec(forward<Ts>(xs)...)); }
#line 3 "lib/util/transpose.hpp"

template <class T, size_t... Is>
auto transpose_impl(const vector<T>& v, index_sequence<Is...>) {
  tuple<vector<decay_t<tuple_element_t<Is, T>>>...> w;
  (get<Is>(w).reserve(v.size()), ...);
  for (const auto& row : v)
    (get<Is>(w).push_back(get<Is>(row)), ...);
  return w;
}

template <class T>
auto transpose(const vector<T>& v) {
  return transpose_impl(v, make_index_sequence<tuple_size_v<T>>{});
}
#line 4 "lib/io.hpp"

struct int1 {
  int val;
  int1(int a = 1): val(a - 1) {}
  operator int() const { return val; }
};

template <size_t BufSize = 1 << 26>
class stdin_reader {
 public:
  stdin_reader() { buf[fread(buf, 1, sizeof(buf), stdin)] = 0; }

  template <class T>
  enable_if_t<is_integral_v<T>> read(T& x) {
    skip(); [[maybe_unused]] bool neg = false;
    if constexpr (is_signed_v<T>) neg = *p == '-' ? (p++, true) : false;
    x = 0; while (*p > ' ') x = x * 10 + (*p++ & 0x0F);
    if constexpr (is_signed_v<T>) x = neg ? -x : x;
  }
  template <class T> void_t<decltype(&T::val)> read(T& x) { x = T((unsigned)(*this)); }
  void read(char* q) {
    skip(); char* p0 = p; while (*p > ' ') p++;
    copy(p0, p, q);
  }
  template <size_t N> void read(char (&s)[N]) { read(s); }
  void read(string& s) {
    skip(); char* p0 = p; while (*p > ' ') p++;
    s.assign(p0, p);
  }
  template <class T, void_t<decltype(tuple_size<T>::value)>* = nullptr>
  void read(T& x) { read_tuple_like(x, make_index_sequence<tuple_size_v<T>>{}); }
  template <class T, class U> void read(pair<T, U>& x) { read(x.first), read(x.second); }
  template <class T, size_t N> void read(T (&a)[N]) { for (auto& e : a) read(e); }

  template <class T> operator T() { T x; return read(x), x; }
  template <class... Ts> void operator()(Ts&... xs) { (read(xs), ...); }
  int operator--() { return (int)*this - 1; }
  template <class T> void vec(vector<T>& v, int n) { v.resize(n); for (auto& e : v) read(e); }
  template <class T> vector<T> vec(int n) { vector<T> v; return vec(v, n), v; }
  template <class T>
  void vvec(vector<vector<T>>& v, int n, int m) { v.resize(n); for (auto& e : v) vec(e, m); }
  template <class T>
  vector<vector<T>> vvec(int n, int m) { vector<vector<T>> v; return vvec(v, n, m), v; }
  template <class... Ts> auto transpose(int n) { return ::transpose(vec<tuple<Ts...>>(n)); }

 private:
  char buf[BufSize], *p = buf;
  void skip() { while (*p <= ' ') p++; }
  template <class T, size_t... Is>
  void read_tuple_like(T& x, index_sequence<Is...>) { (*this)(get<Is>(x)...); }
};

template <size_t BufSize = 1 << 26>
class stdout_writer {
 public:
  ~stdout_writer() { flush(); }
  void flush() { fwrite(buf, 1, p - buf, stdout), p = buf; }
  void write_char(char c) { *p++ = c; }
  void write(char c) { write_char(c); }
  template <class T> enable_if_t<is_integral_v<T>> write(T x) {
    if (!x) return write_char('0');
    if constexpr (is_signed_v<T>) if (x < 0) write_char('-'), x = -x;
    static char tmp[16];
    char* q = end(tmp);
    while (x >= 10000) memcpy(q -= 4, digits.data + x % 10000 * 4, 4), x /= 10000;
    if (x < 10) write_char('0' + x);
    else if (x < 100)
      write_char('0' + (uint8_t)x / 10), write_char('0' + (uint8_t)x % 10);
    else if (x < 1000) memcpy(p, digits.data + x * 4 + 1, 3), p += 3;
    else memcpy(p, digits.data + x * 4, 4), p += 4;
    memcpy(p, q, end(tmp) - q), p += end(tmp) - q;
  }
  template <class T> void_t<decltype(&T::val)> write(T x) { write(x.val()); }
  void write(double x) {
    static char tmp[40]; sprintf(tmp, "%.10f", x); write(tmp);
  }
  void write(const char* s) { while (*s) *p++ = *s++; }
  void write(const string& s) { memcpy(p, s.c_str(), s.size()), p += s.size(); }
  template <class T, class U>
  void write(const pair<T, U>& x) { write(x.first), write_char(' '), write(x.second); }
  template <class... Ts>
  void write(const tuple<Ts...>& x) { write_tuple(x, make_index_sequence<sizeof...(Ts)>{}); }
  template <class... Ts>
  void write(const Ts&... xs) { ((write(xs), write_char(' ')), ...), --p; }
  template <class... Ts> void writeln(const Ts&... xs) { write(xs...), write_char('\n'); }

  template <class... Ts> void operator()(const Ts&... xs) { writeln(xs...); }
  template <class It> void iter(It first, It last, char sep = ' ') {
    if (first == last) write_char('\n');
    else {
      while (first != last) write(*first++), write_char(sep);
      p[-1] = '\n';
    }
  }

#define INSTANT(s) \
  void s() { writeln(#s); }
  INSTANT(No) INSTANT(NO) INSTANT(Aoki)
  INSTANT(possible) INSTANT(Possible) INSTANT(POSSIBLE)
  INSTANT(impossible) INSTANT(Impossible) INSTANT(IMPOSSIBLE)
#undef INSTANT
  void Yes(bool b = true) { writeln(b ? "Yes" : "No"); }
  void YES(bool b = true) { writeln(b ? "YES" : "NO"); }
  void Takahashi(bool b = true) { writeln(b ? "Takahashi" : "Aoki"); }

 private:
  char buf[BufSize], *p = buf;
  template <class T, size_t... Is> void write_tuple(const T& x, index_sequence<Is...>) {
    ((write(get<Is>(x)), write_char(' ')), ...), --p;
  }
  struct four_digits {
    char data[40000];
    constexpr four_digits() : data() {
      for (int i = 0; i < 10000; i++)
        for (int n = i, j = 4; j--;) data[i * 4 + j] = n % 10 + '0', n /= 10;
    }
  } static constexpr digits{};
};

static stdin_reader<> in;
static stdout_writer<> out;
#line 3 "lib/la/vec.hpp"

template <class T, class U, class F, size_t... Is>
void zip_with_impl(T&& a, U&& b, F f, index_sequence<Is...>) {
  (f(get<Is>(a), get<Is>(b)), ...);
}

template <class T>
T& operator+=(T& a, const T& b) {
  zip_with_impl(
      a, b, [](auto&& x, auto&& y) { x += y; },
      make_index_sequence<tuple_size_v<T>>{});
  return a;
}

template <class T>
T& operator-=(T& a, const T& b) {
  zip_with_impl(
      a, b, [](auto&& x, auto&& y) { x -= y; },
      make_index_sequence<tuple_size_v<T>>{});
  return a;
}

template <class T>
T operator+(const T& a, const T& b) {
  T c(a);
  c += b;
  return c;
}

template <class T>
T operator-(const T& a, const T& b) {
  T c(a);
  c -= b;
  return c;
}

template <class T>
T dot(const T& a, const T& b) {
  T res(0);
  zip_with_impl(a, b, [&](auto&& x, auto&& y) { res += x * y; });
  return res;
}

template <class T, enable_if_t<tuple_size_v<T> == 2>* = nullptr>
auto det(const T& a, const T& b) {
  return get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b);
}
#line 3 "lib/arith/sqrt.hpp"

template <class T>
T floor_sqrt(T x) {
  if (x == 0) return 0;
  T s = round(sqrt(x));
  return (s + x / s) / 2;
}

template <class T>
T ceil_sqrt(T x) {
  return x == 0 ? 0 : floor_sqrt(x - 1) + 1;
}
#line 2 "lib/numeric/int/bisect.hpp"

template <class I, class F>
I bisect(I l, I r, F p) {
  while (l != r) {
    I m = ((l ^ r) >> 1) + (l & r);
    if (p(m)) l = m + 1;
    else r = m;
  }
  return l;
}
#line 5 "lib/ds/cht.hpp"

template <class T>
using linear_fn = pair<T, T>;

template <class T>
T apply(linear_fn<T> f, T x) {
  return f.first * x + f.second;
}

// checked (CF 660F)

// min/max of linear functions
template <class T, bool Maximize = false>
class convex_hull_trick {
 public:
  convex_hull_trick() : hull({linear_fn<T>{0, sentinel()}}) { }
  template <class It>
  convex_hull_trick(It first, It last) {
    init(first, last);
  }
  void clear() {
    hull.clear(), edges.clear();
    hull.emplace_back(0, sentinel());
  }
  template <bool Sorted = false, class It>
  void init(It first, It last) {
    clear();
    int n = distance(first, last);
    hull.reserve(n + 1), edges.reserve(n);
    if (!Sorted) sort(first, last);
    for (auto it = first; it != last; it++) {
      while (!edges.empty() &&
             (det(edges.back(), *it - hull.back()) <= 0) ^ Maximize)
        hull.pop_back(), edges.pop_back();
      edges.push_back(*it - hull.back()), hull.push_back(*it);
    }
  }
  void rebuild() {
    vector<linear_fn<T>> fs(all(hull));
    fs.insert(fs.end(), all(aux));
    sort(all(fs));
    init(all(fs));
  }

  void add(linear_fn<T> f) { aux.push_back(f); }
  void add(T a, T b) { aux.emplace_back(a, b); }

  T apply(T x) {
    linear_fn<T> f(1, -x);
    int i = bisect<int>(0, edges.size(), [&](int j) {
      return (det(f, edges[j]) < 0) ^ Maximize;
    });
    T ans = ::apply(hull[i], x);
    for (auto g : aux) ans = min(ans, ::apply(g, x));
    return ans;
  }

 private:
  vector<linear_fn<T>> hull, edges, aux;
  static T sentinel() {
    return floor_sqrt(numeric_limits<T>::max()) * (Maximize ? -1 : 1);
  }
};
#line 3 "main.cpp"

int n = in;
auto a = in.vec<int>(n);
convex_hull_trick<ll, true> cht;
vector<linear_fn<ll>> fs;

ll rec(int L, int R) {
  if (R - L == 1) return max(0, a[L]);
  int m = (L + R) / 2;
  ll ans = max(rec(L, m), rec(m, R));
  fs.clear();
  fs.emplace_back(0, 0);
  ll sum = 0;
  repr2(l, L, m) {
    sum += a[l];
    fs.emplace_back(fs.back().first + 1, fs.back().second + sum);
  }
  cht.init<true>(all(fs));
  ll x = 0, c = 0;
  ans = max(ans, cht.apply(0));
  rep2(r, m, R) {
    x += a[r];
    c += 1LL * (r - m + 1) * a[r];
    ans = max(ans, cht.apply(x) + c);
  }
  return ans;
}

int main() {
  out(rec(0, n));
}