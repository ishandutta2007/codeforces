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
	const int N=3e5+10,mod=998244353;
	int T,n;
	int a[N];
	bool vis[N];
	int st[N],top;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i) a[i]=0;
			for(int i=1;i<=n;++i) if(!a[i])
			{
				top=0;
				printf("? %lld\n",i);
				fflush(stdout);
				st[++top]=read();
				while("1")
				{
					printf("? %lld\n",i);
					fflush(stdout);
					st[++top]=read();
					if(st[top]==st[1]) break;
				}
				for(int i=1;i<top;++i) a[st[i]]=st[i+1];
			}
			printf("! ");
			for(int i=1;i<=n;++i)
			{
				printf("%lld",a[i]);
				if(i!=n) putchar(' ');
			}
			puts("");
			fflush(stdout);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1 3 4 2
1 2 3 4
1 3 4 2
1 4 2 3
1 2 3 4
*/