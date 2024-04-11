/*************************************************************************
    > File Name: I.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 16:07:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
ll t,n,l,r;
ull x,y,z,b1,b2;
vector<ll> v;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        v.clear();
        ll ans=LONG_LONG_MAX;
        scanf("%lld%lld%lld%llu%llu%llu%llu%llu",&n,&l,&r,&x,&y,&z,&b1,&b2);
        ll rg=r-l+1;
        ll a1,a2,minx;
        a1=(ll)b1%rg+l;a2=(ll)b2%rg+l;
        if(a1<0) v.push_back(-a1);
        if(a2<0) v.push_back(-a2);
        if(a2>a1) ans=min(ans,a2*a1);
        minx=min(a1,a2);
        for(ll i=3;i<=n;i++)
        {
            ll b3=(b1*x+b2*y+z)%(1LL<<32);
            b1=b2;b2=b3;
            ll a3=(ll)b3%rg+l;
            //ll a3;scanf("%lld",&a3);
            if(a3<0) v.push_back(-a3);
            if(a3>minx) ans=min(ans,1LL*a3*minx);
            minx=min(minx,a3);
        }
        if(v.size()>=2)
        {
            int sz=(int)v.size();
            minx=min(v[sz-1],v[sz-2]);
            if(v[sz-2]>v[sz-1]) ans=min(ans,v[sz-1]*v[sz-2]);
            for(int i=sz-3;i>=0;i--) 
            {
                if(v[i]>minx) ans=min(ans,1LL*v[i]*minx);
                minx=min(minx,v[i]);
            }
        }
        if(ans==LONG_LONG_MAX) puts("IMPOSSIBLE"); else printf("%lld\n",ans);
    }
    return 0;
}