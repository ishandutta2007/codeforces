/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-23 22:03:04
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
ll n,q,a[MAXN],p[MAXN];
ll _mod(ll x) {return x>=MOD?x-MOD:x;}
struct segtree
{
    ll sum[4*MAXN];
    ll sum2[4*MAXN],sum3[4*MAXN];
    void pushup(ll k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
        sum2[k]=_mod(sum2[k*2]+sum2[k*2+1]);
        sum3[k]=_mod(sum3[k*2]+sum3[k*2+1]);
    }
    void build(ll k,ll l,ll r)
    {
        if(l==r) {sum[k]=a[l]; sum2[k]=1LL*a[l]*p[l]%MOD; sum3[k]=1LL*l*a[l]%MOD; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(ll k,ll l,ll r,ll pos,ll v)
    {
        if(l==r)
        {
            sum[k]=v;
            sum2[k]=1LL*v*p[l]%MOD;
            sum3[k]=1LL*v*l%MOD;
            return;
        }
        ll mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    ll query1(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return sum[k];
        ll mid=(l+r)/2;
        return query1(k*2,l,mid,x,y)+query1(k*2+1,mid+1,r,x,y);
    }
    ll find(ll k,ll l,ll r,ll s)
    {
        if(l==r) return l;
        ll mid=(l+r)/2;
        if(sum[k*2]<=s) return find(k*2+1,mid+1,r,s-sum[k*2]);
        return find(k*2,l,mid,s);
    }
    ll query2(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return sum2[k];
        ll mid=(l+r)/2;
        return _mod(query2(k*2,l,mid,x,y)+query2(k*2+1,mid+1,r,x,y));
    }
    ll query3(ll k,ll l,ll r,ll x,ll y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return sum3[k];
        ll mid=(l+r)/2;
        return _mod(query3(k*2,l,mid,x,y)+query3(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++) scanf("%lld",&p[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    seg.build(1,1,n);
    ll l,r;
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld",&l,&r);
        if(l<0) seg.update(1,1,n,-l,r);
        else
        {
            ll A=seg.query1(1,1,n,1,l-1),B=seg.query1(1,1,n,l,r),s=A+B/2;
            ll pos=seg.find(1,1,n,s);
            ll ans=0;
            ans=(1LL*(p[pos]-pos)*(seg.query1(1,1,n,l,pos-1)%MOD)+seg.query3(1,1,n,l,pos-1)-seg.query2(1,1,n,l,pos-1)+MOD)%MOD;
            ans=(ans+seg.query2(1,1,n,pos+1,r)+1LL*(pos-p[pos])*(seg.query1(1,1,n,pos+1,r)%MOD)%MOD-seg.query3(1,1,n,pos+1,r)+MOD)%MOD;
            if(ans<0) ans+=MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}