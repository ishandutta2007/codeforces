
//
// Created by Alexander Morozov on 29/06/16.
//
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<vector<int>> g;

vector<int> col;

set<int> f;

void dfs(int u, int cl)
{
    if (col[u] != -1 && col[u] != cl)
    {
        cout << -1 << endl;
        exit(0);
    }
    if (col[u] != -1)
        return;
    if (cl == 0)
        f.insert(u);
    col[u] = cl;
    for (int x : g[u])
        dfs(x, 1 ^ cl);
}

int main()
{
    int n, m; cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    col = vector<int>(n, -1);
    for (int i = 0; i < n; ++i)
        if (col[i] == -1)
            dfs(i, 0);
    cout << f.size() << endl;
    for (auto& x : f)
        cout << x + 1 << ' ';
    cout << endl;
    cout << n - f.size() << endl;
    for (int i = 0; i < n; ++i)
        if (!f.count(i))
            cout << i + 1 << ' ';
    cout << endl;
}