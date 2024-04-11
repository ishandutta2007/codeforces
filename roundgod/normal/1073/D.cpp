/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 22:54:36
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
ll n,a[MAXN],T;
struct segtree
{
    ll sum[4*MAXN],cnt[4*MAXN];
    void pushup(ll k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
        cnt[k]=cnt[k*2]+cnt[k*2+1];
    }
    void build(ll k,ll l,ll r)
    {
        if(l==r) {cnt[k]=1; sum[k]=a[l]; return;}
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void del(ll k,ll l,ll r,ll p)
    {
        if(l==r) {cnt[k]=0; sum[k]=0; return;}
        ll mid=(l+r)/2;
        if(p<=mid) del(k*2,l,mid,p); else del(k*2+1,mid+1,r,p);
        pushup(k);
    }
    ll query_sum(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        ll mid=(l+r)/2;
        return query_sum(k*2,l,mid,x,y)+query_sum(k*2+1,mid+1,r,x,y);
    }
    ll query_cnt(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return cnt[k];
        ll mid=(l+r)/2;
        return query_cnt(k*2,l,mid,x,y)+query_cnt(k*2+1,mid+1,r,x,y);
    }
    ll find(ll k,ll l,ll r,ll cur)
    {
        if(l==r) return l;
        ll mid=(l+r)/2;
        if(sum[k*2]>cur) return find(k*2,l,mid,cur);
        else return find(k*2+1,mid+1,r,cur-sum[k*2]);
    }
}seg;
int main()
{
    scanf("%lld%lld",&n,&T);
    ll cnt=n,sum=0,ans=0,pos=1;
    for(ll i=1;i<=n;i++) {scanf("%lld",&a[i]); sum+=a[i];}
    seg.build(1,1,n);
    while(sum>0)
    {
        ans+=(T/sum)*cnt;T%=sum;
        if(T==0) break;
        if(seg.query_sum(1,1,n,pos,n)<=T) {T-=seg.query_sum(1,1,n,pos,n); ans+=seg.query_cnt(1,1,n,pos,n); pos=1;}
        ll has=T+seg.query_sum(1,1,n,1,pos-1);
        ll to=seg.find(1,1,n,has);to--;
        ans+=seg.query_cnt(1,1,n,pos,to);T-=seg.query_sum(1,1,n,pos,to);pos=to+1;
        seg.del(1,1,n,to+1);cnt--;sum-=a[to+1];
    }
    printf("%lld\n",ans);
    return 0;
}