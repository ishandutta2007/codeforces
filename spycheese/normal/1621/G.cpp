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

vector<mint> cntEnds(vector<int> const& a) {
  vector<mint> d(sz(a));
  Fen<mint> fen(sz(a) + 3);
  for (int i = 0; i < sz(a); ++i) {
    d[i] = 1 + fen.sum(a[i]);
    fen.add(a[i], d[i]);
  }
  return d;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  {
    vector<int> a2 = a;
    unique(a2);
    for (int &x : a)
      x = lowerBound(a2, x);
  }
  auto d1 = cntEnds(a);

  vector<int> arev = a;
  reverse(all(arev));
  for (int &x : arev) x = n - 1 - x;
  auto d2 = cntEnds(arev);
  reverse(all(d2));

  mint ans = 0;
  for (int i = 0; i < n; ++i)
    ans += d1[i] * d2[i];

  vector<vector<int>> poss(n);
  for (int i = 0; i < n; ++i)
    poss[a[i]].push_back(i);

  int cmax = -1;
  Fen<mint> fen(n + 3);
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == cmax) {
      ans -= d1[i];
    } else if (a[i] > cmax) {
      vector<int> ps;
      for (int j = max(0, cmax); j < a[i]; ++j)
        ps.insert(ps.end(), all(poss[j]));
      ps.push_back(i);
      unique(ps);
      vector<pair<int, mint>> cc;
      while (!ps.empty()) {
        int j = ps.back();
        ps.pop_back();
        if (j > i) continue;
        mint d = 0;
        if (j == i)
          d = 1;
        else
          d = fen.sum(a[j] + 1, n + 3);
        ans -= d * d1[j];
        fen.add(a[j], d);
        cc.push_back({a[j], d});
      }
      for (auto p : cc)
        fen.add(p.X, -p.Y);
      cmax = a[i];
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}