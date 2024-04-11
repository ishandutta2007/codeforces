#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

namespace geometry {
using Real = double;
constexpr Real EPS = 1e-8;
constexpr Real PI = 3.14159265358979323846L;

inline int sgn(Real x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }

inline int compare(Real a, Real b) { return sgn(a - b); }

inline bool equals(Real a, Real b) { return compare(a, b) == 0; }

struct Point {
    Real x, y;

    Point() {}

    Point(Real x, Real y) : x(x), y(y) {}

    Point& operator+=(const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }

    Point& operator-=(const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    Point& operator*=(const Real& k) {
        x *= k, y *= k;
        return *this;
    }

    Point& operator/=(const Real& k) {
        x /= k, y /= k;
        return *this;
    }

    Point operator+(const Point& p) const { return Point(*this) += p; }

    Point operator-(const Point& p) const { return Point(*this) -= p; }

    Point operator*(const Real& k) const { return Point(*this) *= k; }

    Point operator/(const Real& k) const { return Point(*this) /= k; }

    Point operator-() const { return Point(-x, -y); }

    bool operator==(const Point& p) const { return (compare(x, p.x) == 0 && compare(y, p.y) == 0); }

    bool operator!=(const Point& p) const { return !(*this == p); }

    bool operator<(const Point& p) const {
        return compare(x, p.x) < 0 || (compare(x, p.x) == 0 && compare(y, p.y) < 0);
    }

    bool operator>(const Point& p) const {
        return compare(x, p.x) > 0 || (compare(x, p.x) == 0 && compare(y, p.y) > 0);
    }

    friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << p.x << ' ' << p.y; }

    Real norm() const { return x * x + y * y; }

    Real abs() const { return std::hypot(x, y); }

    Real arg() const { return std::atan2(y, x); }

    Point normal() const { return Point(-y, x); }

    Point unit() const { return *this / abs(); }

    Point rotate(Real theta) const {
        return Point(x * std::cos(theta) - y * std::sin(theta), x * std::sin(theta) + y * std::cos(theta));
    }
};

Point polar(const Real& r, const Real& theta) { return Point(cos(theta), sin(theta)) * r; }

Real dot(const Point& p, const Point& q) { return p.x * q.x + p.y * q.y; }

Real cross(const Point& p, const Point& q) { return p.x * q.y - p.y * q.x; }

Real distance(const Point& p, const Point& q) { return (p - q).abs(); }

struct Line {
    Point a, b;

    Line() {}

    Line(const Point& a, const Point& b) : a(a), b(b) {}

    Line(const Real& A, const Real& B, const Real& C) {  // Ax + By = c
        if (equals(A, 0)) {
            assert(!equals(B, 0));
            a = Point(0, C / B);
            b = Point(1, C / B);
        } else if (equals(B, 0)) {
            a = Point(C / A, 0);
            b = Point(C / A, 1);
        } else {
            a = Point(0, C / B);
            b = Point(C / A, 0);
        }
    }

    friend std::istream& operator>>(std::istream& is, Line& l) { return is >> l.a >> l.b; }

    friend std::ostream& operator<<(std::ostream& os, const Line& l) { return os << l.a << " to " << l.b; }

    Point diff() const { return b - a; }
};

struct Segment : Line {
    Segment() {}

    Segment(Point a, Point b) : Line(a, b) {}

    Real length() const { return diff().abs(); }
};

Point proj(const Line& l, const Point& p) {
    Point v = l.diff().unit();
    return l.a + v * dot(v, p - l.a);
}

Point refl(const Line& l, const Point& p) {
    Point h = proj(l, p);
    return h + (h - p);
}

bool orthogonal(const Line& l, const Line& m) { return equals(dot(l.diff(), m.diff()), 0); }

bool parallel(const Line& l, const Line& m) { return equals(cross(l.diff(), m.diff()), 0); }

enum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };

Position ccw(const Point& a, Point b, Point c) {
    b -= a, c -= a;
    if (sgn(cross(b, c)) == +1) return COUNTER_CLOCKWISE;
    if (sgn(cross(b, c)) == -1) return CLOCKWISE;
    if (sgn(dot(b, c)) == -1) return ONLINE_BACK;
    if (compare(b.norm(), c.norm()) == -1) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(const Line& l, const Point& p) { return abs(ccw(l.a, l.b, p)) != 1; }

bool intersect(const Line& l, const Line& m) {
    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(), l.b - m.a);
    if (equals(A, 0) && equals(B, 0)) return true;
    return !parallel(l, m);
}

bool intersect(const Line& l, const Segment& s) {
    return sgn(cross(l.diff(), s.a - l.a)) * sgn(cross(l.diff(), s.b - l.a)) <= 0;
}

bool intersect(const Segment& s, const Point& p) { return ccw(s.a, s.b, p) == ON_SEGMENT; }

