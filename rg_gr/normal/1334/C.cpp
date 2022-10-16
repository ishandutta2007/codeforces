#include <stdio.h>
#include <string.h>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
int a[300005],b[300005],c[300005];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),x=0x3f3f3f3f3f3f3f3fll,p=0,sum=0;
		for(int i=0;i<n;i++)a[i]=read(),b[(i+1)%n]=read();
		for(int i=0;i<n;i++)p+=a[i],
		sum+=c[i]=a[i]>=b[i]?b[i]:a[i],x=x<c[i]?x:c[i];
		printf("%lld\n",p-sum+x);
	}
}