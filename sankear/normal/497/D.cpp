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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 1111;

struct point {
    
    ll x, y;
    
    point() {}
    
    point(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
    
};

struct line {
    
    ll a, b, c;
    
    line(point &A, point &B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = -a * A.x - b * A.y;
    }
    
};

point operator - (const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
}

bool operator == (const point &a, const point &b) {
    return a.x == b.x && a.y == b.y;
}

int n[2];
point o[2];
point a[2][N];

inline ll sqr(ll x) {
    return x * x;
}

struct dline {
    
    double a, b, c;
    
    dline(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
};

inline double sqr(double x) {
    return x * x;
}

inline void norm(dline &l) {
    double d = sqrt(sqr(l.a) + sqr(l.b));
    l.a /= d;
    l.b /= d;
    l.c /= d;
}

inline void rot(point v, double cs, double si, double &x, double &y) {
    x = v.x * cs - v.y * si;
    y = v.x * si + v.y * cs;
}

inline bool le(double a, double b) {
    return b - a > -eps;
}

inline bool inside(double x1, double y1, double x2, double y2, double x, double y) {
    double min_x = x1, max_x = x2;
    if (min_x > max_x) {
        swap(min_x, max_x);
    }
    double min_y = y1, max_y = y2;
    if (min_y > max_y) {
        swap(min_y, max_y);
    }
    return le(min_x, x) && le(x, max_x) && le(min_y, y) && le(y, max_y);
}

inline void check(dline l1, dline l2, point p, point q, point u, point v, point w) {
    double d = l1.a * l2.b - l2.a * l1.b;
    double cs = (l1.b * l2.c - l2.b * l1.c) / d;
    double si = (l2.a * l1.c - l1.a * l2.c) / d;
    //assert(fabs(l1.a * cs + l1.b * si + l1.c) < eps);
    //assert(fabs(l2.a * cs + l2.b * si + l2.c) < eps);
    //assert(fabs(sqr(cs) + sqr(si) - 1.0) < eps);
    double x1, y1;
    rot(u, cs, si, x1, y1);
    double x2, y2;
    rot(v, cs, si, x2, y2);
    double x, y;
    rot(w, cs, si, x, y);
    if (inside(x1 + p.x, y1 + p.y, x2 + p.x, y2 + p.y, x + q.x, y + q.y)) {
        puts("YES");
        exit(0);
    }
}

inline void check(dline l, point p, point q, point u, point v, point w) {
    norm(l);
    double d = fabs(l.c);
    d = sqrt(max(1 - sqr(d), 0.0));
    dline l2(-l.b, l.a, 0);
    l2.c -= d;
    check(l, l2, p, q, u, v, w);
    l2.c += 2 * d;
    check(l, l2, p, q, u, v, w);
}

inline void solve(int num) {
    point oo = o[num ^ 1] - o[num];
    ll x0 = oo.x, y0 = oo.y;
    for (int i = 0; i < n[num]; ++i) {
        point u = a[num][i] - o[num], v = a[num][(i + 1) % n[num]] - o[num];
        line l(u, v);
        for (int j = 0; j < n[num ^ 1]; ++j) {
            point w = a[num ^ 1][j] - o[num ^ 1];
            ll A = l.a * x0 + l.b * y0;
            ll B = l.a * y0 - l.b * x0;
            ll C = l.c + l.a * w.x + l.b * w.y;
            assert(sqr(A) + sqr(B) > 0);
            if (sqr(C) <= sqr(A) + sqr(B)) {
                check(dline(A, B, C), o[num], o[num ^ 1], u, v, w);
            }
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    for (int i = 0; i < 2; ++i) {
        scanf(LLD " " LLD, &o[i].x, &o[i].y);
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; ++j) {
            scanf(LLD " " LLD, &a[i][j].x, &a[i][j].y);
        }
    }
    if (o[0] == o[1]) {
        puts("NO");
        return 0;
    }
    solve(0);
    solve(1);
    puts("NO");
    return 0;
}