#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> G[MAXN];
int color[MAXN],last[MAXN];
int cnt[MAXN],dep[MAXN];
bool vis[MAXN],bad[MAXN];
bool f;
mt19937 wcy(time(NULL));
void dfs(int v)
{
    color[v]=1;
    for(auto to:G[v])
    {
        if(color[to]==0) dfs(to);
        else if(color[to]==2) f=false;
    }
    color[v]=2;
}
bool check(int v)
{
    f=true;
    for(int i=1;i<=n;i++) color[i]=0;
    dfs(v);
    return f;
}
int dfs2(int v)
{
    vis[v]=true;
    last[v]=v;
    for(auto to:G[v])
    {
        if(!vis[to])
        {
            dep[to]=dep[v]+1;
            cnt[v]+=dfs2(to);
            if(dep[last[to]]<dep[last[v]]) last[v]=last[to];
        }
        else
        {
            cnt[v]++;
            cnt[to]--;
            if(dep[to]<dep[last[v]]) last[v]=to;
        }
    }
    if(cnt[v]>1) bad[v]=true; else bad[v]=false;
    return cnt[v];
}
void dfs3(int v)
{
    vis[v]=true;
    if(!bad[v]&&bad[last[v]]) bad[v]=true;
    for(auto to:G[v])
        if(!vis[to])
            dfs3(to);
}
vector<int> ans;
void solve(int v)
{
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) vis[i]=false;
    for(int i=1;i<=n;i++) dep[i]=0;
    dfs2(v);
    for(int i=1;i<=n;i++) vis[i]=false;
    dfs3(v);
    for(int i=1;i<=n;i++)
        if(!bad[i]) ans.push_back(i);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans.clear();
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        for(int T=1;T<=100;T++)
        {
            int v=wcy()%n+1;
            if(check(v))
            {
                solve(v);
                break;
            }
        }
        if((int)ans.size()*5<n) puts("-1");
        else
        {
            for(auto v:ans) printf("%d ",v);
            puts("");
        }
    }
    return 0;
}