#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
inline int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
inline int rdc()
{
	char c=getchar();
	while(c!='A'&&c!='C') c=getchar();
	return c=='A';
}
const int N=4e5+50,Log=20,inf=1e9+50;
int n,m,Q,tot=0;
int W[N];
struct Link
{
	int cnt;
	int he[N];
	struct Edge
	{
		int v,nxt;
	}e[N];
	inline void add(int uu,int vv)
	{
		cnt++;e[cnt].v=vv;e[cnt].nxt=he[uu];he[uu]=cnt;
		cnt++;e[cnt].v=uu;e[cnt].nxt=he[vv];he[vv]=cnt;
	}
}G,T;
struct Segment_tree
{
	int val[N<<2];
	inline void mup(int rt)
	{
		val[rt]=min(val[ls],val[rs]);
	}
	inline void change(int rt,int l,int r,int x,int nv)
	{
		if(l==r)
		{
			val[rt]=nv;
			return ;
		}
		int mid=(l+r)>>1;
		if(mid>=x) change(ls,l,mid,x,nv);
		else change(rs,mid+1,r,x,nv);
		mup(rt);
	}
	inline int query(int rt,int l,int r,int x,int y)
	{
		if(l>=x&&r<=y)
		{
			return val[rt];
		}
		int mid=(l+r)>>1,ras=inf;
		if(mid>=x) ras=min(ras,query(ls,l,mid,x,y));
		if(mid<y) ras=min(ras,query(rs,mid+1,r,x,y));
		return ras;
	}
}s;
struct RBT
{
	int cur;
	int fa[N],prf[N],det[N],siz[N],ms[N],dfn[N];
	multiset<int> st[N];
	inline void dfs(int x,int nf)
	{
		int i,vv;
		siz[x]=1;
		det[x]=det[nf]+1;
		fa[x]=nf;
		for(i=T.he[x];i;i=T.e[i].nxt)
		{
			vv=T.e[i].v;
			if(vv==nf) continue;
			dfs(vv,x);
			siz[x]+=siz[vv];
			if(ms[x]==0||siz[vv]>siz[ms[x]]) ms[x]=vv;
		}
	}
	inline void dfs2(int x,int bf)
	{
		int i,vv;
		prf[x]=bf;
		dfn[x]=++cur;
		if(ms[x]) dfs2(ms[x],bf);
		for(i=T.he[x];i;i=T.e[i].nxt)
		{
			vv=T.e[i].v;
			if(vv==fa[x]||vv==ms[x]) continue;
			dfs2(vv,vv);
		}
	}
	inline void build()
	{
		int i;
		for(i=1;i<=n;i++)
		{
			if(fa[i]) st[fa[i]].insert(W[i]);
		}
		for(i=1;i<=n;i++) s.change(1,1,tot,dfn[i],W[i]);
		for(i=n+1;i<=tot;i++) s.change(1,1,tot,dfn[i],*st[i].begin());
	}
	inline int solve(int x,int y,int &lca)
	{
		int ras=inf;
		while(prf[x]!=prf[y])
		{
			if(det[prf[x]]<det[prf[y]]) swap(x,y);
			ras=min(ras,s.query(1,1,tot,dfn[prf[x]],dfn[x]));
			x=fa[prf[x]];
		}
		if(x==y) 
		{
			ras=min(ras,s.query(1,1,tot,dfn[x],dfn[x]));
			lca=x;
			return ras;
		}
		if(det[x]>det[y]) swap(x,y);
		ras=min(ras,s.query(1,1,tot,dfn[x],dfn[y]));
		lca=x;
		return ras; 
	}
	inline void change(int x,int nv)
	{
		if(fa[x])
		{
			st[fa[x]].erase(st[fa[x]].find(W[x]));
			st[fa[x]].insert(nv);
			s.change(1,1,tot,dfn[fa[x]],*st[fa[x]].begin());
		}
		W[x]=nv;
		s.change(1,1,tot,dfn[x],W[x]);
	}
	inline int query(int x,int y)
	{
		int lca,ras;
		ras=solve(x,y,lca);
		if(lca>n&&fa[lca]) ras=min(ras,W[fa[lca]]);
		return ras; 
	}
}rbt;
int cur=0,top=0;
int dfn[N],pre[N],sta[N];
inline void tarjan(int x)
{
	int i,vv;
	dfn[x]=pre[x]=++cur;
	sta[++top]=x;
	for(i=G.he[x];i;i=G.e[i].nxt)
	{
		vv=G.e[i].v;
		if(!dfn[vv])
		{
			tarjan(vv);
			pre[x]=min(pre[x],pre[vv]);
			if(pre[vv]>=dfn[x])
			{
				tot++;
				while(sta[top+1]!=vv)
				{
					T.add(sta[top],tot);
					top--;
				}
				T.add(x,tot);
			}
		}
		else pre[x]=min(pre[x],dfn[vv]);
	}
}
int main()
{
	int i,uu,vv,op,x,y;
	n=rd();m=rd();Q=rd();
	for(i=1;i<=n;i++) W[i]=rd();
	for(i=1;i<=m;i++)
	{
		uu=rd();vv=rd();
		G.add(uu,vv);
	}
	tot=n;
	tarjan(1);
	rbt.dfs(1,0);
	rbt.dfs2(1,0);
	rbt.build();
	while(Q--)
	{
		op=rdc();x=rd();y=rd();
		if(op==0) rbt.change(x,y);
		else printf("%d\n",rbt.query(x,y));
	}
	return 0;
}