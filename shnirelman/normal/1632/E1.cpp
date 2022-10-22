#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

vector<int> g[N];
int d[N], nxt[N];

int dfs1(int v, int par, int depth) {
    d[v] = depth;

    int mx = d[v], bst = -1;
    for(int u : g[v]) {
        if(u == par)
            continue;

        int rs = dfs1(u, v, depth + 1);

        if(rs > mx) {
            mx = rs;
            bst = u;
        }
    }

    nxt[v] = bst;

    return mx;
}

int dfs2(int v, int par, int depth) {
    int res = min(d[v], depth);
    for(int u : g[v]) {
        if(u == par)
            continue;

        res = max(res, dfs2(u, v, depth + 1));
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, 0, 0);

//    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << d[i] << ' ' << nxt[i] << endl;
//    }

    int v = nxt[0];

    for(int x = 1; x <= n; x++) {
        int res = dfs2(v, -1, x);
        int rs;
        while(nxt[v] != -1 && (rs = dfs2(nxt[v], -1, x)) < res) {
            res = rs;
            v = nxt[v];
        }

        cout << res << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}