bool intersect(const Segment& s, const Segment& t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Real distance(const Line& l, const Point& p) { return distance(p, proj(l, p)); }

Real distance(const Line& l, const Line& m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Line& l, const Segment& s) {
    return intersect(l, s) ? 0 : std::min(distance(l, s.a), distance(l, s.b));
}

Real distance(const Segment& s, const Point& p) {
    Point h = proj(s, p);
    return intersect(s, h) ? distance(p, h) : std::min(distance(p, s.a), distance(p, s.b));
}

Real distance(const Segment& s, const Segment& t) {
    if (intersect(s, t)) return 0;
    return std::min({distance(s, t.a), distance(s, t.b), distance(t, s.a), distance(t, s.b)});
}

Point crosspoint(const Line& l, const Line& m) {
    assert(intersect(l, m));
    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(), l.b - m.a);
    if (equals(A, 0) && equals(B, 0)) return m.a;
    return m.a + m.diff() * B / A;
}

struct Circle {
    Point center;
    Real radius;

    Circle() {}

    Circle(const Point& center, const Real& radius) : center(center), radius(radius) {}

    friend std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.center >> c.radius; }

    friend std::ostream& operator<<(std::ostream& os, const Circle& c) { return os << c.center << ' ' << c.radius; }
};

bool intersect(const Circle& c, const Line& l) { return compare(c.radius, distance(l, c.center)) >= 0; }

int intersect(const Circle& c, const Segment& s) {
    Point h = proj(s, c.center);
    if (compare(distance(c.center, h), c.radius) > 0) return 0;
    Real d1 = (c.center - s.a).abs(), d2 = (c.center - s.b).abs();
    if (compare(c.radius, d1) >= 0 && compare(c.radius, d2) >= 0) return 0;
    if (compare(c.radius, d1) * compare(c.radius, d2) < 0) return 1;
    if (sgn(dot(s.a - h, s.b - h)) < 0) return 2;
    return 0;
}

std::vector<Point> crosspoint(const Circle& c, const Line& l) {
    Point h = proj(l, c.center);
    Real d = c.radius * c.radius - (c.center - h).norm();
    if (sgn(d) < 0) return {};
    if (sgn(d) == 0) return {h};
    Point v = l.diff().unit() * sqrt(d);
    return {h - v, h + v};
}

std::vector<Point> crosspoint(const Circle& c, const Segment& s) {
    int num = intersect(c, s);
    if (num == 0) return {};
    auto res = crosspoint(c, Line(s.a, s.b));
    if (num == 2) return res;
    if (sgn(dot(s.a - res[0], s.b - res[0])) > 0) std::swap(res[0], res[1]);
    return {res[0]};
}

// requirement : c != d
std::vector<Point> crosspoint(const Circle& c1, const Circle& c2) {
    Real r1 = c1.radius, r2 = c2.radius;
    if (r1 < r2) return crosspoint(c2, c1);
    Real d = distance(c1.center, c2.center);
    if (compare(d, r1 + r2) > 0 || compare(d, r1 - r2) < 0) return {};
    Real alpha = std::acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    Real theta = (c2.center - c1.center).arg();
    Point p = c1.center + polar(r1, theta + alpha);
    Point q = c1.center + polar(r1, theta - alpha);
    if (p == q) return {p};
    return {p, q};
}

Line bisector(const Point& p, const Point& q) {
    Point c = (p + q) * 0.5;
    Point v = (q - p).normal();
    return Line(c - v, c + v);
}

Circle circumcircle(Point a, Point b, const Point& c) {
    Point center = crosspoint(bisector(a, c), bisector(b, c));
    return Circle(center, distance(c, center));
}

std::vector<Point> center_given_radius(const Point& a, const Point& b, const Real& r) {
    Point m = (b - a) * 0.5;
    Real d1 = m.abs();
    if (equals(d1, 0) || d1 > r) return {};
    Real d2 = sqrt(r * r - d1 * d1);
    Point n = m.normal() * d2 / d1;
    Point p = a + m - n, q = a + m + n;
    if (p == q) return {p};
    return {p, q};
}

int count_tangent(const Circle& c1, const Circle& c2) {
    Real r1 = c1.radius, r2 = c2.radius;
    if (r1 < r2) return count_tangent(c2, c1);
    Real d = distance(c1.center, c2.center);
    if (compare(d, r1 + r2) > 0) return 4;
    if (compare(d, r1 + r2) == 0) return 3;
    if (compare(d, r1 - r2) > 0) return 2;
    if (compare(d, r1 - r2) == 0) return 1;
    return 0;
}

std::vector<Point> tangent_to_circle(const Circle& c, const Point& p) {
    return crosspoint(c, Circle(p, sqrt((c.center - p).norm() - c.radius * c.radius)));
}

enum Contain { OUT, ON, IN };

struct Polygon : std::vector<Point> {
    using std::vector<Point>::vector;

    Polygon(int n) : std::vector<Point>(n) {}

    std::vector<Segment> segments() const {
        assert(size() > 1);
        std::vector<Segment> segs;
        for (size_t i = 0; i < size(); i++) segs.emplace_back((*this)[i], (*this)[(i + 1) % size()]);
        return segs;
    }

    Real area() const {
        Real sum = 0;
        for (size_t i = 0; i < size(); i++) sum += cross((*this)[i], (*this)[(i + 1) % size()]);
        return std::abs(sum) / 2;
    }

