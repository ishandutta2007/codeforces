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

const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;
const int LOG = 17;

struct val {
    
    ll min_w;
    int min_c, min_num;
    
};

inline bool operator == (const val& a, const val& b) {
    return a.min_w == b.min_w && a.min_c == b.min_c && a.min_num == b.min_num;
}

struct tr {

    ll add;
    val val;
    
};

int maxv, ptr = 0;
bool used[N];
int p[LOG][N];
int sz[N], h[N], prev[N], l[N], r[N], r2[N], pos[N];
vi g[N], lst[N];
tr rmq[4 * N];
bool del_seg[N];
val seg_val[N];
vector<pii> segs;
vi res;

void dfs1(int v) {
    used[v] = true;
    sz[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            p[0][u] = v;
            h[u] = h[v] + 1;
            dfs1(u);
            sz[v] += sz[u];
        }
    }
}

void dfs2(int v, int pv) {
    prev[v] = pv;
    l[v] = ptr;
    for (int num : lst[v]) {
        pos[num] = ptr;
        rmq[ptr + maxv].val.min_w = num;
        rmq[ptr + maxv].val.min_c = v;
        rmq[ptr + maxv].val.min_num = num;
        ++ptr;
    }
    r[v] = ptr - 1;
    int best = -1;
    for (int u : g[v]) {
        if (p[0][u] == v && (best == -1 || sz[u] > sz[best])) {
            best = u;
        }
    }
    if (best != -1) {
        dfs2(best, pv);
    }
    for (int u : g[v]) {
        if (p[0][u] == v && u != best) {
            dfs2(u, u);
        }
    }
    r2[v] = ptr - 1;
}

inline void push(int v) {
    if (rmq[v].add == 0) {
        return;
    }
    rmq[v].val.min_w += rmq[v].add;
    if (v < maxv) {
        rmq[v * 2].add += rmq[v].add;
        rmq[v * 2 + 1].add += rmq[v].add;
    }
    rmq[v].add = 0;
}

inline val merge(const val& a, const val& b) {
    if (b.min_w < a.min_w || (b.min_w == a.min_w && b.min_c < a.min_c)) {
        return b;
    }
    return a;
}

inline void calc(int v) {
    rmq[v].val = merge(rmq[v * 2].val, rmq[v * 2 + 1].val);
}

void add(int v, int gl, int gr, int l, int r, int val) {
    push(v);
    if (gl > r || gr < l || l > r) {
        return;
    }
    if (gl >= l && gr <= r) {
        rmq[v].add += val;
        push(v);
        return;
    }
    int mid = (gl + gr) / 2;
    add(v * 2, gl, mid, l, r, val);
    add(v * 2 + 1, mid + 1, gr, l, r, val);
    calc(v);
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

void go(int v, int u, bool fl) {
    while (prev[v] != prev[u]) {
        segs.pb(mp(l[prev[v]], r[v]));
        v = p[0][prev[v]];
    }
    if (fl) {
        segs.pb(mp(l[u], r[v]));
    } else {
        segs.pb(mp(r[u] + 1, r[v]));
    }
}

inline val get(int v, int gl, int gr, int l, int r) {
    push(v);
    if (gl > r || gr < l || l > r) {
        val res;
        res.min_w = inf;
        res.min_c = -1;
        res.min_num = -1;
        return res;
    }
    if (gl >= l && gr <= r) {
        return rmq[v].val;
    }
    int mid = (gl + gr) / 2;
    return merge(get(v * 2, gl, mid, l, r), get(v * 2 + 1, mid + 1, gr, l, r));
}

void set_inf(int v, int gl, int gr, int pos) {
    push(v);
    if (gl > pos || gr < pos) {
        return;
    }
    if (v >= maxv) {
        rmq[v].val.min_w = inf;
        rmq[v].val.min_c = -1;
        rmq[v].val.min_num = -1;
        return;
    }
    int mid = (gl + gr) / 2;
    set_inf(v * 2, gl, mid, pos);
    set_inf(v * 2 + 1, mid + 1, gr, pos);
    calc(v);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < m; ++i) {
        int cur;
        scanf("%d", &cur);
        --cur;
        lst[cur].pb(i + 1);
    }
    p[0][0] = -1;
    dfs1(0);
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
    while (maxv < m) {
        maxv *= 2;
    }
    for (int i = 0; i < maxv; ++i) {
        rmq[i + maxv].val.min_w = inf;
        rmq[i + maxv].val.min_c = -1;
        rmq[i + maxv].val.min_num = -1;
    }
    dfs2(0, 0);
    assert(ptr == m);
    /*cerr << "g" << endl;
    for (int i = 0; i < n; ++i) {
        cerr << l[i] << " " << r[i] << " " << r2[i] << endl;
    }
    cerr << "pos" << endl;
    for (int i = 1; i <= m; ++i) {
        cerr << pos[i] << endl;
    }*/
    for (int i = maxv - 1; i > 0; --i) {
        calc(i);
    }
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int v, u, k;
            scanf("%d %d %d", &v, &u, &k);
            --v;
            --u;
            int w = get_lca(v, u);
            segs.clear();
            go(v, w, true);
            go(u, w, false);
            for (int j = 0; j < sz(segs); ++j) {
                del_seg[j] = false;
                seg_val[j] = get(1, 0, maxv - 1, segs[j].fs, segs[j].sc);
                if (seg_val[j].min_w > inf / 2) {
                    del_seg[j] = true;
                }
            }
            res.clear();
            while (k > 0) {
                val cur;
                cur.min_w = inf;
                cur.min_c = -1;
                cur.min_num = -1;
                int best_seg = -1;
                for (int j = 0; j < sz(segs); ++j) {
                    if (del_seg[j]) {
                        continue;
                    }
                    cur = merge(cur, seg_val[j]);
                    if (cur == seg_val[j]) {
                        best_seg = j;
                    }
                }
                if (best_seg == -1) {
                    break;
                }
                --k;
                res.pb(cur.min_num);
                //cerr << "rem " << cur.min_num << " " << pos[cur.min_num] << endl;
                set_inf(1, 0, maxv - 1, pos[cur.min_num]);
                seg_val[best_seg] = get(1, 0, maxv - 1, segs[best_seg].fs, segs[best_seg].sc);
                if (seg_val[best_seg].min_w > inf / 2) {
                    del_seg[best_seg] = true;
                }
            }
            printf("%d", sz(res));
            for (int num : res) {
                printf(" %d", num);
            }
            puts("");
        } else {
            assert(t == 2);
            int v, k;
            scanf("%d %d", &v, &k);
            --v;
            add(1, 0, maxv - 1, l[v], r2[v], k);
        }
    }
    return 0;
}