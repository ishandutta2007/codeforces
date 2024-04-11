#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch ls[rt]
#define rch rs[rt]

using namespace std;
const int N=100005,INF=2000000000;
int n,m,root,ans,cnt,h[N],a[N],tot,t[N*60],ls[N*60],rs[N*60],Root[N],ql,qr,x,y,k,dep[N];
struct edge{int v,n;} e[N<<1];

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

void ins(int l,int r,int &rt)
{
	if(!rt) rt=++tot;
	if(l==r)
	{
		t[rt]=y;
		return;
	}
	if(x<=mid) ins(l,mid,lch);
	else ins(mid+1,r,rch);
	t[rt]=min(t[lch],t[rch]);
}

int query(int l,int r,int rt)
{
	if(!rt) return INF;
	if(ql<=l && r<=qr) return t[rt];
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return min(query(l,mid,lch),query(mid+1,r,rch));
}

void merge(int l,int r,int &rt,int lst)
{
	if(!lst) return;
	if(!rt) {rt=lst; return;}
	if(l==r) {t[++tot]=min(t[rt],t[lst]),rt=tot; return;}
	++tot,ls[tot]=ls[rt],rs[tot]=rs[rt],rt=tot;
	merge(l,mid,ls[rt],ls[lst]),merge(mid+1,r,rs[rt],rs[lst]);
	t[rt]=min(t[ls[rt]],t[rs[rt]]);
}

void dfs(int x,int fa,int d)
{
	::x=dep[x]=d,y=a[x],ins(1,n,Root[x]);
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			dfs(e[i].v,x,d+1);
			merge(1,n,Root[x],Root[e[i].v]);
		}
}

int main()
{
	n=getint(),root=getint();
	rep(i,1,n) a[i]=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	t[0]=INF,dfs(root,0,1);
	m=getint();
	while(m--)
	{
		x=(getint()+ans)%n+1,k=(getint()+ans)%n;
		ql=dep[x],qr=ql+k,printf("%d\n",ans=query(1,n,Root[x]));
	}
	return 0;
}