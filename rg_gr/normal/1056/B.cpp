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
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
int a[1005],b[1005];
signed main()
{
	int n=read(),m=read();
	if(n*n*2<m)
	{
		puts("0");
		return 0;
	}
	//if(m==1)
	for(int i=0;i<m;i++)
	{
		int j=i*i%m;
		//if(j==0)j=m;
		if(n-i>=0)a[j]+=(n-i)/m+1;
		if(i==0)a[j]--;
	}
	a[m]=a[0];
	int ans=0;
	for(int i=0;i<m;i++)ans=ans+a[i]*a[m-i];//,printf("%lld ",a[i]);
	printf("%lld\n",ans);
}