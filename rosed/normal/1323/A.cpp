#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
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
	int n;
	int a[N];
	bool f1,f2;
	int pos1,pos2,pos3;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			f1=f2=0;pos3=0;
			for(int x,i=1;i<=n;++i)
			{
				x=read();
				if(x&1)
				{
					if(!f1)f1=1,pos1=i;
					else pos3=i;
				}
				else
				{
					f2=1,pos2=i;
				}
			}
			if(f2)
			{
				printf("1\n%lld\n",pos2);
			}
			else if(f1&&pos3)
			{
				printf("2\n%lld %lld\n",pos1,pos3);
			}
			
			else
			puts("-1");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}