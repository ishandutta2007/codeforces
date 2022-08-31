#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
int n,q;
int l[MAXN],r[MAXN],fa[MAXN],rev[MAXN],val[MAXN],is[MAXN];int v[MAXN],sum[MAXN];
inline bool top(int x){return (!fa[x])||(l[fa[x]]!=x&&r[fa[x]]!=x);}
void up(int x)
{
	is[x]=val[x];
	if(l[x])is[x]&=is[l[x]];
	if(r[x])is[x]&=is[r[x]];
	sum[x]=v[x]+sum[l[x]]+sum[r[x]];
}
void down(int x)
{
	if(rev[x])
	{
		rev[l[x]]^=1;
		rev[r[x]]^=1;
		int tmp=l[x];l[x]=r[x];r[x]=tmp;
		rev[x]=0;
	}
}
void left(int x)
{
	int y=fa[x];int z=fa[y];
	r[y]=l[x];if(l[x])fa[l[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
	fa[y]=x;l[x]=y;
	up(y);up(x);
}
void right(int x)
{
	int y=fa[x];int z=fa[y];
	l[y]=r[x];if(r[x])fa[r[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
	fa[y]=x;r[x]=y;
	up(y);up(x);
}
int st[MAXN];
void splay(int x)
{
	st[st[0]=1]=x;
	for(int k=x;!top(k);k=fa[k])st[++st[0]]=fa[k];
	while(st[0])down(st[st[0]--]);
	while(!top(x))
	{
		int y=fa[x];int z=fa[y];
		if(top(y))
		{
			if(r[y]==x)left(x);else right(x);
		}
		else
		{
			if(r[z]==y)
			{
				if(r[y]==x)left(y),left(x);
				else right(x),left(x);
			}
			else
			{
				if(l[y]==x)right(y),right(x);
				else left(x),right(x);
			}
		}
	}
}
int access(int x)
{
	int y=0;
	for(;x;y=x,x=fa[x])
	{
		splay(x);r[x]=y;up(x);
	}
	return y;
}
void evert(int x)
{
	access(x);splay(x);rev[x]^=1;
}
void link(int x,int y)
{
	evert(y);splay(y);fa[y]=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)is[i]=val[i]=1;
	for(int i=1;i<n;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		is[i+n]=val[i+n]=v[i+n]=sum[i+n]=1;
		link(a,i+n);link(b,i+n);
	}
	scanf("%d",&q);
	while(q--)
	{
		//for(int i=1;i<=n;i++)printf("%d\n",is[i]);
		int opt;scanf("%d",&opt);
		if(opt==1)
		{
			int x;scanf("%d",&x);splay(x+n);val[x+n]=1;up(x+n);
		}
		else
		if(opt==2)
		{
			int x;scanf("%d",&x);splay(x+n);val[x+n]=0;up(x+n);
		}
		else
		{
			int a,b;scanf("%d%d",&a,&b);
			evert(a);access(b);splay(b);
			if(is[b])printf("%d\n",sum[b]);
			else printf("-1\n");
		}
	}
	return 0;
}