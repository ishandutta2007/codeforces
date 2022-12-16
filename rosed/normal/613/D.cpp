#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=4e5+10,inf=1e9+7;
	int n,m;
	vector<int> eg[N];
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
	int lg[N],dep[N],f[N][21],dfn[N],idx;
	int q[N],num;
	int st[N],top;
	bool vis[N];
	inline void dfs1(int now,int fa)
	{
		f[now][0]=fa;dfn[now]=++idx;
		dep[now]=dep[fa]+1;
		for(int i=1;i<=20;++i) f[now][i]=f[f[now][i-1]][i-1];
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(t==fa) continue;
			dfs1(t,now);
		}
	}
	inline int getlca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]^dep[y]) x=f[x][lg[dep[x]-dep[y]]-1];
		if(x==y) return x;
		for(int i=20;~i;--i)
			if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}
	inline bool cmp(const int &a,const int &b)
	{
		return dfn[a]<dfn[b];
	}
	inline void insert(int x)
	{
		if(top==1) {st[++top]=x;return;}
		int lca=getlca(x,st[top]);
		if(lca==st[top])
		{
			st[++top]=x;
			return;
		}
		while(top>1&&dfn[st[top-1]]>=dfn[lca]) eg[st[top-1]].push_back(st[top]),--top;
		if(lca!=st[top]) eg[lca].push_back(st[top]),st[top]=lca;
		st[++top]=x;
	}
	inline int dfs(int now)
	{
		int sum=eg[now].size(),ret=0,siz=0;
		for(int i=0;i<sum;++i)
		{
			int t=eg[now][i];
			ret+=dfs(t);
			if(vis[t]) ++siz;
		}
		if(vis[now]) return siz+ret;
		if(!siz) return ret;
		if(siz>=2) return ret+1;
		vis[now]=1;return ret;
	}
	inline void sol(int now)
	{
		int sum=eg[now].size();
		vis[now]=0;
		for(int i=0;i<sum;++i)
		{
			int t=eg[now][i];
			sol(t);
		}
		eg[now].clear();
	} 
	inline void main()
	{
		n=read();
		for(int x,y,i=1;i<n;++i)
		{
			x=read(),y=read();
			link(x,y);
		}
		for(int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
		lg[0]=1;
		dfs1(1,0);
		m=read();
		for(int i=1;i<=m;++i)
		{
			num=read();
			for(int j=1;j<=num;++j) q[j]=read(),vis[q[j]]=1;
			sort(q+1,q+num+1,cmp);
			bool flag=0;
			for(int j=1;j<=num;++j)
			{
				if(vis[f[q[j]][0]])
				{
					puts("-1");
					flag=1;
					break;
				}
			}
			if(flag)
			{
				for(int j=1;j<=num;++j) vis[q[j]]=0;
				continue;
			}
			st[top=1]=1;
			for(int j=1;j<=num;++j)
			{
				if(q[j]^1) insert(q[j]);
			}
			while(top>0) eg[st[top-1]].push_back(st[top]),--top;
			printf("%lld\n",dfs(1));
			sol(1);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
7
1 2
2 3
3 4
4 5
5 6
6 7
5
3 2 4 6

*/