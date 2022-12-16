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
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=998244353;
	int T,n,m,r,c;
	char s[110][110];
	int totr,totc;
	int flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read(),r=read(),c=read();
			flag=3;
			for(int i=1;i<=n;++i)
			{
				cin>>(s[i]+1);
				for(int j=1;j<=m;++j)
				{
					if(s[i][j]=='B')
					{
						if(i==r&&j==c) flag=0;
						else if(i==r||j==c) flag=min(flag,1ll);
						else flag=min(flag,2ll);
					}
				}
			}
			if(flag==3) puts("-1");
			else printf("%lld\n",flag);
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