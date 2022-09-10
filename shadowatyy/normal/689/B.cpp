#include <bits/stdc++.h>
using namespace std;

int n;

int t[200007];

int d[200007];

bitset <200007> vis;

queue <int> Q;

vector <int> G[200007];

void bfs(int v)
{
    Q.pop();

    for(int i = 0; i < G[v].size(); ++i)
    {
        if(!vis[G[v][i]])
        {
            vis[G[v][i]] = 1;

            d[G[v][i]] = d[v]+1;

            Q.push(G[v][i]);
        }
    }
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", t+i);

        G[i].push_back(i+1);
        G[i+1].push_back(i);

        G[i].push_back(t[i]);
    }

    Q.push(1);

    vis[1] = 1;

    while(!Q.empty())
    {
        bfs(Q.front());
    }

    for(int i = 1; i <= n; ++i)
    {
        printf("%d ", d[i]);
    }
}