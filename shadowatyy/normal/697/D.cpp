#include <bits/stdc++.h>
using namespace std;

int n, c, v1;

long double res[100007];

bitset <100007> vis;

bitset <100007> solved;

vector<int> G[100007];

int p[100007];

int pre[100007];

long double sub[100007];

void dfs(int v)
{
    vis[v] = 1;
    pre[v] = ++c;

    for(int i = 0; i < G[v].size(); ++i)
    {
        if(!vis[G[v][i]])
        {
            p[G[v][i]] = v;
            dfs(G[v][i]);
        }
    }

    sub[v] = c-pre[v]+1;
}

void solve(int v)
{
    solved[v] = 1;

    for(int i = 0; i < G[v].size(); ++i)
    {
        if(!solved[G[v][i]])
        {
            res[G[v][i]] = res[v] + (sub[v]-sub[G[v][i]]-1)/2 + 1;

            solve(G[v][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 2; i <= n; ++i)
    {
        cin >> v1;

        G[v1].push_back(i);
        G[i].push_back(v1);
    }

    res[1] = 1;

    dfs(1);

    solve(1);

    for(int i = 1; i <= n; ++i)
    {
        cout << res[i] << " ";
    }
}