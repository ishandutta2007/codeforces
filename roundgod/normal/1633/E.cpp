#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define MAXM 305
#define MAXK 300005
#define MAXQ 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int u,v,cost,id;};
bool cmp(const edge &e1,const edge &e2)
{
	if(e1.cost==e2.cost) return e1.id<e2.id;
    return e1.cost<e2.cost;
}
edge es[MAXM];
int n,m,p,k,a,b,c;
int fa[MAXN],r[MAXN];
int q[MAXQ];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) fa[x]=y;
    else
    {
        fa[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<int> kruskal(int x)
{
	vector<edge> edges;
	for(int i=0;i<m;i++) 
	{
		edge e=es[i];
		e.cost=max(e.cost-x,x-e.cost);
		edges.push_back(e);
	}
    sort(edges.begin(),edges.end(),cmp);
    init(n);
    vector<int> ans;
    for(int i=0;i<m;i++)
    {
        edge e=edges[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            ans.push_back(e.id);
        }
    }
    return ans;
}
map<vector<int>,int> id;
int lb[MAXK],rb[MAXK],tot;
vector<int> save[MAXK];
int get_id(vector<int> &ans)
{
	if(id.find(ans)==id.end()) {id[ans]=++tot; lb[tot]=INF; rb[tot]=-INF; save[tot]=ans;}
	return id[ans]; 
}
void solve(int l,int r,vector<int> &lans,vector<int> &rans)
{
	if(l>r) return;
	if(lans==rans) 
	{
		int id=get_id(lans);
		lb[id]=min(lb[id],l); rb[id]=max(rb[id],r);
		return;
	}
	if(r-l==1)
	{
		int lid=get_id(lans); int rid=get_id(rans);
		lb[lid]=min(lb[lid],l); rb[lid]=max(rb[lid],l);
		lb[rid]=min(lb[rid],r); rb[rid]=max(rb[lid],r);
		return;
	}
	int mid=(l+r)/2;
	vector<int> tmp=kruskal(mid);
	solve(l,mid,lans,tmp); solve(mid,r,tmp,rans);
}
vector<P> tmp;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
		es[i].id=i;
	}
	scanf("%d%d%d%d%d",&p,&k,&a,&b,&c);
	vector<int> lans=kruskal(0);
	vector<int> rans=kruskal(c-1);
	tot=0;
	solve(0,c-1,lans,rans);
	for(int i=1;i<=tot;i++)
	{
		tmp.push_back(P(rb[i],i));
	}
	sort(tmp.begin(),tmp.end());
	ll ans=0;
	for(int i=1;i<=p;i++)
	{
		scanf("%d",&q[i]);
		int pos=lower_bound(tmp.begin(),tmp.end(),P(q[i],0))-tmp.begin();
		ll res=0;
		for(int id:save[tmp[pos].S]) res+=max(es[id].cost-q[i],q[i]-es[id].cost);
		ans^=res;
	}
	int last=q[p];
	for(int i=p+1;i<=k;i++)
	{
		int now=(1LL*last*a+b)%c;
		int pos=lower_bound(tmp.begin(),tmp.end(),P(now,0))-tmp.begin();
		ll res=0;
		for(int id:save[tmp[pos].S]) res+=max(es[id].cost-now,now-es[id].cost);
		ans^=res;
		last=now;
	}
	printf("%lld\n",ans);
	return 0;
}