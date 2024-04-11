/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 23:36:29
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define y1 NJU_ACM_gisp_zjz
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,x1[MAXN],y1[MAXN],x2[MAXN],y2[MAXN];
set<P> s;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld%lld%lld",&x1[i],&y1[i],&x2[i],&y2[i]);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll x=max(x1[i]-x2[i],x2[i]-x1[i]);
        ll y=max(y1[i]-y2[i],y2[i]-y1[i]);
        if(x==0&&y==0) ans+=1; else ans+=__gcd(x,y)+1;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            ll a1=y2[i]-y1[i],b1=x2[i]-x1[i];
            ll c1=b1*y1[i]-a1*x1[i];
            ll a2=y2[j]-y1[j],b2=x2[j]-x1[j];
            ll c2=b2*y1[j]-a2*x1[j];
            ll p1=b1*c2-b2*c1,q1=a1*c2-a2*c1;
            ll d=a1*b2-a2*b1;
            if(d==0) continue;
            if(p1%d||q1%d) continue;
            if(p1/d<min(x1[i],x2[i])||p1/d>max(x1[i],x2[i])||p1/d<min(x1[j],x2[j])||p1/d>max(x1[j],x2[j])) continue;
            if(q1/d<min(y1[i],y2[i])||q1/d>max(y1[i],y2[i])||q1/d<min(y1[j],y2[j])||q1/d>max(y1[j],y2[j])) continue;
            s.insert(P(p1/d,q1/d));
        }
    }
    for(auto it:s) 
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int X1=it.F-x1[i],Y1=it.S-y1[i];
            int X2=x2[i]-x1[i],Y2=y2[i]-y1[i];
            if(X1*Y2!=Y1*X2) continue;
            if(it.F<min(x1[i],x2[i])||it.F>max(x1[i],x2[i])) continue;
            if(it.S<min(y1[i],y2[i])||it.S>max(y1[i],y2[i])) continue;
            cnt++;
        }
        ans-=cnt-1;
    }
    printf("%lld\n",ans);
    return 0;
}