#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1) 
#define double long double
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10;
	int n,m,k;
	int head[N],cnt=1;
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
	int dfn[N],low[N],col[N],sum,idx;
	int st[N],top;
	vector<int> eg[N];
	int f[N];
	inline int find(int k)
	{
		return f[k]==k?k:f[k]=find(f[k]);
	}
	inline void tarjan(int now,int fa)
	{
		st[++top]=now;
		dfn[now]=low[now]=++idx;
		for(int i=head[now];i;i=a[i].nxt)
		{
			if(i==fa) continue;
			int t=a[i].to;
			if(!dfn[t])
			{
				tarjan(t,i^1);
				low[now]=min(low[now],low[t]);
			}
			else if(!col[t]) low[now]=min(low[now],dfn[t]);
		}
		if(dfn[now]==low[now])
		{
			col[now]=++sum;
			while(st[top]!=now) col[st[top--]]=sum;
			--top;
		}
	}
	int dep[N],lg[N],b[N][21];
	inline void dfs(int now,int fa)
	{
		int sum=eg[now].size();
		dep[now]=dep[fa]+1;
		b[now][0]=fa;
		for(int i=1;i<=20;++i) b[now][i]=b[b[now][i-1]][i-1];
		for(int i=0;i<sum;++i)
		{
			int t=eg[now][i];
			if(t==fa) continue;
			dfs(t,now);
		}
	}
	inline int query(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]^dep[y]) x=b[x][lg[dep[x]-dep[y]]-1];
		if(x==y) return x;
		for(int i=20;~i;--i)
			if(b[x][i]^b[y][i]) x=b[x][i],y=b[y][i];
		return b[x][0];
	}
	int tag1[N],tag2[N];
	bool flag;
	bool vis[N];
	inline void dfs1(int now,int fa)
	{
		vis[now]=1;
		int sum=eg[now].size();
		for(int i=0;i<sum;++i)
		{
			int t=eg[now][i];
			if(t==fa) continue;
			dfs1(t,now);
			tag1[now]+=tag1[t];
			tag2[now]+=tag2[t];
		}
		if(tag1[now]&&tag2[now]) flag=1;
	}
	inline void main()
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;++i) link(read(),read());
		for(int i=1;i<=n;++i)
			if(!dfn[i]) tarjan(i,0);
		for(int i=1;i<=n;++i) f[i]=i,lg[i]=lg[i>>1]+1;
		lg[0]=1;
		for(int now=1;now<=n;++now)
		{
			for(int i=head[now];i;i=a[i].nxt)
			{
				int t=col[a[i].to];
				if(find(t)==find(col[now])) continue;
				f[find(t)]=find(col[now]);
				eg[col[now]].push_back(t);
				eg[t].push_back(col[now]);
			}
		}
		n=sum;
		for(int i=1;i<=n;++i) if(!dep[i]) dfs(i,0);
		for(int x,y,lca,i=1;i<=k;++i)
		{
			x=col[read()],y=col[read()];
			if(find(x)!=find(y))
			{
				flag=1;
				continue;
			}
			lca=query(x,y);
			++tag1[x],--tag1[lca];
			++tag2[y],--tag2[lca];
		}
		for(int i=1;i<=n;++i) if(!vis[i]) dfs1(i,0);
		puts(flag?"No":"Yes");
	}
}
signed main()
{
	red::main();
	return 0;
}