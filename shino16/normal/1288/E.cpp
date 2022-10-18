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
#define reprFromUntil(name, from, until) for (int name = (until) - 1, name##__from = (from); name >= name##__from; name--)

#define EXIT(out) do { OUT(out); exit(0); } while (0)

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

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

template <typename T, typename U> bool chmin(T& var, U x) {
  if (var > x) {
    var = x;
    return true;
  } else return false;
}

template <typename T, typename U> bool chmax(T& var, U x) {
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

struct Edge {
  int to; ll cost;
  Edge(int _to): to(_to), cost(1) {}
  Edge(int _to, ll _cost): to(_to), cost(_cost) {}
  operator int() { return to; }
};

using Graph = vector<vector<Edge>>;

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
  int offset = 0;
  template <typename T>
  void output_integer(T var) {
    var += offset;
    if (var == 0) { putchar('0'); return; }
    if (var < 0) putchar('-'), var = -var;
    char stack[32]; int stack_p = 0;
    while (var) stack[stack_p++] = '0' + (var % 10), var /= 10;
    while (stack_p) putchar(stack[--stack_p]);
  }
  MyPrinter& operator<<(char c) { putchar(c); return *this; }
  MyPrinter& operator<<(double x) { printf("%.10f", x); return *this; }
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
    else for (; s != t; s++) *this << *s << " \n"[next(s, 1) == t];
  }
  template <typename Range>
  void range(const Range& r) { iter(begin(r), end(r)); }
} OUT, OUT1{1};

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


class BIT {
public:
  const int n;
private:
  vector<ll> data;
public:
  BIT(int _n = 0): n(_n), data(_n+1) { }
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) {
    return sum(r) - sum(l);
  }
  void assign(int p, ll v) {
    add(p, v - sum(p, p+1));
  }
  bool chmax(int p, ll v) {
    if (sum(p, p+1) < v) {
      assign(p, v);
      return true;
    } else return false;
  }
};


int main() {
  int n = IN, m = IN;
  VI a(n);
  rep(i, n) a[i] = n-i-1;
  auto _a = IN1.vi(m);
  a.insert(a.end(), all(_a));

  BIT rsq(m+n+20);
  VI prev(n, -1);
  VI right(n, -1);
  VB done(n);
  rep(i, a.size()) {
    done[a[i]] = done[a[i]] or (prev[a[i]] != -1);
    if (prev[a[i]] != -1) chmax(right[a[i]], rsq.sum(prev[a[i]]+2));
    rsq.add(prev[a[i]]+1, 1);
    rsq.add(i+1, -1);
    prev[a[i]] = i;
  }
  rep(i, n) {
    chmax(right[i], rsq.sum(prev[i]+2));
  }
  rep(i, n) OUT(done[i] ? 1 : i+1, right[i]+1);
}