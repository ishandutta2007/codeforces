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
	const int N=3e5+10;
	int n,k;
	int haku;
	int a[N];
	int t[110];
	bool flag;
	int st[110],top;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),k=read();flag=0;
			for(int i=0;i<=100;++i) t[i]=0;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int i=1;i<=n;++i)
			{
				top=0;
				while(a[i])
				{
					st[++top]=a[i]%k;
					a[i]/=k;
				}
				for(int j=top;j;--j)
				{
					t[j-1]+=st[j];
				}
			}
			for(int i=0;i<=100;++i)
			{
				if(t[i]>1)
				{
					flag=1;
					break;
				}
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