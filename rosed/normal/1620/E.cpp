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
	const int N=5e5+10;
	int T,n,m,k;
	int a[N],f[N];
//	inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
	struct node
	{
		int x,y,z;
	}q[N];
	inline void main()
	{
		m=read();
		for(int i=1;i<=5e5;++i) f[i]=i;
		for(int opt,i=1;i<=m;++i)
		{
			opt=read();
			if(opt==1) a[++n]=read();
			else
			{
				q[++k].x=read();
				q[k].y=read();
				q[k].z=n;
			}
		}
		int t=k;
		for(int i=n;i;--i)
		{
			while(t&&q[t].z>=i)
			{
				f[q[t].x]=f[q[t].y];
				--t;
			}
			a[i]=f[a[i]];
		}
		for(int i=1;i<=n;++i) printf("%lld ",a[i]);
		puts("");
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
10
1 1
1 2
1 2
2 2 4
1 3
1 2
2 1 2
1 2
2 2 3
1 3

*/