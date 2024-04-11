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
	const int N=1010;
	int haku;
	int n,m,ans;
	int vis[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;++i) vis[read()]=1;
			int t=1,k=0;
			while(1)
			{
				if(!vis[t])
				{
					if(k==m) break;
					++k;
				}
				++t;
			}
			printf("%lld\n",t-1);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
13 4
1 2 2 2 1 2 1 1 1 2 2 1 1


*/