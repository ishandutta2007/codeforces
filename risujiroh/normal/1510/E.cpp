#include <bits/stdc++.h>

// https://github.com/kth-competitive-programming/kactl
namespace kactl {

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

using R = long double;
constexpr R Eps = 1e-7;

inline namespace primitive {

template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  R dist() const { return sqrt((R)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  R angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); }  // makes dist()=1
  P perp() const { return P(-y, x); }        // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(R a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

template <class P>
R lineDist(const P& a, const P& b, const P& p) {
  return (R)(b - a).cross(p - a) / (b - a).dist();
}

R segDist(const Point<R>& s, const Point<R>& e, const Point<R>& p) {
  if (s == e) return (p - s).dist();
  auto d = (e - s).dist2(), t = min(d, max(R(0), (p - s).dot(e - s)));
  return ((p - s) * d - (e - s) * t).dist() / d;
}

template <class P>
bool onSegment(P s, P e, P p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
bool onSegment(Point<R> s, Point<R> e, Point<R> p) {
  return segDist(s, e, p) <= Eps;
}

template <class P>
vector<P> segInter(P a, P b, P c, P d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c),
       od = a.cross(b, d);
  // Checks if intersection is single non-endpoint point.
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<P> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {all(s)};
}

template <class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
  auto d = (e1 - s1).cross(e2 - s2);
  if (d == 0)  // if parallel
    return {-(s1.cross(e1, s2) == 0), P(0, 0)};
  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
  return {1, (s1 * p + e1 * q) / d};
}

template <class P>
int sideOf(P s, P e, P p) {
  return sgn(s.cross(e, p));
}
template <class P>
int sideOf(const P& s, const P& e, const P& p, R eps) {
  auto a = (e - s).cross(p - s);
  R l = (e - s).dist() * eps;
  return (a > l) - (a < -l);
}

Point<R> linearTransformation(const Point<R>& p0, const Point<R>& p1,
                              const Point<R>& q0, const Point<R>& q1,
                              const Point<R>& r) {
  Point<R> dp = p1 - p0, dq = q1 - q0, num(dp.cross(dq), dp.dot(dq));
  return q0 + Point<R>((r - p0).cross(num), (r - p0).dot(num)) / dp.dist2();
}

struct Angle {
  int x, y;
  int t;
  Angle(int x_, int y_, int t_ = 0) : x(x_), y(y_), t(t_) {}
  Angle operator-(Angle b) const { return {x - b.x, y - b.y, t}; }
  int half() const {
    assert(x || y);
    return y < 0 || (y == 0 && x < 0);
  }
  Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
  Angle t180() const { return {-x, -y, t + half()}; }
  Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
  // add a.dist2() and b.dist2() to also compare distances
  return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
         make_tuple(b.t, b.half(), a.x * (ll)b.y);
}

// Given two points, this calculates the smallest angle between
// them, i.e., the angle that covers the defined line segment.
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
  if (b < a) swap(a, b);
  return (b < a.t180() ? make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) {  // point a + vector b
  Angle r(a.x + b.x, a.y + b.y, a.t);
  if (a.t180() < r) r.t--;
  return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) {  // angle b - angle a
  int tu = b.t - a.t;
  a.t = b.t;
  return {a.x * b.x + a.y * b.y, a.x * b.y - a.y * b.x, tu - (b < a)};
}

// Projects point p onto line ab.
// Set refl=true to get reflection of point p across line ab insted.
// The wrong point will be returned if P is an integer point and the desired
// point doesn't have integer coordinates.
// Products of three coordinates are used in intermediate steps so watch out for
// overflow.
template <class P>
P lineProj(P a, P b, P p, bool refl = false) {
  P v = b - a;
  return p - v.perp() * (1 + refl) * v.cross(p - a) / v.dist2();
}

}  // namespace primitive