    bool is_convex(bool accept_on_segment = true) const {
        int n = size();
        for (int i = 0; i < n; i++) {
            if (accept_on_segment) {
                if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) == CLOCKWISE) {
                    return false;
                }
            } else {
                if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) != COUNTER_CLOCKWISE) {
                    return false;
                }
            }
        }
        return true;
    }
};

Contain contain(const Polygon& P, const Point& p) {
    bool in = false;
    for (size_t i = 0; i < P.size(); i++) {
        if (ccw(P[i], P[(i + 1) % P.size()], p) == ON_SEGMENT) return ON;
        Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;
        if (a.y > b.y) std::swap(a, b);
        if (sgn(a.y) <= 0 && sgn(b.y) > 0 && sgn(cross(a, b)) < 0) in = !in;
    }
    return in ? IN : OUT;
}

Polygon convex_hull(Polygon& P, bool accept_on_segment = false) {
    int n = P.size(), k = 0;
    if (n <= 2) return P;
    std::sort(P.begin(), P.end());
    Polygon ch(n * 2);
    auto check = [&](int i) {
        if (accept_on_segment) return ccw(ch[k - 2], ch[k - 1], P[i]) == CLOCKWISE;
        return ccw(ch[k - 2], ch[k - 1], P[i]) != COUNTER_CLOCKWISE;
    };
    for (int i = 0; i < n; ch[k++] = P[i++]) {
        while (k >= 2 && check(i)) {
            k--;
        }
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = P[i--]) {
        while (k >= t && check(i)) {
            k--;
        }
    }
    ch.resize(k - 1);
    int start = 0;
    for (int i = 1; i < k - 1; i++) {
        if (equals(ch[i].y, ch[start].y) ? ch[i].x < ch[start].x : ch[i].y < ch[start].y) {
            start = i;
        }
    }
    std::rotate(ch.begin(), ch.begin() + start, ch.end());
    return ch;
}

std::tuple<int, int, Real> convex_diameter(const Polygon& convex) {
    assert(convex.is_convex());
    int n = convex.size();
    Real max_dist = -1;
    std::pair<int, int> argmax = {-1, -1};
    for (int i = 0, j = 0; i < n; i++) {
        while (j + 1 < n && distance(convex[i], convex[j + 1]) > distance(convex[i], convex[j])) j++;
        double cur_dist = distance(convex[i], convex[j]);
        if (max_dist < cur_dist) {
            max_dist = cur_dist;
            argmax = {i, j};
        }
    }
    return {argmax.first, argmax.second, max_dist};
}

Polygon convex_cut(const Polygon& convex, const Line& l) {
    assert(convex.is_convex());
    int n = convex.size();
    Polygon res;
    for (int i = 0; i < n; i++) {
        const Point& cur = convex[i];
        const Point& nxt = convex[(i + 1) % n];
        if (ccw(l.a, l.b, cur) != CLOCKWISE) res.emplace_back(cur);
        if (ccw(l.a, l.b, cur) * ccw(l.a, l.b, nxt) < 0) res.emplace_back(crosspoint(Segment(cur, nxt), l));
    }
    return res;
}

Polygon voronoi(const Polygon& P, const std::vector<Point>& ps, size_t idx) {
    Polygon res = P;
    for (size_t i = 0; i < ps.size(); i++) {
        if (i == idx) continue;
        res = convex_cut(res, bisector(ps[idx], ps[i]));
    }
    return res;
}

bool sort_by_argument(Point l, Point r) {
    auto la = l.arg();
    auto ra = r.arg();
    if (abs(la - ra) > 1)
        return la < ra;
    else
        return l.x * r.y > l.y * r.x;
}

}  // namespace geometry

/**
 * @brief 2 
 * @docs docs/geometry/geometry.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

using namespace geometry;
const Point origin = Point(0, 0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n, k;
    cin >> n >> k;
    vector<Point> P(n);
    cin >> P;

    auto check = [&](double x) {
        int cur = 0;
        vector<pair<double, int>> vs;
        for (int i = 0; i < n; i++) {
            if (distance(origin, P[i]) > 2 * x) continue;
            if (P[i] == origin) {
                cur++;
                continue;
            }
            auto ps = center_given_radius(origin, P[i], x);  // out -> in
            auto ra = ps[1].arg();
            auto la = ps[0].arg();
            if (ra < la) {
                cur++;
                vs.emplace_back(ra, -1);
                ra += 2 * PI;
            }
            vs.emplace_back(la, 1);
            vs.emplace_back(ra, -1);
        }
        if (cur >= k) return true;
        sort(ALL(vs));
        for (size_t i = 0; i < vs.size(); i++) {
            cur += vs[i].second;
            if (i + 1 == vs.size() || vs[i + 1].first - vs[i].first > EPS) {
                if (cur >= k) {
                    return true;
                }
            }
        }
        return false;
    };

    double lb = 0, ub = 200010;
    for (int _ = 0; _ < 50; _++) {
        double mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    cout << ub << '\n';
    return 0;
}