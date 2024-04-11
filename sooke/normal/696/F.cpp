#include <bits/stdc++.h>
 
inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}
 
const long double eps = 1e-16L, inf = 1e9;
const long double Eps = 1e-14L, Inf = 1e18;
const long double EPS = 1e-08L;
 
namespace Geometry {
    struct Point {
        long double x, y;
 
        inline long double length() const {
            return std::sqrt(x * x + y * y);
        }
    };
 
    bool operator <(const Point &u, const Point &v) {
        return std::abs(u.x - v.x) < eps ? u.y < v.y : u.x < v.x;
    }
    Point operator ~(const Point &u) {
        return (Point) {-u.y, u.x};
    }
    Point operator -(const Point &u) {
        return (Point) {-u.x, -u.y};
    }
    Point operator *(const Point &u, long double k) {
        return (Point) {u.x * k, u.y * k};
    }
    Point operator /(const Point &u, long double k) {
        return (Point) {u.x / k, u.y / k};
    }
    Point operator +(const Point &u, const Point &v) {
        return (Point) {u.x + v.x, u.y + v.y};
    }
    Point operator -(const Point &u, const Point &v) {
        return (Point) {u.x - v.x, u.y - v.y};
    }
    Point operator >>(const Point &u, const Point &v) {
        return (Point) {v.x - u.x, v.y - u.y};
    }
    long double operator *(const Point &u, const Point &v) {
        return u.x * v.x + u.y * v.y;
    }
    long double operator ^(const Point &u, const Point &v) {
        return u.x * v.y - u.y * v.x;
    }
    
    struct Line {
        Point s, t;
        long double arg, dis;
 
        Line(Point u, Point v) {
            s = u; t = v;
            arg = std::atan2((s >> t).y, (s >> t).x);
            dis = (s ^ t) / (s >> t).length();
        }
 
        inline bool contain(Point u) {
            return ((s >> t) ^ (s >> u)) > -Eps;
        }
    };
 
    bool operator <(const Line &a, const Line &b) {
        return std::abs(a.arg - b.arg) < Eps ? a.dis < b.dis : a.arg < b.arg;
    }
    Point operator &(const Line &a, const Line &b) {
        Point u = a.s >> a.t, v = b.s >> b.t, w = a.s >> b.s;
        if (std::abs(u ^ v) < eps) { return (Point) {-Inf, -Inf}; }
        return a.s + u * ((w ^ v) / (u ^ v));
    }
 
    std::vector<Line> intersection(std::vector<Line> a) {
        std::sort(a.begin(), a.end());
        int l = 0, r = -1;
        std::vector<Line> que = a;
        for (int i = 0; i < (int) a.size(); i++) {
            if (i > 0 && std::abs(a[i - 1].arg - a[i].arg) < Eps) { continue; }
            for (; l < r && !a[i].contain(que[r] & que[r - 1]); r--);
            for (; l < r && !a[i].contain(que[l] & que[l + 1]); l++);
            que[++r] = a[i];
        }
        for (; l < r && !que[l].contain(que[r] & que[r - 1]); r--);
        for (; l < r && !que[r].contain(que[l] & que[l + 1]); l++);
        a.assign(que.begin() + l, que.begin() + r + 1);
        return a;
    }
}
 
using namespace Geometry;
 
const int N = 305;
 
int n;
long double ans;
Point p[N], q[N], s, t;
 
struct Element {
    Line a;
    int i;
}; std::vector<Element> e;
 
bool operator <(const Element &x, const Element &y) {
    return x.a < y.a;
}
 
std::vector<Line> get(int i, int j, int o) {
    std::vector<Line> a;
    if (o == 0) {
        for (auto k : e) {
            if (k.i == -1 || (i <= k.i && k.i < j)) {
                a.push_back(k.a);
            }
        }
    } else {
        for (auto k : e) {
            if (k.i == -1 || (k.i < i || j <= k.i)) {
                a.push_back(k.a);
            }
        }
    }
    return intersection(a);
}
 
bool check(long double mid) {
    e.clear();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        e.push_back((Element) {Line(p[i], p[j]), -1});
        e.push_back((Element) {Line(p[j] + q[i] * mid, p[i] + q[i] * mid), i});
    }
    std::sort(e.begin(), e.end());
    std::vector<Line> a, b;
    for (int i = 0, j = 0; i < n && j < n; i++) {
        for (; j < n; j++) {
            if (get(i, j + 1, 0).size() <= 2) { break; }
        }
        a = get(i, j, 1);
        if (a.size() > 2) {
            b = get(i, j, 0);
            s = a[0] & a[1]; t = b[0] & b[1];
            return true;
        }
    }
    return false;
}
 
int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        p[i].x = read(); p[i].y = read();
    }
    for (int i = 0; i < n; i++) {
        q[i] = ~(p[i] >> p[(i + 1) % n]);
        q[i] = q[i] / q[i].length();
    }
    for (long double l = 0, r = 2e4, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - EPS; ans = mid;
        } else {
            l = mid + EPS;
        }
    }
    check(ans); ans += 1e-8;
    printf("%.12Lf\n", ans);
    printf("%.12Lf %.12Lf\n", s.x, s.y);
    printf("%.12Lf %.12Lf\n", t.x, t.y);
    return 0;
}