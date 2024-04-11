#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=50005,M=200;
int n,m,q,x,w,ql,qr,tot,c[N],ls[N*M],rs[N*M],h[N],cnt;
int dep[N],siz[N],fa[N],son[N],dfn[N],pos[N],top[N],root[N];
LL C,ans,ans1[N],ans2[N],t[N*M],cur[N*M],val[N];
struct edge{int v,n;} e[N];

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

void dfs1(int x,int f,int d)
{
	dep[x]=d,fa[x]=f,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
	{
		dfs1(e[i].v,x,d+1),siz[x]+=siz[e[i].v];
		if(!son[x] || siz[son[x]]<siz[e[i].v]) son[x]=e[i].v;
	}
}

void dfs2(int x,int t)
{
	top[x]=t,pos[dfn[x]=++*dfn]=x;
	if(son[x]) dfs2(son[x],t);
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=son[x])
			dfs2(e[i].v,e[i].v);
}

void turn(int l,int r,int &rt,int x)
{
	if(!rt) rt=++tot;
	t[rt]+=x*(r-l+1),cur[rt]+=x;
}

void pushdown(int l,int r,int rt)
{
	if(cur[rt]) turn(l,mid,ls[rt],cur[rt]),turn(mid+1,r,rs[rt],cur[rt]),cur[rt]=0;
}

LL query(int l,int r,int &rt,int tp)
{
	if(!rt) rt=++tot;
	if(ql<=l && r<=qr)
	{
		LL ret=t[rt];
		turn(l,r,rt,tp);
		return ret;
	}
	pushdown(l,r,rt);
	LL ret=0;
	if(ql<=mid) ret+=query(l,mid,ls[rt],tp);
	if(mid<qr) ret+=query(mid+1,r,rs[rt],tp);
	t[rt]=t[ls[rt]]+t[rs[rt]];
	return ret;
}

LL query(int x,int c,int tp)
{
	LL rt=0;
	while(x)
	{
		ql=dfn[top[x]],qr=dfn[x];
		rt+=query(1,n,root[c],tp);
		x=fa[top[x]];
	}
	return tp*rt;
}

void ins(int x,int c,int tp)
{
	ans1[c]+=tp*dep[x];
	LL a=query(x,c,tp);
	ans2[c]+=2*a+dep[x];
}

int main()
{
	n=getint(),m=getint(),q=getint(),C=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n) c[i]=getint();
	rep(i,2,n) addedge(getint(),i);
	rep(i,1,m) val[i]=getint();
	dfs1(1,0,1),dfs2(1,1);
	rep(i,1,n) ins(i,c[i],1);
	while(q--)
	{
		if(getint()==1) x=getint(),w=getint(),ins(x,c[x],-1),ins(x,c[x]=w,1);
		else
		{
			x=getint(),ans=ans2[x]*val[x]*val[x]-2*C*ans1[x]*val[x]+n*C*C;
			printf("%.10lf\n",(double)ans/n);
		}
	}
	return 0;
}