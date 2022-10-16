// Problem: E. Swedish Heroes
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
//#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while((c<48||c>49)&&c!='S'&&c!='F')c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int a,b,c,d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==1&&j==2)a=re1d();
				else if(i==2&&j==1)b=re1d();
				else if(i==n-1&&j==n)c=re1d();
				else if(i==n&&j==n-1)d=re1d();
				else re1d();
			}
		if(a==b)
		{
			int x=0;
			if(c==a)x++;
			if(d==a)x++;
			odl(x);
			if(c==a)odp(n-1,n);
			if(d==a)odp(n,n-1);
		}
		else
		{
			if(c==d)
			{
				odl(1);
				if(c==a)odp(1,2);
				else odp(2,1);
			}
			else
			{
				odl(2);
				if(a)odp(1,2);
				else odp(2,1);
				if(c)odp(n,n-1);
				else odp(n-1,n);
			}
		}
	}
	return 0;
}