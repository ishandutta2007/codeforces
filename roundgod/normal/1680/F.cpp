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
int t,n,m,a[MAXN],b[MAXN];
vector<P> G[MAXN];
int odd,num[MAXN],col[MAXN],dfn[MAXN],fa[MAXN],deven[MAXN],dodd[MAXN],tot;
bool even[MAXN],vis[MAXN],faid[MAXN];
bool used[MAXN];
void dfs(int v,int p)
{
    dfn[v]=++tot; fa[v]=p;
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(dfn[to]>dfn[v]||to==p) continue;
        if(col[to]!=-1)
        {
            if(col[to]==col[v])
            {  
                odd++;
                num[id]++;
                int i=0;
                dodd[to]--; dodd[v]++;
            }
            else
            {
                even[id]=true;
                int i=0;
                deven[to]--; deven[v]++;
            }
        }
        else
        {
            col[to]=col[v]^1;
            faid[to]=id; dfs(to,v);
        }
    }
}
void diff_dfs(int v)
{
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(fa[to]!=v) continue;
        diff_dfs(to); dodd[v]+=dodd[to]; deven[v]+=deven[to];
        num[id]+=dodd[to]; 
        if(deven[to]) even[id]=true; 
    }
}
vector<int> good;
void dfs2(int v)
{
    vis[v]=true;
    if(good.size()) return;
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(!used[id]&&(!even[id]&&odd==num[id])||!odd)
        {
            used[id]=true;
            good.push_back(id);
        }
        if(!vis[to]) dfs2(to);
    }
}
void dfs3(int v)
{
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(id==good[0]) continue;
        if(col[to]==-1)
        {
            col[to]=col[v]^1;
            dfs3(to);
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        odd=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++) num[i]=0,even[i]=false;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            G[a[i]].push_back(P(b[i],i)); G[b[i]].push_back(P(a[i],i));
        }
        for(int i=1;i<=n;i++) col[i]=-1,dfn[i]=deven[i]=dodd[i]=0;
        tot=0;
        col[1]=0;dfs(1,0); diff_dfs(1);
        good.clear();
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=0;i<m;i++) used[i]=false;
        dfs2(1);
        if(!good.size()) {puts("NO"); continue;}
        puts("YES");
        int id=good[0];
        for(int i=1;i<=n;i++) col[i]=-1;
        col[a[id]]=1;
        dfs3(a[id]);
        for(int i=1;i<=n;i++) if(col[i]==-1) {col[i]=1; dfs3(i);}
        for(int i=1;i<=n;i++) printf("%d",col[i]);
        puts("");
    }
    return 0;
}