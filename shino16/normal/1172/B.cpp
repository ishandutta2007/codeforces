#ifndef LOCAL
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#endif

#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iostream>
#include <cmath>
#include <cassert>
#include <cstring>

using namespace std;

using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1000000007;
const ll INF_LL = 1'000'000'000'000'000'007;

#define __overload3(_1, _2, _3, name,...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(_name##__LINE__, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = until - 1, name##__from = (from); name >= name##__from; name--)

#define EXIT(out) do { OUT(out); exit(0); } while (0)

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define fs first
#define sn second

#ifdef LOCAL
#define debug(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";debugos<<(v)<<newl;} while (0)
#define debugv(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";for(auto e:(v)){debugos<<e<<" ";}debugos<<newl;} while (0)
#define debuga(m,w) do {debugos << "L" << __LINE__ << " " << #m << " > ";for(int x=0;x<(w);x++){debugos<<(m)[x]<<" ";}debugos<<newl;} while (0)
#define debugaa(m,h,w) do {debugos << "L" << __LINE__ << " " << #m << " > \n";for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){debugos<<(m)[y][x]<<" ";}debugos<<newl;}} while (0)
#else
#define debug(v) do {v;} while (0)
#define debugv(v) do; while (0)
#define debuga(m,w) do; while (0)
#define debugaa(m,h,w) do; while (0)
#endif

#define newl "\n"
constexpr int dr[] = {1,-1,0,0};  // LRUD
constexpr int dc[] = {0,0,1,-1};

bool inside(int r, int c, int H, int W) {
  return 0 <= r and r < H and 0 <= c and c < W;
}

template <typename T> bool chmin(T& var, T x) {
  if (var > x) {
    var = x;
    return true;
  } else return false;
}

template <typename T> bool chmax(T& var, T x) {
  if (var < x) {
    var = x;
    return true;
  } else return false;
}

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

ll power(ll e, int t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t&1) res = (res * e) % mod;
    t >>= 1;
    e = (e * e) % mod;
  }
  return res;
}

template <typename T> T divceil(T m, T d) {
  assert(m >= 0 and d > 0);
  return (m+d-1)/d;
}

template<typename T>
vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

string operator*(const string& s, int times) {
  string res = "";
  rep(times) res += s;
  return res;
}

class MyScanner {
public:
  int offset = 0;
  char nc(){
#ifdef LOCAL
    return getchar();
#else
    static char buf[100000],*L=buf,*R=buf;
    return L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;
#endif
  }
  template <typename T> void input_integer(T& var) {
    var = 0; T sign = 1;
    int cc = nc();
    for (; cc<'0' || '9'<cc; cc = nc())
      if (cc == '-') sign = -1;
    for (; '0' <= cc && cc <= '9'; cc = nc())
      var = (var << 3) + (var << 1) + cc - '0';
    var = var * sign; var += offset;
  }
  int c() { char c; while (c = nc(), c == ' ' or c == '\n'); return c; }
  MyScanner& operator>>(char& var) { var = c(); return *this; }
  MyScanner& operator>>(int& var) { input_integer<int>(var); return *this; }
  MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; }
  MyScanner& operator>>(string& var) {
    var = ""; int cc = nc();
    for (; !isvisiblechar(cc); cc = nc());
    for (; isvisiblechar(cc); cc = nc())
      var.push_back(cc);
    return *this;
  }
  template <typename T>
  operator T() { T x; *this >> x; return x; }
  template <typename T>
  void operator()(T &t) { *this >> t; }
  template <typename T, typename... Ts>
  void operator()(T &t, Ts &...ts) { *this >> t; this->operator()(ts...); }
  template <typename Iter>
  void iter(Iter first, Iter last) { while (first != last) *this >> *first, first++; }
  VI vi(int n) { VI res(n); iter(all(res)); return res; }
  VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] = vi(m); return res; }
  VLL vll(int n) { VLL res(n); iter(all(res)); return res; }
  VVLL vvll(int n, int m) { VVLL res(n); rep(i, n) res[i] = vll(m); return res; }
  template <typename T>
  vector<T> v(int n) { vector<T> res(n); iter(all(res)); return res; }
private:
  int isvisiblechar(int c) { return 0x21 <= c && c <= 0x7E; }
} IN, IN1{-1};

