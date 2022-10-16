#include <stdio.h>
#include <string.h>
inline int read()
{
	char c=getchar();int num=0;
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
char a[200005];
int b[3][200005],c[3][200005];
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",a);
		int n=strlen(a);
		for(int i=0;i<n;i++)
		{
			a[i]-=49;
			b[a[i]][i]=i;
			b[(a[i]+1)%3][i]=i>0?b[(a[i]+1)%3][i-1]:-10000000;
			b[(a[i]+2)%3][i]=i>0?b[(a[i]+2)%3][i-1]:-10000000;
		}
		for(int i=n-1;i>=0;i--)
		{
			c[a[i]][i]=i;
			c[(a[i]+1)%3][i]=i<n-1?c[(a[i]+1)%3][i+1]:10000000;
			c[(a[i]+2)%3][i]=i<n-1?c[(a[i]+2)%3][i+1]:10000000;
		}
		int ans=0x3f3f3f3f;
		for(int i=1;i<n-1;i++)
		{
			if(a[i]==0)ans=min(ans,c[(a[i]+1)%3][i+1]-b[(a[i]+2)%3][i-1]+1);
			if(a[i]==0)ans=min(ans,c[(a[i]+2)%3][i+1]-b[(a[i]+1)%3][i-1]+1);
		}
		for(int i=1;i<n-1;i++)
		{
			if(a[i]==1)ans=min(ans,c[(a[i]+1)%3][i+1]-b[(a[i]+2)%3][i-1]+1);
			if(a[i]==1)ans=min(ans,c[(a[i]+2)%3][i+1]-b[(a[i]+1)%3][i-1]+1);
		}
		for(int i=1;i<n-1;i++)
		{
			if(a[i]==2)ans=min(ans,c[(a[i]+1)%3][i+1]-b[(a[i]+2)%3][i-1]+1);
			if(a[i]==2)ans=min(ans,c[(a[i]+2)%3][i+1]-b[(a[i]+1)%3][i-1]+1);
		}
		printf("%d\n",ans>200000?0:ans);
	}
}