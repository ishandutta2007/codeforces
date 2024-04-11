/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 21:49:34
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,q;
set<P> s[MAXN];
struct node
{
    ll l,r,sum,lazy1,lazy2;
}seg[4*MAXN];
ll _mod(ll x)
{
    if(x<0) x+=MOD;
    return x>=MOD?x-MOD:x;
}
void Lazy(ll k)
{
    if(seg[k].l!=seg[k].r)
    {
        for(ll i=k*2;i<=k*2+1;i++)
        {
            seg[i].sum=seg[i].sum*seg[k].lazy2%MOD;
            seg[i].sum=_mod((seg[i].sum+seg[k].lazy1*(seg[i].r-seg[i].l+1))%MOD);
            seg[i].lazy1=_mod((seg[i].lazy1*seg[k].lazy2+seg[k].lazy1)%MOD);
            seg[i].lazy2=seg[i].lazy2*seg[k].lazy2%MOD;
        }
    }
    seg[k].lazy1=0;seg[k].lazy2=1;
}
void build(ll k,ll l,ll r)
{
    seg[k].l=l;seg[k].r=r;seg[k].lazy1=0;seg[k].lazy2=1;seg[k].sum=0;
    if(l==r) return;
    ll mid=(l+r)/2;
    build(k*2,l,mid);build(k*2+1,mid+1,r);
}
void update1(ll k,ll l,ll r,ll x)
{
    if(seg[k].l>r||seg[k].r<l) return;
    if(seg[k].l>=l&&seg[k].r<=r)
    {
        seg[k].sum=_mod(seg[k].sum+(seg[k].r-seg[k].l+1)*x);
        seg[k].lazy1=_mod(seg[k].lazy1+x);
        return;
    }
    Lazy(k);
    update1(k*2,l,r,x);update1(k*2+1,l,r,x);
    seg[k].sum=_mod(seg[k*2].sum+seg[k*2+1].sum);
}
void update2(ll k,ll l,ll r)
{
    if(seg[k].l>r||seg[k].r<l) return;
    if(seg[k].l>=l&&seg[k].r<=r)
    {
        seg[k].sum=_mod(seg[k].sum*2);
        seg[k].lazy1=_mod(seg[k].lazy1*2);
        seg[k].lazy2=_mod(seg[k].lazy2*2);
        return;
    }
    Lazy(k);
    update2(k*2,l,r);update2(k*2+1,l,r);
    seg[k].sum=_mod(seg[k*2].sum+seg[k*2+1].sum);
}
ll query(ll k,ll l,ll r)
{
    if(seg[k].l>r||seg[k].r<l) return 0;
    if(seg[k].l>=l&&seg[k].r<=r) return seg[k].sum;
    Lazy(k);
    return _mod(query(k*2,l,r)+query(k*2+1,l,r));
}
void process(ll x,ll l,ll r)
{
    ll lb=l,rb=r;
    for(auto it=s[x].begin();it!=s[x].end();)
    {
        ll lx=max((*it).F,l),rx=min((*it).S,r);
        if(rx>=lx)
        {
            update2(1,lx,rx);
            //printf("update2 %d %d\n",lx,rx);
            update1(1,lx,rx,-1);
            //printf("update1 %d %d -1\n",lx,rx);
            lb=min(lb,(*it).F);rb=max(rb,(*it).S);
            it=s[x].erase(it);
        }
        else it++;
    }
   // printf("update1 %d %d 1\n",l,r);
    update1(1,l,r,1);
    s[x].insert(P(lb,rb));
}
int main()
{
    scanf("%lld%lld",&n,&q);
    build(1LL,1LL,n);
    ll type,l,r,x;
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld%lld",&type,&l,&r);
        //printf("%lld %lld %lld\n",type,l,r);
        if(type==1) 
        {
            scanf("%lld",&x);
            process(x,l,r); 
        }
        else printf("%lld\n",query(1,l,r));
    }
    return 0;
}