inline namespace circle {

bool circleInter(Point<R> a, Point<R> b, R r1, R r2,
                 pair<Point<R>, Point<R>>* out) {
  if (a == b) {
    assert(r1 != r2);
    return false;
  }
  Point<R> vec = b - a;
  R d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2,
    p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
  if (sum * sum < d2 || dif * dif > d2) return false;
  Point<R> mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
  *out = {mid + per, mid - per};
  return true;
}

template <class P>
vector<pair<P, P>> tangents(P c1, R r1, P c2, R r2) {
  P d = c2 - c1;
  R dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
  if (d2 == 0 || h2 < 0) return {};
  vector<pair<P, P>> out;
  for (R sign : {-1, 1}) {
    P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
    out.push_back({c1 + v * r1, c2 + v * r2});
  }
  if (h2 == 0) out.pop_back();
  return out;
}

#define arg(p, q) atan2(p.cross(q), p.dot(q))
R circlePoly(Point<R> c, R r, vector<Point<R>> ps) {
  auto tri = [&](Point<R> p, Point<R> q) {
    auto r2 = r * r / 2;
    Point<R> d = q - p;
    auto a = d.dot(p) / d.dist2(), b = (p.dist2() - r * r) / d.dist2();
    auto det = a * a - b;
    if (det <= 0) return arg(p, q) * r2;
    auto s = max(R(0), -a - sqrt(det)), t = min(R(1), -a + sqrt(det));
    if (t < 0 || 1 <= s) return arg(p, q) * r2;
    Point<R> u = p + d * s, v = p + d * t;
    return arg(p, u) * r2 + u.cross(v) / 2 + arg(v, q) * r2;
  };
  auto sum = 0.0;
  rep(i, 0, sz(ps)) sum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);
  return sum;
}
#undef arg

R ccRadius(const Point<R>& A, const Point<R>& B, const Point<R>& C) {
  return (B - A).dist() * (C - B).dist() * (A - C).dist() /
         abs((B - A).cross(C - A)) / 2;
}
Point<R> ccCenter(const Point<R>& A, const Point<R>& B, const Point<R>& C) {
  Point<R> b = C - A, c = B - A;
  return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}

pair<Point<R>, R> mec(vector<Point<R>> ps) {
  shuffle(all(ps), mt19937(time(0)));
  Point<R> o = ps[0];
  R r = 0, EPS = 1 + 1e-8;
  rep(i, 0, sz(ps)) if ((o - ps[i]).dist() > r * EPS) {
    o = ps[i], r = 0;
    rep(j, 0, i) if ((o - ps[j]).dist() > r * EPS) {
      o = (ps[i] + ps[j]) / 2;
      r = (o - ps[i]).dist();
      rep(k, 0, j) if ((o - ps[k]).dist() > r * EPS) {
        o = ccCenter(ps[i], ps[j], ps[k]);
        r = (o - ps[i]).dist();
      }
    }
  }
  return {o, r};
}

// Finds the intersection between a circle and a line.
// Returns a vector of either 0, 1, or 2 intersection points.
// P is intended to be Point<double>.
template <class P>
vector<P> circleLine(P c, R r, P a, P b) {
  P ab = b - a, p = a + ab * (c - a).dot(ab) / ab.dist2();
  R s = a.cross(b, c), h2 = r * r - s * s / ab.dist2();
  if (h2 < 0) return {};
  if (h2 == 0) return {p};
  P h = ab.unit() * sqrt(h2);
  return {p - h, p + h};
}

}  // namespace circle

