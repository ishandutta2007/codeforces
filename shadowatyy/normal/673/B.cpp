#include <bits/stdc++.h>
using namespace std;

int n, m, v1, v2, min1 = 1000000, max1, min2 = 1000000, max2;

vector <int> G[100007];

bitset <100007> vis;
bitset <100007> p;

vector <int> f;

void dfs(int v)
{
    vis[v] = 1;

    for(int i = 0; i < G[v].size(); i++)
    {
        if(!vis[G[v][i]])
        {
            p[G[v][i]] = p[v]^1;

            if(v>G[v][i] && !p[v] && p[G[v][i]])
            {
                p[v] = 1;
                p[G[v][i]] = 0;
            }
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
            dfs(i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!G[i].empty())
        {
            if(p[i])
            {
                max1 = max(max1, i);
                min1 = min(min1, i);
            }
            else
            {
                max2 = max(max2, i);
                min2 = min(min2, i);
            }
        }
    }

    if(min1<max2)
    {
        cout << 0;
        return 0;
    }

    for(int v = 1; v <= n; v++)
    {
        if(G[v].empty())
        {
            f.push_back(v);
        }
        else
        {
            for(int i = 0; i < G[v].size(); i++)
            {
                if(p[v]==p[G[v][i]])
                {
                    cout << 0;
                    return 0;
                }
            }
        }
    }


    if(max2+1==min1)
    {
        cout << 1;
        return 0;
    }

    int first = 0;
    int last = f.size()-1;

    while(f[first]<=max2 && first<n-1)
    {
        first++;
    }

    while(f[last]>=min1 && last>0)
    {
        last--;
    }

    if(m)
        cout << 2 + last-first;
    else
        cout << n-1;

}