/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-19 11:32:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll pre[MAXN],suf[MAXN]; 
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    a[0]=a[n+1]=2;
    ll last=1,now=2;
    while(last<=n)
    {
        while(now<=n+1&&a[now]==1) now++;
        for(ll i=last;i<now;i++) suf[i]=now;
        last=now;now++;
    }
    suf[0]=(a[1]!=1?1:suf[1]);
    last=n,now=n-1;
    while(last>0)
    {
        while(now>=0&&a[now]==1) now--;
        for(ll i=last;i>now;i--) pre[i]=now;
        last=now;now--;
    }
    pre[n+1]=(a[n]!=1?n:pre[n]);
    /*for(ll i=0;i<=n+1;i++)
        printf("%lld ",pre[i]);
    puts("");
    for(ll i=0;i<=n+1;i++)
        printf("%lld ",suf[i]);
    puts("");*/
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll res=1,now=suf[pre[i]],sum=0;
        if(now!=i&&k==1) ans++;
        sum+=now-i;
        while(now<=n)
        {
            if(a[now]>=INF/res) break;
            res*=a[now];
            sum+=a[now];
            if(res%k==0&&res/k==sum) 
            {
                ans++;
                //printf("%lld %lld %lld %lld\n",i,now,res,sum);
            }
            ll inc=suf[now]-now;
            if(inc>=1)
            {
                if(res%k==0&&res/k>sum&&res/k<sum+inc) 
                {
                    ans++;
                    //printf("2 %lld %lld %lld %lld\n",i,now,res,sum);
                }
            }
            now=suf[now];
            sum+=inc-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}