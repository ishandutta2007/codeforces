#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,sz[MAXN];
int dp[MAXN][MAXK],cnt[MAXK];
int s[MAXK][MAXK];
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void dfs(int v,int p)
{
    dp[v][0]=2;sz[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        for(int j=min(m,sz[v]+sz[to]+1);j>=0;j--)
        {
            int sum=0;
            for(int k=max(0,j-sz[v]-1);k<=min(j,sz[to]);k++)
            {
                add(sum,1LL*dp[v][j-k]*dp[to][k]%MOD);
                if(j!=k) add(sum,1LL*dp[v][j-k-1]*(dp[to][k]-(k==0))%MOD);
            }
            dp[v][j]=sum;
        }
        sz[v]+=sz[to]+1;
    }
    for(int i=1;i<=min(m,sz[v]);i++) add(cnt[i],dp[v][i]);
    for(int i=1;i<=min(m,sz[v]);i++)
    {
        for(auto to:G[v])
        {
            if(to==p) continue;
            dec(cnt[i],dp[to][i]);
            dec(cnt[i],dp[to][i-1]-(i==1));
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    s[1][1]=1;
    for(int i=2;i<=m;i++)
        for(int j=1;j<=i;j++)
        {
            s[i][j]=s[i-1][j-1];
            add(s[i][j],1LL*j*s[i-1][j]%MOD);
        }
    int fact=1,ans=0;
    for(int i=1;i<=m;i++)
    {
        fact=1LL*fact*i%MOD;
        add(ans,1LL*cnt[i]*fact%MOD*s[m][i]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}