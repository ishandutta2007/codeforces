#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
int a[200005];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),x=read();
		for(int i=0;i<n;i++)a[i]=read();
		std::sort(a,a+n);
		int cur=n-1,c=0,q=0;
		while(cur>=0)
		{
			c+=a[cur];
			if(c/(q+1)>=x)q++;
			else break;
			cur--;
		}
		printf("%lld\n",q);
	}
}