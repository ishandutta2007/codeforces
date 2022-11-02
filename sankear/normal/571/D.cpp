#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define pbk pop_back
#define prev _prev
#define rank _rank
#define next _next
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define left _left
#define right _right
#define hash _hash

typedef long long ll;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const double inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e6) + 100;

const int MERGE_UNIVER = 1;
const int MERGE_VOEN = 2;
const int ADD_UNIVER = 3;
const int DEL_VOEN = 4;
const int CNT = 5;

struct query {
    
    int t, a, b;
    
    query() {}
    
    query(int t, int a, int b) : t(t), a(a), b(b) {}
    
    query(int t, int a) : t(t), a(a), b(-1) {}
    
};

int eptr;
query q[N];
int u[N], v[N];
bool del[2 * N];
int l1[2 * N], sz[2 * N], r1[2 * N], l2[2 * N], r2[2 * N];
vi g1[2 * N], g2[2 * N];
ll add[5 * N];
int max_time[5 * N];
vector<pii> qr[N];
ll ans[N];

void dfs(vi* g, int* l, int* r, int v) {
    l[v] = eptr++;
    for (int i = 0; i < sz(g[v]); ++i) {
        dfs(g, l, r, g[v][i]);
    }
    r[v] = eptr - 1;
}

void update_time(int v, int gl, int gr, int l, int r, int t) {
    if (gl > r || gr < l) {
        return;
    }
    if (gl >= l && gr <= r) {
        max_time[v] = t;
        return;
    }
    int mid = (gl + gr) / 2;
    update_time(v * 2, gl, mid, l, r, t);
    update_time(v * 2 + 1, mid + 1, gr, l, r, t);
}

inline int get_time(int v, int gl, int gr, int pos) {
    int res = -1;
    for (;;) {
        res = max(res, max_time[v]);
        if (gl == gr) {
            break;
        }
        int mid = (gl + gr) / 2;
        if (pos <= mid) {
            v *= 2;
            gr = mid;
        } else {
            v = v * 2 + 1;
            gl = mid + 1;
        }
    }
    return res;
}

inline void add_val(int v, int gl, int gr, int l, int r, ll val) {
    if (gl > r || gr < l) {
        return;
    }
    if (gl >= l && gr <= r) {
        add[v] += val;
        return;
    }
    int mid = (gl + gr) / 2;
    add_val(v * 2, gl, mid, l, r, val);
    add_val(v * 2 + 1, mid + 1, gr, l, r, val);
}

inline ll get_add(int v, int gl, int gr, int pos) {
    ll res = 0;
    for (;;) {
        res += add[v];
        if (gl == gr) {
            break;
        }
        int mid = (gl + gr) / 2;
        if (pos <= mid) {
            v *= 2;
            gr = mid;
        } else {
            v = v * 2 + 1;
            gl = mid + 1;
        }
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'U') {
            int a, b;
            scanf("%d %d", &a, &b);
            --a;
            --b;
            q[i] = query(MERGE_UNIVER, a, b);
            continue;
        }
        if (ch == 'M') {
            int a, b;
            scanf("%d %d", &a, &b);
            --a;
            --b;
            q[i] = query(MERGE_VOEN, a, b);
            continue;
        }
        if (ch == 'A') {
            int a;
            scanf("%d", &a);
            --a;
            q[i] = query(ADD_UNIVER, a);
            continue;
        }
        if (ch == 'Z') {
            int a;
            scanf("%d", &a);
            --a;
            q[i] = query(DEL_VOEN, a);
            continue;
        }
        if (ch == 'Q') {
            int a;
            scanf("%d", &a);
            --a;
            q[i] = query(CNT, a);
            continue;
        }
        assert(false);
    }
    for (int i = 0; i < n; ++i) {
        u[i] = v[i] = i;
    }
    int ptr = n;
    for (int i = 0; i < m; ++i) {
        if (q[i].t == MERGE_UNIVER) {
            del[u[q[i].a]] = del[u[q[i].b]] = true;
            g1[ptr].pb(u[q[i].a]);
            g1[ptr].pb(u[q[i].b]);
            u[q[i].a] = ptr++;
        }
    }
    for (int i = 0; i < ptr; ++i) {
        if (!del[i]) {
            g1[ptr].pb(i);
        }
        del[i] = false;
    }
    eptr = 0;
    dfs(g1, l1, r1, ptr);
    ptr = n;
    for (int i = 0; i < m; ++i) {
        if (q[i].t == MERGE_VOEN) {
            del[v[q[i].a]] = del[v[q[i].b]] = true;
            g2[ptr].pb(v[q[i].a]);
            g2[ptr].pb(v[q[i].b]);
            v[q[i].a] = ptr++;
        }
    }
    for (int i = 0; i < ptr; ++i) {
        if (!del[i]) {
            g2[ptr].pb(i);
        }
    }
    eptr = 0;
    dfs(g2, l2, r2, ptr);
    int maxv = 1;
    while (maxv < n + m) {
        maxv *= 2;
    }
    for (int i = 1; i < 2 * maxv; ++i) {
        max_time[i] = -1;
    }
    ptr = n;
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (q[i].t == MERGE_VOEN) {
            v[q[i].a] = ptr++;
        }
        if (q[i].t == DEL_VOEN) {
            update_time(1, 0, maxv - 1, l2[v[q[i].a]], r2[v[q[i].a]], i);
        }
        if (q[i].t == CNT) {
            int t = get_time(1, 0, maxv - 1, l2[q[i].a]);
            if (t >= 0) {
                qr[t].pb(mp(i, -1));
            }
            qr[i].pb(mp(i, 1));
        }
    }
    ptr = n;
    for (int i = 0; i < n; ++i) {
        u[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        if (q[i].t == MERGE_UNIVER) {
            sz[ptr] = sz[u[q[i].a]] + sz[u[q[i].b]];
            u[q[i].a] = ptr++;
        }
        if (q[i].t == ADD_UNIVER) {
            add_val(1, 0, maxv - 1, l1[u[q[i].a]], r1[u[q[i].a]], sz[u[q[i].a]]);
        }
        for (int j = 0; j < sz(qr[i]); ++j) {
            ans[qr[i][j].fs] += qr[i][j].sc * get_add(1, 0, maxv - 1, l1[q[qr[i][j].fs].a]);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (q[i].t == CNT) {
            printf(LLD "\n", ans[i]);
        }
    }
    return 0;
}