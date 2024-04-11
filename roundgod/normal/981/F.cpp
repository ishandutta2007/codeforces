/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 20:43:54
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,L,k,a[MAXN],b[MAXN];
bool C(ll x)
{
    int lb=-1,rb=4*n,cur_lb=0,cur_rb=0;
    for(ll i=0;i<n;i++)
    {
        while(b[cur_lb]<a[i]-x) cur_lb++;
        while(b[cur_rb]<=a[i]+x) cur_rb++;
        lb=max(lb+1,cur_lb);
        rb=min(rb+1,cur_rb);
    }
    return lb<rb;
}
int main()
{
    scanf("%I64d%I64d",&n,&L);
    for(ll i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]+=L;
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&b[i]);
    sort(b,b+n);
    for(ll i=0;i<n;i++)
    {
        b[n+i]=b[i]+L;
        b[2*n+i]=b[i]+2*L;
    }
    b[n*3]=4LL*L;
    ll l=-1,r=L;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%I64d\n",r);
    return 0;
}