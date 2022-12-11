#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5 + 100;

struct edge {
    int u, v, c;
};
vector<edge> g;
vector<int> e[MAXN];
vector<int> en[MAXN];
int used[MAXN];
vector<int> col;
vector<int> vcol;

int cnt = 1;
int dfs(int v, int par) {
    used[v] = true;
    int res = 0;
    forn(i, e[v].size()) {
        int u = e[v][i];
        int nm = en[v][i];
        if (u == par)
            continue;
        if (!used[u]) {
            int c = dfs(u, v);
            if (c > 0) {
                col[nm] = c;
                if (vcol[c] != v) {
                    res = c;
                }
            }
        } else {
            if (col[nm] != 0)
                continue;
            vcol[cnt] = u;
            res = cnt;
            col[nm] = cnt++;
        }
    }
    return res;
}


vector<int> onc[MAXN];
bool goodc[MAXN];
vector<int> E[MAXN];
vector<edge> G;
int S, T;
int timer = 1;

void addedge(int u, int v, int c) {
    E[u].push_back(G.size());
    G.push_back({u, v, c});
    E[v].push_back(G.size());
    G.push_back({v, u, 0});
}

int findf(int v) {
    if (v == T)
        return 1;
    used[v] = timer;
    for (auto i : E[v]) {
        int to = G[i].v;
        if (used[to] != timer && G[i].c > 0) {
            if (findf(to)) {
                G[i].c--;
                G[i^1].c++;
                return 1;
            }
        }
    }
    return 0;
}
int csize[MAXN];

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--, v--;
        c--;
        e[u].pb(v);
        en[u].pb(i);
        e[v].pb(u);
        en[v].pb(i);
        g.push_back({u, v, c});

    }
    col.resize(m, 0);
    vcol.resize(m + 1, 0);
    forn(i, n) {
        if (!used[i])
            dfs(i, -1);
    }
    forn(i, m) {
        //cerr << g[i].u+1  << ' ' << g[i].v+1 << ' ' << col[i] << '\n';
        csize[col[i]]++;
    }
    cnt--;
    vector<bool> onlyc(m, true);
    vector<int> ccnt(m, 0);
    vector<int> acnt(m, 0);
    vector<bool> goodcl(m, 0);
    
    forn(i, g.size()) {
        edge ed = g[i];
        acnt[ed.c]++;
        if (col[i] == 0) {
            onlyc[ed.c] = false;
        } else {
            ccnt[ed.c]++;
            onc[col[i]].pb(ed.c);
        }
    }
    /*
    for (int i = 1; i <= cnt; ++i) {
        for (auto j : onc[i]) {
            cerr << j << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
*/
    int colcnt = 0;
    forn(i, m) {
        if (acnt[i] > 0)
            colcnt++;
        if (acnt[i] > ccnt[i])
            goodcl[i] = true;
    }
    for (int i = 1; i <= cnt; ++i) {
        if (csize[i] <= 1) {
            goodc[i] = true;
        }
        for (auto j : onc[i]) {
            if (goodcl[j])
                goodc[i] = true;
        }
    }
    S = 0;
    T = 1 + cnt + m;
    int maxfl = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (!goodc[i]) {
            maxfl++;
            addedge(S, i, 1);
            for (auto j : onc[i]) {
                addedge(i, j + 1 + cnt, 1);
            }
        }
    }
    forn(i, m) {
        if (!goodcl[i])
            addedge(i + cnt + 1, T, ccnt[i] - 1);
    }
    int flow = 0;
    clr(used);
    while (true) {
        timer++;
        if (findf(S)) {
            flow++;
        } else {
            break;
        }
        /*
        for (auto e : G) {
            cout << e.u << ' ' << e.v << ' ' << e.c << '\n';
        }
        cout << '\n';*/
    }
    cout << colcnt - (maxfl - flow) << '\n';
    return 0;
}