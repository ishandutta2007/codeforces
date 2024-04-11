/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 23:09:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],b[MAXN];
ll suma[MAXN],sumb[MAXN],proga[MAXN],progb[MAXN];
int main()
{
    scanf("%lld",&n);
    ll sum=0;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
    for(ll i=1;i<=n;i++) scanf("%lld",&b[i]),sum+=b[i];
    for(ll i=n;i>=1;i--) suma[i]=a[i]+suma[i+1];
    for(ll i=n;i>=1;i--) sumb[i]=b[i]+sumb[i+1];
    for(ll i=n;i>=1;i--) proga[i]=suma[i]+proga[i+1];
    for(ll i=n;i>=1;i--) progb[i]=sumb[i]+progb[i+1];
    ll ans=0,res=0,t=0;
    for(int i=1;i<=n;i++)
    {
        if(i&1) 
        {
            ans=max(ans,res+proga[i]+(i-1)*2*suma[i]+(n-i+2)*sumb[i]-progb[i]+(i-1+n)*sumb[i]);
            //printf("%lld\n",res+proga[i]+(i-1)*2*suma[i]+(n-i+2)*sumb[i]-progb[i]+(i-1+n)*sumb[i]);
            t++;
            res+=t*a[i];
            ans=max(ans,res+progb[i]+(i*2-1)*sumb[i]+(n-i+1)*suma[i+1]-proga[i+1]+(i+n)*suma[i+1]);
            //printf("%lld\n",res+progb[i]+(i*2-1)*sumb[i]+(n-i+1)*suma[i+1]-proga[i+1]+(i+n)*suma[i+1]);
            t++;
            res+=t*b[i];
        }
        else
        {
            ans=max(ans,res+progb[i]+(i-1)*2*sumb[i]+(n-i+2)*suma[i]-proga[i]+(i-1+n)*suma[i]);
            //printf("%lld\n",res+progb[i]+(i-1)*2*sumb[i]+(n-i+2)*suma[i]-proga[i]+(i-1+n)*suma[i]);
            t++;
            res+=t*b[i];
            ans=max(ans,res+proga[i]+(i*2-1)*suma[i]+(n-i+1)*sumb[i+1]-progb[i+1]+(i+n)*sumb[i+1]);
            //printf("%lld\n",res+proga[i]+(i*2-1)*suma[i]+(n-i+1)*sumb[i+1]-progb[i+1]+(i+n)*sumb[i+1]);
            t++;
            res+=t*a[i];
        }
    }
    printf("%lld\n",ans-sum);
    return 0;
}