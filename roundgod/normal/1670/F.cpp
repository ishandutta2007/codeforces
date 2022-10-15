#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n;
ll xl,xr,xz;
vector<int> r,z;
int comb[1005][1005];
int dp[72][1025][2];
int solve(int now,int pre,int greater)
{
    if(now==61)
    {
        return (pre==0&&greater==0)?1:0;
    }
    if(dp[now][pre][greater]!=-1) return dp[now][pre][greater];
    int ans=0;
    for(int i=z[now];i<=n;i+=2)
    {
        int sum=(pre+i);
        int ngreater;
        if((sum&1)==r[now]) ngreater=greater; else ngreater=((sum&1)>r[now]?1:0);
        add(ans,1LL*comb[n][i]*solve(now+1,sum>>1,ngreater)%MOD);
    }
    return dp[now][pre][greater]=ans;
}
ll get_ans(ll xr,ll xz)
{
    memset(dp,-1,sizeof(dp));
    r.clear(); z.clear();
    while(xr) {r.push_back(xr&1); xr>>=1;}
    while(xz) {z.push_back(xz&1); xz>>=1;}
    while(r.size()!=61) r.push_back(0);
    while(z.size()!=61) z.push_back(0);
    return solve(0,0,0);
}
int main()
{
    comb[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++)
        {
            comb[i][j]=comb[i-1][j-1];
            add(comb[i][j],comb[i-1][j]);
        }
    }
    scanf("%d%lld%lld%lld",&n,&xl,&xr,&xz);
    int ans=get_ans(xr,xz); dec(ans,get_ans(xl-1,xz));
    printf("%d\n",ans);
    return 0;
}