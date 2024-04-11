#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;
const int KK = 55;

struct point {
    
    double x, y;
    
    point() {}
    
    point(double x, double y) : x(x), y(y) {}
    
};

inline point operator - (const point& a, const point& b) {
    return point(a.x - b.x, a.y - b.y);
}

int sz, ptr;
double A[N], B[N], C[N];
double dp[KK][N];
double t[N];
point st[N];

inline double vec(const point& a, const point& b) {
    return a.x * b.y - b.x * a.y;
}

inline bool bad(const point& a, const point& b, const point& c) {
    point v1 = b - a, v2 = c - b;
    return vec(v1, v2) <= 0;
}

inline void add(const point& p) {
    while (sz >= 2 && bad(st[sz - 2], st[sz - 1], p)) {
        --sz;
    }
    if (sz == 0) {
        ptr = 0;
    } else {
        ptr = min(ptr, sz - 1);
    }
    st[sz++] = p;
}

inline double calc(const point& p, double C) {
    return p.y - p.x * C;
}

int main() {
    cerr << sizeof(dp) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, K;
    cin >> n >> K;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", t + i);
        t[i] = 1.0 / t[i];
    }
    for (int i = 1; i <= n; ++i) {
        A[i] = A[i - 1] + 1.0 / t[i];
        B[i] = B[i - 1] + t[i] * A[i];
        C[i] = C[i - 1] + t[i];
    }
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            dp[k][i] = 1e100;
        }
    }
    dp[0][0] = 0;
    for (int k = 1; k <= K; ++k) {
        sz = 0, ptr = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp[k - 1][i - 1] < 1e50) {
                add(point(A[i - 1], dp[k - 1][i - 1] - B[i - 1] + A[i - 1] * C[i - 1]));
            }
            if (i < k) {
                dp[k][i] = 1e100;
            } else {
                assert(sz > 0);
                while (ptr + 1 < sz && calc(st[ptr + 1], C[i]) < calc(st[ptr], C[i])) {
                    ++ptr;
                }
                dp[k][i] = calc(st[ptr], C[i]) + B[i];
            }
        }
    }
    printf("%.18lf\n", dp[K][n]);
    return 0;
}