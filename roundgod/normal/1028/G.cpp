/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 18:17:38
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000
#define INF 20000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
ll dp[MAXN+5][10];
ll find(ll x,ll left)
{
    if(x>10000) return find(10000,left)+x-10000;
    if(dp[x][left]!=-1) return dp[x][left];
    if(left==0) return dp[x][left]=x;
    ll cur;
    cur=x;
    for(ll i=1;i<=x;i++)
        cur=find(cur,left-1)+1;
    cur=find(cur,left-1);
    return dp[x][left]=cur;
}
void solve()
{
    ll l=1,r=find(1,5);
    for(ll i=4;i>=0;i--)
    {
        vector<ll> v;v.clear();
        ll cur=l;
        for(ll j=0,x=min((ll)MAXN,l);j<x;j++)
        {
            ll now=find(cur,i);
            v.push_back(now);
            cur=now+1;
        }
        printf("%lld\n",(ll)v.size());
        fflush(stdout);
        for(ll j=0;j<(int)v.size();j++)
            printf("%lld ",v[j]);
        cout<<endl;
        ll p;
        scanf("%lld",&p);
        if(p<0) return;
        else if(p>0) l=v[p-1]+1;
        if(p!=(int)v.size()) r=v[p-1];
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    solve();
    return 0;
}