#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> list_gr;
vector<bool> used;

void dfs(int v, vector<int> &ver)
{
    used[v] = true;
    ver.push_back(v);
    for (auto x : list_gr[v])
        if (!used[x])
            dfs(x, ver);
}

int find_max_color(map<int, int> color)
{
    int clr = -1;
    int amnt = 0;
    for (auto x : color)
        if (x.second > amnt)
        {
            clr = x.first;
            amnt = x.second;
        }
    return clr;
}

int main()
{
    int n, k, m;
    cin >> n >> m >> k;
    list_gr.resize(n);
    used.resize(n, false);
    vector<int> clr(n);
    for (auto &x : clr)
        cin >> x;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        list_gr[l].push_back(r);
        list_gr[r].push_back(l);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (!used[i])
        {
            map<int, int> color;
            vector<int> v;
            dfs(i, v);
            for (auto x : v)
            {
                if (color.count(clr[x]))
                    ++color[clr[x]];
                else
                    color[clr[x]] = 1;
            }
            int c = find_max_color(color);
            for (auto x : color)
                if (x.first != c)
                    ans += x.second;
        }
    cout << ans << endl;
}