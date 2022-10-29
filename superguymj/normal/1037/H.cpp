#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=100005;
char s[N],st[N<<1];
int n,m,ql,qr,h[N<<1],cnt;
struct edge{int v,n;} e[N<<1];
int fa[N<<1],len[N<<1],p[N<<1],root[N<<1],trf[N<<1][30],lst,tot,top;
int seg_tot,ls[N*50],rs[N*50],t[N*50],mx[N],pos[N<<1],dfn[N<<1],siz[N<<1];

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

void add(int c)
{
	int u=lst,v,x=++tot;
	lst=tot,len[x]=len[u]+1;
	for(; u && !trf[u][c]; trf[u][c]=x,u=fa[u]);
	if(!u) fa[x]=1;
	else if(len[u]+1==len[v=trf[u][c]]) fa[x]=v;
	else
	{
		int w=++tot;
		fa[w]=fa[v],len[w]=len[u]+1;
		memcpy(trf[w],trf[v],sizeof(trf[v]));
		for(fa[v]=fa[x]=w; u && trf[u][c]==v; trf[u][c]=w,u=fa[u]);
	}
}

void ins(int l,int r,int &rt,int lst,int x)
{
	if(!rt) rt=++seg_tot;
	if(l==r)
	{
		t[rt]=1;
		return;
	}
	if(x<=mid) ins(l,mid,ls[rt],ls[lst],x),rs[rt]=rs[lst];
	else ins(mid+1,r,rs[rt],rs[lst],x),ls[rt]=ls[lst];
	t[rt]=t[ls[rt]]+t[rs[rt]];
}

void dfs(int x)
{
	pos[dfn[x]=++*dfn]=x,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n) dfs(e[i].v),siz[x]+=siz[e[i].v];
}

void build()
{
	lst=tot=1;
	memset(h,-1,sizeof(h));
	rep(i,1,n) add(s[i]-'a'),p[lst]=i;
	rep(i,2,tot) addedge(fa[i],i);
	dfs(1);
	rep(i,1,tot)
	{
		int x=pos[i];
		if(p[x]) ins(1,n,root[i],root[i-1],p[x]);
		else root[i]=root[i-1];
	}
}

void PRT(int x,int c)
{
	rep(i,1,x) putchar(st[i]);
	putchar(c),puts("");
}

int query(int l,int r,int lst,int rt)
{
	if(t[rt]-t[lst]==0) return 0;
	if(l==r) return l;
	if(qr<=mid) return query(l,mid,ls[lst],ls[rt]);
	int ret=query(mid+1,r,rs[lst],rs[rt]);
	if(ret) return ret;
	return query(l,mid,ls[lst],ls[rt]);
}

bool check(int x,int ln)
{
	return query(1,n,root[dfn[x]-1],root[dfn[x]+siz[x]-1])-ql+1>=ln;
}

void solve()
{
	mx[top=0]=1;
	int p=1,m=strlen(st+1);
	rep(i,1,m) if(trf[p][st[i]-'a']) mx[++top]=p=trf[p][st[i]-'a']; else break;
	repd(i,top,0)
	{
		int x=mx[i],c=i==m?0:st[i+1]+1-'a';
		rep(j,c,25) if(trf[x][j] && check(trf[x][j],i+1))
		{
			PRT(i,j+'a');
			return;
		}
	}
	puts("-1");
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	m=getint(),build();
	while(m--)
	{
		ql=getint(),qr=getint(),scanf("%s",st+1);
		solve();
	}
	return 0;
}