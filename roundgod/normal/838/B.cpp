#include<bits/stdc++.h>
#define MAXN 400005
#define MAXQ 400005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,t;
vector<ll> G[MAXN];
ll d[MAXN],f[MAXN],x[MAXN],y[MAXN],w[MAXN],cost[MAXN],num[MAXN];
bool vis[MAXN];
void dfs(ll v)
{
	d[v]=++t;
	vis[v]=true;
	for(ll i=0;i<G[v].size();i++)
	{
		ll to=G[v][i];
		if(!vis[to]) dfs(to);
	}
	f[v]=t;
}
struct node
{
    ll l,r,ans,lazy;
    void update(ll x)
   	{
   		ans+=x;
   		lazy+=x;
   	}
}seg[4*MAXN];
void build(ll k,ll l,ll r)
{
    seg[k].l=l;
    seg[k].r=r;
    seg[k].lazy=seg[k].ans=0;
    if(l==r) return;
    ll mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
void Lazy(ll k)
{
    ll res=seg[k].lazy;
    seg[k].lazy=0;
    if(seg[k].l==seg[k].r) return;
    seg[k*2].update(res);
    seg[k*2+1].update(res);
}
void update(ll k,ll l,ll r,ll val) 
{
    if(l>seg[k].r||r<seg[k].l) return;
    if(l<=seg[k].l&&r>=seg[k].r) 
    {
        seg[k].update(val);
        return;
    }
    if(seg[k].lazy) Lazy(k);
    update(k*2,l,r,val);
    update(k*2+1,l,r,val);
    seg[k].ans=min(seg[k*2].ans,seg[k*2+1].ans);
}
ll query(ll k,ll l,ll r) 
{
    if(l>seg[k].r||r<seg[k].l) return INF;
    if (l<=seg[k].l&&r>=seg[k].r) return seg[k].ans;
    if(seg[k].lazy) Lazy(k);
    ll res=min(query(k*2,l,r),query(k*2+1,l,r));
    seg[k].ans=min(seg[k*2].ans,seg[k*2+1].ans);
    return res;
}
int main()
{
    scanf("%I64d%I64d",&n,&q);
    for(ll i=1;i<=n-1;i++)
    {
    	scanf("%I64d%I64d%I64d",&x[i],&y[i],&w[i]);
    	G[x[i]].push_back(y[i]);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    build(1,1,n);
    for(ll i=n;i<=2*(n-1);i++)
    {
    	scanf("%I64d%I64d%I64d",&x[i],&y[i],&w[i]);
    	cost[x[i]]=w[i];
    	update(1,d[x[i]],d[x[i]],w[i]);
    }
    for(ll i=1;i<=n-1;i++)
    	update(1,d[y[i]],f[y[i]],w[i]);
    for(ll i=0;i<q;i++)
    {
    	ll type,a,b;
    	scanf("%I64d%I64d%I64d",&type,&a,&b);
    	if(type==1)
    	{
    		if(a<=n-1)
    		{
    			update(1,d[y[a]],f[y[a]],b-w[a]);
    			w[a]=b;
    		}
    		else
    		{
    			update(1,d[x[a]],d[x[a]],b-cost[x[a]]);
    			cost[x[a]]=b;
    		}
    	}
    	else
    	{
    		if(d[a]<=d[b]&&f[a]>=f[b]) printf("%I64d\n",query(1,d[b],d[b])-query(1,d[a],d[a])-cost[b]+cost[a]);
    		else printf("%I64d\n",query(1,d[b],d[b])-cost[b]+query(1,d[a],f[a])-query(1,d[a],d[a])+cost[a]);
    	}
    }
    return 0;
}