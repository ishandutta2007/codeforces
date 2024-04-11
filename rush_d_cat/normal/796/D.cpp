#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int NICO = 300000+10;
int n, k, d, u, v, x, y;
int par[NICO], dis[NICO], vis[NICO];
vector<int> G[NICO], id[NICO], res;
queue<int> q;
int main()
{
    scanf("%d %d %d", &n, &k, &d);
    for(int i=1;i<=n;i++)
    {
        dis[i] = NICO;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d", &x);
        q.push(x); 
        dis[x] = 0;
        par[x] = x;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d %d", &x, &y);
        id[x].push_back(i);
        id[y].push_back(i);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans = 0;
    while(q.size())
    {
        int cur = q.front(); q.pop();
        for(int i=0;i<G[cur].size();i++)
        {
            int t = G[cur][i];
            if(par[t] != 0 && par[t] == par[cur])
            {
                continue;
            }
            if(par[t] != 0 && par[t] != par[cur])
            {
                if(!vis[id[cur][i]])
                    vis[id[cur][i]] = 1, res.push_back(id[cur][i]);
                continue;
            }
            if(dis[cur] + 1 <= d) 
            {
                dis[t] = dis[cur] + 1;
                par[t] = par[cur];
                q.push(t);
            }
        }
    }
    
    printf("%d\n", res.size());
    sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++)
    {
        printf("%d ", res[i]);
    }
}