#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;
typedef pair <ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T, typename M> T& updMin(T& a, M const& b) { if (b < a) a = b; return a; }
template<typename T, typename M> T& updMax(T& a, M const& b) { if (a < b) a = b; return a; }

ll divFloor(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b : (a - b + 1) / b; }
ll divCeil(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b : a / b; }
ll divFloorS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1; }
ll divCeilS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1; }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }
template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false; out << x;
  }
  return out;
}
template<typename T> ostream& operator << (ostream& out, vector<vector<T>> const& a) {
  for (vector<T> const& x : a) out << x << "\n";
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

template<typename T>
T pw(T a, ll b) {
  T r = T(1);
  for (; b; b >>= 1) {
    if (b & 1) r *= a;
    a *= a;
  }
  return r;
}

int euclid(int x, int y, int &ax, int &ay) {
  if (y == 0) {
    ax = 1; ay = 0;
    return x;
  }
  int b;
  int g = euclid(y, x % y, b, ax);
  ay = b - (x / y) * ax;
  return g;
}
int invMod(int a, int mod) {
  int x, y;
  int g = euclid(mod, a, y, x);
  assert(g == 1);
  x %= mod; if (x < 0) x += mod;
  return x;
}

template<int M>
struct mint_t {
  int v;
  
  mint_t() = default;
  mint_t(int v) : v(v % M) { if (v < 0) v += M; }
  mint_t(ll v) : v(v % M) { if (v < 0) v += M; }
  mint_t(mint_t<M> const& b) = default;

  mint_t& operator = (mint_t const& b) = default;

  mint_t& operator += (mint_t b) { v += b.v; if (v >= M) v -= M; return *this; }
  mint_t& operator -= (mint_t b) { v -= b.v; if (v < 0) v += M; return *this; }
  mint_t& operator *= (mint_t b) { v = 1LL * v * b.v % M; return *this; }
  mint_t& operator /= (mint_t b) { return *this *= invMod(b.v, M);}

  mint_t operator - () const { return mint_t(v == 0 ? 0 : M - v); }

  mint_t& operator ++() { if (++v == M) v = 0; return *this; }
  mint_t& operator --() { if (v == 0) v = M - 1; else --v; return *this; }
  mint_t operator ++(int) { mint_t a = *this; ++*this; return a; }
  mint_t operator --(int) { mint_t a = *this; --*this; return a; }

  operator int() const { return v; }
};

template<int M> mint_t<M> operator + (mint_t<M> a, mint_t<M> b) { return a += b; }
template<int M> mint_t<M> operator - (mint_t<M> a, mint_t<M> b) { return a -= b; }
template<int M> mint_t<M> operator * (mint_t<M> a, mint_t<M> b) { return a *= b; }
template<int M> mint_t<M> operator / (mint_t<M> a, mint_t<M> b) { return a /= b; }

template<int M> mint_t<M> operator + (mint_t<M> a, int b) { return a += b; }
template<int M> mint_t<M> operator - (mint_t<M> a, int b) { return a -= b; }
template<int M> mint_t<M> operator * (mint_t<M> a, int b) { return a *= b; }
template<int M> mint_t<M> operator / (mint_t<M> a, int b) { return a /= b; }

template<int M> mint_t<M> operator + (int a, mint_t<M> b) { mint_t<M> aa = a; return aa += b; }
template<int M> mint_t<M> operator - (int a, mint_t<M> b) { mint_t<M> aa = a; return aa -= b; }
template<int M> mint_t<M> operator * (int a, mint_t<M> b) { mint_t<M> aa = a; return aa *= b; }
template<int M> mint_t<M> operator / (int a, mint_t<M> b) { mint_t<M> aa = a; return aa /= b; }

template<int M> bool operator == (mint_t<M> a, mint_t<M> b) { return a.v == b.v; }
template<int M> bool operator != (mint_t<M> a, mint_t<M> b) { return a.v != b.v; }
template<int M> bool operator < (mint_t<M> a, mint_t<M> b) { return a.v < b.v; }
template<int M> bool operator > (mint_t<M> a, mint_t<M> b) { return a.v > b.v; }
template<int M> bool operator <= (mint_t<M> a, mint_t<M> b) { return a.v <= b.v; }
template<int M> bool operator >= (mint_t<M> a, mint_t<M> b) { return a.v >= b.v; }
template<int M> bool operator == (mint_t<M> a, int b) { return a == mint_t<M>(b); }
template<int M> bool operator != (mint_t<M> a, int b) { return a != mint_t<M>(b); }
template<int M> bool operator < (mint_t<M> a, int b) { return a < mint_t<M>(b); }
template<int M> bool operator > (mint_t<M> a, int b) { return a > mint_t<M>(b); }
template<int M> bool operator <= (mint_t<M> a, int b) { return a <= mint_t<M>(b); }
template<int M> bool operator >= (mint_t<M> a, int b) { return a >= mint_t<M>(b); }
template<int M> bool operator == (int a, mint_t<M> b) { return b == mint_t<M>(a); }
template<int M> bool operator != (int a, mint_t<M> b) { return b != mint_t<M>(a); }
template<int M> bool operator < (int a, mint_t<M> b) { return b < mint_t<M>(a); }
template<int M> bool operator > (int a, mint_t<M> b) { return b > mint_t<M>(a); }
template<int M> bool operator <= (int a, mint_t<M> b) { return b <= mint_t<M>(a); }
template<int M> bool operator >= (int a, mint_t<M> b) { return b >= mint_t<M>(a); }

template<int M> mint_t<M> inv(mint_t<M> a) { return mint_t<M>(invMod(a.v, M)); }

namespace std {
  template<int M>
  struct hash<mint_t<M>> {
    size_t operator()(mint_t<M> const& a) const {
      return hash<int>()(a.v);
    }
  };
}

template<int M>
istream& operator >> (istream &in, mint_t<M> &a) {
  int x;
  in >> x;
  a = x;
  return in;
}

template<int M>
ostream& operator << (ostream &out, mint_t<M> a) {
  return out << a.v;
}

const int MOD = 1000000007;
typedef mint_t<MOD> mint;

template<typename T>
struct Fen {
  vector<T> t;
  Fen() = default;
  explicit Fen(int n) : t(n, T(0)) {}
  void add(int p, T x) { for (; p < sz(t); p |= p + 1) t[p] += x; }
  T sum(int p) { T s = 0; for (p = min(p, sz(t)) - 1; p >= 0; p = (p&(p+1))-1) s += t[p]; return s; }
  T sum(int l, int r) { return l < r ? sum(r) - sum(l) : T(0); }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  struct Task {
    int a, b;
    int i;
  };
  vector<Task> ts(n);
  for (int i = 0; i < n; ++i) {
    cin >> ts[i].a >> ts[i].b;
    ts[i].i = i;
  }
  sort(all(ts), [&](Task const& x, Task const& y) { return x.b < y.b; });
  vector<int> i2i(n);
  for (int i = 0; i < n; ++i)
    i2i[ts[i].i] = i;

  vector<mint> w(n);
  Fen<mint> wf(n * 2 + 3);
  for (int i = 0; i < n; ++i) {
    w[i] = 1 + wf.sum(ts[i].a, ts[i].b);
    wf.add(ts[i].a, w[i]);
  }

  int m;
  cin >> m;
  vector<int> s(m);
  cin >> s;
  for (int &x : s)
    x = i2i[x - 1];
  sort(all(s));

  mint ans = 0;
  for (int i = 0; i < s.back(); ++i)
    ans += w[i];
  for (int i = s.back(); i < n; ++i) {
    wf.add(ts[i].a, -w[i]);
    w[i] = 0;
  }

  int i = sz(s) - 1;
  while (true) {
    ++ans;
    int j = i - 1;
    while (j >= 0 && !(ts[s[i]].a < ts[s[j]].a && ts[s[j]].a < ts[s[i]].b)) --j;
    if (j == -1) break;
    for (int q = s[j]; q < s[i]; ++q) {
      wf.add(ts[q].a, -w[q]);
      w[q] = 0;
    }
    ans += wf.sum(ts[s[i]].a, ts[s[i]].b);
    i = j;
  }

  cout << ans << "\n";

  return 0;
}