#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n;
	int a[N];
	char s[N];
	int pre[N],suf[N];
	bool flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();flag=0;
			for(int i=1;i<=n;++i) a[i]=read(),suf[i]=pre[i]=0;
			cin>>(s+1);
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='R')
				{
					if(a[i]>n) flag=1;
					else if(a[i]>0) ++suf[a[i]];
				}
				else
				{
					if(a[i]<1) flag=1;
					else if(a[i]<=n) ++pre[a[i]];
				}
			}
			pre[0]=suf[n+1]=0;
			for(int i=1;i<=n;++i)
			{
				pre[i]+=pre[i-1];
				if(pre[i]>i) flag=1; 
			}
			for(int i=n;i;--i)
			{
				suf[i]+=suf[i+1];
				if(suf[i]>n-i+1) flag=1;
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