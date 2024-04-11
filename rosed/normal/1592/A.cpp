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
	const int N=5e5+10;
	int T,n,hp;
	int s1,s2,s;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),hp=read();
			s1=s2=0;
			for(int x,i=1;i<=n;++i)
			{
				x=read();
				if(x>s1) s2=s1,s1=x;
				else if(x>s2) s2=x;
			}
			s=s1+s2;
			int sum=ceil((double)(hp)/(double)(s));
			int tot=sum*s;
			if(tot-s2>=hp) sum=sum*2-1;
			else sum=sum*2;
			printf("%lld\n",sum);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}