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
	const int N=3e5+10;
	int n,m,sum,ans;
	int a[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i];
		sort(a+1,a+n+1);
		a[0]=-1e15,a[++n]=1e15; 
		m=read();
		for(int x,y,t,i=1;i<=m;++i)
		{
			x=read(),y=read();
			t=lower_bound(a+1,a+n+1,x)-a;
			ans=1e18;
			if(t<=n) ans=max(0ll,y-(sum-a[t]));
			//cout<<y<<' '<<(sum-a[t])<<"!!!!"<<endl;
			--t;
			if(t>=1) ans=min(ans,x-a[t]+max(0ll,y-(sum-a[t])));
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}