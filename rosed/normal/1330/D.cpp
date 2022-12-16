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
	const int N=110;
	int haku;
	int mod,d,ret;
	int a[N],b[N];
	inline void solve(int x)
	{
		for(int i=100;i;--i) b[i]=a[i-1]*x%mod;
		for(int i=1;i<=100;++i) a[i]=(b[i]+a[i])%mod;
	}
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			d=read(),mod=read();ret=0;
			if(d==1)
			{
				printf("%lld\n",d%mod);
				continue;
			}
			++d;
			for(int i=0;i<=100;++i) a[i]=b[i]=0;
			a[0]=a[1]=1;
			int t=2;
			while((1<<t)<=d)
			{
				solve((1<<t)-(1<<(t-1)));
				++t;
			}
			solve(d-(1<<(t-1)));
			for(int i=1;i<=100;++i) (ret+=a[i])%=mod;
			printf("%lld\n",ret);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
10
1 1000000000
2 999999999
3 99999998
4 9999997
5 999996
6 99995
7 9994
8 993
9 92
10 1

*/