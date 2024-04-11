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
template<typename T> T pw(T a, ll b) { T r = T(1); if (b <= 0) return r; for (;; b >>= 1) { if (b & 1) r *= a; if (b) a *= a; else return r; } }

template<typename T> void unique(vector<T> &a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> int lowerBound(vector<T> const& a, T const& x) { return lower_bound(all(a), x) - a.begin(); }
template<typename T> int upperBound(vector<T> const& a, T const& x) { return upper_bound(all(a), x) - a.begin(); }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename T> T getOrDef(vector<T> const& a, int i, T const& def = T()) { return i < 0 || i >= sz(a) ? def : a[i]; }
template<typename T> T getOrDef(vector<vector<T>> const& a, int i, int j, T const& def = T()) { return i < 0 || i >= sz(a) ? def : getOrDef(a[i], j, def); }
template<typename T> T backOrDef(vector<T> const& a, T const& def = T()) { return a.empty() ? def : a.back(); }

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
  mint_t(int v) : v(v % M) { if (this->v < 0) this->v += M; }
  mint_t(ll v) : v(v % M) { if (this->v < 0) this->v += M; }
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

template<int M> mint_t<M> operator + (ll a, mint_t<M> b) { mint_t<M> aa = a; return aa += b; }
template<int M> mint_t<M> operator - (ll a, mint_t<M> b) { mint_t<M> aa = a; return aa -= b; }
template<int M> mint_t<M> operator * (ll a, mint_t<M> b) { mint_t<M> aa = a; return aa *= b; }
template<int M> mint_t<M> operator / (ll a, mint_t<M> b) { mint_t<M> aa = a; return aa /= b; }

template<int M> mint_t<M> operator + (mint_t<M> a, ll b) { return a += b; }
template<int M> mint_t<M> operator - (mint_t<M> a, ll b) { return a -= b; }
template<int M> mint_t<M> operator * (mint_t<M> a, ll b) { return a *= b; }
template<int M> mint_t<M> operator / (mint_t<M> a, ll b) { return a /= b; }

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
template<int M> bool operator == (mint_t<M> a, ll b) { return a == mint_t<M>(b); }
template<int M> bool operator != (mint_t<M> a, ll b) { return a != mint_t<M>(b); }
template<int M> bool operator < (mint_t<M> a, ll b) { return a < mint_t<M>(b); }
template<int M> bool operator > (mint_t<M> a, ll b) { return a > mint_t<M>(b); }
template<int M> bool operator <= (mint_t<M> a, ll b) { return a <= mint_t<M>(b); }
template<int M> bool operator >= (mint_t<M> a, ll b) { return a >= mint_t<M>(b); }
template<int M> bool operator == (ll a, mint_t<M> b) { return b == mint_t<M>(a); }
template<int M> bool operator != (ll a, mint_t<M> b) { return b != mint_t<M>(a); }
template<int M> bool operator < (ll a, mint_t<M> b) { return b < mint_t<M>(a); }
template<int M> bool operator > (ll a, mint_t<M> b) { return b > mint_t<M>(a); }
template<int M> bool operator <= (ll a, mint_t<M> b) { return b <= mint_t<M>(a); }
template<int M> bool operator >= (ll a, mint_t<M> b) { return b >= mint_t<M>(a); }

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

const int MOD = 998244353;
typedef mint_t<MOD> mint;

namespace ffti {
  const int D = 21;
  const int DMAX = 23;
  const int W = 31; // DO NOT TOUCH
  const int MOD = 998244353;
  const int N = 1 << D;
  int w[N];
  int p[N];

  int pw(int a, int b) {
    int r = 1;
    for (; b; b >>= 1) {
      if (b & 1) r = 1LL * r * a % MOD;
      a = 1LL * a * a % MOD;
    }
    return r;
  }

  void init() {
    static bool inited = false;
    if (inited) return;
    inited = true;
    assert(D <= DMAX);
    int w0 = W;
    for (int i = 0; i < DMAX - D; ++i)
      w0 = 1LL * w0 * w0 % MOD;
    int wi = 0;
    for (int cn = 2; cn <= N; cn *= 2) {
      w[wi++] = 1;
      int cw0 = pw(w0, N / cn);
      for (int i = 1; i < cn / 2; ++i, ++wi)
        w[wi] = 1LL * cw0 * w[wi - 1] % MOD;
    }
    int j = 0;
    for (int i = 1; i < N; ++i) {
      if (!(i & (1 << j))) ++j;
      p[i] = p[i ^ (1 << j)] | (1 << (D - 1 - j));
    }
  }

  void fft(int *a, int n) {
    assert(n <= N && n != 0 && !(n&(n - 1)));
    init();
    for (int i = 0; i < n; ++i) {
      int ni = p[i] / (N / n);
      if (i > ni) swap(a[i], a[ni]);
    }
    int wi0 = 0;
    for (int cn = 1; cn < n; cn *= 2) {
      for (int s = 0; s < n; s += 2*cn)
        for (int i = 0; i < cn; ++i) {
          int x = a[s + i];
          int y = 1LL * a[s + cn + i] * w[wi0 + i] % MOD;
          int x1 = x + y; if (x1 >= MOD) x1 -= MOD;
          int y1 = x - y; if (y1 < 0) y1 += MOD;
          a[s + i] = x1;
          a[s + cn + i] = y1;
        }
      wi0 += cn;
    }
  }

  void fftInv(int *a, int n) {
    int ni = pw(n, MOD - 2);
    for (int i = 0; i < n; ++i)
      a[i] = 1LL * a[i] * ni % MOD;
    reverse(a + 1, a + n);
    fft(a, n);
  }
}

int polyMulMod(int const* a1, int n1, int const* a2, int n2, int *a3, int m3 = -1) {
  if (n1 <= 0 || n2 <= 0 || m3 == 0) {
    if (m3 != -1) memset(a3, 0, sizeof(int) * m3);
    return 0;
  }
  if (m3 != -1) {
    n1 = min(n1, m3);
    n2 = min(n2, m3);
  }
  int n3 = n1 + n2 - 1;
  if (m3 == -1) m3 = n3;
  int n = 1;
  while (n < n3) n *= 2;
  assert(n <= ffti::N);
  static int buf1[ffti::N], buf2[ffti::N];
  for (int i = 0; i < n; ++i)
    buf1[i] = (i < n1 ? a1[i] : 0);
  for (int i = 0; i < n; ++i)
    buf2[i] = (i < n2 ? a2[i] : 0);
  ffti::fft(buf1, n);
  ffti::fft(buf2, n);
  int ni = ffti::pw(n, ffti::MOD - 2);
  for (int i = 0; i < n; ++i)
    buf1[i] = 1LL * buf1[i] * buf2[i] % ffti::MOD * ni % ffti::MOD;
  reverse(buf1 + 1, buf1 + n);
  ffti::fft(buf1, n);
  memcpy(a3, buf1, sizeof(int) * min(m3, n3));
  if (m3 > n3)
    memset(a3 + n3, 0, sizeof(int) * (m3 - n3));
  return min(n3, m3);
}

typedef mint_t<ffti::MOD> mintf;
int polyMul(mintf const* a1, int n1, mintf const* a2, int n2, mintf *a3, int n3 = -1) {
  return polyMulMod((int const*)a1, n1, (int const*)a2, n2, (int*)a3, n3);
}

void polyFft(mintf *a, int n) { ffti::fft((int*)a, n); }
void polyFftInv(mintf *a, int n) { ffti::fftInv((int*)a, n); }

void polyInv(mintf const* a, int n, mintf *b, int m) {
  assert(n > 0 && a[0] != 0);
  assert(a != b);
  if (m <= 0) return;
  static mintf bf[ffti::N];
  bf[0] = 1 / a[0];
  for (int s = 1; s < m; s *= 2) {
    static mintf af[ffti::N];
    for (int i = 0; i < s * 2; ++i)
      af[i] = (i < n ? a[i] : mintf(0));
    memset(af + s * 2, 0, sizeof(mintf) * s * 2);
    polyFft(af, s * 4);
    memset(bf + s, 0, sizeof(mintf) * s * 3);
    polyFft(bf, s * 4);
    mintf ni = (mintf)1 / (s * 4);
    for (int i = 0; i < s * 4; ++i)
      bf[i] = bf[i] * (2 - af[i] * bf[i]) * ni;
    reverse(bf + 1, bf + s * 4);
    polyFft(bf, s * 4);
  }
  memcpy(b, bf, sizeof(mintf) * m);
}

vector<mint> mymul(vector<mint> const& a, vector<mint> const& b) {
  vector<mint> c(sz(a) + sz(b) - 1);
  int n = sz(a);
  assert(n == sz(b));
  function<void(int, int)> go = [&](int l, int r) {
    if (l >= r - 1) return;
    int mid = (l + r) / 2;
    go(l, mid);
    go(mid, r);
    vector<mint> res(r - l + 1);
    polyMul(a.data() + l, mid - l, b.data() + mid, r - mid, res.data(), sz(res));
    for (int i = 0; i < sz(res) && l + mid + i < sz(c); ++i)
      c[i + l + mid] += res[i];
  };
  go(0, n);
  return c;
}

mint solve(vector<mint> const& a, vector<int> const& ps, bool rev) {
  int n = sz(a);
  int m = sz(ps);
  mint ans = 0;

  vector<mint> as(n + 1), ais(n + 1);
  for (int i = 0; i < n; ++i) {
    as[i + 1] = as[i] + a[i];
    ais[i + 1] = ais[i] + a[i] * i;
  }

  for (int i = 0; i < m; ++i) {
    int p = ps[i];
    mint cans = ais[n] - ais[p] - (as[n] - as[p]) * p;
    ans += cans / pw<mint>(2, m - i);
  }

  for (int i = 0; i < m; ++i) {
    int p1 = ps[i];
    mint cans = as[p1] * p1 - ais[p1];
    int cnt = m - i - 1;
    ans += cans * (1 - 1 / pw<mint>(2, cnt)) / 2;
  }

  vector<mint> as2(n * 2 + 4);
  vector<mint> ais2(n * 2 + 4);
  for (int i = 0; i <= n; ++i) {
    as2[i * 2 + rev] = as[i];
    as2[i * 2 + rev + 1] = as[i];
    ais2[i * 2 + rev] = ais[i];
    ais2[i * 2 + rev + 1] = ais[i];
  }

  vector<mint> q1a(n), q2(n);
  vector<mint> q1b(n);

  for (int i = 0; i < m; ++i) {
    q1a[ps[i]] = (pw<mint>(2, i));
    q1b[ps[i]] = (pw<mint>(2, i) * ps[i]);
    q2[ps[i]] = (1 / pw<mint>(2, i + 1));
  }

  vector<mint> ca = mymul(q1a, q2);
  vector<mint> cb = mymul(q1b, q2);

  for (int i = 0; i < sz(ca); ++i)
    ans += ca[i] * ais2[i + 2] - cb[i] * as2[i + 2];

  /*for (int i = 0; i < m; ++i)
    for (int j = i + 1; j < m; ++j) {
      int p1 = ps[i];
      int p2 = ps[j];
      int pz = p1 + p2 + 2;
      mint cans = ais2[pz] - as2[pz] * p1;
      ans += cans / pw<mint>(2, j - i + 1);
    }*/

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<mint> a(n);
  cin >> a;
  vector<int> ps(m);
  cin >> ps;
  for (int &x : ps) --x;
  mint ans = solve(a, ps, false);
  reverse(all(a));
  reverse(all(ps));
  for (int &x : ps) x = n - 1 - x;
  ans += solve(a, ps, true);
  ans /= (1 - 1 / pw<mint>(2, m));
  cout << ans << "\n";
  return 0;
}