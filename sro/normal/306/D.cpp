#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double pi = acos(-1), eps = 1e-2;

mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());
double inline randf(int l, int r) { return uniform_real_distribution<double>(l, r)(Rand); }

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
    Point operator + (const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator * (const double &p) const { return Point(x * p, y * p); }
    double inline operator * (const Point &p) const { return x * p.y - y * p.x; }
    double length() { return sqrt(x * x + y * y); }
} p[105];

double dist(Point a, Point b, Point x) {
    return fabs((a - x) * (b - x)) / (b - a).length();
}

Point inline inter(Point aa, Point ab, Point ba, Point bb) {
    Point p1 = aa, v1 = ab - aa;
    Point p2 = ba, v2 = bb - ba;
    return p1 + v1 * (((p2 - p1) * v2) / (v1 * v2));
}

int n;
Point v[105];
double val[105];

bool check() {
    loop(i, n) loop(j, i) if (fabs(val[j] - val[i]) < 1e-2) return 0;
    return 1;
}

int main() {
    scanf("%d", &n);
    if (n <= 4) return puts("No solution"), 0;
    double th = pi * 2 / n;
    loop(i, n) v[i] = Point(cos(th * i), sin(th * i));
    while (1) {
        Point sm;
        circ(i, 2, n - 1) val[i] = randf(-11.451, 11.451) + 114.514, sm = sm + v[i] * val[i];
        if (fabs(v[1].y) < eps) continue;
        val[1] = -sm.y / v[1].y; if (val[1] < 2.33) continue;
        sm = sm + v[1] * val[1];
        val[0] = -sm.x; if (val[0] < 2.33) continue;
        sm = sm + v[0] * val[0];
        if (!check()) continue;
        sm = Point(0, 0);
        loop(i, n) {
            printf("%.3lf %.3lf\n", sm.x, sm.y);
            sm = sm + v[i] * val[i];
        }
        break;
    }
    return 0;
}