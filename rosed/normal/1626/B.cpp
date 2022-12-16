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
	int T,n,st;
	char s[N];
	int a[N];
	bool flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>(s+1);n=strlen(s+1);flag=0;st=1;
			for(int i=1;i<=n;++i) a[i]=s[i]-'0';
			for(int i=n;i>1;--i)
			{
				if(a[i]+a[i-1]>=10)
				{
					int t=a[i]+a[i-1];
					a[i-1]=1;
					a[i]=t%10;
					flag=1;break;
				}
			}
			if(!flag) a[2]+=a[1],st=2;
			for(int i=st;i<=n;++i) printf("%lld",a[i]);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
87495
15495
81195
87135
87414

*/