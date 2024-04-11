#include <bits/stdc++.h>

#define double long double

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

namespace Geometry {
    const double eps = 1e-8L;

    struct Point {
        int x, y;
    };

    bool operator <(const Point &u, const Point &v) {
        return u.x == v.x ? u.y < v.y : u.x < v.x;
    }
    Point operator >>(const Point &u, const Point &v) {
        return {v.x - u.x, v.y - u.y};
    }
    int operator *(const Point &u, const Point &v) {
        return u.x * v.x + u.y * v.y;
    }
    int operator ^(const Point &u, const Point &v) {
        return u.x * v.y - u.y * v.x;
    }
    double angle(Point u, Point i, Point j) {
        Point ui = u >> i, uj = u >> j;
        return 1.0L * (ui * uj) / (ui ^ uj);
    }
    double angle(Point u, Point i, Point j, int &d) {
        Point ui = u >> i, uj = u >> j; d = ui ^ uj;
        return 1.0L * (ui * uj) / d;
    }
    bool contain(Point u, Point i, Point v) {
        if (u.x > v.x) { std::swap(u.x, v.x); }
        if (u.y > v.y) { std::swap(u.y, v.y); }
        return u.x <= i.x && i.x <= v.x && u.y <= i.y && i.y <= v.y;
    }
}

using namespace Geometry;

int n, m;
std::vector<Point> p, q;

std::vector<Point> findHull(std::vector<Point> p) {
    std::vector<Point> u, d;
    int n = p.size();
    std::sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        for (; u.size() > 1 && ((u[u.size() - 2] >> u.back()) ^ (u.back() >> p[i])) >= 0; u.pop_back());
        u.push_back(p[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (; d.size() > 1 && ((d[d.size() - 2] >> d.back()) ^ (d.back() >> p[i])) >= 0; d.pop_back());
        d.push_back(p[i]);
    }
    for (int i = 1; i + 1 < d.size(); i++) { u.push_back(d[i]); }
    std::reverse(u.begin(), u.end());
    return u;
}

void check(Point s, Point t) {
    double l = -1e18, r = 1e18, w;
    for (int i = 0, d; i < n; i++) {
        w = angle(p[i], s, t, d);
        if (d > 0) {
            l = std::max(l, w);
        } else if (d < 0) {
            r = std::min(r, w);
        } else if (!contain(s, p[i], t)) {
            return;
        }
        if (l + eps >= r) { return; }
    }
    for (int i = 0, d; i < m; i++) {
        w = angle(q[i], s, t, d);
        if (d < 0) {
            l = std::max(l, w);
        } else if (d > 0) {
            r = std::min(r, w);
        } else if (contain(s, q[i], t)) {
            return;
        }
        if (l + eps >= r) { return; }
    }
    printf("YES\n"); exit(0);
}

void solve(std::vector<Point> f) {
    check(f[0], f[1]);
    if (f.size() == 2) { return; }
    double max = -1e18;
    for (int i = 2; i < f.size(); i++) {
        max = std::max(max, std::abs(angle(f[i], f[0], f[1])));
    }
    for (int i = 2; i < f.size(); i++) {
        if (max < std::abs(angle(f[i], f[0], f[1])) + eps) {
            std::vector<Point> l, r;
            for (int j = 1; j <= i; j++) {
                l.push_back(f[j]);
            }
            r.push_back(f[0]);
            for (int j = i; j < f.size(); j++) {
                r.push_back(f[j]);
            }
            solve(l); solve(r);
            break;
        }
    }
}
void solve() {
    solve(findHull(p));
}

int main() {
    n = read(); m = read();
    if (n == 1 || m == 1) { printf("YES\n"); return 0; }
    p.resize(n); q.resize(m);
    for (int i = 0; i < n; i++) { p[i].x = read(); p[i].y = read(); }
    for (int i = 0; i < m; i++) { q[i].x = read(); q[i].y = read(); }
    solve(); std::swap(n, m); std::swap(p, q); solve();
    printf("NO\n");
    return 0;
}