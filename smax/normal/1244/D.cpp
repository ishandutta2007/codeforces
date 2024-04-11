#include <bits/stdc++.h>
using namespace std;

int c[3][100000], indegree[100000] = {};
vector<int> path, adj[100000];

long long dfs(int u, int p, int color, int diff) {
    long long ret = c[color][u];
    path[u] = color + 1;
    for (int v : adj[u])
        if (v != p)
            ret += dfs(v, u, (color + diff + 3) % 3, diff);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<3; i++)
        for (int j=0; j<n; j++)
            cin >> c[i][j];

    bool ok = true;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
        if (indegree[u] > 2 || indegree[v] > 2)
            ok = false;
    }

    if (!ok)
        cout << "-1\n";
    else {
        int start;
        for (int i=0; i<n; i++)
            if (indegree[i] == 1) {
                start = i;
                break;
            }

        long long ret = LLONG_MAX;
        vector<int> ans;
        path.resize(n);
        for (int i=0; i<3; i++)
            for (int d : {-1, 1}) {
                long long tot = dfs(start, -1, i, d);
                if (tot < ret) {
                    ret = tot;
                    ans = path;
                }
            }

        cout << ret << "\n";
        for (int i : ans)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}