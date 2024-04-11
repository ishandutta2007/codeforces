#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,len[MAXN],son[MAXN],tmp[MAXN],*f[MAXN],ans[MAXN],*id=tmp;
vector<int> G[MAXN];
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        if(len[to]>len[son[v]]) son[v]=to;
    }
    len[v]=len[son[v]]+1;
}
void dfs2(int v,int p)
{
    f[v][0]=1;
    if(son[v])
    {
        f[son[v]]=f[v]+1;
        dfs2(son[v],v);
        ans[v]=ans[son[v]]+1;
    }
    for(auto to:G[v])
    {
        if(to==p||to==son[v]) continue;
        f[to]=id; id+=len[to]; dfs2(to,v);
        for(int j=1;j<=len[to];j++)
        {
            f[v][j]+=f[to][j-1];
            if((j<ans[v]&&f[v][j]>=f[v][ans[v]])||(j>ans[v]&&f[v][j]>f[v][ans[v]])) ans[v]=j;
        }
    }
    if(f[v][ans[v]]==1) ans[v]=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0); f[1]=id; id+=len[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}