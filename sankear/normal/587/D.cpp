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
const int N = int(1e6) + 100;

struct edge {
    
    int v, u, c, t;
    
};

int n, m, ptr;
edge e[N];
bool used[N];
int t[N], ord[N], col[N];
vector<pii> g[N];
vi dg[N], rg[N];
vi lst;

inline void fail() {
    puts("No");
    exit(0);
}

inline void add(int a, int b) {
    dg[a].pb(b);
    rg[b].pb(a);
}

void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < sz(dg[v]); ++i) {
        if (!used[dg[v][i]]) {
            dfs1(dg[v][i]);
        }
    }
    ord[ptr++] = v;
}

void dfs2(int v) {
    col[v] = ptr;
    for (int i = 0; i < sz(rg[v]); ++i) {
        if (col[rg[v][i]] == -1) {
            dfs2(rg[v][i]);
        }
    }
}

inline bool check(int t) {
    for (int i = 0; i < 2 * m; ++i) {
        dg[i].clear();
        rg[i].clear();
    }
    int sz = 2 * m;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) == 0) {
            continue;
        }
        for (int it = 0; it < 2; ++it) {
            int ver = g[i][0].sc * 2;
            for (int j = 1; j < sz(g[i]); ++j) {
                add(g[i][j].sc * 2 + 1, ver);
                int nver = sz++;
                dg[nver].clear();
                rg[nver].clear();
                add(nver, ver);
                add(nver, g[i][j].sc * 2);
                ver = nver;
            }
            reverse(all(g[i]));
        }
        int j = 0;
        while (j < sz(g[i])) {
            int z = j;
            while (z + 1 < sz(g[i]) && g[i][j].fs == g[i][z + 1].fs) {
                ++z;
            }
            if (z - j + 1 > 2) {
                fail();
            }
            if (z - j + 1 == 2) {
                add(g[i][j].sc * 2, g[i][j + 1].sc * 2 + 1);
                add(g[i][j + 1].sc * 2, g[i][j].sc * 2 + 1);
            }
            j = z + 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (e[i].t > t) {
            add(i * 2 + 1, i * 2);
        }
    }
    for (int i = 0; i < sz; ++i) {
        col[i] = -1;
        used[i] = false;
    }
    ptr = 0;
    for (int i = 0; i < sz; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    for (int i = sz - 1; i >= 0; --i) {
        if (col[ord[i]] == -1) {
            dfs2(ord[i]);
            ++ptr;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (col[i * 2] == col[i * 2 + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &e[i].v, &e[i].u, &e[i].c, &e[i].t);
        --e[i].v;
        --e[i].u;
        g[e[i].v].pb(mp(e[i].c, i));
        g[e[i].u].pb(mp(e[i].c, i));
        t[i] = e[i].t;
    }
    t[m] = 0;
    sort(t, t + m + 1);
    int k = unique(t, t + m + 1) - t;
    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
    }
    int res = -1, l = 0, r = k - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(t[mid])) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (res == -1) {
        fail();
    }
    check(t[res]);
    for (int i = 0; i < m; ++i) {
        if (col[i * 2] < col[i * 2 + 1]) {
            lst.pb(i);
        }
    }
    printf("Yes\n%d %d\n", t[res], sz(lst));
    for (int i = 0; i < sz(lst); ++i) {
        printf("%d ", lst[i] + 1);
    }
    puts("");
    return 0;
}