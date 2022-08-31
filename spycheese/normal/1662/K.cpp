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

template<typename T>
struct Vec2 {
	T x, y;
	
	Vec2() {}
	Vec2(T nx, T ny) : x(nx), y(ny) {}
  template<typename M> Vec2(Vec2<M> const& b) : x(T(b.x)), y(T(b.y)) {}

	Vec2 operator - () const { return {-x, -y}; }
	Vec2 operator + (Vec2 const& b) const { return {x + b.x, y + b.y}; }
	Vec2 operator - (Vec2 const& b) const { return {x - b.x, y - b.y}; }
	Vec2 operator * (T b) const { return {x * b, y * b}; }
	Vec2 operator / (T b) const { return {x / b, y / b}; }

	Vec2& operator += (Vec2 const& b) { x += b.x; y += b.y; return *this; }
	Vec2& operator -= (Vec2 const& b) { x -= b.x; y -= b.y; return *this; }
	Vec2& operator *= (T b) { x *= b; y *= b; return *this; }
	Vec2& operator /= (T b) { x /= b; y /= b; return *this; }

	bool operator == (Vec2 const& b) const { return x == b.x && y== b.y; }
	bool operator != (Vec2 const& b) const { return !(*this == b); }
	bool operator <  (Vec2 const& b) const { return x == b.x ? y < b.y : x < b.x; }
	bool operator <= (Vec2 const& b) const { return !(b < *this); }
	bool operator >  (Vec2 const& b) const { return b < *this; }
	bool operator >= (Vec2 const& b) const { return !(*this < b); }
};

template<typename T>
typename enable_if<numeric_limits<T>::is_integer, Vec2<T>>::type operator % (Vec2<T> const& a, T b) {
  return {a.x % b, a.y % b};
}
template<typename T>
typename enable_if<numeric_limits<T>::is_integer, Vec2<T>&>::type operator %= (Vec2<T>& a, T b) {
  a.x %= b; a.y %= b; return a;
}

template<typename T> istream& operator >> (istream& in, Vec2<T>& v) { return in >> v.x >> v.y; }
template<typename T> ostream& operator << (ostream& out, Vec2<T> const& v) { return out << v.x << " " << v.y; }
template<typename T> Vec2<T> operator * (T b, Vec2<T> const& a) { return a * b; }
template<typename T> T dot(Vec2<T> const& a, Vec2<T> const& b) { return a.x * b.x + a.y * b.y; }
template<typename T> T cross(Vec2<T> const& a, Vec2<T> const& b) { return a.x * b.y - a.y * b.x; }
template<typename T> T length2(Vec2<T> const& a) { return a.x * a.x + a.y * a.y; }
template<typename T> Vec2<T> rotate90(Vec2<T> const& a) { return {-a.y, a.x}; }

template<typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec2<T>>::type normalize(Vec2<T> const& a) {
  return a / sqrt(a.x * a.x + a.y * a.y);
}

template<typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec2<T>>::type rotate(Vec2<T> const& a, T b) {
  T c = cos(b), s = sin(b); return {a.x*c - a.y*s, a.y*c + a.x*s};
}

template<typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec2<T>>::type ang2vec(T a) {
  return {cos(a), sin(a)};
}

template<typename T> using myDouble = typename conditional<numeric_limits<T>::is_integer, double, T>::type;

template<typename T, typename D = myDouble<T>>
D getAngle(Vec2<T> const& a) { return atan2((D)a.y, (D)a.x); }

template<typename T, typename D = myDouble<T>>
D getAngle(Vec2<T> const& a, Vec2<T> const& b) { return atan2((D)cross(a, b), (D)dot(a, b)); }

template<typename T, typename D = myDouble<T>>
D length(Vec2<T> const& a) { return sqrt((D)a.x*a.x + (D)a.y*a.y); }

template<typename T>
bool cmpAng(Vec2<T> const& v1, Vec2<T> const& v2) {
  int c1 = sgn(v1.y), c2 = sgn(v2.y);
  bool h1 = c1 > 0 || (c1 == 0 && sgn(v1.x) > 0);
  bool h2 = c2 > 0 || (c2 == 0 && sgn(v2.x) > 0);
  if (h1 != h2) return h1 > h2;
  return sgn(cross(v1, v2)) > 0;
}

// Check that angles v, v1, v2 are in this orde ccw
template<typename T>
bool cmpAngRel(Vec2<T> const& v, Vec2<T> const& v1, Vec2<T> const& v2) {
  int c1 = sgn(cross(v, v1)), c2 = sgn(cross(v, v2));
  bool h1 = c1 > 0 || (c1 == 0 && sgn(dot(v, v1)) >= 0);
  bool h2 = c2 > 0 || (c2 == 0 && sgn(dot(v, v2)) >= 0);
  if (h1 != h2) return h1 > h2;
  return sgn(cross(v1, v2)) > 0;
}

