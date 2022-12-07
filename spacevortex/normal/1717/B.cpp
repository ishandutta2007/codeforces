#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
int T,n,K,r,c,val;
int main()
{
	//freopen("a.in","r",stdin);
	int i,j,ans1,ans2;
	T=rd();
	while(T--)
	{
		n=rd();K=rd();r=rd();c=rd();
		ans1=ans2=0;
		val=r+c;val%=K;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i+j)%K==val) ans1++;
			}
		}
		val=r+n-c;
		val%=K;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i+n-j)%K==val) ans2++;
			}
		}
		if(ans1<=ans2)
		{
			val=r+c;val%=K;
			for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i+j)%K==val) putchar('X');
				else putchar('.');
			}
			putchar('\n');
		}
		}
		else 
		{
				val=r+n-c;
		val%=K;
				for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i+n-j)%K==val) putchar('X');
				else putchar('.');
			}
			putchar('\n');
		}
		}
	}
	return 0;
}