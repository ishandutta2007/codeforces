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
	int T;
	int n;
	char s[N];
	bool vis[100];
	bool vis2[100];
	bool f[10][10];
	inline bool isprime(int x)
	{
		for(int i=2;i*i<=x;++i)
		{
			if(x%i==0) return 0;
		}
		return 1;
	}
	inline void main()
	{
		T=read();
		for(int i=2;i<=99;++i) vis[i]=isprime(i); 
		for(int i=10;i<=99;++i)
		{
			if(i%10==0) continue;
			if(!vis[i]) f[i%10][i/10]=1;
		}
		while(T--)
		{
			n=read();
			cin>>(s+1);
			memset(vis2,0,sizeof(vis2));
			bool flag=0;
			for(int x,i=1;i<=n;++i)
			{
				x=s[i]-'0';
				if(!vis[x])
				{
					printf("1\n%lld\n",x);
					flag=1;
					break;
				}
			}
			for(int x,i=1;i<=n&&!flag;++i)
			{
				x=s[i]-'0';
				for(int k=1;k<=9;++k)
				{
					if(f[x][k]&&vis2[k]) 
					{
						printf("2\n%lld\n",k*10+x);
						flag=1;
						break;
					}
				}
				if(flag) break;
				vis2[x]=1;
			}
		} 
	}
}
signed main()
{
	red::main();
	return 0;
}
//90 103 99 83 102 70 86 70 99 71