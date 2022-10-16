/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 23:51:35
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
ll n,k,a[MAXN],cnt1,cnt2,minx,maxx;
int main()
{
    scanf("%lld",&n);
    if(n==1)
    {
        ll x;
        scanf("%lld",&x);
        printf("%lld\n",x);
        return 0;
    }
    minx=INF;maxx=-INF;
    ll psum=0,nsum=0;
    ll x;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&x);
        if(x>0) psum+=x,cnt1++;
        if(x<0) nsum-=x,cnt2++;
        if(x==0) cnt1++,cnt2++;
        if(x>0) minx=min(minx,x);
        if(x<0) maxx=max(maxx,x);
    }
    ll ans=psum+nsum;
    if(cnt1==0&&cnt2==0) ans=0;
    else if(cnt2==0) ans-=2*minx;
    else if(cnt1==0) ans+=2*maxx;
    printf("%lld\n",ans);
    return 0;
}