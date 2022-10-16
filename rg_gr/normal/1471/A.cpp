#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),x=read(),minn=0,maxn=0;
		while(n--)
		{
			int q=read();
			minn+=q;
			maxn+=(q-1)/x+1;
		}
		minn=(minn-1)/x+1;
		printf("%lld %lld\n",minn,maxn);
	}
	return 0;
}