class MyPrinter {
public:
  template <typename T>
  void output_integer(T var) {
    if (var == 0) { putchar('0'); return; }
    if (var < 0) putchar('-'), var = -var;
    char stack[32]; int stack_p = 0;
    while (var) stack[stack_p++] = '0' + (var % 10), var /= 10;
    while (stack_p) putchar(stack[--stack_p]);
  }
  MyPrinter& operator<<(char c) { putchar(c); return *this; }
  MyPrinter& operator<<(double x) { printf("%.10f\n", x); return *this; }
  template <typename T> MyPrinter& operator<<(T var) { output_integer<T>(var); return *this; }
  MyPrinter& operator<<(char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const string& str) {
    const char* p = str.c_str();
    const char* l = p + str.size();
    while (p < l) putchar(*p++);
    return *this;
  }
  template <typename T>
  void operator()(T x) { *this << x << newl; }
  template <typename T, typename... Ts>
  void operator()(T x, Ts ...xs) { *this << x << " "; this->operator()(xs...); }
  template <typename Iter>
  void iter(Iter s, Iter t) {
    if (s == t) *this << "\n";
    else {
      for (; s != t; s++) {
        *this << *s << " \n"[next(s, 1) == t];
      }
    }
  }
  template <typename Range>
  void range(const Range& r) { iter(begin(r), end(r)); }
} OUT;

class DebugPrint {
public:
  template <typename T>
  DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
    return *this;
  }
} debugos;

template <typename OutStream, typename T, typename U>
OutStream& operator<<(OutStream& out, const pair<T, U>& var) {
  return out << var.first << " " << var.second;
}
template <typename OutStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
OutStream& tuple_impl(OutStream& out, const Tuple& var) {
  return out;
}
template <typename OutStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
OutStream& tuple_impl(OutStream& out, const Tuple& var) {
  out << get<I>(var) << " ";
  return tuple_impl<OutStream, Tuple, I+1, N>(out, var);
}
template <typename OutStream, typename... Ts>
OutStream& operator<<(OutStream& out, const tuple<Ts...>& var) {
  return tuple_impl<OutStream, tuple<Ts...>, 0, sizeof...(Ts)>(out, var);
}
template <typename InStream, typename T, typename U>
InStream& operator>>(InStream& in, pair<T, U>& var) {
  return in >> var.first >> var.second;
}
template <typename InStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
InStream& tuple_impl(InStream& in, Tuple& var) {
  return in;
}
template <typename InStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
InStream& tuple_impl(InStream& in, Tuple& var) {
  in >> get<I>(var);
  return tuple_impl<InStream, Tuple, I+1, N>(in, var);
}
template <typename InStream, typename... Ts>
InStream& operator>>(InStream& in, tuple<Ts...>& var) {
  return tuple_impl<InStream, tuple<Ts...>, 0, sizeof...(Ts)>(in, var);
}


class modint;
constexpr modint pow(modint, size_t);
constexpr ll MOD = 998244353;

class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint& rhs) {
    return value != rhs.value;
  }
  constexpr modint operator-() const {
    return modint(0) - *this;
  }
  constexpr modint operator+(const modint& rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint &operator-=(const modint& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint &operator*=(const modint& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint &operator/=(const modint& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint &operator++() {
    return *this += 1;
  }
  constexpr modint operator++(int) {
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint &operator--() {
    return *this -= 1;
  }
  constexpr modint operator--(int) {
    modint tmp(*this);
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


template <typename OutStream>
OutStream& operator<<(OutStream& out, modint n) {
  out << n.value;
  return out;
}

template <typename InStream>
InStream& operator>>(InStream& in, modint& n) {
  ll var; in >> var; n = modint(var);
  return in;
}

constexpr modint pow(modint base, size_t exp) {
  modint res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
modint choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint(0);
  modint nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}

template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif
FixPoint : private F
{
public:
explicit constexpr FixPoint(F&& f) noexcept
: F(std::forward<F>(f))
{}

template<typename... Args>
constexpr decltype(auto)
operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif
{
return F::operator()(*this, std::forward<Args>(args)...);
}
};


template<typename F>
static inline constexpr decltype(auto)
fix(F&& f) noexcept
{
return FixPoint<F>{std::forward<F>(f)};
}



struct binomial {
  vector<modint> fact, invfact;
  // O(n)
  binomial(int n): fact(n+1), invfact(n+1) {
    fact[0] = 1;
    rep(i, n) fact[i+1] = fact[i] * modint(i+1);
    invfact[n] = modint(1) / fact[n];
    repr(i, n) invfact[i] = invfact[i+1] * modint(i+1);
  }
  // O(1)
  modint operator()(int n, int r) {
    chmin(r, n-r);
    if (r < 0) return modint(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};

int main() {
  int n = IN;
  VVI graph(n);
  rep(n-1) {
    int u = IN, v = IN;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  auto fact = move(binomial(n).fact);

  modint res = fix([&](auto f, auto v, auto par)->modint{
    modint tmp = 1;
    for (auto next : graph[v]) if (next != par) tmp *= f(next, v);
    tmp *= fact[graph[v].size()];
    return tmp;
  })(0, -1);

  OUT(res*modint(n));
}