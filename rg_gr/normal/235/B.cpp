#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define int long long
const int mod=1000003;
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57)f=(c=='-'?-1:f),c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
signed main()
{
	int n=read();double b=0,c=0;
	while(n--)
	{
		double q;scanf("%lf",&q);
		b+=(c+c+1)*q;
		c=(c+1)*q;
	}
	printf("%.9lf\n",b);
}