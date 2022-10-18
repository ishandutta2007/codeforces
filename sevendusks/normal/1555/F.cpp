/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
const int N=1e6+100;
int n,q,ret,v[N],son[N][2],fa[N],tag[N];
int sum[N],cnt[N],f[N],A[N],sz[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline bool nroot(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
inline int sf(int x){return son[fa[x]][1]==x;}
inline void connect(int x,int y,int dir){fa[x]=y,son[y][dir]=x;}
inline void pushup(int x)
{
	sum[x]=sum[son[x][0]]^sum[son[x][1]];
	if (x>n) sum[x]^=v[x];
	cnt[x]=cnt[son[x][0]]+cnt[son[x][1]];
	if (x>n) cnt[x]+=f[x];
	sz[x]=sz[son[x][0]]+sz[son[x][1]]+(x>n);
}
inline void rev(int x){tag[x]^=1;swap(son[x][0],son[x][1]);}
inline void upd(int x){f[x]=A[x]=1;cnt[x]+=sz[x];}
inline void pushdown(int x)
{
	if (tag[x])
	{
		if (son[x][0]) rev(son[x][0]);
		if (son[x][1]) rev(son[x][1]);
		tag[x]=0;
	}
	if (A[x])
	{
		if (son[x][0]) upd(son[x][0]);
		if (son[x][1]) upd(son[x][1]);
		A[x]=0;
	}
}
inline void pushall(int x)
{
	if (nroot(x)) pushall(fa[x]);
	pushdown(x);
}
inline void rotate(int x)
{
	int f=fa[x],gf=fa[f],xd=sf(x),fd=sf(f),s=son[x][xd^1];
	if (nroot(f)) connect(x,gf,fd);
	connect(f,x,xd^1);
	if (s) connect(s,f,xd);
	fa[x]=gf,son[f][xd]=s;
	pushup(f);
}
inline void splay(int x)
{
	pushall(x);
	while (nroot(x))
	{
		if (!nroot(fa[x])) rotate(x);
		else if (sf(fa[x])==sf(x)) rotate(fa[x]),rotate(x);
		else rotate(x),rotate(x);
	}
    pushup(x);
}
inline void access(int x){for(int y=0;x;y=x,x=fa[x])splay(x),son[x][1]=y,pushup(x);}
inline void makeroot(int x){access(x);splay(x);rev(x);}
inline int findroot(int x){access(x);splay(x);while(son[x][0])pushdown(x),x=son[x][0];splay(x);return x;}
inline void split(int x,int y){makeroot(x);access(y);splay(y);}
inline void link(int x,int y)
{
	makeroot(x);
	if (findroot(y)!=x) fa[x]=y;
}
inline void cut(int x,int y)
{
	split(x,y);
	if (findroot(y)==x&&son[x][1]==y&&!son[x][0]) son[x][1]=fa[y]=0,pushup(x);
}
signed main()
{ 
	n=read();q=read();
	ret=n;
	while (q--)
	{
		int x=read(),y=read(),w=read();
		if (findroot(x)!=findroot(y))
		{
			puts("YES");
			ret++;v[ret]=w;
			link(x,ret);link(ret,y);
		}
		else
		{
			split(x,y);
			if (cnt[y]||(sum[y]^w)!=1) puts("NO");
			else
			{
				puts("YES");
				upd(y);
			}
		}
	}
}