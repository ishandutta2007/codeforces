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
	const int N=5e4+10;
	int haku;
	int n,m,k,sum;
	int a[N],b[N];
	inline void main()
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;++i) a[i]=a[i-1]+read();
		for(int i=1;i<=m;++i) b[i]=b[i-1]+read();
		for(int i=1;i<=min(k,m);++i)
		{
			if(k%i) continue;
			int tmp1=0,tmp2=0;
			for(int j=i;j<=m;++j)
			{
				if(b[j]-b[j-i]==i) ++tmp1;
			}
			for(int j=k/i;j<=n;++j)
			{
				if(a[j]-a[j-(k/i)]==(k/i)) ++tmp2;
			}
			sum+=tmp1*tmp2;
		}
		printf("%lld\n",sum);
	}
}
signed main()
{
	red::main();
	return 0;
}