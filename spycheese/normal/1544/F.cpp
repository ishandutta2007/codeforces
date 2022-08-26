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

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }

// ========================================================================= //

const int N = 21;

template<typename T>
T pw(T a, ll b) {
  T r = T(1);
  for (; b; b >>= 1) {
    if (b & 1) r *= a;
    a *= a;
  }
  return r;
}

template<int M>
struct mint_t {
  int v;
  
  mint_t() : v(0) {}
  mint_t(int v) : v(v % M) { if (v < 0) v += M; }
  mint_t(ll v) : v(v % M) { if (v < 0) v += M; }
  mint_t(mint_t<M> const& b) : v(b.v) {}

  mint_t& operator = (mint_t b) { v = b.v; return *this; }

  mint_t& operator += (mint_t b) { v += b.v; if (v >= M) v -= M; return *this; }
  mint_t& operator -= (mint_t b) { v -= b.v; if (v < 0) v += M; return *this; }
  mint_t& operator *= (mint_t b) { v = v * b.v % M; return *this; }
  mint_t& operator /= (mint_t b) { return *this *= pw(b, M - 2);}

  mint_t operator - () const { return mint_t(v == 0 ? 0 : M - v); }
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
template<int M> bool operator == (int a, mint_t<M> b) { return b == mint_t<M>(a); }
template<int M> bool operator != (int a, mint_t<M> b) { return b != mint_t<M>(a); }

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

const int MOD = 31607;
typedef mint_t<MOD> mint;
//typedef double mint;

void transpose(int n, mint a[N][N]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
      swap(a[i][j], a[j][i]);
}

mint solveRows(int n, mint a[N][N]) {
  mint ans = 1;
  for (int i = 0; i < n; ++i) {
    mint p = 1;
    for (int j = 0; j < n; ++j) p *= a[i][j];
    ans *= 1 - p;
  }
  return 1 - ans;
}

mint solveBoth(int n, mint a[N][N]) {
  mint ans = 0;
  static mint rp[N];
  for (int i = 0; i < n; ++i) {
    rp[i] = 1;
    for (int j = 0; j < n; ++j) rp[i] *= a[i][j];
  }
  int n1 = n / 2;
  int n2 = n - n1;
  static mint cp1[N][1 << 10];
  static mint cp2[N][1 << 11];
  for (int j = 0; j < n; ++j) {
    for (int mask = 0; mask < (1 << n1); ++mask) {
      mint p = 1;
      for (int i = 0; i < n1; ++i)
        if (!((1 << i) & mask))
          p *= a[i][j];
      cp1[j][mask] = p;
    }
    for (int mask = 0; mask < (1 << n2); ++mask) {
      mint p = 1;
      for (int i = 0; i < n2; ++i)
        if (!((1 << i) & mask))
          p *= a[i + n1][j];
      cp2[j][mask] = p;
    }
  }

  for (int rmask = 1; rmask < 1 << n; ++rmask) {
    mint cans = 1;
    for (int j = 0; j < n; ++j) {
      mint p = cp1[j][rmask & ((1 << n1) - 1)] * cp2[j][rmask >> n1];
      cans *= 1 - p;
    }
    cans = 1 - cans;
    bool sign = 1;
    for (int i = 0; i < n; ++i)
      if (rmask & (1 << i)) {
        sign = !sign;
        cans *= rp[i];
      }
    if (sign) ans -= cans; else ans += cans;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);

  int n;
  static mint a[N][N];
  static mint b[N][N];
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      a[i][j] /= 10000;
    }

  mint ans = 0;
  ans += solveRows(n, a);
  transpose(n, a);
  ans += solveRows(n, a);
  transpose(n, a);

  mint pd1 = 1, pd2 = 1;
  for (int i = 0; i < n; ++i) pd1 *= a[i][i];
  for (int i = 0; i < n; ++i) pd2 *= a[i][n - 1 - i];
  mint pd12 = pd1 * pd2;
  if (n % 2 == 1) pd12 /= a[n / 2][n / 2];

  ans += pd1 + pd2 - pd12;

  memcpy(b, a, sizeof(b));
  for (int i = 0; i < n; ++i) b[i][i] = 1;
  ans -= pd1 * solveRows(n, b);
  transpose(n, b);
  ans -= pd1 * solveRows(n, b);

  memcpy(b, a, sizeof(b));
  for (int i = 0; i < n; ++i) b[i][n - i - 1] = 1;
  ans -= pd2 * solveRows(n, b);
  transpose(n, b);
  ans -= pd2 * solveRows(n, b);

  memcpy(b, a, sizeof(b));
  for (int i = 0; i < n; ++i) b[i][n - i - 1] = 1;
  for (int i = 0; i < n; ++i) b[i][i] = 1;
  ans += pd12 * solveRows(n, b);
  transpose(n, b);
  ans += pd12 * solveRows(n, b);

  ans -= solveBoth(n, a);

  memcpy(b, a, sizeof(b));
  for (int i = 0; i < n; ++i) b[i][i] = 1;
  ans += pd1 * solveBoth(n, b);

  memcpy(b, a, sizeof(b));
  for (int i = 0; i < n; ++i) b[i][n - 1 - i] = 1;
  ans += pd2 * solveBoth(n, b);

  memcpy(b, a, sizeof(b));
  for (int i = 0; i < n; ++i) b[i][i] = 1;
  for (int i = 0; i < n; ++i) b[i][n - 1 - i] = 1;
  ans -= pd12 * solveBoth(n, b);

  cout << ans << "\n";

  return 0;
}