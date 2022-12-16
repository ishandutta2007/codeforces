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
	const int N=1e5+10;
	int haku;
	int n,m,ret;
	int a[110];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			ret=0;
			memset(a,0,sizeof(a));
			for(int x,i=1;i<=m;++i)
			{
				x=read();
				for(int i=0;i<60;++i)
				{
					if((x>>i)&1)
					{
						++a[i];
						break;
					}
				}
			}
			for(int i=0;i<62;++i)
			{
				if((n>>i)&1)
				{
					if(a[i]) --a[i];
					else
					{
						bool flag=0;
						for(int k=i+1;k<63;++k)
						{
							if(a[k])
							{
								--a[k];
								for(int j=k-1;j>=i;--j) ++a[j];
								ret+=(k-i);
								flag=1;
								break;
							}
						}
						if(!flag)
						{
							ret=-1;
							break;
						}
					}
				}
				a[i+1]+=a[i]>>1;
			}
			printf("%lld\n",ret);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}