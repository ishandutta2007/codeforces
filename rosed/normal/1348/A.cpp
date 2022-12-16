#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=998244353;
	int haku,n,m,sum;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=n/2;
			sum=1<<n;
			for(int i=1;i<m;++i) sum+=(1<<i);
			for(int i=m;i<n;++i) sum-=(1<<i); 
			printf("%lld\n",abs(sum));
		}
	}
}
signed main()
{
	red::main();
	return 0;
}