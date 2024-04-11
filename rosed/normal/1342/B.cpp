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
	const int N=110,p=1e9+7;
	int haku,n,ret;
	bool flag;
	char s[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			scanf("%s",s+1);n=strlen(s+1);
			flag=0;
			for(int i=2;i<=n;++i)
			{
				if(s[i]!=s[i-1])
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				for(int i=1;i<=n;++i)
				{
					putchar(s[i]);
				}
			}
			else
			{
				for(int i=1;i<=n;++i)
				{
					putchar('1');
					putchar('0');
				}
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