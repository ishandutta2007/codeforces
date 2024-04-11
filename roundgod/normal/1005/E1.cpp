/*************************************************************************
    > File Name: E1.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 23:38:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN];
map<ll,ll> mp;
int main()
{
    scanf("%lld%lld",&n,&m);
    ll id=-1;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==m) id=i;
    }
    ll ans=0;
    ll cnt=0;
    for(ll i=id;i<=n;i++)
    {
        if(a[i]>a[id]) cnt++;
        if(a[i]<a[id]) cnt--;
        if(mp.find(cnt)==mp.end()) mp[cnt]=1; else mp[cnt]++;
    }
    cnt=0;
    for(ll i=id;i>=1;i--)
    {
        if(a[i]>a[id]) cnt++; 
        if(a[i]<a[id]) cnt--;
        if(mp.find(-cnt)!=mp.end()) ans+=mp[-cnt];
        if(mp.find(-cnt+1)!=mp.end()) ans+=mp[-cnt+1];
    }
    printf("%lld\n",ans);
    return 0;
}