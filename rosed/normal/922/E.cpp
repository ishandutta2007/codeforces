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
	const int N=2e5+10,base=131,mod=998244353;
	int n;
	int w,up,b,x,sum;
	int a[N],c[N],s[N];
	int f[10010][2],t;
	inline void main()
	{
		n=read(),w=up=read(),b=read(),x=read();
		for(int i=1;i<=n;++i) a[i]=read(),s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;++i) c[i]=read();
		memset(f,-0x3f,sizeof(f));
		f[0][0]=up;
		for(int i=1;i<=n;++i)
		{
			t^=1;
			for(int k=0;k<=s[i];++k) f[k][t]=-2e18;
			for(int j=0;j<=a[i];++j)
			{
				for(int k=s[i];k>=j;--k)
				{
					if(f[k-j][t^1]<c[i]*j) continue;
					f[k][t]=max(f[k][t],f[k-j][t^1]-c[i]*j);
				}
			}
			for(int k=0;k<=s[i];++k) f[k][t]=min(up+k*b,f[k][t]+x);
		}
		for(int k=s[n];~k;--k) if(f[k][t]>=0)
		{
			sum=k;break;
		}
		printf("%lld\n",sum);
	}
}
signed main()
{
	red::main();
	return 0;
}