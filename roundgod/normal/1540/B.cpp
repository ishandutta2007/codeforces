#include<bits/stdc++.h>
#define MAXN 405
#define MAXLOGN 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int inv[MAXN];
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
int dp[MAXN][MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int root)
{
    memset(pa,0,sizeof(pa));
    dfs(root,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=n;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    inv[1]=1;
	for (int i=2;i<=400;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0) dp[i][j]=0;
            else if(j==0) dp[i][j]=1;
            else dp[i][j]=1LL*(dp[i-1][j]+dp[i][j-1])*inv[2]%MOD;
        }
    int ans=0;
    for(int root=1;root<=n;root++)
    {
        init(root);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int l=lca(i,j);
                int d1=dis(l,i),d2=dis(l,j);
                //probability that j goes prior to i is d1/d1+d2
                add(ans,dp[d1][d2]);
            }
    }
    ans=1LL*ans*inv[n]%MOD;
    printf("%d\n",ans);
    return 0;
}