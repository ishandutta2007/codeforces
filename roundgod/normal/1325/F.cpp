#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,threshold;
vector<int> G[MAXN];
bool vis[MAXN];
int dep[MAXN],fa[MAXN];
vector<int> v[MAXN];
void dfs(int v,int p,int d)
{
    vis[v]=true;
    dep[v]=d;
    fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!vis[to]) dfs(to,v,d+1);
        else
        {
            if(dep[to]<dep[v]&&dep[v]-dep[to]+1>=threshold)
            {
                puts("2");
                printf("%d\n",dep[v]-dep[to]+1);
                int x=v;
                printf("%d",x);
                while(x!=to)
                {
                    x=fa[x];
                    printf(" %d",x);
                }
                puts("");
                exit(0);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    threshold=1;
    while(threshold*threshold<n) threshold++;
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++) v[dep[i]%(threshold-1)].push_back(i);
    for(int i=0;i<threshold-1;i++)
    {
        if((int)v[i].size()>=threshold)
        {
            puts("1");
            for(int j=0;j<threshold;j++) printf("%d ",v[i][j]);
            exit(0);
        }
    }
    assert(0);
    return 0;
}