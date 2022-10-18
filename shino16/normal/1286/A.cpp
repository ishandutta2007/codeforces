#ifdef LOCAL
#pragma GCC optimize ("O0")
#else
#pragma GCC optimize ("O3")
#endif

#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VVVI = vector<vector<vector<int>>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VVVLL = vector<vector<vector<ll>>>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using PII = pair<int, int>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1e9 + 7;
const ll INF_LL = 1e18 + 7;

#define __overload3(_1, _2, _3, name,...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(__name, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repFromTo(name, from, to) repFromUntil(name, from, to + 1)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = until - 1, name##__from = (from); name >= name##__from; name--)
#define reprFromTo(name, from, to) reprFromUntil(name, from, to + 1)

#define EXIT(out) do { OUT(out); exit(0); } while (false)

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define _1 first
#define _2 second

#define debug(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";debugos<<(v)<<newl;} while (0)
#define debugv(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";for(auto e:(v)){debugos<<e<<" ";}debugos<<newl;} while (0)
#define debuga(m,w) do {debugos << "L" << __LINE__ << " " << #m << " > ";for(int x=0;x<(w);x++){debugos<<(m)[x]<<" ";}debugos<<newl;} while (0)
#define debugaa(m,h,w) do {debugos << "L" << __LINE__ << " " << #m << " > \n";for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){debugos<<(m)[y][x]<<" ";}debugos<<newl;}} while (0)

#define newl "\n"
constexpr int dr[] = {1,-1,0,0};
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

template <typename T> T divceil(T m, T d) {
  return (m+d-1)/d;
}

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

template<typename T>
vector<T> make_v(size_t a, T b){return vector<T>(a, b);}

template<typename... Ts>
auto make_v(size_t a, Ts... ts){
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

string operator*(const string& s, int times) {
  string res = "";
  rep(times) res += s;
  return res;
}

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

class MyScanner {
public:
  template <typename T> void input_integer(T& var) {
    var = 0; T sign = 1;
    int cc = getchar();
    for (; cc<'0' || '9'<cc; cc = getchar())
      if (cc == '-') sign = -1;
    for (; '0' <= cc && cc <= '9'; cc = getchar())
      var = (var << 3) + (var << 1) + cc - '0';
    var = var * sign;
  }
  int c() { char c; while (c = getchar(), c == ' ' or c == '\n'); return c; }
  MyScanner& operator>>(char& var) { var = c(); return *this; }
  MyScanner& operator>>(int& var) { input_integer<int>(var); return *this; }
  MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; }
  MyScanner& operator>>(string& var) {
    int cc = getchar();
    for (; !isvisiblechar(cc); cc = getchar());
    for (; isvisiblechar(cc); cc = getchar())
      var.push_back(cc);
    return *this;
  }
  template <typename T, typename U>
  MyScanner& operator>>(pair<T, U>& var) {
    return *this >> var.first >> var.second;
  }
  template <typename... Ts>
  MyScanner& operator>>(tuple<Ts...>& var) {
    return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I == N>* = nullptr>
  MyScanner& tuple_impl(Tuple& var) {
    return *this;
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I != N>* = nullptr>
  MyScanner& tuple_impl(Tuple& var) {
    *this >> get<I>(var);
    return tuple_impl<Tuple, I+1, N>(var);
  }
  template <typename T>
  operator T() {
    T x;
    *this >> x;
    return x;
  }
  template <typename T>
  void operator()(T &t) {
    *this >> t;
  }
  template <typename T, typename... Ts>
  void operator()(T &t, Ts &...ts) {
    *this >> t;
    this->operator()(ts...);
  }
  template <typename Iter>
  void iter(Iter first, Iter last) {
    while (first != last) *this >> *first, first++;
  }
  VI vi(int n) {
    VI res(n);
    iter(all(res));
    return res;
  }
  VLL vll(int n) {
    VLL res(n);
    iter(all(res));
    return res;
  }
  VVI vvi(int h, int w) {
    VVI res(h);
    rep(i, h) res[i] = this->vi(w);
    return res;
  }
  template <typename T>
  vector<T> v(int n) {
    vector<T> res(n);
    iter(all(res));
    return res;
  }
private:
  int isvisiblechar(int c) {
    return 0x21 <= c && c <= 0x7E;
  }
} IN;

class MyPrinter {
public:
  template <typename T>
  void output_integer(T var) {
    if (var == 0) { putchar('0'); return; }
    if (var < 0)
      putchar('-'),
      var = -var;
    char stack[32]; int stack_p = 0;
    while (var)
      stack[stack_p++] = '0' + (var % 10),
      var /= 10;
    while (stack_p)
      putchar(stack[--stack_p]);
  }
  MyPrinter& operator<<(char c) { putchar(c); return *this; }
  template <typename T> MyPrinter& operator<<(T var) { output_integer<T>(var); return *this; }
  MyPrinter& operator<<(char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const string& str) {
    const char* p = str.c_str();
    const char* l = p + str.size();
    while (p < l) putchar(*p++);
    return *this;
  }
  // MyPrinter& operator<<(const modint& var) { output_integer<ll>(var.value); return *this; }
  template <typename T>
  void operator()(T x) {
    *this << x << newl;
  }
  template <typename T, typename... Ts>
  void operator()(T x, Ts ...xs) {
    *this << x << " ";
    this->operator()(xs...);
  }
  template <typename T, typename U>
  MyPrinter& operator<<(pair<T, U>& var) {
    return *this << var.first << " " << var.second;
  }
  template <typename... Ts>
  MyPrinter& operator<<(tuple<Ts...>& var) {
    return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I == N>* = nullptr>
  MyPrinter& tuple_impl(Tuple& var) {
    return *this;
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I != N>* = nullptr>
  MyPrinter& tuple_impl(Tuple& var) {
    *this << get<I>(var) << " ";
    return tuple_impl<Tuple, I+1, N>(var);
  }
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
  void range(const Range& r) {
    iter(begin(r), end(r));
  }
} OUT;


int main() {
  int n = IN;
  auto p = IN.vi(n);
  rep(i, n) p[i]--;
  vector<bool> used(n);
  rep(i, n) if (p[i]>=0) used[p[i]] = true;
  VI rest(2);
  rep(i, n) if (not used[i]) rest[i&1]++;

  rep(i, n) if (p[i] >= 0) p[i] &= 1;
  int zeros = rest[0], ones = rest[1];
  debug(zeros); debug(ones);
  debugv(p);

  auto dp = make_v(n+1, zeros+1, ones+1, 2, (ll)INF);
  rep(p, 2) dp[0][0][0][p] = 0;
  rep(i, n) rep(z, zeros+1) rep(o, ones+1) {
    if (p[i] >= 0) {
      chmin(dp[i+1][z][o][p[i]],
            min(dp[i][z][o][0] + p[i], dp[i][z][o][1] + !p[i]));
    } else {
      if (z+1 <= zeros)
        rep(p, 2) chmin(dp[i+1][z+1][o][0], dp[i][z][o][p] + p);
      if (o+1 <= ones)
        rep(p, 2) chmin(dp[i+1][z][o+1][1], dp[i][z][o][p] + !p);
    }
  }
  // rep(i, n+1) rep(z, zeros+1) rep(o, ones+1) rep(p, 2)
  //   printf("dp[%d][%d][%d][%d] = %lld\n", i+1, z, o, p, dp[i][z][o][p]);
  OUT(*min_element(all(dp[n][zeros][ones])));
}