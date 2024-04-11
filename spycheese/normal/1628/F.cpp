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

vector<char> solve(vector<pair<LVec2, LVec2>> segs, vector<LVec2> const& qs, LVec2 const& dir) {
  LVec2 vv = -rotate90(dir);
  struct Event {
    LVec2 p;
    int type;
    int sid;
    int vid;
  };
  vector<Event> es;

  int viq = 0;
  int vis = sz(qs);
  int vit = vis + sz(segs);
  int vn = vit + 1;

  for (int i = 0; i < sz(qs); ++i) {
    Event e;
    e.p = qs[i];
    e.type = 0;
    e.sid = -1;
    e.vid = viq + i;
    es.push_back(e);
  }

  for (int i = 0; i < sz(segs); ++i) {
    LVec2 &p1 = segs[i].X, &p2 = segs[i].Y;
    if (dot(p2 - p1, vv) == 0) continue;
    if (dot(p2 - p1, vv) < 0) swap(p1, p2);
    Event e;

    e.p = p1;
    e.type = -1;
    e.sid = i;
    e.vid = vis + i;
    es.push_back(e);

    e.p = p2;
    e.type = 1;
    e.sid = i;
    e.vid = vis + i;
    es.push_back(e);

    LVec2 dir2 = p2 - p1;
    if (dot(dir2, dir) < 0) dir2 = -dir2;
    if (dot(dir2, dir) * dot(dir2, dir) * 2 > length2(dir2) * length2(dir)) {
      e.p = (dot(p1, dir) > dot(p2, dir) ? p1 : p2);
      e.type = 0;
      e.sid = -1;
      e.vid = vis + i;
      es.push_back(e);
    }
  }

  {
    Event e;
    e.p = {0, 0};
    e.type = -2;
    e.sid = -1;
    e.vid = vit;
    es.push_back(e);
    e.p = {0, 0};
    e.type = 2;
    e.sid = -1;
    e.vid = vit;
    es.push_back(e);
  }

  sort(all(es), [&](Event const& a, Event const& b) {
    ll d1 = dot(a.p, vv);
    ll d2 = dot(b.p, vv);
    if (d1 != d2) return d1 < d2;
    return a.type < b.type;
  });

  vector<int> nxt(vn, -1);

  static LVec2 gdir;
  static LVec2 gp;
  gdir = dir;
  struct Seg {
    LVec2 a, b;
    int i;
    bool operator < (Seg const& s2) const {
      return cross(a - gp, b - a) * cross(gdir, s2.b - s2.a) < cross(s2.a - gp, s2.b - s2.a) * cross(gdir, b - a);
    };
  };
  set<Seg> st;
  for (Event const& e : es) {
    gp = e.p;
    if (e.type == -1) {
      st.insert({segs[e.sid].X, segs[e.sid].Y, e.vid});
    } else if (e.type == 1) {
      st.erase({segs[e.sid].X, segs[e.sid].Y, e.vid});
    } else if (e.type == 0) {
      auto it = st.upper_bound(Seg({e.p, e.p + vv, -1}));
      if (it == st.end()) {
      } else {
        nxt[e.vid] = it->i;
      }
    } else if (e.type == -2) {
      st.insert({-vv, vv, e.vid});
    } else if (e.type == 2) {
      st.erase({-vv, vv, e.vid});
    }
  }

  vector<int> res(vn, -1);
  vector<char> ans(sz(qs));
  res[vit] = 1;
  for (int i = 0; i < sz(ans); ++i) {
    function<int(int)> go = [&](int v) {
      if (v == -1) return 0;
      if (res[v] != -1) return res[v];
      return res[v] = go(nxt[v]);
    };
    ans[i] = go(i);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<LVec2, LVec2>> ss(n);
  cin >> ss;
  int q;
  cin >> q;
  vector<LVec2> qs(q);
  cin >> qs;
  vector<char> ans(q, 0);

  for (int i = 0; i < q; ++i) {
    bool ok = true;
    LVec2 p = qs[i];
    for (auto const& seg : ss) {
      LVec2 a = seg.X, b = seg.Y;
      if (cross(p, b - a) == 0) continue;
      if (sgn(cross(p, b)) * sgn(cross(p, a)) == 1) continue;
      if (sgn(cross(p - a, b - a)) * sgn(cross(-a, b - a)) == 1) continue;
      ok = false;
      break;
    }
    if (ok)
      ans[i] = 1;
  }

  for (auto const& seg : ss) {
    vector<char> ans2;
    ans2 = solve(ss, qs, -seg.X);
    for (int i = 0; i < q; ++i)
      if (ans2[i])
        ans[i] = 1;
    ans2 = solve(ss, qs, -seg.Y);
    for (int i = 0; i < q; ++i)
      if (ans2[i])
        ans[i] = 1;
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "YES\n" : "NO\n");
  }

  return 0;
}