#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int a[200005];
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int maxmin(int x)
{
	int maxn=0,minn=9;
	while(x)maxn=max(maxn,x%10),minn=min(minn,x%10),x/=10;
	return maxn*minn;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int a1=read(),k=read();
		for(int i=2;i<=k;i++)
		{
			int u=maxmin(a1);
			if(u)a1+=u;
			else break;
		}
		printf("%lld\n",a1);
	}
}