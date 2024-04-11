#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=998244353;
	int haku,n,ret,maxn,ans;
	int a[N];
	int s[N][210];
	int tmp[210];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();ret=0;
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				for(int j=1;j<=200;++j) s[i][j]=s[i-1][j]+(a[i]==j);
			}
			a[n+1]=0;
			for(int k=1;k<=200;++k) ret=max(ret,s[n][k]),tmp[k]=n+1;
			for(int i=1;i<=n;++i)
			{
				--tmp[a[i]];
				while(tmp[a[i]]>=i&&a[tmp[a[i]]]!=a[i]) --tmp[a[i]];
				if(tmp[a[i]]<=i) continue;
				ans=0;
				for(int k=1;k<=200;++k)
				{
					ans=max(ans,s[tmp[a[i]]-1][k]-s[i][k]);
				}
				ret=max(ret,s[i][a[i]]*2+ans);
			}
			printf("%d\n",ret);
			for(int i=1;i<=n;++i)
			{
				a[i]=0;
				for(int k=1;k<=200;++k) s[i][k]=0;
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}