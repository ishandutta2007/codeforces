#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10;
	int haku;
	int n,ret;
	int a[N],tr[N];
	bool vis[N],g[N],f[N];
	inline int lowbit(int i)
	{
		return i&-i;
	}
	inline void update(int x,int k)
	{
		for(int i=x;i<=n;i+=lowbit(i))
			tr[i]+=k;
	}
	inline int query(int y)
	{
		int ret=0;
		for(int i=y;i;i-=lowbit(i))
			ret+=tr[i];
		return ret;
	}
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();ret=0;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int i=1;i<=n;++i)
			{
				if(vis[a[i]]) break;
				vis[a[i]]=1;
				update(a[i],1);
				if(query(i)==i) g[i]=1;
			}
			for(int i=1;i<=n;++i) vis[a[i]]=0,tr[i]=0;
			for(int i=n;i;--i)
			{
				if(vis[a[i]]) break;
				vis[a[i]]=1;
				update(a[i],1);
				if(query(n-i+1)==n-i+1) f[i]=1;
			}
			for(int i=1;i<n;++i)
				if(g[i]&&f[i+1]) ++ret;
			printf("%lld\n",ret);
			for(int i=1;i<n;++i)
				if(g[i]&&f[i+1]) printf("%lld %lld\n",i,n-i);
			for(int i=1;i<=n;++i) tr[i]=0,vis[a[i]]=0,g[i]=f[i]=0;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6
5
1 4 3 2 1

6
2 4 1 3 2 1
4
2 1 1 3
4
1 3 3 1
12
2 1 3 4 5 6 7 8 9 1 10 2
3
1 1 1


*/