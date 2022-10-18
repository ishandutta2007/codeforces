#ifdef LOCAL
#pragma GCC optimize ("O0")
#else
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

using namespace std;

using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using PII = pair<int, int>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1e9 + 7;
const ll INF_LL = (ll)1e18 + 7;

#define __overload3(_1, _2, _3, name,...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(__name, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = until - 1, name##__from = (from); name >= name##__from; name--)

#define EXIT(out) do { OUT(out); exit(0); } while (0)

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

template <typename T>
struct minT {
  T operator()(T a, T b) {
    return min(a, b);
  }
};

template <typename T>
struct maxT {
  T operator()(T a, T b) {
    return max(a, b);
  }
};

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

ll power(ll e, int t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t&1) res = (res * e) % mod;
    t >>= 1;
    e = (e * e) % mod;
  }
  return res;
}

template <typename T> T divceil(T, T);

template <typename T> T divfloor(T m, T d) {
  if (sgn(m) * sgn(d) >= 0) return m / d;
  else return -divceil(abs(m), abs(d));
}

template <typename T> T divceil(T m, T d) {
  if (m >= 0 and d > 0) return (m+d-1)/d;
  else if (m < 0 and d < 0) return divceil(-m, -d);
  else return -divfloor(abs(m), abs(d));
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

class MyScanner {
public:
  int offset = 0;
  template <typename T> void input_integer(T& var) {
    var = 0; T sign = 1;
    int cc = getchar();
    for (; cc<'0' || '9'<cc; cc = getchar())
      if (cc == '-') sign = -1;
    for (; '0' <= cc && cc <= '9'; cc = getchar())
      var = (var << 3) + (var << 1) + cc - '0';
    var = var * sign; var += offset;
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
  template <typename T>
  operator T() {
    T x; *this >> x;
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
  VVI vvi(int n, int m) {
    VVI res(n);
    rep(i, n) res[i] = vi(m);
    return res;
  }
  VLL vll(int n) {
    VLL res(n);
    iter(all(res));
    return res;
  }
  VVLL vvll(int n, int m) {
    VVLL res(n);
    rep(i, n) res[i] = vll(m);
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
} IN, IN1{-1};

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
  void operator()(T x) {
    *this << x << newl;
  }
  template <typename T, typename... Ts>
  void operator()(T x, Ts ...xs) {
    *this << x << " ";
    this->operator()(xs...);
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

template <typename T, typename U>
ostream& operator<<(ostream& out, pair<T, U> var) {
  return out << var.first << " " << var.second;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
ostream& tuple_impl(ostream& out, Tuple var) {
  return out;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
ostream& tuple_impl(ostream& out, Tuple var) {
  out << get<I>(var) << " ";
  return tuple_impl<Tuple, I+1, N>(var);
}
template <typename... Ts>
ostream& operator<<(ostream& out, tuple<Ts...> var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
}
template <typename T, typename U>
MyPrinter& operator<<(MyPrinter& out, pair<T, U> var) {
  return out << var.first << " " << var.second;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
MyPrinter& tuple_impl(MyPrinter& out, Tuple var) {
  return out;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
MyPrinter& tuple_impl(MyPrinter& out, Tuple var) {
  out << get<I>(var) << " ";
  return tuple_impl<Tuple, I+1, N>(var);
}
template <typename... Ts>
MyPrinter& operator<<(MyPrinter& out, tuple<Ts...> var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
}
template <typename T, typename U>
MyScanner& operator>>(MyScanner& in, pair<T, U>& var) {
  return in >> var.first >> var.second;
}
template <typename... Ts>
MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
MyScanner& tuple_impl(MyScanner& in, Tuple& var) {
  return in;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
MyScanner& tuple_impl(MyScanner& in, Tuple& var) {
  in >> get<I>(var);
  return tuple_impl<Tuple, I+1, N>(var);
}

int main() {
  int t = IN;
  rep(t) {
    ll n = IN, s = IN;
    auto lr = IN.v<PII>(n);
    sort(all(lr));
    rep(i, n) s -= lr[i]._1;
    int ok = lr[n/2]._1, ng = INF;
    debug(ok);
    while (ng - ok > 1) {
      int m = (ok+ng)/2;
      int todo = n/2+1;
      ll rest = s;
      repr(i, n) if (m <= lr[i]._2) {
        int d = max(0, m - lr[i]._1);
        rest -= d;
        todo--;
        if (todo == 0) break;
      }
      bool fail = todo != 0 or rest < 0;
      (fail ? ng : ok) = m;
    }
    OUT(ok);
  }
}