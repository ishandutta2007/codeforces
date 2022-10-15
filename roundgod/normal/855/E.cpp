#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10][80][1024][2];
int bit[80];
int base;
ll dfs(int pos,int s,int flag,int z)
{
    if(pos==-1)return (s==0&&!z);
    if(!flag&&dp[base-1][pos][s][z]!=-1)
        return dp[base-1][pos][s][z];
    ll ans=0;
    int end=flag?bit[pos]:base-1;
    for(int i=0;i<=end;i++)
    {
        ans+=dfs(pos-1,(z&&i==0)?0:s^(1<<i),flag&&i==end,z&&i==0);
    }
    if(!flag)dp[base-1][pos][s][z]=ans;
    return ans;
}
ll solve(ll n)
{
    int len=0;
    if(n==0) return 0;
    while(n)
    {
        bit[len++]=n%base;
        n/=base;
    }
    return dfs(len-1,0,1,1);
}
int main()
{
    int T;
    ll a,b;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        scanf("%d %I64d %I64d",&base,&a,&b);
        printf("%I64d\n",solve(b)-solve(a-1));
    }
    return 0;
}