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
const int MAXN = 1e6 + 1000;

struct cell {
    int x, y;
};
vector<int> e[MAXN];

int n, m;
int mr[MAXN], mc[MAXN];
int tonum(const cell & c) {
    return c.x * m + c.y;
}
cell fromnum(int n) {
    return {n / m, n % m};
}

void addedge(int u, int v) {
    e[u].pb(v);
    e[v].pb(u);
}

pair<int, int> ord[MAXN];
bool used[MAXN];
vector<int> path;

void dfs(int v) {
    used[v] = true;
    path.pb(v);
    for (auto u : e[v]) {
        if (!used[u])
            dfs(u);
    }
}


int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    vector<vector<int>> a;
    scanf("%d%d", &n, &m);
    a.resize(n);

    forn(i, n) {
        a[i].resize(m);
        forn(j, m){
            scanf("%d", &a[i][j]);
            int nm = tonum({i, j});
            ord[nm] = {a[i][j], nm};
        }
    }
    int N = n * m;
    sort(ord, ord + N);
    forn(i, n) {
        map<int, int> last;
        forn(j, m) {
            if (last.count(a[i][j]) != 0) {
                addedge(tonum({i, j}), tonum({i, last[a[i][j]]}));
            }
            last[a[i][j]] = j;
        }
    }
    forn(j, m) {
        map<int, int> last;
        forn(i, n) {
            if (last.count(a[i][j]) != 0) {
                addedge(tonum({i, j}), tonum({last[a[i][j]], j}));
            }
            last[a[i][j]] = i;
        }
    }
    forn(i, N) {
        if (!used[ord[i].second]) {
            path.clear();
            dfs(ord[i].second);
            int mx = 0;
            for (auto v : path) {
                cell c = fromnum(v);
                mx = max(mx, mr[c.x]);
                mx = max(mx, mc[c.y]);
            }
            int nv = mx + 1;
            for (auto v : path) {
                cell c = fromnum(v);
                a[c.x][c.y] = nv;
                mr[c.x] = max(mr[c.x], nv);
                mc[c.y] = max(mc[c.y], nv);
            }
        }
    }
    forn(i, n) {
        forn(j, m) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    

    
    return 0;
}