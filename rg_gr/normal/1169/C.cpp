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
int a[300005];
int b[300005];
int check(int u,int m,int n)
{
	for(int i=1;i<=n;i++)
	{
		int v=(m+b[i-1]-b[i])%m;
	//	printf("%lld %lld\n",u,v);
		if(v<=u)
		{
			b[i]=b[i-1];
		}
		else if(b[i]>=b[i-1])continue;
		else return 0;
	}
	return 1;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int L=0,R=m-1,ans;
	while(L<=R)
	{
		int M=L+R>>1;
		for(int i=1;i<=n;i++)b[i]=a[i];
		if(check(M,m,n))ans=M,R=M-1;
		else L=M+1;
	}
	printf("%lld\n",ans);
}