#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

vector<int> g[N];
vector<int> a[N];
int d[N];
int p[N];
bool used[N];

void dfs(int v, int par, int depth) {
    d[v] = depth;
    a[depth].push_back(v);
    p[v] = par;

    used[v] = true;

    for(auto u : g[v]) {
        if(!used[u]) {
            dfs(u, v, depth + 1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        a[i].erase(a[i].begin(), a[i].end());
        d[i] = 0;
        p[i] = 0;
        used[i] = false;
    }

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0, 1);

    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] > d[mx])
            mx = i;
    }

    if(d[mx] >= (n + 1) / 2) {
        cout << "PATH" << '\n';
        cout << d[mx] << '\n';
        while(p[mx] != mx) {
            cout << mx + 1 << ' ';
            mx = p[mx];
        }

        cout << 1 << '\n';
    } else {
        vector<pii> res;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j < a[i].size(); j += 2) {
                res.emplace_back(a[i][j - 1], a[i][j]);
            }
        }

        cout << "PAIRING" << '\n';
        cout << res.size() << '\n';
        for(auto p : res)
            cout << p.f + 1 << ' ' << p.s + 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}