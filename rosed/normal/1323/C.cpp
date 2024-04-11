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
	const int N=1e6+10;
	int haku;
	int n,m,ret;
	char s[N];
	inline void main()
	{
		n=read();
		scanf("%s",s+1);
		if(n&1)
		{
			puts("-1");
			return;
		}
		int sum=0,pos=0;
		bool f=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='(') ++sum;
			else --sum;
			if(!f&&sum<0) f=1,pos=i-1;
			if(f&&sum==0)
			{
				ret+=i-pos;
				f=0;
			}
		}
		if(f) ret+=n-pos;
		if(sum) puts("-1");
		else printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}