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
const int N = int(1e5) + 100;
const int Q = 5050;

struct seg {
    
    int l, r, num;
    double prob;
    
};

bool operator < (const seg &a, const seg &b) {
    return mp(a.r - a.l, a.num) > mp(b.r - b.l, b.num);
}

int maxv, q;
int a[N];
int rmq[4 * N];
seg s[Q];
vi g[Q];
int val[Q];
double p[Q][Q], lp[Q][Q];
double d[Q][2], nd[Q][2];

inline int get_max(int l, int r) {
    int res = -inf;
    l += maxv;
    r += maxv;
    while (l <= r) {
        res = max(res, rmq[l]);
        l = (l + 1) / 2;
        res = max(res, rmq[r]);
        r = (r - 1) / 2;
    }
    return res;
}

inline bool inside(seg &a, seg &b) {
    return a.l <= b.l && b.r <= a.r;
}

void dfs(int v) {
    for (int i = 0; i < sz(g[v]); ++i) {
        dfs(g[v][i]);
    }
    for (int i = 0; i < q; ++i) {
        d[i][0] = (i == 0 ? 0 : 1);
        d[i][1] = (i == 0 ? 1 : 0);
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        assert(val[v] >= val[u]);
        for (int j = 0; j < q; ++j) {
            nd[j][0] = nd[j][1] = 0;
        }
        for (int j = 0; j < q; ++j) {
            // 0
            int can = min(val[v] - val[u] + j, q) - 1;
            if (can >= 0) {
                nd[j][0] += d[j][0] * lp[u][can];
                nd[j][1] += d[j][1] * lp[u][can];
            }
            // 1
            int need = val[v] - val[u] + j;
            if (need < q) {
                nd[j][1] += (d[j][0] + d[j][1]) * p[u][need];
            }
        }
        for (int j = 0; j < q; ++j) {
            d[j][0] = nd[j][0];
            d[j][1] = nd[j][1];
        }
    }
    for (int i = 0; i < q; ++i) {
        p[v][i] = d[i][1] * (1 - s[v].prob);
        if (i > 0) {
            p[v][i] += d[i - 1][1] * s[v].prob;
        }
        lp[v][i] = (i > 0 ? lp[v][i - 1] : 0) + p[v][i];
    }
}

int main() {
    cerr << "size = " << (sizeof(p) + sizeof(lp)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    ++q;
    s[0].l = -1;
    s[0].r = n;
    s[0].num = 0;
    s[0].prob = 0;
    for (int i = 1; i < q; ++i) {
        scanf("%d %d %lf", &s[i].l, &s[i].r, &s[i].prob);
        --s[i].l;
        --s[i].r;
        s[i].num = i;
    }
    sort(s, s + q);
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < n; ++i) {
        rmq[i + maxv] = a[i];
    }
    for (int i = n; i < maxv; ++i) {
        rmq[i + maxv] = -inf;
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
    }
    for (int i = 0; i < q; ++i) {
        val[i] = get_max(max(s[i].l, 0), min(s[i].r, n - 1));
    }
    for (int i = 1; i < q; ++i) {
        int best = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (inside(s[j], s[i])) {
                best = j;
                break;
            }
        }
        assert(best != -1);
        g[best].pb(i);
    }
    dfs(0);
    double ans = 0;
    for (int i = 0; i < q; ++i) {
        ans += (val[0] + i) * p[0][i];
    }
    printf("%.18lf\n", ans);
    return 0;
}