#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<vector<int>> reb;

void dfs(int ind) {
    if (vis[ind])
        return;
    vis[ind] = true;
    for (int i = 0; i < reb[ind].size(); i++) {
        dfs(reb[ind][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vis.assign(n + 1, false);
    reb.resize(n + 1);
    int u, v;
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        reb[u].push_back(v);
        reb[v].push_back(u);
    }
    int clik = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        clik++;
        dfs(i);
    }
    cout << k - (n - clik) << endl;
    return 0;
}