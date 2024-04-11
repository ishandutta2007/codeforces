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
struct Vec3 {
	T x, y, z;
	
	Vec3() {}
	Vec3(T nx, T ny, T nz) : x(nx), y(ny), z(nz) {}
  template<typename M> Vec3(Vec3<M> const& b) : x(T(b.x)), y(T(b.y)), z(T(b.z)) {}

	Vec3 operator - () const { return {-x, -y, -z}; }
	Vec3 operator + (Vec3 const& b) const { return {x + b.x, y + b.y, z + b.z}; }
	Vec3 operator - (Vec3 const& b) const { return {x - b.x, y - b.y, z - b.z}; }
	Vec3 operator * (T b) const { return {x * b, y * b, z * b}; }
	Vec3 operator / (T b) const { return {x / b, y / b, z / b}; }

	Vec3& operator += (Vec3 const& b) { x += b.x; y += b.y; z += b.z; return *this; }
	Vec3& operator -= (Vec3 const& b) { x -= b.x; y -= b.y; z -= b.z; return *this; }
	Vec3& operator *= (T b) { x *= b; y *= b; z *= b; return *this; }
	Vec3& operator /= (T b) { x /= b; y /= b; z /= b; return *this; }

	bool operator == (Vec3 const& b) const { return x == b.x && y == b.y && z == b.z; }
	bool operator != (Vec3 const& b) const { return !(&this == b); }
	bool operator <  (Vec3 const& b) const { return x != b.x ? x < b.x : (y != b.y ? y < b.y : z < b.z); }
	bool operator <= (Vec3 const& b) const { return !(b < *this); }
	bool operator >  (Vec3 const& b) const { return b < *this; }
	bool operator >= (Vec3 const& b) const { return !(*this < b); }
};

template<typename T>
typename enable_if<numeric_limits<T>::is_integer, Vec3<T>>::type operator % (Vec3<T> const& a, T b) {
  return {a.x % b, a.y % b, a.z % b};
}
template<typename T>
typename enable_if<numeric_limits<T>::is_integer, Vec3<T>&>::type operator %= (Vec3<T>& a, T b) {
  a.x %= b; a.y %= b; a.z %= b; return a;
}

