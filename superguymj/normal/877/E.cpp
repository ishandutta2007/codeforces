#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=200005;
bool cur[N<<2];
char s[10];
int n,m,x,a[N],h[N],cnt,ql,qr,dfn[N],pos[N],siz[N],t[N<<2];
struct edge{int v,n;} e[N];

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
}

void dfs(int x)
{
	siz[x]=1,pos[dfn[x]=++*dfn]=x;
	for(int i=h[x]; i!=-1; i=e[i].n)
		dfs(e[i].v),siz[x]+=siz[e[i].v];
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt]=a[pos[l]];
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void turn(int l,int r,int rt)
{
	cur[rt]^=1,t[rt]=r-l+1-t[rt];
}

void pushdown(int l,int r,int rt)
{
	if(cur[rt])
	{
		turn(l,mid,lch);
		turn(mid+1,r,rch);
		cur[rt]=0;
	}
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(l,r,rt);
		return;
	}
	pushdown(l,r,rt);
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

int query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt];
	pushdown(l,r,rt);
	if(qr<=mid) return query(l,mid,lch);
	if(ql>mid) return query(mid+1,r,rch);
	return query(l,mid,lch)+query(mid+1,r,rch);
}

int main()
{
	scanf("%d",&n),memset(h,-1,sizeof(h));
	rep(i,2,n) scanf("%d",&x),addedge(x,i);
	rep(i,1,n) scanf("%d",&a[i]);
	dfs(1),build(1,n,1);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d",s,&x);
		if(s[0]=='g')
		{
			ql=dfn[x],qr=ql+siz[x]-1;
			printf("%d\n",query(1,n,1));
		}
		else
		{
			ql=dfn[x],qr=ql+siz[x]-1;
			modify(1,n,1);
		}
	}
	return 0;
}