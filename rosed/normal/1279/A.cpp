#include<bits/stdc++.h>
using namespace std;
namespace red{
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	int haku;
	int n,m,k;
	int maxn,minn;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read(),k=read();
			maxn=max(max(n,m),k);
			if(maxn>n+m+k-maxn+1) puts("No");
			else puts("Yes");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}