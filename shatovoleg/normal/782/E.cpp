#include <bits/stdc++.h>

using namespace std;

vector<int> euler, tin;
vector<vector<int>> list_gr;

void dfs(int v)
{
    tin[v] = euler.size();
    euler.push_back(v);
    for (auto x : list_gr[v])
        if (tin[x] < 0)
        {
            dfs(x);
            euler.push_back(v);
        }
}

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    tin.resize(n, -1);
    list_gr.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        list_gr[x].push_back(y);
        list_gr[y].push_back(x);
    }
    int moves = (2 * n) / k + bool((2 * n) % k);
    dfs(0);
    int i = 0;
    vector<vector<int>> clones;
    while (i < euler.size())
    {
        clones.push_back(vector<int>());
        for (int j = 0; j < moves && i < euler.size(); ++j, ++i)
            clones.back().push_back(euler[i]);
    }
    while (clones.size() < k)
        clones.push_back({euler[0], euler[1]});
    for (auto &x : clones)
    {
        cout << x.size() << " ";
        for (auto &y : x)
            cout << y + 1 << " ";
        cout << endl;
    }
}