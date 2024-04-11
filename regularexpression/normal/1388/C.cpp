#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define int long long
#define ll long long

const int N = 1e5 + 7;

int n, m;
vector<int> g[N];
int p[N], pp[N], h[N], c[N];
bool ans;

void dfs(int v, int pr = -1) {
    pp[v] = p[v];
    for (auto u : g[v]) {
        if (u != pr) {
            dfs(u, v);
            pp[v] += pp[u];
        }
    }
    c[v] = pp[v] - h[v];
    if (c[v] < 0 || (c[v] & 1)) ans = 0;
    c[v] /= 2;
    if (c[v] > pp[v]) ans = 0;
    int ss = 0;
    for (auto u : g[v]) {
        if (u != pr) ss += c[u];
    }
    if (ss + p[v] < c[v]) ans = 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        g[i] = {};
    }
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].pb(u);
        g[u].pb(v);
    }
    ans = 1;
    dfs(0);
    cout << (ans ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}