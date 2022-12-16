#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,n;
	char s[N];
	bool flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>(s+1);
			n=strlen(s+1);flag=0;
			if(n&1){puts("NO");continue;}
			for(int i=1,j=n/2+1;j<=n;++i,++j)
			{
				if(s[i]!=s[j]){flag=1;break;}
			}
			puts(flag?"NO":"YES");
		} 
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
3
EENEE

*/