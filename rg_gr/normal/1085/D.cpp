#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#define int long long
//#define __int128 long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57)f=(c=='-'?-1:f),c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
int deg[100005];
signed main()
{
	int n=read(),m=read(),ans=0;
	for(int i=1;i<n;i++)deg[read()]++,deg[read()]++;
	for(int i=1;i<=n;i++)if(deg[i]==1)ans++;
	printf("%.10lf\n",2.0*m/ans);
}