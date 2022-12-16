#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=998244353;
	int T;
	int n;
	struct edge
	{
		int nxt,to,id;
	}a[N];
	int head[N],cnt;
	inline void link(int x,int y,int z)
	{
		a[++cnt].nxt=head[x];
		a[cnt].to=y;
		a[cnt].id=z;
		head[x]=cnt; 
	}
	int rd[N],ans[N],rt;
	inline void dfs(int now,int fa,int vf)
	{
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(t==fa) continue;
			ans[a[i].id]=vf^1;
			dfs(t,now,vf^1);
		}
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i) head[i]=rd[i]=0;cnt=0;
			for(int x,y,i=1;i<n;++i)
			{
				x=read(),y=read();
				link(x,y,i);link(y,x,i);
				++rd[x],++rd[y];
			}
			int maxn=0;
			for(int i=1;i<=n;++i)
			{
				if(rd[i]>maxn) maxn=rd[i],rt=i;
			}
			if(maxn>2){puts("-1");continue;}
			int js=0;
			for(int i=head[rt];i;i=a[i].nxt)
			{
				int t=a[i].to;
			//	cout<<rt<<' '<<t<<"!!"<<endl; 
				if(++js==1)
				{
					ans[a[i].id]=2;
					dfs(t,rt,2);
				} 
				else
				{
					ans[a[i].id]=3;
					dfs(t,rt,3);
				}
			}
			for(int i=1;i<n;++i) printf("%lld ",ans[i]);
			puts(" ");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
2 3 5 7 11 13 17 19 23 29 31

*/