template<typename T> istream& operator >> (istream& in, Vec3<T>& v) { return in >> v.x >> v.y >> v.z; }
template<typename T> ostream& operator << (ostream& out, Vec3<T> const& v) { return out << v.x << " " << v.y << " " << v.z; }
template<typename T> Vec3<T> operator * (T b, Vec3<T> const& a) { return a * b; }
template<typename T> T dot(Vec3<T> const& a, Vec3<T> const& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
template<typename T> Vec3<T> cross(Vec3<T> const& a, Vec3<T> const& b) {
  return {
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  };
}
template<typename T> T length2(Vec3<T> const& a) { return a.x * a.x + a.y * a.y + a.z * a.z; }

template<typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec3<T>>::type normalize(Vec3<T> const& a) {
  return a / sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

template<typename T> using myDouble = typename conditional<numeric_limits<T>::is_integer, double, T>::type;

template<typename T, typename D = myDouble<T>>
D getAngle(Vec3<T> const& a, Vec3<T> const& b) { return atan2((D)cross(a, b), (D)dot(a, b)); }

template<typename T, typename D = myDouble<T>>
D length(Vec3<T> const& a) { return sqrt((D)a.x*a.x + (D)a.y*a.y + (D)a.z*a.z); }

template<typename T>
typename enable_if<numeric_limits<T>::has_quiet_NaN, bool>::type isnan(Vec3<T> const& a) {
  return isnan(a.x) || isnan(a.y) || isnan(a.z); 
}
template<typename T>
typename enable_if<!numeric_limits<T>::has_quiet_NaN, bool>::type isnan(Vec3<T> const&) { return false; }

template<typename T> bool isZero(Vec3<T> const& a) { return isZero(a.x) && isZero(a.y) && isZero(a.z); }

typedef Vec3<ll> LVec3;
typedef Vec3<double> DVec3;
const DVec3 DV3NAN = DVec3(DNAN, DNAN, DNAN);

long double sqr(long double x) { return x*x; }

struct Point {
  LVec3 p;
  vector<int> e;
  vector<int> fs;
  bool added = 0;
};

struct Face {
  int ps[3];
  long double ea = 0, eb = 0, ec = 0;
};

struct Event {
  int askI;
  ll h;
  int pi;
};

struct DSU {
  vector<int> p;
  DSU() = default;
  explicit DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<Point> ps(n);
  for (auto &p : ps)
    cin >> p.p;
  int m;
  cin >> m;
  vector<Face> fs(m);
  for (int j = 0; j < m; ++j) {
    auto &f = fs[j];
    for (int i = 0; i < 3; ++i) {
      cin >> f.ps[i];
      --f.ps[i];
      for (int q = 0; q < i; ++q) {
        ps[f.ps[i]].e.push_back(f.ps[q]);
        ps[f.ps[q]].e.push_back(f.ps[i]);
      }
      ps[f.ps[i]].fs.push_back(j);
    }
    sort(fs[j].ps, fs[j].ps + 3, [&](int x, int y) { return ps[x].p.z > ps[y].p.z; });
  }

  vector<Event> es;
  for (int i = 0; i < n; ++i)
    es.push_back({-1, ps[i].p.z, i});
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll h;
    int pi;
    cin >> h >> pi;
    --pi;
    es.push_back({i, h, pi});
  }

  sort(all(es), [](Event const& a, Event const& b) {
    if (a.h == b.h) return a.askI > b.askI;
    return a.h > b.h;
  });
  vector<long double> ans(q, -1);

  DSU dsu(n);
  vector<long double> sea(n), seb(n), sec(n);

  for (Event const& e : es) {
    ll h = e.h;
    if (e.askI == -1) {
      int pi = e.pi;
      Point &p = ps[pi];
      for (int pj : p.e)
        if (ps[pj].added) {
          int x = dsu.get(pi);
          int y = dsu.get(pj);
          if (dsu.merge(x, y)) {
            sea[x] += sea[y];
            seb[x] += seb[y];
            sec[x] += sec[y];
          }
        }
      p.added = 1;
      for (int fi : p.fs) {
        Face &f = fs[fi];

        int rr = dsu.get(f.ps[0]);
        sea[rr] -= f.ea;
        seb[rr] -= f.eb;
        sec[rr] -= f.ec;

        LVec3 p1 = ps[f.ps[2]].p;
        LVec3 p2 = ps[f.ps[1]].p;
        LVec3 p3 = ps[f.ps[0]].p;
        long double aa = 0.5 * length(cross(p2 - p1, p3 - p1));
        long double a3 = (p3.z - p1.z == 0 ? 0.0 : 1. * (p3.z - p2.z) / (p3.z - p1.z) * aa);
        long double a1 = aa - a3;

        if (pi == f.ps[2]) {
          f.ea = 0;
          f.eb = 0;
          f.ec = aa;
        } else if (pi == f.ps[1]) {
          if (p1.z != p2.z) {
            long double c = a1 / sqr(p1.z - p2.z);
            f.ea = -c;
            f.eb = 2*p1.z*c;
            f.ec = aa - p1.z*p1.z*c;
          }
        } else if (pi == f.ps[0]) {
          if (p3.z != p2.z) {
            long double c = a3 / sqr(p3.z - p2.z);
            f.ea = c;
            f.eb = -2*p3.z*c;
            f.ec = p3.z*p3.z*c;
          }
        }

        sea[rr] += f.ea;
        seb[rr] += f.eb;
        sec[rr] += f.ec;
      }
    } else {
      int pi = e.pi;
      Point const& p = ps[pi];
      if (p.p.z <= e.h) continue;
      int vr = dsu.get(pi);
      long double &cans = ans[e.askI];
      cans = sea[vr] * h * h + seb[vr] * h + sec[vr];
    }
  }

  for (long double x : ans)
    cout << fixed << setprecision(10) << x << "\n";

  return 0;
}