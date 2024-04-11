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
	const int N=3e5+10;
	int T,n;
	int a,b,c;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int x=1;x*x<=n;++x)
			{
				if(n%x==0)
				{
					c=x;
					int tmp=n/c-1;
					if(tmp%2==0)
					{
						a=(tmp/2-1)*c,b=(tmp/2+1)*c;
						while(a%2==0) --a,++b;
					}
					else
					{
						a=(tmp/2)*c,b=(tmp/2+1)*c;
					}
					break;
				}
			}
	//	cout<<a+b+c<<' '<<__gcd(a,b)<<"!!!"<<endl;
			printf("%lld %lld %lld\n",a,b,c);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
k1g+k2g+g=n;
n=(k1+k2+1)
n-1=k1+k2
*/