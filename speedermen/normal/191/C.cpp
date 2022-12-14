#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)((x).size())
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int n, up[N][18], dep[N];
int d[N], res[N];
vector < pii > g[N];

void go(int v, int p) {
    if (v == 1) up[v][0] = v;
    else up[v][0] = p;
    FOR(i, 1, 17) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto to : g[v]) {
        if (to.first == p) continue;
        dep[to.first] = dep[v] + 1;
        go(to.first, v);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    FOR(ii, 0, 17) {
        int i = 17 - ii;
        if (dep[up[v][i]] >= dep[u]) {
            v = up[v][i];
        }
    }
    if (u == v) return v;
    FOR(ii, 0, 17) {
        int i = 17 - ii;
        if (up[v][i] != up[u][i])
            v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

void dfs(int v, int p) {
    for (auto to : g[v]) {
        if (to.first == p) continue;
        dfs(to.first, v);
        res[to.second] = d[to.first];
        d[v] += d[to.first];
    }
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    go(1, 0);
    int q;
    cin >> q;
    FOR(i, 1, q) {
        int x, y;
        cin >> x >> y;
        d[x] += 1;
        d[y] += 1;
        d[lca(x, y)] -= 2;
    }
    dfs(1, 0);
    FOR(i, 1, n - 1) {
        cout << res[i] << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}