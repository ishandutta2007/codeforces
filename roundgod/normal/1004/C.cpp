/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 13:45:40
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
ll n,a[MAXN],l[MAXN],r[MAXN];
ll bit[MAXN+1];
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        if(l[a[i]]==0)
        {
            l[a[i]]=i;
            add(i,1);
        }
    }
    ll ans=0;
    for(ll i=n;i>=1;i--)
    {
        if(r[a[i]]==0)
        {
            r[a[i]]=i;
            ans+=sum(i-1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}