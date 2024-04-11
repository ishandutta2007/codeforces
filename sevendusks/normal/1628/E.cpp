/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=6*1e5+100;
int n,q,val[N],son[N][2],dfn[N*2],fa[N][21],de[N],tr[N],cnt;
struct node
{
	int u,v,w;
}sh[N];
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
	void init(int n){for (int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
	void merge(int a,int b)
	{
		a=find(a);b=find(b);
		if (a==b) return;
		fa[a]=b;
	}
}T;
void dfs(int x,int father)
{
	fa[x][0]=father;dfn[x]=++cnt;tr[cnt]=x;
	if (x<=n) return;
	de[son[x][0]]=de[x]+1;de[son[x][1]]=de[x]+1;
	dfs(son[x][0],x);dfs(son[x][1],x);
}
int lca(int a,int b)
{
	if (de[a]>de[b]) swap(a,b);
	for (int i=20;i>=0;i--) if (de[fa[b][i]]>=de[a]) b=fa[b][i];
	if (a==b) return a;
	for (int i=20;i>=0;i--) if (fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
	return fa[a][0]; 
}
namespace seg
{
	int MIN[N*4],MAX[N*4],tag[N*4],oMIN[N*4],oMAX[N*4];
	void pushup(int x)
	{
		MIN[x]=min(MIN[ls],MIN[rs]);
		MAX[x]=max(MAX[ls],MAX[rs]);
		oMAX[x]=max(oMAX[ls],oMAX[rs]);
		oMIN[x]=min(oMIN[ls],oMIN[rs]);
	}
	void pushdown(int x)
	{
		if (tag[x]==0)
		{
			MIN[ls]=MIN[rs]=inf,MAX[ls]=MAX[rs]=-inf;
			tag[ls]=tag[rs]=0;
			tag[x]=-1;
		}
		if (tag[x]==1)
		{
			MIN[ls]=oMIN[ls];MAX[ls]=oMAX[ls];
			MIN[rs]=oMIN[rs];MAX[rs]=oMAX[rs];
			tag[ls]=tag[rs]=1;
			tag[x]=-1;
		}
	}
	void build(int x,int l,int r)
	{
		MAX[x]=-inf,MIN[x]=inf;tag[x]=-1;
		if (l==r){oMAX[x]=oMIN[x]=dfn[l];return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	void change(int x,int l,int r,int ll,int rr,int op)
	{
		if (ll<=l&&rr>=r)
		{
			tag[x]=op;
			if (op==1) MIN[x]=oMIN[x],MAX[x]=oMAX[x];
			else MIN[x]=inf,MAX[x]=-inf;
			return;
		}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,op);
		if (rr>mid) change(rs,mid+1,r,ll,rr,op);
		pushup(x);
	}
}
signed main()
{
	n=read();q=read();
	for (int i=1;i<n;i++) sh[i]=(node){read(),read(),read()};
	sort(sh+1,sh+n,[](node a,node b){return a.w<b.w;});
	T.init(2*n);
	for (int i=1;i<n;i++)
	{
		int u=T.find(sh[i].u),v=T.find(sh[i].v);
		val[n+i]=sh[i].w;son[n+i][0]=u;son[n+i][1]=v;
		T.merge(u,n+i);T.merge(v,n+i);
	}
	int rt=n+n-1;
	dfs(rt,rt);
	for (int j=1;j<=20;j++) for (int i=1;i<n+n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	seg::build(1,1,n);
	while (q--)
	{
		int op=read();
		if (op==1)
		{
			int l=read(),r=read();
			seg::change(1,1,n,l,r,1);
		}
		if (op==2)
		{
			int l=read(),r=read();
			seg::change(1,1,n,l,r,0);
		}
		if (op==3)
		{
			int x=read(),a=seg::MIN[1],b=seg::MAX[1];
			if (a==inf||(a==b&&tr[a]==x))
			{
				printf("-1\n");
				continue;
			}
			a=tr[a];b=tr[b];
			printf("%d\n",max(val[lca(a,x)],val[lca(b,x)]));
		}
	}
}