#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAXN = 200000 + 9;

int n, m, start;
vector<int> e[MAXN];
int pre[MAXN];
int vis[MAXN];
int t, t2;
int cnt;

void dfs(int cur)
{
    vis[cur] = cnt;
    for (int v : e[cur])
    {
        if (vis[v])
        {
            if (vis[v] != cnt && !t)
            {
                t = v;
                t2 = cur;
            }
            continue;
        }
        pre[v] = cur;
        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> start;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (v != start)
            e[u].push_back(v);
    }
    for (int u : e[start])
    {
        ++cnt;
        if (!vis[u])
        {
            pre[u] = start;
            dfs(u);
        }
        else
        {
            if (!t)
            {
                t = u;
                t2 = start;
            }
        }
    }
    if (t)
    {
        cout << "Possible\n";
        vector<int> path1, path2;
        for (int cur = t; cur; cur = pre[cur])
            path1.push_back(cur);
        reverse(path1.begin(), path1.end());
        for (int cur = t2; cur; cur = pre[cur])
            path2.push_back(cur);
        reverse(path2.begin(), path2.end());
        path2.push_back(t);
        cout << path1.size() << '\n';
        for (int u : path1)
        {
            cout << u << ' ';
        }
        cout << '\n';
        cout << path2.size() << '\n';
        for (int u : path2)
        {
            cout << u << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "Impossible\n";
    }

    return 0;
}