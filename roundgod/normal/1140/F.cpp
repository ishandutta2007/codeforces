#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,q,x[MAXN],y[MAXN],xcnt[MAXN],ycnt[MAXN];
vector<P> edges[4*MAXN];
bool ask[MAXN];
ll p[MAXN],r[MAXN],sz[MAXN];
ll ans[MAXN];
ll num;
struct update
{
    ll x,y;
    bool addrk;
};
update st[MAXN];
ll t;
void init(ll n)
{
    for(ll i=1;i<=2*n;i++)
    {
        p[i]=i;
        r[i]=0;
        xcnt[i]=(i<=n); ycnt[i]=(i>n);
    }
}
ll find(ll x)
{
   while(p[x]!=x) x=p[x];
   return x;
}
bool unite(ll x,ll y)
{
    //printf("unite %lld %lld\n",x,y);
    x=find(x);
    y=find(y);
    if(x==y) return false;
    num-=xcnt[x]*ycnt[x]; num-=xcnt[y]*ycnt[y];
    if(r[x]<r[y]) 
    {
        p[x]=y;  xcnt[y]+=xcnt[x]; ycnt[y]+=ycnt[x]; num+=xcnt[y]*ycnt[y];
        st[t++]=(update){x,y,false};
    }
    else
    {
        p[y]=x; xcnt[x]+=xcnt[y]; ycnt[x]+=ycnt[y]; num+=xcnt[x]*ycnt[x];
        st[t++]=(update){y,x,r[x]==r[y]};
        if(r[x]==r[y]) r[x]++;
    }
    //printf("num=%lld\n",num);
    return true;
}
void undo()
{
    assert(t);
    ll x=st[t-1].x,y=st[t-1].y;
    //printf("undo %lld %lld %lld\n",x,y,st[t-1].addrk);
    num-=xcnt[y]*ycnt[y];
    xcnt[y]-=xcnt[x]; ycnt[y]-=ycnt[x];
    num+=xcnt[y]*ycnt[y]; num+=xcnt[x]*ycnt[x];
    p[x]=x;p[y]=y;
    if(st[t-1].addrk) r[y]--;
    t--;
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
void add_edge(ll k,ll l,ll r,ll x,ll y,ll u,ll v)
{
    if(x>r||l>y) return;
    if(l>=x&&r<=y)
    {
        edges[k].push_back(P(u,v));
        return;
    }
    ll mid=(l+r)/2;
    add_edge(k*2,l,mid,x,y,u,v);add_edge(k*2+1,mid+1,r,x,y,u,v);
}
void solve(ll k,ll l,ll r)
{
    if(l>r) return;
    ll cnt=0;
    for(auto e:edges[k]) if(unite(e.F,e.S)) cnt++;  
    if(l==r)
    {
        ans[l]=num;
        for(ll i=0;i<cnt;i++) undo();
        return;
    }
    ll mid=(l+r)/2;
    solve(k*2,l,mid);solve(k*2+1,mid+1,r);
    //printf("cnt %lld %lld %lld\n",l,r,cnt);
    for(ll i=0;i<cnt;i++) undo();
}
map<P,int> mp;
vector<int> xx,yy;
int main()
{
    scanf("%lld",&n);num=0;init(n);
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld%lld",&x[i],&y[i]);
        xx.push_back(x[i]);yy.push_back(y[i]);
    }
    sort(xx.begin(),xx.end());sort(yy.begin(),yy.end());
    xx.erase(unique(xx.begin(),xx.end()),xx.end()); yy.erase(unique(yy.begin(),yy.end()),yy.end());
    for(ll i=1;i<=n;i++)
    {
        x[i]=lower_bound(xx.begin(),xx.end(),x[i])-xx.begin()+1;
        y[i]=lower_bound(yy.begin(),yy.end(),y[i])-yy.begin()+1;
    }
    for(ll i=1;i<=n;i++)
    {
        if(mp[P(x[i],y[i]+n)]<=0) mp[P(x[i],y[i]+n)]=i;
        else
        {
            add_edge(1,1,n,mp[P(x[i],y[i]+n)],i-1,x[i],y[i]+n);
            mp[P(x[i],y[i]+n)]=-1;
        }
    }
    for(auto p:mp) if(p.S!=-1) add_edge(1,1,n,p.S,n,p.F.F,p.F.S);
    solve(1,1,n);
    for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}