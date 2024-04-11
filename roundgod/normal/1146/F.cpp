#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,p[MAXN];
vector<int> G[MAXN];
int dp[MAXN][3];
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
void dfs(int v)
{
    dp[v][1]=0; dp[v][2]=1;
    dp[v][0]=((int)G[v].size()>0);
    for(auto to:G[v])
    {
        dfs(to);
        dp[v][0]=1LL*dp[v][0]*(dp[to][0]+dp[to][2])%MOD;
        dp[v][2]=1LL*dp[v][2]*(0LL+dp[to][0]+dp[to][1]+2LL*dp[to][2])%MOD;
    }
    for(auto to:G[v])
    {
        add(dp[v][1],1LL*dp[v][0]*pow_mod(dp[to][0]+dp[to][2],MOD-2)%MOD*(dp[to][1]+dp[to][2])%MOD);
    }
    dec(dp[v][2],dp[v][0]);
    dec(dp[v][2],dp[v][1]);
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        G[p[i]].push_back(i);
    }
    dfs(1);
    int ans=dp[1][0];
    add(ans,dp[1][2]);
    printf("%d\n",ans);
    return 0;
}