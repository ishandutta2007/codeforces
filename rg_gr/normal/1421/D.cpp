// Problem: D. Hexagons
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/D
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
#define int long long
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
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
#define fs(x,y,z) x=min(x,(y)+(z))
signed main()
{
	int T=read();
	while(T--)
	{
		int y=read(),x=read(),a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
		for(int i=0;i<1000;i++)
		{
			fs(b,a,c);
			fs(c,b,d);
			fs(d,c,e);
			fs(e,d,f);
			fs(f,e,a);
			fs(a,f,b);
		}
		     if(x>=y&&y>=0)oldl(y*a+(x-y)*b);
		else if(x>=0&&y>=x)oldl(x*a+(y-x)*f);
		else if(x<=0&&y>=0)oldl(-e*x+f*y);
		else if(x>=0&&y<=0)oldl(b*x-c*y);
		else if(x<=0&&y<=x)oldl(-d*x+(x-y)*c);
		else               oldl(-d*y+(y-x)*e);
	}
	return 0;
}