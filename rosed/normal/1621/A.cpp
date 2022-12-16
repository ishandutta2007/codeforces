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
	const int N=3e5+10,mod=998244353;
	int T,n,k;
	int a[45][45];
	inline void main()
	{
		T=read(); 
		while(T--)
		{
			n=read(),k=read();
			if((n+1)/2<k) {puts("-1");continue;}
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j) a[i][j]=0;
			
			for(int i=1,j=1;j<=k;i+=2,++j) a[i][i]=1;
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					putchar(a[i][j]?'R':'.');
				}
				puts("");
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}