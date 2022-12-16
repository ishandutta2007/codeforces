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
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,inf=2e9,mod=998244353; 
	int haku;
	int n,k,opt;
	int a[N];
	bool flag;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),k=read();flag=0;
			if(n==1)
			{
				int x=read();
				puts(x==k?"yes":"no");
				continue;
			}
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				if(a[i]==k) a[i]=0,flag=1;
				else if(a[i]>k) a[i]=1;
				else if(a[i]<k) a[i]=-1;
			}
			if(!flag)
			{
				puts("no");
				continue;
			}
			flag=0;
			for(int i=1;i<=n;++i)
			{
				if(a[i]>=0&&a[i+1]>=0&&i!=n) flag=1;
				if(a[i]>=0&&a[i+2]>=0&&i<n-1) flag=1;
			}
			puts(flag?"yes":"no");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
5
7 5
5 1 1 1 6 6 1

*/