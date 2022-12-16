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
	const int N=1e5+10;
	int haku;
	int n,k;
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
	bool vis[N];
	int s[N],num,sum;
	inline void dfs(int now,int fa)
	{
		bool f=0;
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(t==fa||vis[t]) continue;
			dfs(t,now);f=1;
		}
		if(!f) s[++num]=now;
	}
	inline void main()
	{
		n=read();k=n/2;
		for(int x,y,i=1;i<n;++i)
		{
			x=read(),y=read();
			link(x,y);
		}
		int rt=1,lca;
		dfs(1,0);
		while("haku")
		{
			int a,b;
			if(num>=2) a=s[1],b=s[2];
			else if(num==1) a=rt,b=s[1];
			else
			{
				cout<<"! "<<rt<<endl;
				return;
			}
			cout<<"? "<<a<<' '<<b<<endl;
			lca=read();
			if(lca==a||lca==b||++sum==k)
			{
				cout<<"! "<<lca<<endl;
				return;
			}
			vis[a]=vis[b]=1;
			rt=lca;num=0;
			dfs(rt,0);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

*/