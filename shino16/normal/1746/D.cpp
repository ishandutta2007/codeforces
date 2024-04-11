#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3")
/* #pragma GCC target("avx2") */
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
#line 3 "lib/io.hpp"

struct int1 {
  int val; int1(int a = 1) : val(a - 1) {}
  operator int() const { return val; }
};

template <size_t BufSize = 1 << 26>
class stdin_reader {
 public: stdin_reader() { buf[fread(buf, 1, sizeof(buf), stdin)] = 0; } template <class T> enable_if_t<is_integral_v<T>> read(T& x) { skip(); [[maybe_unused]] bool neg = false; if constexpr (is_signed_v<T>) neg = *p == '-' ? (p++, true) : false; x = 0; while (*p > ' ') x = x * 10 + (*p++ & 0x0F); if constexpr (is_signed_v<T>) x = neg ? -x : x; } template <class T> void_t<decltype(&T::val)> read(T& x) { x = T((unsigned)(*this)); } void read(char*& q) { skip(); q = p; while (*p > ' ') p++; *p = 0; } template <size_t N> void read(char (&s)[N]) { read(s); } void read(string& s) { skip(); char* p0 = p; while (*p > ' ') p++; s.assign(p0, p); } template <class T, void_t<decltype(tuple_size<T>::value)>* = nullptr> void read(T& x) { read_tuple_impl(x, make_index_sequence<tuple_size_v<T>>{}); } template <class T, class U> void read(pair<T, U>& x) { read(x.first), read(x.second); } template <class T, size_t N> void read(T (&a)[N]) { for (auto& e : a) read(e); } template <class T> operator T() { T x; return read(x), x; } template <class... Ts> void operator()(Ts&... xs) { (read(xs), ...); } int operator--() { return (int)*this - 1; } template <class T> T* arr(int n) { T* p = new T[n + 1]; rep(i, n) read(p[i]); return p; } template <class T> void vec(vector<T>& v, int n) { v.resize(n); for (auto& e : v) read(e); } template <class T> vector<T> vec(int n) { vector<T> v; return vec(v, n), v; } template <class... Ts> tuple<vector<Ts>...> vecs(int n) { tuple<vector<Ts>...> res; vecs_impl(res, n, make_index_sequence<sizeof...(Ts)>{}); return res; } template <class T> void vvec(vector<vector<T>>& v, int n, int m) { v.resize(n); for (auto& e : v) vec(e, m); } template <class T> vector<vector<T>> vvec(int n, int m) { vector<vector<T>> v; return vvec(v, n, m), v; } template <class... Ts> auto cols(int n) { return transpose(vec<tuple<Ts...>>(n)); } private: char buf[BufSize], *p = buf; void skip() { while (*p <= ' ') p++; } template <class T, size_t... Is> void read_tuple_impl(T& x, index_sequence<Is...>) { (*this)(get<Is>(x)...); } template <class T, size_t... Is> void vecs_impl(T& x, int n, index_sequence<Is...>) { (vec(get<Is>(x), n), ...); } template <class T, size_t... Is> static auto transpose_impl(const vector<T>& v, index_sequence<Is...>) { tuple<vector<decay_t<tuple_element_t<Is, T>>>...> w; (get<Is>(w).reserve(v.size()), ...); for (const auto& row : v) (get<Is>(w).push_back(get<Is>(row)), ...); return w; } template <class T> static auto transpose(const vector<T>& v) { return transpose_impl(v, make_index_sequence<tuple_size_v<T>>{}); }
};

template <size_t BufSize = 1 << 26>
class stdout_writer {
 public: ~stdout_writer() { flush(); } void flush() { fwrite(buf, 1, p - buf, stdout), p = buf; } void write_char(char c) { *p++ = c; } void write(char c) { write_char(c); } template <class T> enable_if_t<is_integral_v<T>> write(T x) { if (!x) return write_char('0'); if constexpr (is_signed_v<T>) if (x < 0) write_char('-'), x = -x; static char tmp[16]; char* q = end(tmp); while (x >= 10000) memcpy(q -= 4, digits.data + x % 10000 * 4, 4), x /= 10000; if (x < 10) write_char('0' + x); else if (x < 100) write_char('0' + (uint8_t)x / 10), write_char('0' + (uint8_t)x % 10); else if (x < 1000) memcpy(p, digits.data + x * 4 + 1, 3), p += 3; else memcpy(p, digits.data + x * 4, 4), p += 4; memcpy(p, q, end(tmp) - q), p += end(tmp) - q; } template <class T> void_t<decltype(&T::val)> write(T x) { write(x.val()); } void write(double x) { static char tmp[40]; sprintf(tmp, "%.15f", x); write(tmp); } void write(const char* s) { while (*s) *p++ = *s++; } void write(const string& s) { memcpy(p, s.c_str(), s.size()), p += s.size(); } template <class T, class U> void write(const pair<T, U>& x) { write(x.first), write_char(' '), write(x.second); } template <class... Ts> void write(const tuple<Ts...>& x) { write_tuple(x, make_index_sequence<sizeof...(Ts)>{}); } template <class... Ts> void write(const Ts&... xs) { ((write(xs), write_char(' ')), ...), --p; } template <class... Ts> void writeln(const Ts&... xs) { write(xs...), write_char('\n'); } template <class... Ts> void operator()(const Ts&... xs) { writeln(xs...); } template <class It> void iter(It first, It last, char sep = ' ') { if (first == last) write_char('\n'); else { while (first != last) write(*first++), write_char(sep); p[-1] = '\n'; } } void del() { *--p = 0; } void Yes(bool b = true) { writeln(b ? "Yes" : "No"); } void YES(bool b = true) { writeln(b ? "YES" : "NO"); } void Takahashi(bool b = true) { writeln(b ? "Takahashi" : "Aoki"); } private: char buf[BufSize], *p = buf; template <class T, size_t... Is> void write_tuple(const T& x, index_sequence<Is...>) { ((write(get<Is>(x)), write_char(' ')), ...), --p; } struct four_digits { char data[40000]; constexpr four_digits() : data() { for (int i = 0; i < 10000; i++) for (int n = i, j = 4; j--;) data[i * 4 + j] = n % 10 + '0', n /= 10; } } static constexpr digits{}; public:
#define INSTANT(s) void s() { writeln(#s); }
  INSTANT(No) INSTANT(NO) INSTANT(Aoki) INSTANT(possible) INSTANT(Possible) INSTANT(POSSIBLE) INSTANT(impossible) INSTANT(Impossible) INSTANT(IMPOSSIBLE)
#undef INSTANT
};

