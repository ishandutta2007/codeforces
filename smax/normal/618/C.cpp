#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

template<typename T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Point operator + (const Point &other) const {return Point(x + other.x, y + other.y);}
    Point operator - (const Point &other) const {return Point(x - other.x, y - other.y);}
    Point operator * (T c) const {return Point(x * c, y * c);}
    Point operator / (T c) const {return Point(x / c, y / c);}
    Point& operator += (const Point &other) {return *this = *this + other;}
    Point& operator -= (const Point &other) {return *this = *this - other;}
    Point& operator *= (T c) {return *this = *this * c;}
    Point& operator /= (T c) {return *this = *this / c;}
    bool operator < (const Point &other) const {return tie(x, y) < tie(other.x, other.y);}
    bool operator <= (const Point &other) const {return tie(x, y) <= tie(other.x, other.y);}
    bool operator > (const Point &other) const {return tie(x, y) > tie(other.x, other.y);}
    bool operator >= (const Point &other) const {return tie(x, y) >= tie(other.x, other.y);}
    bool operator == (const Point &other) const {return tie(x, y) == tie(other.x, other.y);}
    bool operator != (const Point &other) const {return tie(x, y) != tie(other.x, other.y);}
    T mag2() const {return x * x + y * y;}
    double mag() const {return sqrt(mag2());}
    Point unit() const {return *this / mag();}
    Point perp() const {return Point(-y, x);}
    Point normal() const {return perp().unit();}
    double angle() const {return atan2(y, x);}
    Point rot(double ang) const {return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));}
    friend T dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
    friend T cross(const Point<T> &a, const Point<T> &b) {return a.x * b.y - a.y * b.x;}
    friend T dist2(const Point<T> &a, const Point<T> &b) {return (a - b).mag2();}
    friend double dist(const Point<T> &a, const Point<T> &b) {return (a - b).mag();}
    friend T ccw(const Point<T> &a, const Point<T> &b, const Point<T> &o) {return cross(a - o, b - o);}
    friend double angle(const Point<T> &a, const Point<T> &b) {return atan2(cross(a, b), dot(a, b));}
    friend Point<T> rot(const Point<T> &p, const Point<T> &o, double ang) {return o + (p - o).rot(ang);}
    friend ostream& operator << (ostream &os, const Point &p) {return os << "(" << p.x << ", " << p.y << ")";}
};

template<typename T>
struct Line {
    Point<T> a, b, ab;

    Line() {}

    Line(const Point<T> &_a, const Point<T> &_b) : a(_a), b(_b), ab(b - a) {}

    friend bool onLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return p == l.a;
        return cross((p - l.a), l.ab) == 0;
    }

    friend bool onSegment(const Point<T> &p, const Line &s) {
        if (s.a == s.b) return p == s.a;
        Point<T> va = s.a - p, vb = s.b - p;
        return cross(va, vb) == 0 && dot(va, vb) <= 0;
    }

    friend double distLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return dist(p, l.a);
        return abs(cross(p - l.a, l.ab)) / l.ab.mag();
    }

    friend double distSegment(const Point<T> &p, const Line &s) {
        if (dot(p - s.a, s.ab) <= 0) return dist(p, s.a);
        if (dot(p - s.b, s.ab) >= 0) return dist(p, s.b);
        return distLine(p, s);
    }

    friend Point<T> proj(const Point<T> &p, const Line &l) {
        Point<T> ret = l.a;
        if (l.a != l.b) ret += l.ab * dot(p - l.a, l.ab) / l.ab.mag2();
        return ret;
    }

    friend Point<T> reflect(const Point<T> &p, const Line &l) {
        return proj(p, l) * 2 - p;
    }

    friend ostream& operator << (ostream &os, const Line &l) {
        return os << "<" << l.a.x << ", " << l.a.y << "> + t<" << l.ab.x << ", " << l.ab.y << ">";
    }
};

typedef Point<long long> P;
typedef Line<long long> L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<P> pts(n);
    for (int i=0; i<n; i++)
        cin >> pts[i].x >> pts[i].y;

    // start with 0 and 1
    L base(pts[0], pts[1]);
    pair<long long, int> closer(LLONG_MAX, 1);
    for (int i=2; i<n; i++)
        if (onSegment(pts[i], base))
            closer = min(closer, {dist2(pts[0], pts[i]), i});
    if (closer.second != 1)
        base = L(pts[0], pts[closer.second]);

    pair<double, int> best(DBL_MAX, -1);
    for (int i=1; i<n; i++)
        if (i != closer.second && !onLine(pts[i], base))
            best = min(best, {distLine(pts[i], base), i});

    assert(best.second != -1);
    cout << "1 " << closer.second + 1 << " " << best.second + 1 << "\n";

    return 0;
}