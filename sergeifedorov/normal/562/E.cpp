#ifdef blabla
#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i ++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()
#define sqr(a) ((a)*(a))

typedef long long li;

struct Point {
    li x, y;
    Point() { x = y = 0; }
    Point(li _x, li _y) : x(_x), y(_y) {}
};

bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator == (const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}

Point operator - (const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

li Cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

bool cw(Point a, Point b, Point c) {
    return Cross(b - a, c - a) <= 0;
}

vector<Point> Convex(vector<Point> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<Point> up;
    up.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
        while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
            up.pop_back();
        up.push_back(a[i]);
    }

#ifdef blabla
    forn(i, up.size()) {
        cerr << up[i].x << " " << up[i].y << endl;
    }
    cerr << endl;
#endif

    return up;
}

void Max() {
    puts("Max");
    exit(0);
}

void Min() {
    puts("Min");
    exit(0);
}

int main() {
#ifdef blabla
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif

    int n, m, xx, yy;
    scanf("%d%d%d%d", &n, &m, &xx, &yy);
    vector<Point> a(n), b(m);

    li xa = 0, xb = 0, ya = 0, yb = 0;
    forn(i, n) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        xa = max(xa, a[i].x);
        ya = max(ya, a[i].y);
    }
    forn(i, m) {
        scanf("%lld%lld", &b[i].x, &b[i].y);
        xb = max(xb, b[i].x);
        yb = max(yb, b[i].y);
    }

    if (xa >= xb || ya >= yb) {
        Max();
    }

    b.push_back(Point(0, yb));
    b.push_back(Point(xb, 0));
    set<Point> s(a.begin(), a.end());

    vector<Point> h1 = Convex(b);
    a.insert(a.end(), b.begin(), b.end());

    vector<Point> h2 = Convex(a);

    if (h1 == h2) {
        forn(i, h1.size()) {
            if (s.count(h1[i])) {
                Max();              
            }
        }
        Min();
    }

    Max();
    return 0;
}