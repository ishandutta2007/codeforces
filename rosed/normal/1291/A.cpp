#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=10010;
	int haku;
	int n,sum;
	char s[N]; 
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			scanf("%s",s+1);
			sum=0;
			for(int i=1;i<=n;++i)
			{
				s[i]-='0';
				sum+=s[i];
			}
			if((sum&1)==0)
			{
				while((s[n]&1)==0&&n) --n;
				if(!n)
				{
					puts("-1");
				}
				else
				{
					for(int i=1;i<=n;++i)
					{
						putchar(s[i]+48);
					}
					puts("");
				}
			}
			else
			{
				while((s[n]&1)==0&&n) --n;
				--n;
				while((s[n]&1)==0&&n>=0) --n;
				if(n<=0)
				{
					puts("-1");
				}
				else
				{
					for(int i=1;i<=n;++i)
					{
						putchar(s[i]+48);
					}
					puts("");
				}
			}
		}
	}
}
signed main()
{

	red::main();
	return 0;
}