stdin_reader<> in;
stdout_writer<> out;

#line 3 "lib/util/seed.hpp"

auto seed() {
#if defined(LOCAL) || defined(FIX_SEED)
  return 314169265258979;
#endif
  return chrono::steady_clock::now().time_since_epoch().count();
}
#line 3 "lib/util/rand.hpp"

uint32_t rand32() {
  static uint32_t x = seed();
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return x;
}
#line 3 "lib/util/hash.hpp"

template <class T, class = void>
struct simple_hash : hash<T> { };

template <class T>
struct simple_hash<T, void_t<decltype(tuple_size<T>::value)>> {
  size_t operator()(const T& x) const {
    return hash_impl(x, make_index_sequence<tuple_size_v<T>>{});
  }
 private:
  template <size_t... Is>
  static size_t hash_impl(const T& x, index_sequence<Is...>) {
    size_t res = 0;
    ((void)(res ^= (res << 16) ^ simple_hash<tuple_element_t<Is, T>>{}(get<Is>(x))),
     ...);
    return res;
  }
};

uint64_t splitmix64(uint64_t x) {
  // http://xorshift.di.unimi.it/splitmix64.c
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}

template <class T, class = void>
struct anti_hack_hash;

template <class T>
struct anti_hack_hash<T, enable_if_t<is_convertible_v<T, uint64_t>>> {
  size_t operator()(T x) const {
    static const uint64_t ofs = seed();
    return splitmix64((uint64_t)x + ofs);
  }
};

template <class T>
struct anti_hack_hash<T, void_t<decltype(tuple_size<T>::value)>> {
  size_t operator()(const T& x) const {
    return hash_impl(x, make_index_sequence<tuple_size_v<T>>{});
  }
 private:
  static auto make_seed() {
    array<uint64_t, tuple_size_v<T>> res;
    res[0] = seed();
    rep(i, tuple_size_v<T> - 1) res[i + 1] = splitmix64(res[i]) + seed();
    return res;
  }
  template <size_t... Is>
  static size_t hash_impl(const T& x, index_sequence<Is...>) {
    static auto seed = make_seed();
    size_t res = 0;
    ((void)(res = splitmix64(res + get<Is>(x) + get<Is>(seed))), ...);
    return res;
  }
};
#line 4 "lib/ds/hash_map.hpp"
#include <ext/pb_ds/assoc_container.hpp>

template <class K, class V, class Hash = anti_hack_hash<K>>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
#line 3 "main.cpp"

int n;
int p[200000];
int s[200000];
vector<int> ch[200000];
hash_map<int, ll> memo[200000];

ll f(int v, int k) {
  if (auto it = memo[v].find(k); it != memo[v].end()) return it->second;
  auto m = ch[v].size();
  if (m == 0) return 1LL * s[v] * k;
  int lo = k / m, hi = k / m + (k % m != 0);
  vector<ll> flo, fhi;
  flo.reserve(m), fhi.reserve(m);
  for (auto u : ch[v]) flo.push_back(f(u, lo)), fhi.push_back(f(u, hi));
  ll ans = 1LL * s[v] * k + accumulate(all(flo), 0LL);
  int chi = k - lo * m;
  rep(i, m) fhi[i] -= flo[i];
  nth_element(fhi.begin(), fhi.end() - chi, fhi.end());
  ans += accumulate(fhi.end() - chi, fhi.end(), 0LL);
  return memo[v][k] = ans;
}

void solve() {
  n = in;
  int k = in;
  rep(i, n-1) p[i+1] = --in;
  rep(i, n) s[i] = in;
  rep(v, n) ch[v].clear(), memo[v].clear();
  rep2(v, 1, n) ch[p[v]].push_back(v);
  out(f(0, k));
  rep(v, n) assert(memo[v].size() <= 2);
}

int main() {
  int T = in;
  while (T--) solve();
}