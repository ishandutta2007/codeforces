#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=300005;
typedef long long LL;
int q,k,x;
LL a[N],c[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

struct lct
{
	bool cur[N];
	int l[N],r[N],f[N];
	LL siz1[N],siz2[N],ans1,ans2;

	bool isroot(int x)
	{
		return l[f[x]]!=x && r[f[x]]!=x;
	}

	void pushup(int x)
	{
		siz1[x]=a[x]+siz1[l[x]]+siz1[r[x]];
		siz2[x]=a[x]*c[x]+siz2[l[x]]+siz2[r[x]];
	}
	
	void turn(int x)
	{
		if(x)
		{
			cur[x]=1,a[x]=siz1[x]=siz2[x]=0;
		}
	}

	void pushdown(int x)
	{
		if(cur[x]) turn(l[x]),turn(r[x]),cur[x]=0;
	}

	void rotate(int x)
	{
		int y=f[x],z=f[y];
		if(l[z]==y) l[z]=x;
		if(r[z]==y) r[z]=x;
		f[x]=z,f[y]=x;
		if(l[y]==x) f[l[y]=r[x]]=y,r[x]=y;
		else f[r[y]=l[x]]=y,l[x]=y;
		pushup(y),pushup(x);
	}
	
	void dfs(int x)
	{
		if(isroot(x))
		{
			pushdown(x);
			return;
		}
		dfs(f[x]),pushdown(x);
	}

	void splay(int x)
	{
		for(dfs(x); !isroot(x); rotate(x))
		{
			int y=f[x],z=f[y];
			if(!isroot(y)) rotate((l[z]==y)^(l[y]==x)?x:y);
		}
	}

	void access(int x)
	{
		for(int t=0; x; t=x,x=f[x])
			splay(x),r[x]=t,pushup(x);
	}

	void link(int x,int y)
	{
		access(x),splay(x),f[y]=x;
	}

	void find(int x)
	{
		if(siz1[x]<=k)
		{
			ans1=siz1[x],ans2=siz2[x],turn(x);
			return;
		}

		if(siz1[l[x]]>=k) find(l[x]);
		else if(siz1[l[x]]+a[x]>=k)
		{
			LL y=k-siz1[l[x]];
			ans1+=k,ans2+=siz2[l[x]]+c[x]*y;
			a[x]-=y,turn(l[x]),splay(x);
		}
		else
		{
			ans1+=siz1[l[x]]+a[x],k-=siz1[l[x]]+a[x];
			ans2+=siz2[l[x]]+a[x]*c[x],turn(l[x]),a[x]=0;
			find(r[x]);
		}
	}
	
	void query(int x)
	{
		access(x),splay(x);
		ans1=ans2=0,find(x);
		printf("%lld %lld\n",ans1,ans2);
		fflush(stdout);
	}
} t;

int main()
{
	q=getint(),a[1]=getint(),c[1]=getint();
	rep(i,2,q+1)
	{
		if(getint()==1)
		{
			x=getint()+1,a[i]=getint(),c[i]=getint();
			t.link(x,i);
		}
		else
		{
			x=getint()+1,k=getint();
			t.query(x);
		}
	}
	return 0;
}