/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 15:49:08
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,a[MAXN],pre[MAXN];
ll dis(ll x,ll y) {x-=y; return x<0?x+n:x;}
int main()
{
    scanf("%lld%lld",&n,&q);
    ll sum=0;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(ll i=0;i<q;i++)
    {
        ll b;scanf("%lld",&b);
        if(b>=sum) {puts("1"); continue;}
        ll now=1,cnt=0,id=-1,mx=INF;
        for(ll j=1;j<=n;j++)
        {
            while(cnt<=b)
            {
                cnt+=a[now];
                now++;if(now>n) now-=n;
            }
            now--;if(now<=0) now+=n;cnt-=a[now];
            pre[j]=dis(now,j);
            //printf("%lld %lld\n",j,pre[j]);
            if(pre[j]<mx)
            {
                mx=pre[j];
                id=j;
            }
            cnt-=a[j];
        }
        ll ans=INF;
        for(ll j=id;j<=id+mx;j++)
        {
            ll now=j,cnt=0,lastdis=0;
            while(now>n) now-=n;
            while(true)
            {
                //printf("%lld %lld\n",now,lastdis);
                now=now+pre[now];
                if(now>n) now-=n;
                cnt++;
                if(dis(now,j)<lastdis) break;
                lastdis=dis(now,j);
            }
            ans=min(ans,cnt);
        }
        printf("%lld\n",ans);
    }
    return 0;
}