#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=998244353;
	int haku,n,m,k,cnt,s,sum;
	int a[110],c[110],b[110];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),k=read();
			int sum=0;
			memset(c,0,sizeof(c));
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				if(!c[a[i]]) c[a[i]]=1,b[++sum]=a[i];
			}
			if(sum>k) {puts("-1");continue;}
			printf("%lld\n",n*k);
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=k;++j)
				{
					int t=j%sum;
					if(!t) t=sum;
					printf("%lld ",b[t]);
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
/*
4
5 3
1 2 2 1 3

3 2
1 2 3
4 4
4 3 4 2

*/