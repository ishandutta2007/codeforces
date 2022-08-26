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

template<int const* M>
struct mint_t {
  int v;
  
  mint_t() = default;
  mint_t(int v) : v(v % *M) { if (v < 0) v += *M; }
  mint_t(ll v) : v(v % *M) { if (v < 0) v += *M; }
  mint_t(mint_t<M> const& b) = default;

  mint_t& operator = (mint_t const& b) = default;

  mint_t& operator += (mint_t b) { v += b.v; if (v >= *M) v -= *M; return *this; }
  mint_t& operator -= (mint_t b) { v -= b.v; if (v < 0) v += *M; return *this; }
  mint_t& operator *= (mint_t b) { v = 1LL * v * b.v % *M; return *this; }
  mint_t& operator /= (mint_t b) { return *this *= invMod(b.v, *M);}

  mint_t operator - () const { return mint_t(v == 0 ? 0 : *M - v); }

  mint_t& operator ++() { if (++v == *M) v = 0; return *this; }
  mint_t& operator --() { if (v == 0) v = *M - 1; else --v; return *this; }
  mint_t operator ++(int) { mint_t a = *this; ++*this; return a; }
  mint_t operator --(int) { mint_t a = *this; --*this; return a; }

  operator int() const { return v; }
};

template<int const* M> mint_t<M> operator + (mint_t<M> a, mint_t<M> b) { return a += b; }
template<int const* M> mint_t<M> operator - (mint_t<M> a, mint_t<M> b) { return a -= b; }
template<int const* M> mint_t<M> operator * (mint_t<M> a, mint_t<M> b) { return a *= b; }
template<int const* M> mint_t<M> operator / (mint_t<M> a, mint_t<M> b) { return a /= b; }

template<int const* M> mint_t<M> operator + (mint_t<M> a, int b) { return a += b; }
template<int const* M> mint_t<M> operator - (mint_t<M> a, int b) { return a -= b; }
template<int const* M> mint_t<M> operator * (mint_t<M> a, int b) { return a *= b; }
template<int const* M> mint_t<M> operator / (mint_t<M> a, int b) { return a /= b; }

template<int const* M> mint_t<M> operator + (int a, mint_t<M> b) { mint_t<M> aa = a; return aa += b; }
template<int const* M> mint_t<M> operator - (int a, mint_t<M> b) { mint_t<M> aa = a; return aa -= b; }
template<int const* M> mint_t<M> operator * (int a, mint_t<M> b) { mint_t<M> aa = a; return aa *= b; }
template<int const* M> mint_t<M> operator / (int a, mint_t<M> b) { mint_t<M> aa = a; return aa /= b; }

template<int const* M> bool operator == (mint_t<M> a, mint_t<M> b) { return a.v == b.v; }
template<int const* M> bool operator != (mint_t<M> a, mint_t<M> b) { return a.v != b.v; }
template<int const* M> bool operator < (mint_t<M> a, mint_t<M> b) { return a.v < b.v; }
template<int const* M> bool operator > (mint_t<M> a, mint_t<M> b) { return a.v > b.v; }
template<int const* M> bool operator <= (mint_t<M> a, mint_t<M> b) { return a.v <= b.v; }
template<int const* M> bool operator >= (mint_t<M> a, mint_t<M> b) { return a.v >= b.v; }
template<int const* M> bool operator == (mint_t<M> a, int b) { return a == mint_t<M>(b); }
template<int const* M> bool operator != (mint_t<M> a, int b) { return a != mint_t<M>(b); }
template<int const* M> bool operator < (mint_t<M> a, int b) { return a < mint_t<M>(b); }
template<int const* M> bool operator > (mint_t<M> a, int b) { return a > mint_t<M>(b); }
template<int const* M> bool operator <= (mint_t<M> a, int b) { return a <= mint_t<M>(b); }
template<int const* M> bool operator >= (mint_t<M> a, int b) { return a >= mint_t<M>(b); }
template<int const* M> bool operator == (int a, mint_t<M> b) { return b == mint_t<M>(a); }
template<int const* M> bool operator != (int a, mint_t<M> b) { return b != mint_t<M>(a); }
template<int const* M> bool operator < (int a, mint_t<M> b) { return b < mint_t<M>(a); }
template<int const* M> bool operator > (int a, mint_t<M> b) { return b > mint_t<M>(a); }
template<int const* M> bool operator <= (int a, mint_t<M> b) { return b <= mint_t<M>(a); }
template<int const* M> bool operator >= (int a, mint_t<M> b) { return b >= mint_t<M>(a); }

template<int const* M> mint_t<M> inv(mint_t<M> a) { return mint_t<M>(invMod(a.v, *M)); }

template<int const* M>
istream& operator >> (istream &in, mint_t<M> &a) {
  int x;
  in >> x;
  a = x;
  return in;
}

template<int const* M>
ostream& operator << (ostream &out, mint_t<M> a) {
  return out << a.v;
}

int mod = 1;
typedef mint_t<&mod> mint;

const int N = 111;
mint cnk[N][N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k >> mod;
  for (int i = 0; i < N; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
  }
  static mint d1[N];
  d1[0] = 1;
  for (int nn = 1; nn <= n; ++nn) {
    for (int q = 0; q < nn; ++q)
      d1[nn] += d1[q] * d1[nn - q - 1] * cnk[nn - 1][q];
  }
  static mint d[N][N];
  d[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    d[i][1] = d1[i];

  for (int iter = 0; iter < m - 1; ++iter) {
    static mint nd[N][N];
    memset(nd, 0, sizeof(nd));
    nd[0][0] = 1;
    for (int n1 = 0; n1 < n; ++n1)
      for (int m1 = 0; m1 <= min(n1, k); ++m1) {
        if (d[n1][m1] == 0) continue;
        for (int m2 = 0; m2 + m1 <= k; ++m2)
          for (int n2 = m2 ? m2 + iter : 0; n1 + n2 < n; ++n2) {
            nd[n1 + n2 + 1][m1 + m2] += d[n1][m1] * d[n2][m2] * cnk[n1 + n2][n1];
          }
      }
    memcpy(d, nd, sizeof(nd));
  }
  mint ans = d[n][k];
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}