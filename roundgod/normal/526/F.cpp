/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 16:25:22
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
ll n,k,a[MAXN];
struct segtree
{
    ll val[4*MAXN],lazy[4*MAXN],cnt[4*MAXN];
    void Lazy(ll k)
    {
        lazy[k*2]+=lazy[k];lazy[k*2+1]+=lazy[k];
        val[k*2]+=lazy[k];val[k*2+1]+=lazy[k];
        lazy[k]=0;
    }
    void build(ll k,ll l,ll r)
    {
        lazy[k]=0;
        if(l==r) {val[k]=l; cnt[k]=1; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        merge(k);
    }
    void merge(ll k)
    {
        if(val[k*2]>val[k*2+1])
        {
            val[k]=val[k*2+1];cnt[k]=cnt[k*2+1];
        }
        else if(val[k*2]<val[k*2+1])
        {
            val[k]=val[k*2];cnt[k]=cnt[k*2];
        }
        else {val[k]=val[k*2];cnt[k]=cnt[k*2]+cnt[k*2+1];}
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            val[k]+=v;
            lazy[k]+=v;
            return;
        }
        Lazy(k);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v);update(k*2+1,mid+1,r,x,y,v);
        merge(k);
    }
    void add(ll l,ll r,ll v)
    {
        update(1,1,n,l,r,v);
    }
    P query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return P(INF,0);
        if(l>=x&&r<=y) return P(val[k],cnt[k]);
        Lazy(k);
        ll mid=(l+r)/2;
        P p=query(k*2,l,mid,x,y);P q=query(k*2+1,mid+1,r,x,y);
        if(p.F>q.F) swap(p,q);
        if(p.F==q.F) return P(p.F,p.S+q.S);
        return p;
    }
}seg;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        a[x]=y;
    }
    P st1[MAXN],st2[MAXN];
    ll t1=0,t2=0,ans=0;
    seg.build(1,1,n);
    for(ll i=1;i<=n;i++)
    {
        ll now=i;
        while(t1>0&&st1[t1-1].F<a[i])
        {
            seg.add(st1[t1-1].S,now-1,a[i]-st1[t1-1].F);
            now=st1[t1-1].S;
            t1--;
        }
        st1[t1++]=P(a[i],now);
        now=i;
        while(t2>0&&st2[t2-1].F>a[i])
        {
            seg.add(st2[t2-1].S,now-1,st2[t2-1].F-a[i]);
            now=st2[t2-1].S;
            t2--;
        }
        st2[t2++]=P(a[i],now);
        P p=seg.query(1,1,n,1,i); 
        ans+=p.S;
    }
    printf("%lld\n",ans);
    return 0;
}