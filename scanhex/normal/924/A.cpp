#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> cur;
vector<bool> used;
void dfs(int u)
{
    if (used[u])
        return;
    cur.push_back(u);
    used[u] = true;
    for (int v : g[u])
        dfs(v);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> matr(n);
    for (auto& x : matr)
        cin >> x;
    g.resize(n + m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matr[i][j] == '#')
                g[i].push_back(j + n), g[j + n].push_back(i);
    used.resize(n + m);
    for (int i = 0; i < n + m; ++i)
    {
        if (used[i])
            continue;
        cur.clear();
        dfs(i);
        for (int x : cur)
            for (int y : cur)
                if (x < n && y >= n && matr[x][y - n] == '.')
                {
                    cout << "No\n";
                    return 0;
                }
    }
    cout << "Yes\n";
}