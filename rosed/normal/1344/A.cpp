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
	const int N=2e5+10,p=1e9+7;
	int haku,n,ret;
	int a[N];
	bool vis[N],flag;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();flag=0;
			for(int i=0;i<n;++i) a[i]=(read()%n+n)%n;
			for(int i=0;i<n;++i) vis[i]=0;
			for(int i=0;i<n;++i)
			{
				int t=(i+a[i])%n;
				flag|=vis[t];vis[t]=1;
			}
			puts(flag?"NO":"YES");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
2 
4 
0 < 1 
0 < 2 
0 < 3

*/