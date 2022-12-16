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
	const int N=3e5+10,mod=1e9+7;
	int T,n,m,sum,ans;
	int pw[N];
	struct node
	{
		int l,r,x;
		inline bool operator < (const node &t) const
		{
			return r<t.r;
		}
	}a[N];
	int b[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();pw[0]=1;ans=0;
			for(int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
			for(int i=1;i<=m;++i) a[i].l=read(),a[i].r=read(),a[i].x=read();
			sort(a+1,a+m+1);
			for(int k=0;k<30;++k)
			{
				sum=0;
				for(int i=1;i<=n;++i) b[i]=0;
				for(int i=1;i<=m;++i)
				{
				//	if(k==1) cout<<(a[i].x)<<"!!"<<endl;
					if((a[i].x>>k)&1)
					{
						
					//	cout<<"!!!!"<<endl;
						if(!b[a[i].l]) ++sum,b[a[i].l]=1;
					}
				}
				int x=pw[sum-1],y=pw[n-sum];
			//	cout<<(x*y%mod*(1<<k))%mod<<"!!"<<endl;
				ans=(ans+x*y%mod*(1<<k)%mod)%mod;
			}
			printf("%lld\n",ans);
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
2 1
1 2 2

*/