#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
const int N=200005;
int n,m,q,h[N],cnt,dfn[N],top[N],dep[N],siz[N],son[N],fa[N];
int tot,t[N*40],ls[N*40],rs[N*40],nxt[20][N],x,ql,qr,ans,root[N];
int pos[N],T[N<<2];
vector <int> p[N],a[N],b[N];
struct edge{int v,n;} e[N];
struct data{int x,dep;};

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
}

void dfs0(int x,int d)
{
	dep[x]=d,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
	{
		dfs0(e[i].v,d+1);
		siz[x]+=siz[e[i].v];
		if(!son[x] || siz[son[x]]<siz[e[i].v])
			son[x]=e[i].v;
	}
}

void dfs1(int x,int t)
{
	top[x]=t,pos[dfn[x]=++*dfn]=x;
	if(son[x]) dfs1(son[x],t);
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=son[x])
			dfs1(e[i].v,e[i].v);
}

int lca(int x,int y)
{
	while(top[x]!=top[y])
		dep[top[x]]>dep[top[y]]?x=fa[top[x]]:y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}

void ins(int l,int r,int &rt)
{
	if(!rt) rt=++tot;
	if(l==r)
	{
		++t[rt];
		return;
	}
	if(x<=mid) ins(l,mid,ls[rt]);
	else ins(mid+1,r,rs[rt]);
}

void updata(int l,int r,int lst,int &rt)
{
	if(!rt)
	{
		rt=lst;
		return;
	}
	if(l==r)
	{
		t[rt]+=t[lst];
		return;
	}
	updata(l,mid,ls[lst],ls[rt]);	
	updata(mid+1,r,rs[lst],rs[rt]);
	t[rt]=t[ls[rt]]+t[rs[rt]];
}

int query(int l,int r,int lst,int rt)
{
	if(ql<=l && r<=qr) return t[rt]-t[lst];
	if(qr<=mid) return query(l,mid,ls[lst],ls[rt]);
	if(mid<ql) return query(mid+1,r,rs[lst],rs[rt]);
	return query(l,mid,ls[lst],ls[rt])+query(mid+1,r,rs[lst],rs[rt]);
}

void turn(int rt,int x)
{
	if(!T[rt] || dep[x]<dep[T[rt]]) T[rt]=x;
}

void chkmin(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(rt,x);
		return;
	}
	if(ql<=mid) chkmin(l,mid,lch);
	if(mid<qr) chkmin(mid+1,r,rch);
}	

void ins(int u,int v)
{
	int t=lca(u,v);
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ql=dfn[top[u]],qr=dfn[u],x=t,chkmin(1,n,1);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	ql=dfn[u],qr=dfn[v],x=t,chkmin(1,n,1);
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		if(!T[rt]) nxt[0][pos[l]]=pos[l];
		else nxt[0][pos[l]]=T[rt];
		return;
	}
	if(T[rt]) turn(lch,T[rt]),turn(rch,T[rt]);
	build(l,mid,lch),build(mid+1,r,rch);
}

data find(int u,int fa)
{
	data rt=(data){0,0};
	repd(i,17,0)
		if(dep[nxt[i][u]]>dep[fa])
			rt.dep+=(1<<i),u=nxt[i][u];
	if(dep[nxt[0][rt.x=u]]>dep[fa]) rt.dep=-1;
	else ++rt.dep;
	return rt;
}

int main()
{
	n=getint(),memset(h,-1,sizeof(h));
	rep(i,2,n) fa[i]=getint(),addedge(fa[i],i);
	dfs0(1,1),dfs1(1,1);
	m=getint();
	rep(i,1,m)
	{
		int u=getint(),v=getint(),t=lca(u,v);
		if(t!=u && t!=v)
		{	p[dfn[u]].pb(dfn[v]);
			p[dfn[v]].pb(dfn[u]);
		}
		ins(u,v);
	}
	rep(i,1,n)
	{
		int siz=p[i].size()-1;
		rep(j,0,siz) x=p[i][j],ins(1,n,root[i]);
		updata(1,n,root[i-1],root[i]);
	}
	build(1,n,1);
	rep(i,1,17)
		rep(j,1,n)
			nxt[i][j]=nxt[i-1][nxt[i-1][j]];
	q=getint();
	while(q--)
	{
		int u=getint(),v=getint(),t=lca(u,v);
		if(dep[u]>dep[v]) swap(u,v);
		if(t==u) printf("%d\n",find(v,t).dep);
		else
		{
			data x=find(u,t),y=find(v,t);
			if(x.dep==-1 || y.dep==-1)
			{
				puts("-1");
				continue;
			}
			ql=dfn[y.x],qr=ql+siz[y.x]-1;
			ans=x.dep+y.dep-(bool)query(1,n,root[dfn[x.x]-1],root[dfn[x.x]+siz[x.x]-1]);
			printf("%d\n",ans);
		}
	}
	return 0;
}