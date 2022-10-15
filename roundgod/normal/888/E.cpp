#include<bits/stdc++.h>
#define MAXN 40
using namespace std;
typedef long long ll;
ll n,m;
ll a[MAXN];
set<ll> s1,s2;
int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    ll n2=n/2;
    for(ll i=0;i<1<<n2;i++)
    {
        ll s=0;
        for(ll j=0;j<n2;j++)
            if(i>>j&1) s=(s+a[j])%m;
        s1.insert(s);
    }
    for(ll i=0;i<1<<(n-n2);i++)
    {
        ll s=0;
        for(ll j=0;j<n-n2;j++)
            if(i>>j&1) s=(s+a[n2+j])%m;
        s2.insert(s);
    }
    s2.insert(m);
    ll ans=0;
    for(auto i=s1.begin();i!=s1.end();i++)
    {
        ll x=*i;
        auto p=s2.upper_bound(m-x-1);
        if(p==s2.begin()) {ans=max(ans,x); continue;}
        p--;
        ans=max(ans,x+*p);
    }
    printf("%I64d\n",ans);
    return 0;
}