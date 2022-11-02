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
const int MOD = int(1e9) + 7;

struct tr {
    
    int l, r, sum, sum2, add;
    
};

int n, maxv, ptr;
int l[N], r[N], h[N], ans[N];
vector<pii> g[N], q[N];
tr rmq[4 * N];

inline void norm(int &a) {
    while (a >= MOD) {
        a -= MOD;
    }
}

void dfs(int v, int pv) {
    if (pv != -1) {
        for (int i = 0; i < sz(g[v]); ++i) {
            if (g[v][i].fs == pv) {
                g[v].erase(g[v].begin() + i);
                break;
            }
        }
    }
    l[v] = ptr++;
    for (int i = 0; i < sz(g[v]); ++i) {
        h[g[v][i].fs] = h[v] + g[v][i].sc;
        norm(h[g[v][i].fs]);
        dfs(g[v][i].fs, v);
    }
    r[v] = ptr - 1;
}

inline void push(int v) {
    if (rmq[v].add == 0) {
        return;
    }
    rmq[v].sum2 = (rmq[v].sum2 + 2LL * rmq[v].add * rmq[v].sum) % MOD;
    int add = (1LL * rmq[v].add * rmq[v].add) % MOD;
    add = (1LL * add * (rmq[v].r - rmq[v].l + 1)) % MOD;
    rmq[v].sum2 += add;
    norm(rmq[v].sum2);
    rmq[v].sum = (rmq[v].sum + 1LL * (rmq[v].r - rmq[v].l + 1) * rmq[v].add) % MOD;
    if (v < maxv) {
        rmq[v * 2].add += rmq[v].add;
        norm(rmq[v * 2].add);
        rmq[v * 2 + 1].add += rmq[v].add;
        norm(rmq[v * 2 + 1].add);
    }
    rmq[v].add = 0;
}

inline void calc(int v) {
    rmq[v].sum2 = rmq[v * 2].sum2 + rmq[v * 2 + 1].sum2;
    norm(rmq[v].sum2);
    rmq[v].sum = rmq[v * 2].sum + rmq[v * 2 + 1].sum;
    norm(rmq[v].sum);
}

void update(int v, int l, int r, int val) {
    push(v);
    if (rmq[v].l > r || rmq[v].r < l || l > r) {
        return;
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        rmq[v].add += val;
        norm(rmq[v].add);
        push(v);
        return;
    }
    update(v * 2, l, r, val);
    update(v * 2 + 1, l, r, val);
    calc(v);
}

inline int get_sum2(int v, int l, int r) {
    push(v);
    if (rmq[v].l > r || rmq[v].r < l || l > r) {
        return 0;
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        return rmq[v].sum2;
    }
    int res = get_sum2(v * 2, l, r) + get_sum2(v * 2 + 1, l, r);
    norm(res);
    return res;
}

void solve(int v) {
    for (int i = 0; i < sz(q[v]); ++i) {
        int sum2 = get_sum2(1, l[q[v][i].fs], r[q[v][i].fs]);
        int all = get_sum2(1, 0, n - 1);
        sum2 *= 2;
        norm(sum2);
        ans[q[v][i].sc] = sum2 - all;
        if (ans[q[v][i].sc] < 0) {
            ans[q[v][i].sc] += MOD;
        }
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        int gl = l[g[v][i].fs], gr = r[g[v][i].fs], val = g[v][i].sc, neg = MOD - val;
        norm(neg);
        update(1, 0, gl - 1, val);
        update(1, gr + 1, n - 1, val);
        update(1, gl, gr, neg);
        solve(g[v][i].fs);
        update(1, gl, gr, val);
        update(1, gr + 1, n - 1, neg);
        update(1, 0, gl - 1, neg);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a;
        --b;
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }
    ptr = 0;
    h[0] = 0;
    dfs(0, -1);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        q[u].pb(mp(v, i));
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < maxv; ++i) {
        rmq[i + maxv].l = rmq[i + maxv].r = i;
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i].l = rmq[i * 2].l;
        rmq[i].r = rmq[i * 2 + 1].r;
    }
    for (int i = 0; i < n; ++i) {
        int pos = l[i] + maxv;
        rmq[pos].sum = h[i];
        rmq[pos].sum2 = (1LL * h[i] * h[i]) % MOD;
        rmq[pos].add = 0;
    }
    for (int i = n; i < maxv; ++i) {
        rmq[i + maxv].sum = rmq[i + maxv].sum2 = rmq[i + maxv].add = 0;
    }
    for (int i = maxv - 1; i > 0; --i) {
        calc(i);
    }
    solve(0);
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}