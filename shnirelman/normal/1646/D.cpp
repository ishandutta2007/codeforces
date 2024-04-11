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
using pili = pair<int, li>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

pili operator + (pili a, pili b) {
    return pili(a.f + b.f, a.s + b.s);
}

vector<int> g[N];
pili dp[N][2];

void dfs1(int v, int par) {
    dp[v][0] = {0, -1};
    dp[v][1] = {1, -int(g[v].size())};
    for(int u : g[v]) {
        if(u == par)
            continue;

        dfs1(u, v);

        dp[v][1] = dp[v][1] + dp[u][0];
        dp[v][0] = dp[v][0] + max(dp[u][0], dp[u][1]);
    }
}

int a[N];

void dfs2(int v, int par, int col) {
    a[v] = (col == 0 ? 1 : g[v].size());

    for(int u : g[v]) {
        if(u == par)
            continue;

        if(col == 1)
            dfs2(u, v, 0);
        else if(dp[u][0] >= dp[u][1])
            dfs2(u, v, 0);
        else
            dfs2(u, v, 1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    if(n == 2) {
        cout << "2 2\n1 1\n";
        return 0;
    }

    dfs1(0, -1);

    pili res;
    if(dp[0][0] > dp[0][1]) {
        res = dp[0][0];
        dfs2(0, -1, 0);
    } else {
        res = dp[0][1];
        dfs2(0, -1, 1);
    }

    cout << res.f << ' ' << -res.s << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}