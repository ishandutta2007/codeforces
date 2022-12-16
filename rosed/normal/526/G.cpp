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
	const int N=3e5+10,inf=0x3f3f3f3f3f3f3f3f;
	int n,m,ans,sum,leave;
	int rd[N];
	int head[N],cnt;
	struct point
	{
		int nxt,to,val;
		point(){}
		point(const int &nxt,const int &to,const int &val):nxt(nxt),to(to),val(val){}
	}a[N<<1];
	inline void link(int x,int y,int z)
	{
		a[++cnt]=(point){head[x],y,z};head[x]=cnt;
		a[++cnt]=(point){head[y],x,z};head[y]=cnt;
	}
	struct tree
	{
		int rt,f[N][21],g[N][21],d[N],dep[N],son[N],top[N],rk[N];
		int l[N],r[N],s[N],tot;
		inline void dfs1(int now,int fa)
		{
			for(int i=head[now];i;i=a[i].nxt)
			{
				int t=a[i].to;
				if(t==fa) continue;
				d[t]=d[now]+a[i].val;
				dfs1(t,now);
			}
		}
		inline void dfs2(int now)
		{
			for(int i=head[now];i;i=a[i].nxt)
			{
				int t=a[i].to;
				if(t==f[now][0]) continue;
				f[t][0]=now,g[t][0]=a[i].val;
				for(int j=1;j<=20;++j)
				{
					f[t][j]=f[f[t][j-1]][j-1];
					g[t][j]=g[t][j-1]+g[f[t][j-1]][j-1];
				}
				d[t]=d[now]+a[i].val;
				dfs2(t);
				if(dep[t]+a[i].val>dep[now])
					dep[now]=dep[t]+a[i].val,son[now]=t;
			}
			for(int i=head[now];i;i=a[i].nxt)
			{
				int t=a[i].to;
				if(t==f[now][0]||t==son[now]) continue;
				s[l[++tot]=t]=dep[t]+a[i].val;
			}
		}
		inline void getrt(int now)
		{
			dfs1(now,0);rt=now;
			for(int i=1;i<=n;++i) if(d[i]>d[rt]) rt=i;
			d[rt]=0;dfs2(rt);s[l[++tot]=rt]=dep[rt];
			sort(l+1,l+tot+1,[&](int i,int j){return s[i]>s[j];});
			for(int i=1;i<=tot;++i) r[i]=r[i-1]+s[l[i]];
			for(int i=1;i<=tot;++i)
			{
				int x=l[i],p=x;
				while(x) top[x]=p,rk[x]=i,x=son[x];
			}
		}
		inline int solve1(int x,int y)
		{
			int z=dep[x];
			for(int i=20;~i;--i)
				if(rk[f[x][i]]>=y) z+=g[x][i],x=f[x][i];
			return r[y-1]+z+g[x][0];
		}
		inline int solve2(int x,int y)
		{
			int z=dep[x];
			for(int i=20;~i;--i)
				if(rk[f[x][i]]>y) z+=g[x][i],x=f[x][i];
			return r[y]-dep[f[x][0]]+z+g[x][0];
		}
		inline int ask(int x,int y)
		{
			y=2*y-1;
			return rk[x]<=y?r[y]:max(solve1(x,y),solve2(x,y));
		}
	}t[2];
	inline void main()
	{
		n=read(),m=read();
		for(int x,y,z,i=1;i<n;++i)
		{
			x=read(),y=read(),z=read();
			++rd[x],++rd[y];
			link(x,y,z);
			sum+=z;
		}
		for(int i=1;i<=n;++i) leave+=(rd[i]==1);
		t[0].getrt(1),t[1].getrt(t[0].rt);
		for(int x,y,i=1;i<=m;++i)
		{
			x=read(),y=read();
			x=(x+ans-1)%n+1,y=(y+ans-1)%n+1;
			printf("%lld\n",ans=2*y>=leave?sum:max(t[0].ask(x,y),t[1].ask(x,y)));
		}
	}
}
signed main()
{
	red::main();
	return 0;
}