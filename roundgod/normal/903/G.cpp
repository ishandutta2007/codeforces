#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
int a[MAXN],b[MAXN];
ll c[MAXN];
vector<P> edges[MAXN];
struct segtree
{
	ll mini[4*MAXN],lazy[4*MAXN];
	void pushup(int k)
	{
		mini[k]=min(mini[k*2],mini[k*2+1]);
	}
	void add(int k,ll v)
	{
		mini[k]+=v; lazy[k]+=v;
	}
	void pushdown(int k)
	{
		if(!lazy[k]) return;
		for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
		lazy[k]=0;
	}
	void build(int k,int l,int r)
	{
		lazy[k]=0;
		if(l==r)
		{
			mini[k]=b[l-1];
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid); build(k*2+1,mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int x,int y,int v)
	{
		if(x>r||l>y) return;
		if(l>=x&&r<=y) {add(k,v); return;}
		pushdown(k);
		int mid=(l+r)/2;
		update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
		pushup(k);
	}
}seg;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n-1;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edges[x].push_back(P(y,z));
	}
	seg.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		for(auto p:edges[i]) seg.update(1,1,n,1,p.F,p.S);
		c[i]=seg.mini[1];
	}
	multiset<ll> ms;
	for(int i=1;i<=n;i++) ms.insert(a[i]+c[i]);
	printf("%lld\n",*ms.begin());
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ms.erase(ms.find(a[x]+c[x]));
		a[x]=y;
		ms.insert(a[x]+c[x]);
		printf("%lld\n",*ms.begin());
	}
	return 0;
}