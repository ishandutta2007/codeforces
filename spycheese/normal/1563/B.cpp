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

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

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
    f = false;
    out << x;
  }
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

int M;

template<typename T>
T pw(T a, ll b) {
  T r = T(1);
  for (; b; b >>= 1) {
    if (b & 1) r *= a;
    a *= a;
  }
  return r;
}

struct mint_t {
  int v;
  
  mint_t() = default;
  mint_t(int v) : v(v % M) { if (v < 0) v += M; }
  mint_t(ll v) : v(v % M) { if (v < 0) v += M; }
  mint_t(mint_t const& b) = default;

  mint_t& operator = (mint_t const& b) = default;

  mint_t& operator += (mint_t b) { v += b.v; if (v >= M) v -= M; return *this; }
  mint_t& operator -= (mint_t b) { v -= b.v; if (v < 0) v += M; return *this; }
  mint_t& operator *= (mint_t b) { v = 1LL * v * b.v % M; return *this; }
  mint_t& operator /= (mint_t b) { return *this *= pw(b, M - 2);}

  mint_t operator - () const { return mint_t(v == 0 ? 0 : M - v); }

  mint_t& operator ++() { if (++v == M) v = 0; return *this; }
  mint_t& operator --() { if (v == 0) v = M - 1; else --v; return *this; }
  mint_t operator ++(int) { mint_t a = *this; ++*this; return a; }
  mint_t operator --(int) { mint_t a = *this; --*this; return a; }

  operator int() const { return v; }
};

mint_t operator + (mint_t a, mint_t b) { return a += b; }
mint_t operator - (mint_t a, mint_t b) { return a -= b; }
mint_t operator * (mint_t a, mint_t b) { return a *= b; }
mint_t operator / (mint_t a, mint_t b) { return a /= b; }

 mint_t operator + (mint_t a, int b) { return a += b; }
 mint_t operator - (mint_t a, int b) { return a -= b; }
 mint_t operator * (mint_t a, int b) { return a *= b; }
 mint_t operator / (mint_t a, int b) { return a /= b; }

 mint_t operator + (int a, mint_t b) { mint_t aa = a; return aa += b; }
 mint_t operator - (int a, mint_t b) { mint_t aa = a; return aa -= b; }
 mint_t operator * (int a, mint_t b) { mint_t aa = a; return aa *= b; }
 mint_t operator / (int a, mint_t b) { mint_t aa = a; return aa /= b; }

 bool operator == (mint_t a, mint_t b) { return a.v == b.v; }
 bool operator != (mint_t a, mint_t b) { return a.v != b.v; }
 bool operator < (mint_t a, mint_t b) { return a.v < b.v; }
 bool operator > (mint_t a, mint_t b) { return a.v > b.v; }
 bool operator <= (mint_t a, mint_t b) { return a.v <= b.v; }
 bool operator >= (mint_t a, mint_t b) { return a.v >= b.v; }
 bool operator == (mint_t a, int b) { return a == mint_t(b); }
 bool operator != (mint_t a, int b) { return a != mint_t(b); }
 bool operator < (mint_t a, int b) { return a < mint_t(b); }
 bool operator > (mint_t a, int b) { return a > mint_t(b); }
 bool operator <= (mint_t a, int b) { return a <= mint_t(b); }
 bool operator >= (mint_t a, int b) { return a >= mint_t(b); }
 bool operator == (int a, mint_t b) { return b == mint_t(a); }
 bool operator != (int a, mint_t b) { return b != mint_t(a); }
 bool operator < (int a, mint_t b) { return b < mint_t(a); }
 bool operator > (int a, mint_t b) { return b > mint_t(a); }
 bool operator <= (int a, mint_t b) { return b <= mint_t(a); }
 bool operator >= (int a, mint_t b) { return b >= mint_t(a); }


istream& operator >> (istream &in, mint_t &a) {
  int x;
  in >> x;
  a = x;
  return in;
}


ostream& operator << (ostream &out, mint_t a) {
  return out << a.v;
}

typedef mint_t mint;

void solve() {
  int n;
  cin >> n >> M;
  vector<mint> d(n + 1);
  vector<mint> ds(n + 2);
  d[n] = 1;
  ds[n] = 1;
  for (int a = n - 1; a >= 1; --a) {
    d[a] = ds[a + 1];
    for (int z = 2; true; ++z) {
      int x1 = z * a;
      if (x1 > n) break;
      int x2 = min(z * (a + 1), n + 1);
      d[a] += ds[x1] - ds[x2];
    }
    ds[a] = ds[a + 1] + d[a];
  }
  cout << d[1] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}