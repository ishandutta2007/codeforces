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
	const int N=2e6+10,mod=998244353;
	int T,n,ans;
	struct node
	{
		int s,id;
		inline bool operator < (const node &t) const
		{
			return s>t.s;
		}
	}a[N];
	int pos[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();ans=0;
			for(int i=1;i<=n;++i) a[i].s=read(),a[i].id=i;
			pos[0]=0;
			sort(a+1,a+n+1); 
			for(int k=1,i=1;i<=n;i+=2,++k)
			{
				pos[a[i].id]=k;ans+=a[i].s*k*2;
				if(i<n) {pos[a[i+1].id]=-k;ans+=a[i+1].s*k*2;}
			}
			printf("%lld\n",ans);
			for(int i=0;i<=n;++i) printf("%lld ",pos[i]);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}