inline namespace polygon {

template <class P>
bool inPolygon(vector<P>& p, P a, bool strict = true) {
  int cnt = 0, n = sz(p);
  rep(i, 0, n) {
    P q = p[(i + 1) % n];
    if (onSegment(p[i], q, a)) return !strict;
    // or: if (segDist(p[i], q, a) <= eps) return !strict;
    cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}

template <class T>
T polygonArea2(vector<Point<T>>& v) {
  T a = v.back().cross(v[0]);
  rep(i, 0, sz(v) - 1) a += v[i].cross(v[i + 1]);
  return a;
}

Point<R> polygonCenter(const vector<Point<R>>& v) {
  Point<R> res(0, 0);
  R A = 0;
  for (int i = 0, j = sz(v) - 1; i < sz(v); j = i++) {
    res = res + (v[i] + v[j]) * v[j].cross(v[i]);
    A += v[j].cross(v[i]);
  }
  return res / A / 3;
}

vector<Point<R>> polygonCut(const vector<Point<R>>& poly, Point<R> s,
                            Point<R> e) {
  vector<Point<R>> res;
  rep(i, 0, sz(poly)) {
    Point<R> cur = poly[i], prev = i ? poly[i - 1] : poly.back();
    bool side = s.cross(e, cur) < 0;
    if (side != (s.cross(e, prev) < 0))
      res.push_back(lineInter(s, e, cur, prev).second);
    if (side) res.push_back(cur);
  }
  return res;
}

vector<Point<ll>> convexHull(vector<Point<ll>> pts) {
  if (sz(pts) <= 1) return pts;
  sort(all(pts));
  vector<Point<ll>> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (Point<ll> p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

array<Point<ll>, 2> hullDiameter(vector<Point<ll>> S) {
  int n = sz(S), j = n < 2 ? 0 : 1;
  pair<ll, array<Point<ll>, 2>> res({0, {S[0], S[0]}});
  rep(i, 0, j) for (;; j = (j + 1) % n) {
    res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});
    if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0) break;
  }
  return res.second;
}

bool inHull(const vector<Point<ll>>& l, Point<ll> p, bool strict = true) {
  int a = 1, b = sz(l) - 1, r = !strict;
  if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
  if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
  if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r) return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (sideOf(l[0], l[c], p) > 0 ? b : a) = c;
  }
  return sgn(l[a].cross(l[b], p)) < r;
}

#define cmp(i, j) sgn(dir.perp().cross(poly[(i) % n] - poly[(j) % n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
template <class P>
int extrVertex(vector<P>& poly, P dir) {
  int n = sz(poly), lo = 0, hi = n;
  if (extr(0)) return 0;
  while (lo + 1 < hi) {
    int m = (lo + hi) / 2;
    if (extr(m)) return m;
    int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
    (ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
  }
  return lo;
}
#undef extr
#undef cmp
#define cmpL(i) sgn(a.cross(poly[i], b))
template <class P>
array<int, 2> lineHull(P a, P b, vector<P>& poly) {
  int endA = extrVertex(poly, (a - b).perp());
  int endB = extrVertex(poly, (b - a).perp());
  if (cmpL(endA) < 0 || cmpL(endB) > 0) return {-1, -1};
  array<int, 2> res;
  rep(i, 0, 2) {
    int lo = endB, hi = endA, n = sz(poly);
    while ((lo + 1) % n != hi) {
      int m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;
      (cmpL(m) == cmpL(endB) ? lo : hi) = m;
    }
    res[i] = (lo + !cmpL(hi)) % n;
    swap(endA, endB);
  }
  if (res[0] == res[1]) return {res[0], -1};
  if (!cmpL(res[0]) && !cmpL(res[1]))
    switch ((res[0] - res[1] + sz(poly) + 1) % sz(poly)) {
      case 0:
        return {res[0], res[0]};
      case 2:
        return {res[1], res[1]};
    }
  return res;
}
#undef cmpL

// Calculates the area of the union of n polygons (not necessarily convex).
// The points within each polygon must be given in CCW order.
// (Epsilon checks may optionally be added to sideOf/sgn, but shouldn't be
// needed.)
R rat(Point<R> a, Point<R> b) { return sgn(b.x) ? a.x / b.x : a.y / b.y; }
R polyUnion(vector<vector<Point<R>>>& poly) {
  R ret = 0;
  rep(i, 0, sz(poly)) rep(v, 0, sz(poly[i])) {
    Point<R> A = poly[i][v], B = poly[i][(v + 1) % sz(poly[i])];
    vector<pair<R, int>> segs = {{0, 0}, {1, 0}};
    rep(j, 0, sz(poly)) if (i != j) {
      rep(u, 0, sz(poly[j])) {
        Point<R> C = poly[j][u], D = poly[j][(u + 1) % sz(poly[j])];
        int sc = sideOf(A, B, C), sd = sideOf(A, B, D);
        if (sc != sd) {
          R sa = C.cross(D, A), sb = C.cross(D, B);
          if (min(sc, sd) < 0) segs.emplace_back(sa / (sa - sb), sgn(sc - sd));
        } else if (!sc && !sd && j < i && sgn((B - A).dot(D - C)) > 0) {
          segs.emplace_back(rat(C - A, B - A), 1);
          segs.emplace_back(rat(D - A, B - A), -1);
        }
      }
    }
    sort(all(segs));
    for (auto& s : segs) s.first = min(max(s.first, R(0)), R(1));
    R sum = 0;
    int cnt = segs[0].second;
    rep(j, 1, sz(segs)) {
      if (!cnt) sum += segs[j].first - segs[j - 1].first;
      cnt += segs[j].second;
    }
    ret += A.cross(B) * sum;
  }
  return ret / 2;
}

}  // namespace polygon

