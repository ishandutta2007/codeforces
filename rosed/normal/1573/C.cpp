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
	const int N=4e5+10;
	int T,n,ans; 
	struct edge
	{
		int nxt,to;
	} a[N<<1];
	int head[N],cnt;
	int rd[N],f[N],tot;
	queue<int> q;
	inline void link(int x,int y)
	{
		a[++cnt].nxt=head[x];
		a[cnt].to=y;
		head[x]=cnt;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();tot=cnt=ans=0;
			for(int i=1;i<=n;++i) head[i]=f[i]=0;
			for(int x,i=1;i<=n;++i)
			{
				x=read();rd[i]=x;
				for(int k=1;k<=x;++k)
				{
					link(read(),i);
				}
				if(!x){ q.push(i);f[i]=1;}
			}
			while(!q.empty())
			{
				++tot;
				int now=q.front();
				q.pop();
				ans=max(ans,f[now]);
				for(int t,i=head[now];i;i=a[i].nxt)
				{
					t=a[i].to;
					if(now>t) f[t]=max(f[t],f[now]+1);
					else f[t]=max(f[t],f[now]);
					if(!--rd[t]) q.push(t);
				}
			}
			if(tot<n) puts("-1");
			else printf("%lld\n",ans);
		}
		
	}
}
signed main()
{
	red::main();
	return 0;
}