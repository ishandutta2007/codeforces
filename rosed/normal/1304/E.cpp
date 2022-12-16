#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=1e5+10;
	int n,m;
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
	int dep[N],f[N][21],lg[N];
	inline void dfs(int now,int fa)
	{
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
		int ret=0;
		if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]^dep[y])
		{
			int d=lg[dep[x]-dep[y]]-1;
			ret+=1<<d;
			x=f[x][d];
		}
		if(x==y) return ret;
		for(int i=20;~i;--i)
			if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i],ret+=1<<(i+1);
		return ret+2;
	}
	inline void main()
	{
		n=read();
		for(int i=1;i<n;++i) link(read(),read());
		dfs(1,0);
		for(int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
		lg[0]=1;
		m=read();
		for(int aa,bb,x,y,k,kk,i=1;i<=m;++i)
		{
			x=read(),y=read(),aa=read(),bb=read(),k=read();
			kk=k&1;
			int len1=query(aa,bb);
			int len2=query(aa,x)+query(bb,y)+1;
			int len3=query(aa,y)+query(bb,x)+1;
			if((len1%2==kk&&len1<=k)||(len2%2==kk&&len2<=k)||(len3%2==kk&&len3<=k)) puts("YES");
			else puts("NO");
		}
	}
}
signed main()
{
//	freopen("data.out","r",stdin);
//	freopen("ans.out","w",stdout);
	red::main();
	return 0;
}
/*
5
1 2
2 3
3 4
4 5
5
1 4 1 3 2

*/