#undef sz
#undef all
#undef rep

}  // namespace kactl

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

using namespace kactl;
using P = Point<R>;

P go(const string& s) {
  int n = size(s);
  vector<P> v{P(n, 0)};
  int h = 0;
  for (int i : Per(n)) {
    if (s[i] == '(')
      --h;
    else
      ++h;
    v.emplace_back(i, h);
  }
  return polygonCenter(v);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  P g;
  g.x = scan<R>();
  g.y = scan<R>();

  vector<vector<tuple<P, R, string>>> v(n / 2 + 1);
  for (int mask : Rep(1 << n / 2)) {
    string s(n / 2, '(');
    for (int i : Rep(n / 2))
      if (mask >> i & 1) s[i] = ')';
    vector<R> h(n / 2 + 1);
    for (int i : Rep(n / 2)) {
      if (s[i] == '(')
        h[i + 1] = h[i] + 1;
      else if (s[i] == ')')
        h[i + 1] = h[i] - 1;
      else
        assert(false);
    }
    if (*min_element(ALL(h)) < 0) continue;
    {
      vector<P> temp;
      temp.emplace_back(n / 2, 0);
      for (int i : Per(n / 2 + 1)) temp.emplace_back(i, h[i]);
      v[int(h.back())].emplace_back(polygonCenter(temp), polygonArea2(temp), s);
    }
  }

  auto check = [&](const string& t) -> bool {
    return (go(t) - g).dist() < 1e-7;
  };

  for (auto&& e : v) {
    sort(ALL(e), [&](auto a, auto b) {
      return (get<0>(a) - g).angle() < (get<0>(b) - g).angle();
    });
  }

  for (int mask : Rep(1 << n / 2)) {
    string s(n / 2, '(');
    for (int i : Rep(n / 2))
      if (mask >> i & 1) s[i] = ')';
    vector<R> h(n / 2 + 1);
    for (int i : Per(n / 2)) {
      if (s[i] == '(')
        h[i] = h[i + 1] - 1;
      else if (s[i] == ')')
        h[i] = h[i + 1] + 1;
      else
        assert(false);
    }
    if (*min_element(ALL(h)) < 0) continue;

    auto&& e = v[int(h[0])];

    {
      vector<P> temp;
      temp.emplace_back(n / 2, 0);
      for (int i : Per(n / 2 + 1)) temp.emplace_back(n / 2 + i, h[i]);
      P q = polygonCenter(temp);
      R b = polygonArea2(temp);

      auto go = [&](R lo, R hi) -> void {
        int l = lower_bound(
                    ALL(e), lo,
                    [&](auto t, R x) { return (get<0>(t) - g).angle() < x; }) -
                begin(e);
        int r = lower_bound(
                    ALL(e), hi,
                    [&](auto t, R x) { return (get<0>(t) - g).angle() < x; }) -
                begin(e);
        for (int i : Rep(l, r)) {
          auto&& [p, a, t] = e[i];
          if (((p * a + q * b) / (a + b) - g).dist() < 1e-7) {
            cout << t + s << '\n';
            exit(0);
          }
        }
      };

      R th = (g - q).angle();
      R tau = 2 * acos(R(-1));
      for (int i : Rep(-1, 2)) go(th + i * tau - 0.1, th + i * tau + 0.1);
    }
  }

  assert(false);
}