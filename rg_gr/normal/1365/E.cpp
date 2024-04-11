#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#define int long long
inline int max(int a,int b){return a>b?a:b;
}
//#define __int128 long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57)f=(c=='-'?-1:f),c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
int a[505];
signed main()
{
	int n=read(),ans=0;
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)ans=max(ans,a[i]|a[j]|a[k]);
	printf("%lld\n",ans);
}