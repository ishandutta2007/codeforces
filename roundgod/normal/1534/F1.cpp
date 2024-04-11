#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,V;
int a[MAXN];
string str[MAXN];
int id[MAXN],highest[MAXN],lowest[MAXN];
vector<int> G[MAXN];
int dfn[MAXN],low[MAXN],st[MAXN];
int vis[MAXN];
int cmp[MAXN],cnt,tot,t;
int num[MAXN];
void dfs(int v)
{
    dfn[v]=low[v]=++tot;
    vis[v]=1;
    st[t++]=v;
    for(auto to:G[v])
    {
        if(!vis[to])
        {
            dfs(to);
            low[v]=min(low[v],low[to]);
        }
        else if(vis[to]==1) low[v]=min(low[v],dfn[to]);
    }
    if(dfn[v]==low[v])
    {
        int u;
        do
        {
            u=st[t-1]; t--;
            cmp[u]=cnt;
            vis[u]=2;
        }while(u!=v);
        cnt++;
    }
}
int tarjan()
{
    t=tot=cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<V;i++) if(!dfn[i]) dfs(i);
    return cnt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(str[i][j]=='#') id[i*m+j]=V++;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(str[j][i]=='#')
            {
                if(j!=0&&str[j-1][i]=='#') G[id[j*m+i]].push_back(id[(j-1)*m+i]);
                vector<int> v; v.clear();
                for(int k=j;k<n;k++)
                {
                    if(i>0&&str[k][i-1]=='#') G[id[j*m+i]].push_back(id[k*m+(i-1)]);
                    if(i<m-1&&str[k][i+1]=='#') G[id[j*m+i]].push_back(id[k*m+(i+1)]);
                    if(j!=k&&str[k][i]=='#')
                    {
                        G[id[j*m+i]].push_back(id[k*m+i]);
                        break;
                    }
                } 
            }
        }
    }
    int tt=tarjan();
    int ans=0;
    for(int i=0;i<V;i++)
    {
        for(auto to:G[i])
        {
            if(cmp[i]!=cmp[to]) num[cmp[to]]++;
        }
    }
    for(int i=0;i<tt;i++) if(num[i]==0) ans++;
    printf("%d\n",ans);
    return 0;
}