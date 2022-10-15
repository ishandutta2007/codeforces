/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 23:21:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll st[MAXN],L[MAXN],R[MAXN],l,r,ans,lb,rb;
ll count(ll x)
{
    if(x<k) return 0;
    ll t=(x-k+1)/(k-1);
    ll fst=(x-k+1)-(t)*(k-1),lst=(x-k+1);
    return (((fst+lst)*(t+1))/2)%MOD;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll t=0;
	for(ll i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]<a[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(ll i=n;i>=1;i--)
	{
		while(t>0&&a[st[t-1]]<=a[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll res=0;R[i]--;L[i]++;
        res=res+count(R[i]-L[i]+1);
        res=res-count(i-L[i]);
        res=res-count(R[i]-i);
        res=(res%MOD+MOD)%MOD;
        ans=(ans+a[i]*res)%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}