#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=3e5+10;
	int haku;
	int n;
	int a[N],pre[N],suf[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				pre[i]=(a[i]<(i-1));
				pre[i]+=pre[i-1];
				suf[i]=(a[i]<(n-i));
			}
			suf[n+1]=0;
			for(int i=n;i;--i) suf[i]+=suf[i+1];
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				if(!pre[i]&&!suf[i])
				{
					puts("Yes");
					flag=1;
					break;
				}
			}
			if(!flag) puts("No");
		}
	}
}
signed main()
{

	red::main();
	return 0;
}