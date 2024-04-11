#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

const int N = 1e5 + 13;

vector<int> g[N];
int col[N];
int a[N];

int dfs(int v, int cl) {
    col[v] = cl;
    int res = a[v];
    for(auto u : g[v]) {
        if(col[u] == 0)
            res = min(res, dfs(u, cl));
    }

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        if(col[i] == 0)
            ans += dfs(i, 1);
    }

    cout << ans;
}