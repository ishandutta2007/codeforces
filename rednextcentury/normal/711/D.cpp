#include <bits/stdc++.h>

using namespace std;
int f[1000000];
vector<int> adj[1000000];
int vis[1000000];
int tt;
int xx=0;
int dp[1000000][2];
bool is[1000000];
int ret[1000000][2][2];
int cycle[1000000];
int num=0;
bool viss[1000000];
void getCycle(int v)
{
    num=0;
    while(!viss[v])
    {
        viss[v]=1;
        v=f[v];
        if (viss[v])
        {
            while(!is[v])
            {
                is[v]=1;
                cycle[num++]=v;
                v=f[v];
            }
            return;
        }
    }
}
int sz=0;
void dfs(int v)
{
    sz++;
    vis[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
    }
}
long long MOD=1000000007;
long long p[2000000];
int main()
{
   // freopen("out.txt","w",stdout);
        int n;
        p[0]=1;
        for (int i=1;i<=1500000;i++)
            p[i]=(p[i-1]*2)%MOD;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            adj[i].clear();
        int ans=0;
        for (int i=1; i<=n; i++)
            scanf("%d",&f[i]),adj[i].push_back(f[i]),adj[f[i]].push_back(i);
        long long cur=1;
        for (int i=1;i<=n;i++)
        {
            if (is[i] || vis[i] || viss[i])continue;
            getCycle(i);
            sz=0;
            dfs(i);
            long long ret=(p[sz-num]*((p[num]-2+MOD)%MOD))%MOD;
            cur=(cur*ret)%MOD;
        }

        cout<<cur<<endl;
}