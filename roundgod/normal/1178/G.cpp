#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef long double db;
int n,q,tot,p[MAXN],st[MAXN],ed[MAXN];
vector<int> G[MAXN];
const int blocks=300;
ll a[MAXN],b[MAXN],c[MAXN],d[MAXN],ad[MAXN];
vector<int> order[MAXN];
vector<P> convex_hull[MAXN];
bool need[MAXN];
bool cmp(int x,int y)
{
    return b[x]>b[y];
}
bool check(P x,P y,P z)
{
    return (db)1.0*(z.S-y.S)*(y.F-x.F)<=(db)1.0*(y.S-x.S)*(z.F-y.F);
}
void dfs(int v)
{
    st[v]=++tot;
    for(auto to:G[v])
    {
        b[st[to]]+=b[st[v]];
        a[st[to]]+=a[st[v]];
        dfs(to);
    }
    ed[v]=tot;
}
void dfs2(int v)
{
    for(auto to:G[v])
    {
        b[st[to]]+=b[st[v]];
        a[st[to]]+=a[st[v]];
        dfs2(to);
    }
}
void get_order()
{
    for(int i=1;i<=(n-1)/blocks+1;i++)
    {
        int st=(i-1)*blocks+1,ed=min(n,i*blocks);
        for(int j=st;j<=ed;j++) order[i].push_back(j);
        sort(order[i].begin(),order[i].end(),cmp);
    }
}
void add(int id,P p)
{
    int t=(int)convex_hull[id].size();
    while(t>=2&&check(convex_hull[id][t-2],convex_hull[id][t-1],p))
    {
        convex_hull[id].pop_back();
        t--;
    }
    convex_hull[id].push_back(p);
}
void build(int id)
{
    convex_hull[id].clear();
    int st=(id-1)*blocks+1,ed=min(n,id*blocks);
    if(ad[id])
    {
        for(int j=st;j<=ed;j++)
        {
            c[j]+=b[j]*ad[id];
            d[j]-=b[j]*ad[id];
        }
        ad[id]=0;
    }
    for(int i=0;i<(int)order[id].size();i++)
    {
        P p=P(b[order[id][i]],c[order[id][i]]);
        add(id,p);
    }
    for(int i=(int)order[id].size()-1;i>=0;i--)
    {
        P p=P(-b[order[id][i]],d[order[id][i]]);
        add(id,p);
    }
    int t=(int)convex_hull[id].size();
    while(t>=2&&convex_hull[id][t-1].S<=convex_hull[id][t-2].S)
    {
        convex_hull[id].pop_back();
        t--;
    }
    need[id]=false;
}
ll query_block(int id)
{
    if(need[id]) build(id);
    int t=(int)convex_hull[id].size();
    ll x=ad[id];
    while(t>=2&&convex_hull[id][t-1].F*x+convex_hull[id][t-1].S<=convex_hull[id][t-2].F*x+convex_hull[id][t-2].S)
    {
        convex_hull[id].pop_back();
        t--;
    }
    return convex_hull[id][t-1].F*x+convex_hull[id][t-1].S;
}
ll query(ll l,ll r)
{
    ll ret=0;
    int id=(l-1)/blocks+1;
    while(l<=r&&l%blocks!=1) {ret=max(ret,-b[l]*ad[id]+d[l]); ret=max(ret,b[l]*ad[id]+c[l]); l++;}
    id=(r-1)/blocks+1;
    while(l<=r&&r%blocks!=0) {ret=max(ret,-b[r]*ad[id]+d[r]); ret=max(ret,b[r]*ad[id]+c[r]); r--;}
    while(l<r) {ret=max(ret,query_block((l-1)/blocks+1)); l+=blocks;}
    return ret;
}
void update(ll l,ll r,ll v)
{
    int id=(l-1)/blocks+1;
    while(l<=r&&l%blocks!=1) {d[l]-=v*b[l]; c[l]+=v*b[l]; need[id]=true; l++;}
    id=(r-1)/blocks+1;
    while(l<=r&&r%blocks!=0) {d[r]-=v*b[r]; c[r]+=v*b[r]; need[id]=true; r--;}
    while(l<r) {if(need[(l-1)/blocks+1]) build((l-1)/blocks+1); ad[(l-1)/blocks+1]+=v; l+=blocks;}
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        G[p[i]].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) scanf("%lld",&a[st[i]]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[st[i]]);
    dfs2(1);
    for(int i=1;i<=n;i++)
    {
        b[i]=max(-b[i],b[i]);
        c[i]=b[i]*a[i]; d[i]=-c[i];
        //printf("%d %lld %lld %lld\n",i,b[i],c[i],d[i]);
    }
    get_order();
    for(int i=1;i<=(n-1)/blocks+1;i++) build(i);
    for(int i=0;i<q;i++)
    {
        int type,v,x;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&v,&x);
            update(st[v],ed[v],x);
        }
        else
        {
            scanf("%d",&v);
            printf("%lld\n",query(st[v],ed[v]));
        }
    }
    return 0;
}