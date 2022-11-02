#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define LLD "%I64d"

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = 100;

struct point {
    
    double x, y;
    
    point() {}
    
    point(double x, double y) : x(x), y(y) {}
    
    inline void rot(double ang) {
        double nx = x * cos(ang) - y * sin(ang);
        double ny = x * sin(ang) + y * cos(ang);
        x = nx;
        y = ny;
    }
    
};

point operator - (const point& a, const point& b) {
    return point(a.x - b.x, a.y - b.y);
}

point operator * (const point& a, double b) {
    return point(a.x * b, a.y * b);
}

point operator + (const point& a, const point& b) {
    return point(a.x + b.x, a.y + b.y);
}

point p[10];

inline double vec(const point& a, const point& b) {
    return a.x * b.y - b.x * a.y;
}

inline double scal(const point& a, const point& b) {
    return a.x * b.x + a.y * b.y;
}

inline double sqr(double x) {
    return x * x;
}

inline double len2(const point& a, const point& b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

inline bool check(const point& o, const point& a, const point& b, double ang) {
    point v = a - o;
    v.rot(ang);
    v = o + v;
    return fabs(v.x - b.x) < eps && fabs(v.y - b.y) < eps;
}

struct line {
    
    double a, b, c;
    
    line(const point& A, const point& B) {
        point C = (A + B) * 0.5;
        a = B.x - A.x;
        b = B.y - A.y;
        c = -a * C.x - b * C.y;
    }
    
};

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    double s = vec(p[1] - p[0], p[2] - p[0]);
    if (s < 0) {
        swap(p[1], p[2]);
    }
    line l1(p[0], p[1]);
    line l2(p[1], p[2]);
    double d = l1.a * l2.b - l2.a * l1.b;
    point o((l1.b * l2.c - l2.b * l1.c) / d, (l2.a * l1.c - l1.a * l2.c) / d);
    double ans = 1e100;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            for (int z = 1; z < N; ++z) {
                if (i + j + z > N) {
                    continue;
                }
                double ang = 2 * pi / (i + j + z);
                if (check(o, p[0], p[1], ang * i) && check(o, p[1], p[2], ang * j) && check(o, p[2], p[0], ang * z)) {
                    ans = min(ans, fabs(len2(o, p[0]) * sin(ang)) / 2 * (i + j + z));
                }
            }
        }
    }
    printf("%.18f\n", ans);
    return 0;
}