template<typename T>
typename enable_if<numeric_limits<T>::has_quiet_NaN, bool>::type isnan(Vec2<T> const& a) { return isnan(a.x) || isnan(a.y); }
template<typename T>
typename enable_if<!numeric_limits<T>::has_quiet_NaN, bool>::type isnan(Vec2<T> const&) { return false; }

template<typename T> bool isZero(Vec2<T> const& a) { return isZero(a.x) && isZero(a.y); }

typedef Vec2<ll> LVec2;
typedef Vec2<double> DVec2;
const DVec2 DVNAN = DVec2(DNAN, DNAN);

namespace std {
  template<typename T>
  struct hash<Vec2<T>> {
    size_t operator()(Vec2<T> const& p) const {
      size_t h1 = hash<T>()(p.x);
      size_t h2 = hash<T>()(p.x);
      return hash<size_t>()((h1 * 257ull) ^ h2);
    }
  };
}

pair<double, double> itsLineCircleT(DVec2 p, DVec2 const& v, DVec2 const& c, double r, bool check = true) {
  p -= c;
  double ea = dot(v, v), eb = dot(v, p), ec = dot(p, p) - r * r;
  double dd = eb*eb - ea*ec;
  if (check && dd < -EPS) return {DNAN, DNAN};
  dd = sqrt(max<double>(dd, 0));
  return {(-eb - dd) / ea, (-eb + dd) / ea};
}

pair<DVec2, DVec2> itsLineCircle(DVec2 const& p, DVec2 const& v, DVec2 const& c, double r, bool check = true) {
  pair<double, double> t = itsLineCircleT(p, v, c, r, check);
  return {p + v * t.first, p + v * t.second};
}

pair<DVec2, DVec2> radicalAxis(DVec2 const& c1, double r1, DVec2 const& c2, double r2, bool check = true) {
  if (check && isZero(c1 - c2)) return {DVNAN, DVNAN};
  DVec2 a = c2 - c1;
  double a2 = length2(a);
  double t = (a2 + r1*r1 - r2*r2) / (a2 * 2);
  DVec2 x = c1 + a * t;
  return {x, rotate90(a)};
}

pair<DVec2, DVec2> itsCircles(DVec2 const& c1, double r1, DVec2 const& c2, double r2, bool check = true) {
  double dist = length2(c1 - c2);
  if (check && (dist - (r1 + r2) * (r1 + r2) > EPS || dist - (r1 - r2) * (r1 - r2) < -EPS))
    return {DVNAN, DVNAN};
  auto axis = radicalAxis(c1, r1, c2, r2, check);
  if (isnan(axis.first)) return axis;
  return itsLineCircle(axis.first, axis.second, c1, r1, false);
}

double baz(DVec2 a, DVec2 b, DVec2 c) {
  if (length(a - b) < EPS) return length(a - c);
  if (length(a - c) < EPS) return length(b - c);
  if (length(c - b) < EPS) return length(a - c);
  if (dot(b - a, c - a) / length(b - a) / length(c - a) <= -0.5) return length(b - a) + length(c - a);
  if (dot(a - b, c - b) / length(b - a) / length(c - b) <= -0.5) return length(a - b) + length(c - b);
  if (dot(a - c, b - c) / length(c - a) / length(c - b) <= -0.5) return length(a - c) + length(b - c);
  if (cross(b - a, c - a) < 0) swap(a, c);
  DVec2 p = itsCircles(
      a + (b - a) * 0.5 - rotate90(b - a) / sqrt(3) / 2, length(b - a) / sqrt(3.0),
      a + (c - a) * 0.5 + rotate90(c - a) / sqrt(3) / 2, length(c - a) / sqrt(3.0),
      false
  ).first;
  return length(p - a) + length(p - b) + length(p - c);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  DVec2 a, b, c;
  cin >> a >> b >> c;
  if (cross(b - a, c - a) < 0) swap(b, c);
  double dist = 0;
  dist = max(dist, length(a - b));
  dist = max(dist, length(a - c));
  dist = max(dist, length(c - b));
  if (dot(b - a, c - a) <= 0 || dot(a - b, c - b) <= 0 || dot(a - c, b - c) <= 0) {
    cout << fixed << setprecision(10) << dist << "\n";
    return 0;
  }

  auto bar = [&](double qx, double qy) {
    DVec2 p = a + (b - a) * qx + (c - a) * qy;
    return max({
      baz(p, a, b),
      baz(p, b, c),
      baz(p, a, c)
    });
  };

  auto foo = [&](double x) {
    double l = 0, r = 1 - x;
    for (int iter = 0; iter < 100; ++iter) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (bar(x, m1) < bar(x, m2))
        r = m2;
      else
        l = m1;
    }
    return bar(x, (l + r) / 2);
  };

  double l = 0, r = 1;
  for (int iter = 0; iter < 100; ++iter) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (foo(m1) < foo(m2))
      r = m2;
    else
      l = m1;
  }

  cout << fixed << setprecision(10) << foo((l + r) / 2) << "\n";

  return 0;
}