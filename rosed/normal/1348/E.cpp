#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=510,mod=1e9+7,inf=0x3f3f3f3f; 
	int n,m; 
	bool f[2][N];
	int seq[N];
	inline void main()
	{
		n=read(),m=read();
		f[0][0]=1;
		long long sum=0;
		for(int a,b,i=1;i<=n;++i)
		{
			bool t=i&1;
			a=read(),b=read();
			sum+=a+b;
			int r=a>=m?m-1:a;
			int tot=0;
			for(int j=0;j<=r;++j)
				if((a-j-1+m)/m!=(a-j+b+m)/m) seq[++tot]=j;
			memset(f[t],0,sizeof(f[t]));
			for(int j=0;j<=m-1;++j)
			{
				if(f[t^1][j])
				{
					for(int k=1;k<=tot;++k)
					{
						f[t][(j+seq[k])%m]=1;
					}
				}
			}
		}
		long long ans=0;
		for(int r=0;r<=m-1;++r) if(f[n&1][r])
		{
			int b=((sum-r)%m+m)%m;
			ans=max(ans,(sum-b-r)/m);
		}
		printf("%lld\n",ans);
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
2 4
2 5
1 2

*/