#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <sstream>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = 1010;

struct point {
    double x, y;
};

inline double sqr(double x) {
    return x * x;
}

struct line {
    double a, b, c;
    
    line(const point& A, const point& B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = -a * A.x - b * A.y;
        
        double d = sqrt(sqr(a) + sqr(b));
        a /= d;
        b /= d;
        c /= d;
    }
};

point p[N];

inline double dist(const point& a, const point& b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline double dist(const line& l, const point& p) {
    return fabs(l.a * p.x + l.b * p.y + l.c);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    double ans = 1e100;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = min(ans, dist(p[i], p[j]) / 2);
        }
    }
    for (int i = 0; i < n; ++i) {
        int pi = i - 1;
        if (pi < 0) {
            pi = n - 1;
        }
        int ni = i + 1;
        if (ni >= n) {
            ni = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (i == j || pi == j || ni == j) {
                continue;
            }
            int pj = j - 1;
            if (pj < 0) {
                pj = n - 1;
            }
            int nj = j + 1;
            if (nj >= n) {
                nj = 0;
            }
            if (pj == i || nj == i) {
                continue;
            }
            line l(p[i], p[j]);
            ans = min(ans, dist(l, p[pi]) / 2);
            ans = min(ans, dist(l, p[ni]) / 2);
            ans = min(ans, dist(l, p[nj]) / 2);
            ans = min(ans, dist(l, p[pj]) / 2);
        }
    }
    printf("%.18lf\n", ans);
    return 0;
}