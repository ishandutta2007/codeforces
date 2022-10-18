#line 1 "C:/Users/W/c/lib/template.cpp"

#ifndef LOCAL
#pragma GCC diagnostic warning "-w"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;
#define EXIT(out) do { OUT(out); exit(0); } while (0)
#define __overload3(_1, _2, _3, name, ...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(_repeat\
__LINE__, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = (until)-1, name##__from = (from); name >= name##__from; name--)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl "\n"
template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t & 1) res = (res * e) % mod;
    t >>= 1; e = (e * e) % mod;
  }
  return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r);
  if (r < 0) return 0;
  ll res = 1;
  rep(i, r) res *= n-i, res /= i+1;
  return res;
}
template <typename T> T divceil(T m, T d) { assert(m >= 0 and d > 0); return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
string operator*(const string& s, int times) { string res = ""; rep(times) res += s; return res; }
struct Edge {
  int to; ll cost;
  Edge(int _to) : to(_to), cost(1) {}
  Edge(int _to, ll _cost) : to(_to), cost(_cost) {}
  operator int() { return to; }
};
using Graph = vector<vector<Edge>>;
// IO
// formatted version of following is at https://shino-sky.github.io/cp-lib/library/formatted_template.cpp.html
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
class MyScanner { public: int offset = 0; char nc(){ return getchar(); }
template <typename T> void input_integer(T& var) { var = 0; T sign = 1; int cc = nc(); for (;
cc < '0' || '9' < cc; cc = nc()) if (cc == '-') sign = -1; for (; '0' <= cc && cc <= '9'; cc =
nc()) var = (var << 3) + (var << 1) + cc - '0'; var = var * sign; var += offset; } int c() {
char c; while (c = nc(), c == ' ' or c == '\n'); return c; } MyScanner& operator>>(char& var)
{ var = c(); return *this; } MyScanner& operator>>(int& var) { input_integer<int>(var); return
*this; } MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; } MyScanner&
operator>>(string& var) { var = ""; int cc = nc(); for (; !isvisiblechar(cc); cc = nc()); for
(; isvisiblechar(cc); cc = nc()) var.push_back(cc); return *this; } template <typename T>
operator T() { T x; *this >> x; return x; } template <typename T> void operator()(T &t) { *
this >> t; } template <typename T, typename... Ts> void operator()(T &t, Ts &...ts) { *this >>
t; this->operator()(ts...); } template <typename Iter> void iter(Iter first, Iter last) {
while (first != last) *this >> *first, first++; } VI vi(int n) { VI res(n); iter(all(res));
return res; } VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] = vi(m); return res; } VLL
vll(int n) { VLL res(n); iter(all(res)); return res; } VVLL vvll(int n, int m) { VVLL res(n);
rep(i, n) res[i] = vll(m); return res; } template <typename T> vector<T> v(int n) { vector<T>
res(n); iter(all(res)); return res; } private: int isvisiblechar(int c) { return 0x21 <= c &&
c <= 0x7E; } } IN, IN1{-1}; class MyPrinter { public: int offset = 0; template <typename T>
void output_integer(T var) { var += offset; if (var == 0) { putchar('0'); return; } if (var <
0) putchar('-'), var = -var; char stack[32]; int stack_p = 0; while (var) stack[stack_p++] =
'0' + (var % 10), var /= 10; while (stack_p) putchar(stack[--stack_p]); } MyPrinter& operator
<<(char c) { putchar(c); return *this; } MyPrinter& operator<<(double x) { printf("%.10f", x);
return *this; } template <typename T> MyPrinter& operator<<(T var) { output_integer<T>(var);
return *this; } MyPrinter& operator<<(char* str_p) { while (*str_p) putchar(*(str_p++));
return *this; } MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar(*(str_p++));
return *this; } MyPrinter& operator<<(const string& str) { const char* p = str.c_str(); const
char* l = p + str.size(); while (p < l) putchar(*p++); return *this; } template <typename T>
void operator()(T x) { *this << x << newl; } template <typename T, typename... Ts> void
operator()(T x, Ts ...xs) { *this << x << " "; this->operator()(xs...); } template <typename
Iter> void iter(Iter s, Iter t) { if (s == t) *this << "\n"; else for (; s != t; s++) *this <<
*s << " \n"[next(s, 1) == t]; } } OUT, OUT1{1}; template <typename T, typename U> MyPrinter&
operator<<(MyPrinter& out, const pair<T, U>& var) { return out << var.first << " " << var.
second; } template <typename Tuple, size_t I, size_t N, enable_if_t<I == N>* = nullptr>
MyPrinter& tuple_impl(MyPrinter& out, const Tuple& var) { return out; } template <typename
Tuple, size_t I, size_t N, enable_if_t<I != N>* = nullptr> MyPrinter& tuple_impl(MyPrinter&
out, const Tuple& var) { out << get<I>(var) << " "; return tuple_impl<Tuple, I+1, N>(out, var)
; } template <typename... Ts> MyPrinter& operator<<(MyPrinter& out, const tuple<Ts...>& var) {
return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(out, var); } template <typename T, typename
U> MyScanner& operator>>(MyScanner& in, pair<T, U>& var) { return in >> var.first >> var.
second; } template <typename Tuple, size_t I, size_t N, enable_if_t<I == N>* = nullptr>
MyScanner& tuple_impl(MyScanner& in, Tuple& var) { return in; } template <typename Tuple,
size_t I, size_t N, enable_if_t<I != N>* = nullptr> MyScanner& tuple_impl(MyScanner& in, Tuple
& var) { in >> get<I>(var); return tuple_impl<Tuple, I+1, N>(in, var); } template <typename...
Ts> MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) { return tuple_impl<tuple<Ts...>,
0, sizeof...(Ts)>(in, var); }
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *itr;
itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, set<T>& set_var) { os << "{"; repi(itr,
set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}"; return
os; } void dump_func() { debugos << newl; } template <class Head, class... Tail> void
dump_func(Head &&head, Tail &&...tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos
<< ", "; } dump_func(std::move(tail)...); }
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#pragma GCC diagnostic pop
#line 2 "C:/Users/W/c/lib/util/modint.cpp"

