#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
 
namespace Geometry {
    struct Point {
        int x, y;
    };
 
    bool operator <(const Point &u, const Point &v) {
        return u.x == v.x ? u.y < v.y : u.x < v.x;
    }
    Point operator >>(const Point &u, const Point &v) {
        return {v.x - u.x, v.y - u.y};
    }
    long long operator *(const Point &u, const Point &v) {
        return 1ll * u.x * v.x + 1ll * u.y * v.y;
    }
    long long operator ^(const Point &u, const Point &v) {
        return 1ll * u.x * v.y - 1ll * u.y * v.x;
    }
}

using namespace Geometry;

const int N = 1e5;

int n, x, y, r, ans;
long double max;
std::vector<Point> p;

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
    return u;
}

void insert(Point u) {
    if (u.x < 0 || u.x > N) { return; }
    if (u.y < 0 || u.y > N) { return; }
    if (std::abs(u.x - x) + std::abs(u.y - y) > r) { return; }
    p.push_back(u);
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        x = read(), y = read(), r = read();
        insert((Point) {x - r, y}); insert((Point) {x + r, y});
        insert((Point) {x, y - r}); insert((Point) {x, y + r});
        insert((Point) {x + r - y, 0}); insert((Point) {x - r + y, 0});
        insert((Point) {0, y + r - x}); insert((Point) {0, y - r + x});
        insert((Point) {x + r - (N - y), N}); insert((Point) {x - r + (N - y), N});
        insert((Point) {N, y + r - (N - x)}); insert((Point) {N, y - r + (N - x)});
        insert((Point) {0, 0}); insert((Point) {N, N});
        insert((Point) {0, N}); insert((Point) {N, 0});
    }
    p = findHull(p);
    for (int i = 0, j, k; i < p.size(); i++) {
        j = (i + 1) % p.size(); k = (j + 1) % p.size();
        long double res = 1;
        res *= std::sqrt((p[i] >> p[j]) * (p[i] >> p[j]));
        res *= std::sqrt((p[j] >> p[k]) * (p[j] >> p[k]));
        res *= std::sqrt((p[i] >> p[k]) * (p[i] >> p[k]));
        res /= (p[i] >> p[j]) ^ (p[j] >> p[k]);
        res = std::abs(res);
        if (max < res) {
            max = res; ans = i;
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%d %d\n", p[ans].x, p[ans].y);
        ans = (ans + 1) % p.size();
    }
    return 0;
}