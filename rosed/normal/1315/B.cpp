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
	const int N=1e5+10,mod=1e9+7;
	int haku;
	int n,a,b,k;
	char s[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			a=read(),b=read(),k=read();
			scanf("%s",s+1);n=strlen(s+1);
			s[n]='C';
			int pos=n;
			for(int i=n-1;i;--i)
			{
				if(s[i]!=s[i+1])
				{
					int t=s[i]=='A'?a:b;
					k-=t;
					pos=i+1;
					if(k<0) break;
				}
			}
			if(k>=0) pos=1;
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
1
3 2 8
AABBBBAABB

*/