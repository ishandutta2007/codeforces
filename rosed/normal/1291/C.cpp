#include<bits/stdc++.h>
using namespace std;
namespace red{
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
	const int N=5050;
	int haku;
	int n,m,k,ret;
	int a[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read(),k=read();
			for(int i=1;i<=n;++i) a[i]=read();
			k=min(k,m-1);
			ret=0;
			for(int i=0;i<=k;++i)
			{
				int ans=1e9+7,suf=k-i;
				for(int j=i;j<=i+(m-k)-1;++j)
				{
					int tail=(m-k-(j-i));
					ans=min(ans,max(a[j+1],a[n-suf-tail+1]));
				}
				ret=max(ret,ans);
			}
			cout<<ret<<endl;
		}
	}
}
signed main()
{

	red::main();
	return 0;
}