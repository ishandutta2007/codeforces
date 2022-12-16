#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
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
	const int N=1010;
	int haku; 
	char s[N];
	int n,ret;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			scanf("%s",s+1);
			n=strlen(s+1);
			ret=0;
			bool flag=0;
			int sum=0;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='0') ++sum;
				else
				{
					if(flag) ret+=sum;
					else flag=1;
					sum=0;
				}
			}
			printf("%lld\n",ret);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}