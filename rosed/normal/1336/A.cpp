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
	const int N=4e5+10,inf=1<<30;
	int n,m,ret; 
	int head[N],cnt;
	struct point
	{
		int nxt,to;
		point(){}
		point(const int &nxt,const int &to):nxt(nxt),to(to){}
	}a[N<<2];
	inline void link(int x,int y)
	{
		a[++cnt]=(point){head[x],y};head[x]=cnt;
		a[++cnt]=(point){head[y],x};head[y]=cnt;
	}
	priority_queue<int> q;
	int dep[N],sum[N];
	int str[N];
	inline void dfs(int now,int fa)
	{
		dep[now]=dep[fa]+1;
		str[now]=1;
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(t==fa) continue;
			dfs(t,now);
			str[now]+=str[t];
		}
		q.push(dep[now]-1-(str[now]-1));
	}
	inline void main()
	{
		n=read(),m=read();
		for(int x,y,i=1;i<n;++i)
		{
			x=read(),y=read();
			link(x,y);
		}
		dfs(1,0);
		while(m--) ret+=q.top(),q.pop();
		printf("%lld\n",ret);
	}
}
signed main()
{
	//freopen("haha.in","r",stdin);
	red::main();
	return 0;
}