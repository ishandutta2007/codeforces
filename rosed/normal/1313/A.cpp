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
	const int N=1e5+10,p=998244353;
	int haku;
	int a[4],sum;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			a[1]=read(),a[2]=read(),a[3]=read();
			sort(a+1,a+4);
			sum=0;
			if(a[1]) --a[1],++sum;
			if(a[2]) --a[2],++sum;
			if(a[3]) --a[3],++sum;
			if(a[2]&&a[3]) --a[2],--a[3],++sum;
			if(a[1]&&a[3]) --a[1],--a[3],++sum;
			if(a[1]&&a[2]) --a[1],--a[2],++sum;
			if(a[1]&&a[2]&&a[3]) ++sum;
			printf("%lld\n",sum);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}