#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

vector<int> g[N];
int p[N], h[N];
int a[N], b[N];
int sz[N];

bool ans = true;

void dfs(int v, int par) {


    int a1 = 0, b1 = 0;

    sz[v] = p[v];
    for(auto u : g[v]) {
        if(u == par)
            continue;

        dfs(u, v);

        sz[v] += sz[u];
        a1 += a[u];
        b1 += b[u];
    }

    if((h[v] + sz[v]) % 2 != 0) {
        ans = false;
        return;
    }

    a[v] = (h[v] + sz[v]) / 2;
    b[v] = (sz[v] - h[v]) / 2;

    if(a1 > a[v] || a[v] < 0 || b[v] < 0) {
        ans = false;
    }
}

void solve() {


    int n, m;
    cin >> n >> m;

    ans = true;
    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}