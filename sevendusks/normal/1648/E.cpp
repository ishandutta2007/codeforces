/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=4*1e5+100;
int TT,n,m,cnt,dfn[N],out[N],tr[N],son[N][2],val[N],sz[N],vi[N];
int fa[N][21],de[N],MAX[N][21],ans[N];
struct node
{
	int u,v,w,id;
}sh[N];
vector <int> le[N],ge[N];
vector <pair<int,int> > e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct dsu
{
	int fa[N];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
	void merge(int a,int b)
	{
		a=find(a),b=find(b);
		if (a==b) return;
		fa[a]=b;
	}
}T;
void dfs(int x)
{
	if (x<=n){dfn[x]=out[x]=++cnt,tr[cnt]=x;return;}
	dfs(son[x][0]);dfs(son[x][1]);
	dfn[x]=dfn[son[x][0]];out[x]=out[son[x][1]];
}
void dfs1(int x,int father,int v)
{
	fa[x][0]=father;MAX[x][0]=v;
	for (auto [u,w]:e[x]) if (u!=fa[x][0])
	{
		de[u]=de[x]+1;
		dfs1(u,x,w);
	}
}
int ask(int a,int b)
{
	if (de[a]>de[b]) swap(a,b);
	int ans=0;
	for (int i=20;i>=0;i--) if (de[fa[b][i]]>=de[a]) ans=max(ans,MAX[b][i]),b=fa[b][i];
	if (a==b) return ans;
	for (int i=20;i>=0;i--) if (fa[a][i]!=fa[b][i])
	{
		ans=max({ans,MAX[a][i],MAX[b][i]});
		a=fa[a][i];b=fa[b][i];
	}
	ans=max({ans,MAX[a][0],MAX[b][0]});
	return ans;
}
namespace seg
{
	#define ls x+x
	#define rs x+x+1
	int MIN[N*4],MAX[N*4],tag[N*4],ev;
	void pushup(int x){MIN[x]=min(MIN[ls],MIN[rs]);MAX[x]=max(MAX[ls],MAX[rs]);}
	void pushdown(int x)
	{
		if (tag[x]!=-1)
		{
			MIN[ls]=MIN[rs]=MAX[ls]=MAX[rs]=tag[x];
			tag[ls]=tag[rs]=tag[x];tag[x]=-1;
		}
	}
	void build(int x,int l,int r)
	{
		tag[x]=-1;
		if (l==r){MAX[x]=MIN[x]=tr[l];return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void to(int x,int l,int v)
	{
		if (T.find(v)!=T.find(tr[l]))
		{
			T.merge(tr[l],v);
			// printf("%d %d %d\n",v,tr[l],ev);
			e[v].emplace_back(tr[l],ev);
			e[tr[l]].emplace_back(v,ev);
		}
		MAX[x]=MIN[x]=tag[x]=T.find(tr[l]);
	}
	void upd(int x,int l,int r,int v)
	{
		if (MAX[x]==MIN[x]){to(x,l,v);return;}
		int mid=(l+r)>>1;pushdown(x);
		upd(ls,l,mid,v);upd(rs,mid+1,r,v);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int v)
	{
		if (MAX[x]==MIN[x]){to(x,max(ll,l),v);return;}
		if (ll<=l&&rr>=r){upd(x,l,r,v);return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	#undef ls
	#undef rs
}
signed main()
{
	TT=read();
	while (TT--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) le[i].clear(),ge[i].clear(),e[i].clear();
		for (int i=1;i<=m;i++) sh[i]=(node){read(),read(),read(),i};
		sort(sh+1,sh+1+m,[](node a,node b){return a.w<b.w;});
		T.init(2*n-1);
		for (int i=1,id=n+1;i<=m;i++)
		{
			int u=sh[i].u,v=sh[i].v,w=sh[i].w;
			if (T.find(u)!=T.find(v))
			{
				son[id][0]=T.find(u);son[id][1]=T.find(v);val[id]=w;
				T.merge(u,id);T.merge(v,id);id++;
			}
		}
		cnt=0;
		dfs(2*n-1);
		for (int i=1;i<=m;i++)
		{
			int u=sh[i].u,v=sh[i].v;
			if (dfn[u]<dfn[v]) le[v].push_back(u),ge[u].push_back(v);
			else le[u].push_back(v),ge[v].push_back(u);
		}
		for (int i=1;i<=n;i++)
		{
			auto cmp=[](int a,int b){return dfn[a]<dfn[b];};
			sort(le[i].begin(),le[i].end(),cmp);
			sort(ge[i].begin(),ge[i].end(),cmp);
			reverse(ge[i].begin(),ge[i].end());
		}
		T.init(n);seg::build(1,1,n);
		for (int i=1;i<=n;i++) sz[i]=1;
		for (int x=n+1;x<2*n;x++)
		{
			int ls=son[x][0],rs=son[x][1];
			sz[x]=sz[ls]+sz[rs];seg::ev=val[x];
			if (sz[ls]<sz[rs])
			{
				for (int j=dfn[ls];j<=out[ls];j++)
				{
					int x=tr[j],l=dfn[rs];
					while (!ge[x].empty()&&dfn[ge[x].back()]<=out[rs])
					{
						int y=ge[x].back();ge[x].pop_back();
						if (dfn[y]>l) seg::change(1,1,n,l,dfn[y]-1,x);
						if (dfn[y]>=l) l=dfn[y]+1;
					}
					if (l<=out[rs]) seg::change(1,1,n,l,out[rs],x);
				}
			}
			else
			{
				for (int j=dfn[rs];j<=out[rs];j++)
				{
					int x=tr[j],r=out[ls];
					while (!le[x].empty()&&dfn[le[x].back()]>=dfn[ls])
					{
						int y=le[x].back();le[x].pop_back();
						if (dfn[y]<r) seg::change(1,1,n,dfn[y]+1,r,x);
						if (dfn[y]<=r) r=dfn[y]-1;
					}
					if (r>=dfn[ls]) seg::change(1,1,n,dfn[ls],r,x);
				}
			}
		}
		dfs1(1,1,0);
		for (int j=1;j<=20;j++) for (int i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
			MAX[i][j]=max(MAX[i][j-1],MAX[fa[i][j-1]][j-1]);
		}
		for (int i=1;i<=m;i++) ans[sh[i].id]=ask(sh[i].u,sh[i].v);
		for (int i=1;i<=m;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}