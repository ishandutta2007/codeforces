/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 22:52:10
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
ll n,m,a[MAXN],b[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%lld",&m);
    for(ll i=1;i<=m;i++) scanf("%lld",&b[i]);
    ll t1=1,t2=1,cnt=0;
    bool f=true;
    while(t1<=n&&t2<=m)
    {
        ll sum1=a[t1],sum2=b[t2];
        while(sum1!=sum2&&t1<=n&&t2<=m)
        {
            if(sum1<sum2) t1++,sum1+=a[t1];
            else t2++,sum2+=b[t2];
        }
        if(sum1!=sum2) {f=false; break;}
        cnt++;
        t1++;t2++;
    }
    if(t1<=n||t2<=m) f=false;
    if(!f) puts("-1"); else printf("%lld\n",cnt);
    return 0;
}