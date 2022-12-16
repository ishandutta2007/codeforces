#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10,inf=1<<30;
	int n,rt;
	int ansmin,ansmax;
	int rd[N];
	int st[N],top;
	bool vis[N],q[N];
	int head[N],cnt;
	struct point
	{
		int nxt,to;
		point(){}
		point(const int &nxt,const int &to):nxt(nxt),to(to){}
	}a[N<<1];
	inline void link(int x,int y)
	{
		a[++cnt]=(point){head[x],y};head[x]=cnt;
		a[++cnt]=(point){head[y],x};head[y]=cnt;
	}
	int dep[N],f[N][21],lg[N],id[N],idx;
	inline bool cmp(int x,int y)
	{
		return dep[x]<dep[y];
	}
	inline void dfs(int now,int fa)
	{
		id[now]=++idx;
		dep[now]=dep[fa]+1;
		f[now][0]=fa;
		for(int i=1;i<=20;++i) f[now][i]=f[f[now][i-1]][i-1];
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(t==fa) continue;
			dfs(t,now);
		}
	}
	inline int query(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]^dep[y]) x=f[x][lg[dep[x]-dep[y]]-1];
		if(x==y) return x;
		for(int i=20;~i;--i)
			if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}
	inline void main()
	{
		n=read();
		for(int x,y,i=1;i<n;++i)
		{
			x=read(),y=read();
			link(x,y);
			++rd[x],++rd[y];
		}
		for(int i=1;i<=n;++i)
		{
			if(rd[i]==1)
			{
				rt=i;
				st[++top]=i;
			}
		}
		dep[0]=-1;
		dfs(rt,0);
		for(int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
		ansmin=1;
		for(int i=1;i<=top;++i)
		{
			if(dep[st[i]]&1)
			{
				ansmin=3;
				break;
			}
		}
		sort(st+1,st+top+1,cmp);
		ansmax=1;
		vis[rt]=1;
		for(int i=head[rt];i;i=a[i].nxt) vis[a[i].to]=q[a[i].to]=1;
		for(int x,sum,i=2;i<=top;++i)
		{
			x=st[i];sum=0;
			if(q[f[x][0]]) continue;
			q[f[x][0]]=1;
			while(!vis[x])
			{
				vis[x]=1;
				++sum;
				x=f[x][0];
			}
			ansmax+=sum;
		}
		printf("%lld %lld\n",ansmin,ansmax);
	}
}
signed main()
{
	red::main();
	return 0;
}