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
int a[200005];
int check(int n)
{
	int h=1,t=n,cur=0;
	while(h<=t)
	{
		if(h[a]<t[a])
		{
			if(h[a]>=cur)cur=h[a],h++;
			else return 0;
		}
		else
		{
			if(t[a]>=cur)cur=t[a],t--;
			else return 0;
		}
	}
	return 1;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[n+1-i]=read();
		int L=1,R=n,ans=0;
		while(L<=R)
		{
			int m=L+R>>1;
			if(check(m))L=m+1,ans=m;
			else R=m-1;
		}
		printf("%lld\n",n-ans);
	}
}