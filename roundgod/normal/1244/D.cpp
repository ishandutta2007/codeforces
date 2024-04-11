#include<bits/stdc++.h>
#define MAXN 250005
#define MAXLOGN 20
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n;
int c[3][MAXN];
int deg[MAXN];
int color[MAXN];
int fcolor[MAXN];
vector<int> G[MAXN];
vector<int> ord;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int p)
{
    ord.push_back(v);
    for(auto to:G[v]) if(to!=p) dfs(to,v);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    int leaf=-1;
    for(int i=1;i<=n;i++)
    {
        if((int)G[i].size()>=3) {puts("-1"); return 0;}
        if((int)G[i].size()==1) leaf=i;
    }
    dfs(leaf,0);
    reverse(ord.begin(),ord.end());
    ll ans=INF;
    int id1=-1,id2=-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==j) continue;
            ll res=c[i][ord[0]]+c[j][ord[1]];
            color[1]=i; color[2]=j;
            for(int k=3;k<=n;k++)
            {
                int cc=3-color[k-1]-color[k-2];
                color[k]=cc;
                res+=c[cc][ord[k-1]];
            }
            if(res<ans)
            {
                ans=res;
                id1=i;
                id2=j;
            }
        }
    printf("%lld\n",ans);
    color[1]=id1; color[2]=id2;
    fcolor[ord[0]]=id1; fcolor[ord[1]]=id2;
    for(int k=3;k<=n;k++)
    {
        int cc=3-color[k-1]-color[k-2];
        color[k]=cc;
        fcolor[ord[k-1]]=cc;
    }
    for(int k=1;k<=n;k++) printf("%d ",fcolor[k]+1);
    return 0;
}