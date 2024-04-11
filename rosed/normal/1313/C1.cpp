#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=1e3+10,p=998244353;
	int haku;
	int n,sum,ret,pos,pre;
	int a[N],c[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i)
		{
			sum=a[i],pre=a[i];
			for(int j=i-1;j;--j)
			{
				pre=min(pre,a[j]);
				sum+=pre;
			}
			pre=a[i];
			for(int j=i+1;j<=n;++j)
			{
				pre=min(pre,a[j]);
				sum+=pre;
			}
			if(sum>ret) ret=sum,pos=i;
		}
		c[pos]=a[pos];
		for(int i=pos-1;i;--i) c[i]=min(a[i],c[i+1]);
		for(int i=pos+1;i<=n;++i) c[i]=min(a[i],c[i-1]);
		for(int i=1;i<=n;++i) printf("%lld ",c[i]); 
	}
}
signed main()
{
	red::main();
	return 0;
}