template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);

template <ll MOD = 1000000007>
class modint {
public:
  static constexpr ll Mod = MOD;
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint<MOD>& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint<MOD>& rhs) {
    return value != rhs.value;
  }
  constexpr modint<MOD> operator-() const {
    return modint<MOD>(0) - *this;
  }
  constexpr modint<MOD> operator+(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) += rhs;
  }
  constexpr modint<MOD> operator-(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) -= rhs;
  }
  constexpr modint<MOD> operator*(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) *= rhs;
  }
  constexpr modint<MOD> operator/(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) /= rhs;
  }
  constexpr modint<MOD>& operator+=(const modint<MOD>& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint<MOD>& operator-=(const modint<MOD>& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint<MOD>& operator*=(const modint<MOD>& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint<MOD>& operator/=(const modint<MOD>& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint<MOD>& operator++() {
    return *this += 1;
  }
  constexpr modint<MOD> operator++(int) {
    modint<MOD> tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint<MOD>& operator--() {
    return *this -= 1;
  }
  constexpr modint<MOD> operator--(int) {
    modint<MOD> tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


template <typename OutStream, ll MOD>
OutStream& operator<<(OutStream& out, modint<MOD> n) {
  out << n.value;
  return out;
}

template <typename InStream, ll MOD>
InStream& operator>>(InStream& in, modint<MOD>& n) {
  ll var; in >> var; n = modint<MOD>(var);
  return in;
}

template <ll MOD>
constexpr modint<MOD> pow(modint<MOD> base, ll exp) {
  modint<MOD> res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
template <ll MOD>
modint<MOD> choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint<MOD>(0);
  modint<MOD> nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}
#line 2 "C:/Users/W/c/lib/math/squarematrix.cpp"

// originally written by @beet-aizu
template <typename M = ll>
struct SquareMatrix {
  using arr = vector<M>;
  using mat = vector<arr>;
  int n;
  mat dat;

  SquareMatrix(int _n) : n(_n), dat(n, arr(n)) {}

  SquareMatrix(const mat& _dat) : n(_dat.size()), dat(_dat) {}

  bool operator==(const SquareMatrix& rhs) const { return dat == rhs.dat; }
  bool operator!=(const SquareMatrix& rhs) const { return dat != rhs.dat; }

  size_t size() const { return n; }
  arr& operator[](size_t k) { return dat[k]; }
  const arr& operator[](size_t k) const { return dat[k]; }

  SquareMatrix add_identity() const { return SquareMatrix(); }
  SquareMatrix mul_identity() const {
    SquareMatrix res(n);
    rep(i, n) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    rep(i, n) rep(j, n) rep(k, n)
      res[i][j] += (dat[i][k] * rhs[k][j]);
    return res;
  }

  arr operator*(const arr& rhs) const {
    arr res(n);
    rep(i, n) rep(j, n) res[i] += dat[i][j] * rhs[j];
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++)
        res[i][j] = dat[i][j] + rhs[i][j];
    return res;
  }

  SquareMatrix pow(ll exp) const {
    SquareMatrix a = *this, res = mul_identity();
    while (exp) {
      if (exp & 1) res = res * a;
      a = a * a;
      exp >>= 1;
    }
    return res;
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, n) rep(j, i + 1, n) swap(res.dat[i][j], res.dat[j][i]);
    return res;
  }
};
#line 4 "e.cpp"


using mint = modint<998244353LL>;

int main() {
  ll n = IN, m = IN, l = IN, r = IN;
  r++;
  if (n*m % 2 == 1) EXIT(pow(mint(r-l), n*m));
  auto P = SquareMatrix<mint>(2);
  ll od = r/2 - l/2, ev = r - l - od;
  P[0][0] = P[1][1] = mint(ev);
  P[0][1] = P[1][0] = mint(od);
  OUT((P.pow(n*m)*decltype(P)::arr({1, 0}))[0]);
}