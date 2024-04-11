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
char c[300005];
int pd(int i,int r)
{
	//printf("%lld %lld ",i,r);
	for(int l=i;l<=r;l++)
		for(int j=1;l+j+j<=r;j++)
			if(c[l]==c[l+j]&&c[l]==c[l+j+j])return 0;
	//puts("1");
	return 1;
}
signed main()
{
	scanf("%s",c);
	int n=strlen(c);
	long long ans=n*(n+1)/2;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<=i+7&&j<n;j++)ans-=pd(i,j);
	}
	printf("%lld\n",ans);
}