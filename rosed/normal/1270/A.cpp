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
	const int N=110;
	int haku;
	int n,k1,k2;
	int a[N],b[N];
	bool flag;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),k1=read(),k2=read();
			flag=0;
			for(int i=1;i<=k1;++i) {a[i]=read();if(a[i]==n) flag=1;}
			for(int i=1;i<=k2;++i) b[i]=read();
			puts(flag?"YES":"NO");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}