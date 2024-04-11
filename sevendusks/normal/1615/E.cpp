 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,k,L[N],R[N],cnt,tr[N],fa[N],vi[N];
vector <int> e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
namespace seg//min
{
	int tag[N*4];
	pair<int,int> MAX[N*4];
	inline void pushup(int x){MAX[x]=max(MAX[ls],MAX[rs]);}
	void pushdown(int x)
	{
		if (!tag[x])return;
		tag[ls]+=tag[x];tag[rs]+=tag[x];
		MAX[ls].first+=tag[x];MAX[rs].first+=tag[x];
		tag[x]=0;
	}
	void build(int x,int l,int r)
	{
		tag[x]=0;
		if (l==r){MAX[x]=m_k(0,l);return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r){tag[x]+=v,MAX[x].first+=v;return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	pair<int,int> query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r)return MAX[x];
		int mid=(l+r)>>1;pushdown(x);pair<int,int> ans=m_k(-inf,-inf);
		if (ll<=mid) ans=max(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ans=max(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
}
void dfs(int x,int father)
{
	fa[x]=father;
	if (x!=1) e[x].erase(find(e[x].begin(),e[x].end(),fa[x]));
	if (len(e[x])==0)
	{
		L[x]=R[x]=++cnt;tr[cnt]=x;
		return;
	}
	L[x]=inf;
	for (int u:e[x]) dfs(u,x),L[x]=min(L[x],L[u]);
	R[x]=cnt;
}
int f(int a)
{
	a=min(a,n/2);
	return a*a-n*a;
}
signed main()
{
	n=read();k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs(1,0);
	seg::build(1,1,cnt);
	for (int i=1;i<=n;i++) seg::change(1,1,cnt,L[i],R[i],1);
	int ans=-inf,lim=min(k,cnt),now=0;
	for (int i=1;i<=lim;i++)
	{
		now+=seg::MAX[1].first;
		int x=tr[seg::MAX[1].second];
		while (!vi[x]&&x)
		{
			seg::change(1,1,cnt,L[x],R[x],-1);vi[x]=1;
			x=fa[x];
		}
		ans=max(ans,f(n-now)+i*(n-i));
	}
	for (int i=lim+1;i<=k;i++) ans=max(ans,f(n-now)+i*(n-i));
	printf("%lld\n",ans);
}