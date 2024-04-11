#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,l,r;
	int ans;
	int a[21][N]; 
	inline void main()
	{
		T=read();
		for(int k=0;k<=20;++k)
		{
			for(int i=1;i<=2e5;++i)
			{
				a[k][i]=a[k][i-1];
				if(((i>>k)&1)==0) ++a[k][i];
			}
		}
		while(T--)
		{
			l=read(),r=read();ans=1e9+7;
			for(int k=0;k<20;++k)
			{
				ans=min(ans,a[k][r]-a[k][l-1]);
			}
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
3
EENEE

*/