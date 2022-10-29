#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=100005;
bool cur[N<<2];
int n,m,h[N],cnt,tp,x,ql,qr;
int siz[N],fa[N],top[N],dep[N],son[N],dfn[N];
struct edge{int v,n;} e[N<<1];
struct data
{
	int a,b;
	
	data operator + (data t)
	{
		return (data){a+t.a,max(b+t.a,t.b)};
	}

	void operator += (data t)
	{
		a+=t.a,b+=t.b;
	}
} y,t[N<<2];

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
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs1(int x,int f,int d)
{
	fa[x]=f,dep[x]=d,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=f)
		{
			dfs1(e[i].v,x,d+1);
			siz[x]+=siz[e[i].v];
			if(!son[x] || siz[son[x]]<siz[e[i].v])
				son[x]=e[i].v;
		}
}

void dfs2(int x,int t)
{
	top[x]=t,dfn[x]=++*dfn;
	if(son[x]) dfs2(son[x],t);
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=son[x] && e[i].v!=fa[x])
			dfs2(e[i].v,e[i].v);
}

void turn(int l,int r,int rt)
{
	cur[rt]=1,t[rt]=(data){-(r-l+1),0};
}

void pushdown(int l,int r,int rt)
{
	if(cur[rt]) turn(l,mid,lch),turn(mid+1,r,rch),cur[rt]=0;
}

void reset(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(l,r,rt);
		return;
	}
	pushdown(l,r,rt);
	if(ql<=mid) reset(l,mid,lch);
	if(mid<qr) reset(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt]+=y;
		return;
	}
	pushdown(l,r,rt);
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

data query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt];
	pushdown(l,r,rt);
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return query(l,mid,lch)+query(mid+1,r,rch);
}

data query(int x)
{
	bool jdg=0;
	data ret;
	while(x)
	{
		ql=dfn[top[x]],qr=dfn[x];
		if(!jdg) ret=query(1,n,1),jdg=1;
		else ret=query(1,n,1)+ret;
		x=fa[top[x]];
	}
	return ret;
}

int main()
{
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,2,n) addedge(i,getint());
	
	dfs1(1,0,1),dfs2(1,1),turn(1,n,1);
	while(m--)
	{
		tp=getint();
		if(tp==1)
			y=(data){1,1},x=dfn[getint()],modify(1,n,1);
		if(tp==2)
		{
			x=getint(),y=query(x);
			if(ql=dfn[x]+1,qr=ql+siz[x]-2,ql<=qr) reset(1,n,1);
			x=dfn[x],y=(data){-max(y.a,y.b),-max(y.a,y.b)},modify(1,n,1);
		}
		if(tp==3) x=getint(),y=query(x),puts(max(y.a,y.b)>0?"black":"white");
	}
	return 0;
}