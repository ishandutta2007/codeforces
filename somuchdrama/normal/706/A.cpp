#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::tuple;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;
using std::swap;
using std::make_tuple;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;

const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433;

struct point
{
    double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
};

bool btw(double o, double d1, double d2) {
    return (d1 + EPS < o && o + EPS < d2) || (d2 + EPS < o && o + EPS < d1);
}

bool btw(point o, point p1, point p2) {
    return btw(o.x, p1.x, p2.x) && btw(o.y, p1.y, p2.y);
}

double dist(point a, point b) {
    return sqrt(sqr(b.x - a.x) + sqr(b.y - a.y));
}

double sqdist(point a, point b) {
    return sqr(b.x - a.x) + sqr(b.y - a.y);
}

std::istream & operator >>(std::istream & is, point & p) {
    return is >> p.x >> p.y;
}

std::ostream & operator <<(std::ostream & os, point & p) {
    return os << p.x << ' ' << p.y;
}

struct vc
{
    double x, y;
    vc() {}
    vc(double _x, double _y): x(_x), y(_y) {}
    vc(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    double length() {
        return sqrt(sqr(x) + sqr(y));
    }
    double sqlength() {
        return sqr(x) + sqr(y);
    }
};

point operator +(point a, vc v) {
    return point(a.x + v.x, a.y + v.y);
}

double operator *(vc a, vc b) {
    return a.x * b.x + a.y * b.y;
}

double operator %(vc a, vc b) {
    return a.x * b.y - a.y * b.x;
}

vc operator *(vc v, double x) {
    return vc(v.x * x, v.y * x);
}

vc turn_clockwise(vc a) {
    return vc(a.y, -a.x);
}

vc turn_anticlockwise(vc a) {
    return vc(-a.y, a.x);
}

struct line
{
    double a, b, c;
    line() {}
    line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {
        normalize();
    }
    line(point one, point two) {
        a = one.y - two.y;
        b = two.x - one.x;
        c = -(a * one.x + b * one.y);
        normalize();
    }
    line(vc norm, point cont) {
        a = norm.x;
        b = norm.y;
        c = -(a * cont.x + b * cont.y);
        normalize();
    }
    void normalize() {
        double div = sqrt(sqr(a) + sqr(b));
        a /= div;
        b /= div;
        c /= div;
    }
};

struct circle{
    point center;
    double radius;
    circle() {}
    circle(point _center, double _radius) : center(_center), radius(_radius) {}
    circle(point _center, vc _v) : center(_center) {
        radius = _v.length();
    }
};
point o;
double get(point p, double v) {
    return dist(p, o) / v;
}
int main() {

    int n;
    cin >> o >> n;
    vector<point> a(n);
    vector<double> v(n);
    double ans = 1e18;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> v[i];
        ans = min(ans, get(a[i], v[i]));
    }

    cout << ans << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}