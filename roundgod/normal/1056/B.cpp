/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 16:04:24
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
ll n,m;
ll a[MAXN],cnt[MAXN];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++)
        a[i]=(n+m-i)/m;
    ll ans=0;
    for(ll i=1;i<=m;i++) 
    {
        for(ll j=1;j<=m;j++)
        {
            if((i*i+j*j)%m==0) ans+=a[i]*a[j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}