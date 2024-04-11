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
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int ITERS = 500;

#define y1 yy1

double x1, y1, x2, y2;
double vmax, wx, wy, vx, vy, t;

inline double f(double x1, double y1) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    double a = vmax * vmax - wx * wx - wy * wy;
    double b = 2 * dx * wx + 2 * dy * wy;
    double c = -dx * dx - dy * dy;
    
    // a * t * t + b * t + c >= 0
    
    double d = b * b - 4 * a * c;
    
    assert(d > -eps);
    
    return t + (-b + sqrt(d)) / (2 * a);
}

inline double f2(double x) {
    double d = sqrt(vmax * vmax * t * t - x * x);
    double ans = 1e100, l = -d, r = d;
    for (int i = 0; i < ITERS; ++i) {
        double m1 = (2 * l + r) / 3;
        double f1 = f(x1 + x, y1 + m1);
        double m2 = (l + 2 * r) / 3;
        double f2 = f(x1 + x, y1 + m2);
        ans = min(ans, min(f1, f2));
        if (f1 < f2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return ans;
}

inline double f1() {
    double ans = 1e100, l = -vmax * t, r = vmax * t;
    for (int i = 0; i < ITERS; ++i) {
        double m1 = (2 * l + r) / 3;
        double f1 = f2(m1);
        double m2 = (l + 2 * r) / 3;
        double ff2 = f2(m2);
        ans = min(ans, min(f1, ff2));
        if (f1 < ff2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy >> wx >> wy;

    double dx = x2 - x1;
    double dy = y2 - y1;
    
    double a = vmax * vmax - vx * vx - vy * vy;
    double b = 2 * dx * vx + 2 * dy * vy;
    double c = -dx * dx - dy * dy;
    
    // a * t * t + b * t + c >= 0
    
    double d = b * b - 4 * a * c;
    
    assert(d > -eps);
    
    double need = (-b + sqrt(d)) / (2 * a);
    
    if (need < t + eps) {
        printf("%.18lf\n", need);
        return 0;
    }
    
    x1 += t * vx;
    y1 += t * vy;
    
    double ans = f1();
    
    printf("%.18lf\n", ans);
    
    return 0;
}