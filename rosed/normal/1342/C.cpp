#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
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
	const int N=1e5+10,p=1e9+7;
	int haku,a,b,n,m;
	int sum[40010];
	inline int solve(int l,int r)
	{
		int ret=0;
		int t1=l/n;
		int t2=l%n;
		if(t2) ret-=sum[t2-1];
		int t3=r/n;
		ret+=sum[n]*(t3-t1);
		int t4=r-t3*n;
		return ret+sum[t4];
	}
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			a=read(),b=read(),m=read();
			if(a>b) swap(a,b);
			n=a*b;
			memset(sum,0,sizeof(sum));
			for(int i=1;i<=n;++i)
			{
				sum[i]=sum[i-1];
				if((i%a)!=(i%b%a)) ++sum[i];
			}
			for(int l,r,i=1;i<=m;++i)
			{
				l=read(),r=read();
				printf("%lld ",solve(l,r));
			}
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
7 10 2
7 8
100 210

*/