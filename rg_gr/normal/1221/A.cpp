#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	//int num=0,f=1;char c=getchar();
	//while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	//while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
char a[200005];
signed main()
{
int T=read();
while(T--)
{
	//int n=read();
	//for(int i=1;i<=n;i++)a[i]=re1d();
	int n=read(),x=0;
	for(int i=0;i<n;i++)
	{
		int y=read();
		if(y<=2048)x+=y;
	}
	if(x>=2048)puts("YES");
	else puts("NO");
}
}
//1m1m4m5m1m4m 1p9p1p9p8p1p 5z