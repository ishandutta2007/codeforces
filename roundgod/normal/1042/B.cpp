/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-17 16:11:23
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
ll n,k,a[MAXN];
ll minx[8];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=7;i++) minx[i]=INF;
    for(ll i=1;i<=n;i++)
    {
        ll x;string str;
        scanf("%lld",&x);cin>>str;
        if(str=="A") minx[1]=min(minx[1],x);
        if(str=="B") minx[2]=min(minx[2],x);
        if(str=="C") minx[3]=min(minx[3],x);
        if(str=="AB"||str=="BA") minx[4]=min(minx[4],x);
        if(str=="AC"||str=="CA") minx[5]=min(minx[5],x);
        if(str=="BC"||str=="CB") minx[6]=min(minx[6],x);
        if(str=="ABC"||str=="ACB"||str=="BAC"||str=="BCA"||str=="CAB"||str=="CBA") minx[7]=min(minx[7],x);
    }
    ll ans=INF;
    ans=min(ans,minx[7]);
    ans=min(ans,minx[1]+minx[6]);ans=min(ans,minx[2]+minx[5]);ans=min(ans,minx[3]+minx[4]);
    ans=min(ans,minx[4]+minx[5]);ans=min(ans,minx[4]+minx[6]);ans=min(ans,minx[5]+minx[6]);
    ans=min(ans,minx[1]+minx[2]+minx[3]);
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}