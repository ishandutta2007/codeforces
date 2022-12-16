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
	int a[N];
	int f[N];
	int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>(s+1);
			n=strlen(s+1);
			for(int i=1;i<=n;++i) f[i]=i;
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				int t=i+1;
				if(t>n) t=1;
				if(s[i]=='E')
				{
					f[find(t)]=find(i);
				}
			}
			for(int i=1;i<=n;++i)
			{
				int t=i+1;
				if(t>n) t=1;
				if(s[i]=='N'&&find(i)==find(t)) flag=1;
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