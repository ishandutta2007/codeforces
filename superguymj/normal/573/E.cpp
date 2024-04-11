#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=100005;
const LL INF=1000000000000000000;
int n,a[N],siz[N],fa[N],l[N],r[N],tot,k,root;
LL cur[N],c[N],y,p[N],ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void turn(int x,LL y)
{
	c[x]+=y,cur[x]+=y;
}

void pushdown(int x)
{
	if(cur[x])
	{
		turn(l[x],cur[x]);
		turn(r[x],cur[x]);
		cur[x]=0;
	}
}

void ins(int &x,int f=0)
{
	if(!x)
	{
		x=++tot,siz[x]=1,c[x]=(k+1)*y,fa[x]=f;
		return;
	}
	pushdown(x),++siz[x];
	if((k+siz[l[x]]+1)*y>=c[x]) c[x]+=y,turn(r[x],y),ins(l[x],x);
	else k+=siz[l[x]]+1,ins(r[x],x);
}

void pushup(int x)
{
	siz[x]=1+siz[l[x]]+siz[r[x]];
}

void rotate(int x)
{
	int y=fa[x],z=fa[y];
	if(l[z]==y) l[z]=x;
	if(r[z]==y) r[z]=x;
	fa[x]=z,fa[y]=x;
	if(l[y]==x) fa[l[y]=r[x]]=y,r[x]=y;
	else fa[r[y]=l[x]]=y,l[x]=y;
	pushup(y),pushup(x);
}

void splay(int x)
{
	for(; fa[x]; rotate(x))
	{
		int y=fa[x],z=fa[y];
		if(z) rotate((l[z]==y)^(l[y]==x)?x:y);
	}
}

void dfs(int x)
{
	if(!x) return;
	pushdown(x);
	dfs(l[x]);
	p[++*p]=c[x];
	dfs(r[x]);
}

void PRT()
{
	dfs(root);
	LL x=0;
	rep(i,1,n) ans=max(ans,x+=p[i]);
	printf("%lld\n",ans);
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n)
	{
		k=0,y=a[i],ins(root);
		splay(i),root=i;
	}
	PRT();
	return 0;
}