#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49){c=getchar();}
	return c&1;
}
int a[300005];
int b[300005];
signed main()
{
    int T=read();
    while(T--)
    {
    	int n=read(),sum0=0,sum1=0,tag=0;
		for(int i=0;i<n;i++)a[i]=re1d();
		for(int i=0;i<n;i++)b[i]=re1d();
		for(int i=0;i<n;i++)if(a[i])sum1++;else sum0++;
		for(int i=n-1;i>=0;i--)
		{
			if((a[i]^tag)==b[i])
			{
				if(a[i]^tag)sum1--;
				else sum0--;
				continue;
			}
			if(sum1!=sum0){puts("NO");goto ng;}
			if(b[i])sum1--;
			else sum0--;
			tag^=1;
		}
		puts("YES");
		ng:;
	}
    return 0;
}