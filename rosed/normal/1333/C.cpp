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
	const int N=3e5+10;
	int n,l,sum,ret;
	map<int,int> s;
	inline void main()
	{
		n=read();
		s[0]=1;
		for(int i=1;i<=n;++i)
		{
			sum+=read();
			if(s[sum]) l=max(l,s[sum]);
			ret+=(i-l);
			s[sum]=i+1;
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}