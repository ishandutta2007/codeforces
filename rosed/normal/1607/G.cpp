#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,m,sum,tot;
	int l[N],r[N];
	int tl,tr;
	bool vis[N];
	int f[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();
			tl=tr=sum=0;
			for(int x,y,i=1;i<=n;++i)
			{
				x=read(),y=read();
				sum+=x-y+m;
				l[i]=max(m-y,0ll),r[i]=min(m,x);
				tl+=l[i],tr+=r[i];
			}
			if(sum<2*tl)
			{
				printf("%lld\n",2*tl-sum);
				for(int i=1;i<=n;++i) printf("%lld %lld\n",l[i],m-l[i]);
			}
			else if(sum>2*tr)
			{
				printf("%lld\n",sum-2*tr);
				for(int i=1;i<=n;++i) printf("%lld %lld\n",r[i],m-r[i]);
			}
			else
			{
				printf("%lld\n",sum&1);tot=sum>>1;
				for(int i=1;i<=n;++i) f[i]=l[i],tot-=l[i];
				for(int i=1;i<=n;++i)
				{
					if(tot)
					{
						f[i]+=min(r[i]-l[i],tot);
						tot=max(0ll,tot-(r[i]-l[i]));
					}
					printf("%lld %lld\n",f[i],m-f[i]);
				}
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}