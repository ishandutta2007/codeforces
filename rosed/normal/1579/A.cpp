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
	const int N=1e5+10;
	int T,n; 
	char s[N];
	int sum;
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>(s+1);
			n=strlen(s+1);sum=0;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='B') --sum;
				else ++sum;
			}
			puts(sum?"NO":"YES");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}