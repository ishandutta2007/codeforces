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
	int n,ret;
	int a[N];
	int c[N],num;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			for(int i=1;i<=n;++i) a[i]=read();
			num=0;
			for(int i=1;i<=n;++i)
			{
				if(i!=1&&a[i-1]==-1&&a[i]!=-1) c[++num]=a[i];
				if(i!=n&&a[i+1]==-1&&a[i]!=-1) c[++num]=a[i];
			}
			sort(c+1,c+num+1);
			int t=(c[1]+c[num]);
			if(t&1)
			{
				int t1=t>>1,t2=t>>1;
				t2+=1;
				if(min(t1-c[1],c[num]-t1)<min(t2-c[1],c[num]-t2)) t=t1;
				else t=t2;
			}
			else t>>=1;
			if(!num) t=0;
			ret=0;
			for(int i=1;i<=n;++i) if(a[i]==-1) a[i]=t;
					for(int i=1;i<n;++i)
					{
						ret=max(ret,abs(a[i]-a[i+1]));
					}
					printf("%lld %lld\n",ret,t);
		}
	}
}
signed main()
{

	red::main();
	return 0;
}