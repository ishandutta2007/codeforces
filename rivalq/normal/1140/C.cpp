#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
const int N=300005;
struct node
{
    ll sum;
    ll cnt;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=a.sum+b.sum;
        ret.cnt=a.cnt+b.cnt;
        return ret;
    }
    inline node make_node(ll val,ll x=0)
    {
        node ret;
        ret.sum=val;
        ret.cnt=x;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].sum+=(en-st+1)*lazy[v];
        if(st!=en)
        {
            lazy[v<<1]+=lazy[v];
            lazy[v<<1 | 1]+=lazy[v];
        }
        lazy[v]=0;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val,ll x)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val,x);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val,x);
        else
            update(v<<1 | 1,mid+1,en,in,val,x);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    ll query(ll v,ll st,ll en,ll k)
    {
        if(tree[v].cnt<k)
            return tree[v].sum;
        if(st==en)
            return tree[v].sum;
        ll mid=(st+en)>>1;
        if(tree[v<<1].cnt>=k)
            return query(v<<1,st,mid,k);
        else
            return tree[v<<1].sum+query(v<<1 |1,mid+1,en,k-tree[v<<1].cnt);
    }
}seg;

pair<ll,pll> p[N];

int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    seg.buildTree(1,0,n-1);

    for(int i=0;i<n;++i)
    {   
        cin>>p[i].S.F>>p[i].S.S;
        p[i].F=i;
    }
    map<pll,int> m;
    sort(p,p+n,[&](pair<ll,pll> a,pair<ll,pll> b){return a.S.F>b.S.F;});
    for(int i=0;i<n;++i)
    {
        m[{p[i].S.F,p[i].F}]=i;
        seg.update(1,0,n-1,i,p[i].S.F,1);
    }
    sort(p,p+n,[&](pair<ll,pll> a,pair<ll,pll> b){return a.S.S<b.S.S;});
    ll ans=-INF;
    for(int i=0;i<n;++i)
    {
        amax(ans,seg.query(1,0,n-1,k)*p[i].S.S);
        seg.update(1,0,n-1,m[{p[i].S.F,p[i].F}],0,0);
    }
    cout<<ans;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}