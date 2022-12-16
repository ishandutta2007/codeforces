#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();bool flag=0;
			cin>>(s+1);
			int len=(n+1)/2;
			for(int i=len+1;i<=n&&!flag;++i)
			{
				if(s[i]=='0')
				{
					printf("%d %d %d %d\n",1,i,1,i-1);
					flag=1;
				}
			}
			for(int i=1;n-(i+1)+1>=len&&!flag;++i)
			{
				if(s[i]=='0')
				{
					printf("%d %d %d %d\n",i,n,i+1,n);
					flag=1;
				}
			}
			if(!flag)
			{
				if(n%2==0)
				printf("%d %d %d %d\n",1,n/2,n/2+1,n);
				else 
				printf("%d %d %d %d\n",1,n/2+1,n/2+1,n);
			} 
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
5
11011

*/