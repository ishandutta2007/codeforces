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
#include <stack>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define end _end

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int ITERS = int(1e5);

inline double min(double a, double b, double c, double d) {
    return min(min(a, b), min(c, d));
}

inline double max(double a, double b, double c, double d) {
    return max(max(a, b), max(c, d));
}

inline pair<double, double> get_seg(double a, double b, double t) {
    double l = min((a - t) * (b - t), (a - t) * (b + t), (a + t) * (b - t), (a + t) * (b + t));
    double r = max((a - t) * (b - t), (a - t) * (b + t), (a + t) * (b - t), (a + t) * (b + t));
    return mp(l, r);
}

inline double inter(pair<double, double> a, pair<double, double> b) {
    return max(a.fs, b.fs) < min(a.sc, b.sc);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double l = 0, r = inf;
    for (int i = 0; i < ITERS; ++i) {
        double t = (l + r) / 2;
        pair<double, double> seg1 = get_seg(a, d, t);
        pair<double, double> seg2 = get_seg(b, c, t);
        if (inter(seg1, seg2)) {
            r = t;
        } else {
            l = t;
        }
    }
    printf("%.18lf\n", (l + r) / 2);
    return 0;
}