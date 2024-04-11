#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[505];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		memset(a,0,sizeof(a));
		for(int i=0;i<n+n;i++)
		{
			int x=read();
			if(a[x])continue;
			a[x]=1;
			printf("%lld ",x);
		}
		puts("");
	}
}