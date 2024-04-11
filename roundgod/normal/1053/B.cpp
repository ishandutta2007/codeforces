/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-23 21:09:18
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],even[MAXN],odd[MAXN],sum[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        ll t=0;
        for(ll j=0;j<60;j++) 
            if((a[i]>>j)&1) t++;
        a[i]=t;
    }
    even[0]=odd[0]=sum[0]=0;
    int s=0;
    for(ll i=1;i<=n;i++)
    {
        even[i]=even[i-1];
        odd[i]=odd[i-1];
        sum[i]=a[i]+sum[i-1];
        s+=a[i];
        if(s&1) odd[i]++; else even[i]++;
    }
    ll ans=0,cursum=0;
    for(ll i=1;i<=n;i++)
    {
        ll mx=a[i],curs=a[i];
        for(int j=i+1;j<=min(n,i+140);j++)
        {
            curs+=a[j];
            mx=max(mx,a[j]);
            if(2*mx<=curs&&curs%2==0) ans++; 
        }
        if(cursum&1) ans+=odd[n]-odd[min(n,i+140)];
        else ans+=even[n]-even[min(n,i+140)];
        cursum+=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}