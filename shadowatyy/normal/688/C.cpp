#include <bits/stdc++.h>
using namespace std;

int n, m, v1, v2;

vector <int> G[100007];

int res[100007];

bitset <100007> vis;

vector <int> r1;
vector <int> r2;

void dfs(int v)
{
    vis[v] = 1;

    for(int i = 0; i < G[v].size(); i++)
    {
        if(!vis[G[v][i]])
        {
            if(res[v]==1)
            {
                res[G[v][i]] = 2;
            }
            else
            {
                res[G[v][i]] = 1;
            }

            dfs(G[v][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        cin >> v1 >> v2;

        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            res[i] = 1;
            dfs(i);
        }
    }

    for(int v = 1; v <= n; v++)
    {
        for(int i = 0; i < G[v].size(); i++)
        {
            if(res[v]==res[G[v][i]])
            {
                cout << -1;
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(res[i]==1)
        {
            r1.push_back(i);
        }

        if(res[i]==2)
        {
            r2.push_back(i);
        }
    }

    cout << r1.size() << '\n';

    for(int i = 0; i < r1.size(); i++)
    {
        cout << r1[i] << " ";
    }

    cout << '\n' << r2.size() << '\n';

    for(int i = 0; i < r2.size(); i++)
    {
        cout << r2[i] << " ";
    }
}