#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10;
	const double eps=1e-8;
	int n,s1,s2;
	double p[2020],u[2020];
	double f[2010][2010];
	int g[2010][2010];
	inline void check(double x)
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=s2&&j<=i;++j)
			{
				f[i][j]=f[i-1][j],g[i][j]=g[i-1][j];
				if(j&&f[i-1][j-1]+u[i]>f[i][j]+eps)
				{
					f[i][j]=f[i-1][j-1]+u[i];
					g[i][j]=g[i-1][j-1];
				}
				if(f[i-1][j]+p[i]-x>f[i][j]+eps)
				{
					f[i][j]=f[i-1][j]+p[i]-x;
					g[i][j]=g[i-1][j]+1;
				}
				if(j&&f[i-1][j-1]+p[i]+u[i]-p[i]*u[i]-x>f[i][j]+eps)
				{
					f[i][j]=f[i-1][j-1]+p[i]+u[i]-p[i]*u[i]-x;
					g[i][j]=g[i-1][j-1]+1;
				}
			}
		}
	}
	inline void main()
	{
		n=read(),s1=read(),s2=read();
		for(int i=1;i<=n;++i) scanf("%lf",&p[i]);
		for(int i=1;i<=n;++i) scanf("%lf",&u[i]);
		double l=0,r=1,ret;
		while(r-l>eps)
		{
			double mid=(l+r)/2;
			check(mid);
			if(g[n][s2]<=s1) ret=mid,r=mid;
			else l=mid;
		}
		check(ret);
		printf("%.10f",f[n][s2]+s1*ret);
	}
}
signed main()
{
	red::main();
	return 0;
}