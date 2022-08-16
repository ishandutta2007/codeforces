#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MX 100005

int sz[MX], comps, vis[MX];
vector<int> g[MX];

int dfs(int u)
{
    int r = 1;
    vis[u] = 1;
    for(vector<int>::iterator it = g[u].begin();it!=g[u].end();it++)
        if(!vis[*it]) r += dfs(*it);
    return r;
}

int main()
{
    //freopen("in1.in","r",stdin);
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    while(m--)
    {
        int x, y; scanf("%d %d",&x,&y); --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0;i<n;i++) if(!vis[i]) sz[comps++] = dfs(i);
    if(k==1){ puts("0"); return 0; }
    long long ans = 1;
    for(int i=0;i<comps-2;i++) ans = (ans*n)%k;
    if(comps>1) for(int i=0;i<comps;i++) ans = (ans*sz[i])%k;
    cout<<ans<<endl;
    return 0;
}