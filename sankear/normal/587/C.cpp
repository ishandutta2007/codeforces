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
#include <unordered_map>

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
const int N = int(1e5) + 100;
const int LOG = 17;
const int K = 10;

struct tans {
    
    int sz;
    int val[K];
    
};

int ptr = 0, maxv;
int prev[N], num[N], h[N], sz[N];
int p[LOG][N];
int tmp[2 * K];
tans res;
tans pref[N];
tans rmq[4 * N];
vi g[N], lst[N];

inline void merge(tans& a, tans& b, tans& c) {
    merge(a.val, a.val + a.sz, b.val, b.val + b.sz, tmp);
    c.sz = min(a.sz + b.sz, K);
    memcpy(c.val, tmp, sizeof(int) * c.sz);
}

void dfs1(int v, int pv) {
    p[0][v] = pv;
    if (pv == -1) {
        h[v] = 0;
    } else {
        h[v] = h[pv] + 1;
        g[v].erase(find(all(g[v]), pv));
    }
    sz[v] = 1;
    for (int i = 0; i < sz(g[v]); ++i) {
        dfs1(g[v][i], v);
        sz[v] += sz[g[v][i]];
    }
}

void dfs2(int v, int pv) {
    prev[v] = pv;
    num[v] = ptr++;
    sort(all(lst[v]));
    rmq[num[v] + maxv].sz = pref[v].sz = min(sz(lst[v]), K);
    for (int i = 0; i < rmq[num[v] + maxv].sz; ++i) {
        rmq[num[v] + maxv].val[i] = pref[v].val[i] = lst[v][i];
    }
    if (pv != v) {
        merge(pref[p[0][v]], pref[v], pref[v]);
    }
    int best = -1;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (best == -1 || sz[g[v][i]] > sz[best]) {
            best = g[v][i];
        }
    }
    if (best != -1) {
        dfs2(best, pv);
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i] != best) {
            dfs2(g[v][i], g[v][i]);
        }
    }
}

inline int get_lca(int a, int b) {
    if (h[a] < h[b]) {
        swap(a, b);
    }
    for (int i = LOG - 1; i >= 0; --i) {
        if (p[i][a] != -1 && h[p[i][a]] >= h[b]) {
            a = p[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = LOG - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a];
            b = p[i][b];
        }
    }
    return p[0][a];
}

void go(int v, int gl, int gr, int l, int r) {
    if (gl > r || gr < l || l > r) {
        return;
    }
    if (gl >= l && gr <= r) {
        merge(res, rmq[v], res);
        return;
    }
    int mid = (gl + gr) / 2;
    go(v * 2, gl, mid, l, r);
    go(v * 2 + 1, mid + 1, gr, l, r);
}

inline void go(int v, int pv, int add) {
    while (prev[v] != prev[pv]) {
        merge(res, pref[v], res);
        v = p[0][prev[v]];
    }
    go(1, 0, maxv - 1, num[pv] + add, num[v]);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < m; ++i) {
        int cur;
        scanf("%d", &cur);
        --cur;
        lst[cur].pb(i + 1);
    }
    dfs1(0, -1);
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[i - 1][j] == -1) {
                p[i][j] = -1;
            } else {
                p[i][j] = p[i - 1][p[i - 1][j]];
            }
        }
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    dfs2(0, 0);
    for (int i = maxv - 1; i > 0; --i) {
        merge(rmq[i * 2], rmq[i * 2 + 1], rmq[i]);
    }
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a;
        --b;
        res.sz = 0;
        int ab = get_lca(a, b);
        go(a, ab, 0);
        go(b, ab, 1);
        res.sz = min(res.sz, c);
        printf("%d", res.sz);
        for (int j = 0; j < res.sz; ++j) {
            printf(" %d", res.val[j]);
        }
        puts("");
    }
    return 0;
}