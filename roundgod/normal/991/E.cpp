/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-23 23:37:07
 ************************************************************************/

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
ll n,k,ans,fact[30];
ll cnt[30];
ll a[30];
ll check();
void dfs(ll now)
{
    if(now==10) 
    {
        ans+=check();
        return;
    }
    if(cnt[now]==0) 
    {
        a[now]=0;
        dfs(now+1);
        return;
    }
    else
    {
        for(ll i=1;i<=cnt[now];i++)
        {
            a[now]=i;
            dfs(now+1);
        }
        return;
    }
}
ll comb(ll n,ll k)
{
    return fact[n]/fact[k]/fact[n-k];
}
ll compute()
{
    /*for(int i=0;i<10;i++)
        printf("%lld ",a[i]);
    puts("");*/
    ll res=1,sum=0;
    for(ll i=0;i<10;i++)
        sum+=a[i];
    for(ll i=0;i<10;i++)
    {
        res*=comb(sum,a[i]);
        sum-=a[i];
    }
    //printf("%lld\n",res);
    return res;
}
ll check()
{
    ll res=compute();
    if(a[0]>0)
    {
        a[0]--;
        res-=compute();
        a[0]++;
    }
    return res;
}

int main()
{
    scanf("%lld",&n);
    fact[0]=1;
    for(ll i=1;i<=20;i++)
        fact[i]=i*fact[i-1];
    while(n)
    {
        cnt[n%10]++;
        n/=10;
    }
    dfs(0);
    printf("%lld\n",ans);
    return 0;
}