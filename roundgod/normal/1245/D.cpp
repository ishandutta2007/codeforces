#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 5000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,V,x[MAXN],y[MAXN],c[MAXN],k[MAXN];
ll cost[MAXN][MAXN];
ll mincost[MAXN];
bool used[MAXN];
int pre[MAXN];
vector<P> vec,ans;
vector<int> tmp;
ll prim()
{
    for(int i=1;i<=V;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[1]=0;
    ll res=0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=V;u++)
          if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        if(pre[v]) vec.push_back(P(pre[v],v));
        for(int u=1;u<=V;u++)
        {
            if(mincost[u]>cost[u][v])
            {
                mincost[u]=cost[u][v];
                pre[u]=v;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%d",&k[i]);
    memset(cost,0,sizeof(cost));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            cost[i][j]=cost[j][i]=1LL*(k[i]+k[j])*(max(x[i]-x[j],x[j]-x[i])+max(y[i]-y[j],y[j]-y[i]));
    for(int i=1;i<=n;i++) cost[i][n+1]=cost[n+1][i]=c[i];
    V=n+1;
    printf("%lld\n",prim());
    for(auto p:vec)
    {
        if(p.F==n+1) tmp.push_back(p.S);
        else if(p.S==n+1) tmp.push_back(p.F);
        else ans.push_back(p);
    }
    printf("%d\n",(int)tmp.size());
    for(auto v:tmp) printf("%d ",v);
    puts("");
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}