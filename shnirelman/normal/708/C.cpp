//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 4e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;

/*

*/

int n;
vector<int> g[N];
int sz[N];
int dp1[N], dp2[N];
bool res[N];
int mx_son[N];

void dfs1(int v, int par) {
    sz[v] = 1;

//    cout << "dfs1 " << v << endl;

    mx_son[v] = -1;
    for(int u : g[v]) {
        if(u == par)
            continue;

        dfs1(u, v);

        sz[v] += sz[u];
        if(mx_son[v] == -1 || sz[mx_son[v]] < sz[u])
            mx_son[v] = u;

        if(sz[u] * 2 <= n)
            dp1[v] = max(dp1[v], sz[u]);
        else
            dp1[v] = max(dp1[v], dp1[u]);
    }
}

void dfs2(int v, int par, int x) {
//    cout << "dfs2 " << v << ' ' << par << ' ' << x << endl;
//    int mx = -1;
//    for(int u : g[v]) {
//        if(u != par && sz[u] * 2 > n)
//            mx = u;
//    }
//    if((n - sz[v]) * 2 > n)
//        mx = par;

    int mx1 = -1, mx2 = -1;
    int mx1u = -1, mx2u = -1;

    for(int u : g[v]) {
        if(u == par)
            continue;

        int y = (sz[u] * 2 > n ? dp1[u] : sz[u]);

        if(y > mx1) {
            mx2 = mx1;
            mx2u = mx1u;

            mx1 = y;
            mx1u = u;
        } else if(y > mx2) {
            mx2 = y;
            mx2u = u;
        }
    }

    if((n - sz[v]) * 2 <= n)
        x = n - sz[v];

    for(int u : g[v]) {
        if(u == par)
            continue;

        if((n - sz[u]) * 2 <= n) {
            res[u] = (mx_son[u] == -1 || sz[mx_son[u]] * 2 <= n || (sz[mx_son[u]] - dp1[mx_son[u]]) * 2 <= n);
        } else {
            res[u] = ((n - sz[u] - max(x, mx1u == u ? mx2 : mx1)) * 2 <= n);
        }

        dfs2(u, v, max(x, mx1u == u ? mx2 : mx1));
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, 0);

    res[0] = (mx_son[0] == -1 || sz[mx_son[0]] * 2 <= n || (sz[mx_son[0]] - dp1[mx_son[0]]) * 2 <= n);

    dfs2(0, 0, 0);

    for(int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}