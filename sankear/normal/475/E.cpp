#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = 2020;

int n, ptr, res;
int ord[N], col[N], cnt[N], sz[N], p[N];
bool used[N];
vector<short> g[N], e[N], re[N];
bool can[N][N];
bitset<1010> bits;

void dfs1(int v, int pv = -1) {
    used[v] = true;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i]]) {
            e[v].pb(g[v][i]);
            re[g[v][i]].pb(v);
            dfs1(g[v][i], v);
        } else if (g[v][i] != pv) {
            e[v].pb(g[v][i]);
            re[g[v][i]].pb(v);
        }
    }
}

void dfs2(int v) {
    used[v] = true;
    for (int i = 0; i < sz(e[v]); ++i) {
        if (!used[e[v][i]]) {
            dfs2(e[v][i]);
        }
    }
    ord[ptr++] = v;
}

void dfs3(int v) {
    col[v] = ptr;
    ++cnt[ptr];
    for (int i = 0; i < sz(re[v]); ++i) {
        if (col[re[v][i]] == 0) {
            dfs3(re[v][i]);
        }
    }
}

void dfs4(int v) {
    used[v] = true;
    sz[v] = cnt[v];
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i]]) {
            p[g[v][i]] = v;
            dfs4(g[v][i]);
            sz[v] += sz[g[v][i]];
        }
    }
    res += cnt[v] * sz[v];
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs1(0);
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    ptr = 0;
    dfs2(0);
    ptr = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (col[ord[i]] == 0) {
            ++ptr;
            dfs3(ord[i]);
        }
    }
    for (int i = 1; i <= ptr; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(e[i]); ++j) {
            int a = col[i], b = col[e[i][j]];
            if (a != b && !can[a][b]) {
                can[a][b] = true;
                g[a].pb(b);
                g[b].pb(a);
            }
        }
    }
    for (int i = 1; i <= ptr; ++i) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 1; i <= ptr; ++i) {
        for (int j = 1; j <= ptr; ++j) {
            used[j] = false;
        }
        p[i] = -1;
        res = 0;
        dfs4(i);
        for (int j = 0; j < 1010; ++j) {
            bits.set(j, 0);
        }
        bits.set(0, 1);
        for (int j = 0; j < sz(g[i]); ++j) {
            if (p[g[i][j]] == i) {
                bits = (bits | (bits << sz[g[i][j]]));
            }
        }
        for (int j = 0; j < 1010; ++j) {
            if (bits.test(j)) {
                ans = max(ans, res + (sz[i] - cnt[i] - j) * j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}