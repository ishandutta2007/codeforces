#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1) 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=5e5+10;
	int haku;
	int n,m;
	int ret;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			ret=0;
			if(!m)
			{
				puts("0");
				continue;
			}
			if(m>=(n>>1))
			{
				ret=((n)*(n-1))>>1;
				ret+=m;
				printf("%lld\n",ret);
			}
			else
			{
				int l=1,r=n;
				int t=1;
				while(l<=r)
				{
					if(m*mid<=n-mid+1) t=mid,l=mid+1;
					else r=mid-1;
				}
				ret=((1+t)*t)>>1;
				ret*=m;
				n=n-t;
				ret+=((1+n)*n)>>1;
				printf("%lld\n",ret);
			}
		}
	}
}
signed main()
{

	red::main();
	return 0;
}