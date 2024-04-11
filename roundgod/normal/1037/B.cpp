/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 22:36:35
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
ll n,s,a[MAXN];
int main()
{
    scanf("%lld%lld",&n,&s);
    for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    ll ans=max(a[n/2]-s,s-a[n/2]);
    for(ll i=0;i<n/2;i++)
    {
        if(a[i]>s) ans+=a[i]-s;
    }
    for(ll i=n/2+1;i<n;i++)
    {
        if(a[i]<s) ans+=s-a[i];
    }
    printf("%lld\n",ans);
    return 0;
}