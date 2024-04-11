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
	const int N=5050;
	int haku;
	int n;
	char s[N][N];
	int pos;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			scanf("%s",s[1]+1);
			pos=1;
			for(int i=2;i<=n;++i)
			{
				int t=0;
				for(int j=i;j<=n;++j) s[i][++t]=s[1][j];
				if((n-i)%2==1)
				{
					for(int j=1;j<i;++j) s[i][++t]=s[1][j];
				}
				else
				{
					for(int j=i-1;j;--j) s[i][++t]=s[1][j];
				}
			}
			for(int i=2;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(s[pos][j]<s[i][j]) break;
					if(s[i][j]<s[pos][j])
					{
						pos=i;
						break;
					}
				}
			}
			for(int i=1;i<=n;++i) putchar(s[pos][i]);
			puts("");
			printf("%lld\n",pos);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

*/