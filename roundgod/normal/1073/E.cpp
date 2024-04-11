/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 23:26:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll k;
vector<ll> a;
ll l,r;
void add(ll &a,ll b){a+=b; if(a>=MOD) a-=MOD;}
ll p10[20];
P dp[20][1<<10][2][2];
P solve(ll now,ll mask,ll less,ll zero)
{
    if(now>=(int)a.size()) return P(1,0);
    ll base=(int)a.size()-now-1;
    ll limit=less?9:a[now];
    if(dp[now][mask][less][zero].F!=-1) return dp[now][mask][less][zero];
    ll cnt=0;
    for(ll i=0;i<=9;i++)
        if(mask&(1<<i)) cnt++;
    P cur=P(0,0);
    for(ll i=0;i<=limit;i++)
    {
        if(cnt==k&&(!(mask&(1<<i)))) continue;
        ll newmask=mask|(1<<i);
        if(zero&&i==0) newmask=mask;
        P to=solve(now+1,newmask,(less)||(i!=limit),zero&&(i==0));
        add(cur.F,to.F);add(cur.S,to.S);add(cur.S,1LL*i*to.F%MOD*p10[base]%MOD);
    }
    return dp[now][mask][less][zero]=cur;
}
ll find_ans(ll x)
{
    a.clear();
    for(ll i=0;i<20;i++)
        for(ll j=0;j<(1<<10);j++)
        {
            dp[i][j][0][0]=dp[i][j][0][1]=dp[i][j][1][0]=dp[i][j][1][1]=P(-1,-1);
        }
    while(x)
    {
        a.push_back(x%10);x/=10;
    }
    reverse(a.begin(),a.end());
    //printf("%lld\n",solve(0,0,0,1).S);
    return solve(0,0,0,1).S;
}
int main()
{
    p10[0]=1;
    for(int i=1;i<=19;i++) p10[i]=10LL*p10[i-1]%MOD;
    scanf("%lld%lld%lld",&l,&r,&k);
    printf("%lld\n",(find_ans(r)-find_ans(l-1)+MOD)%MOD);
    return 0;
}