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
int T,n,m,a,b;
int main()
{
	//freopen("a.in","r",stdin);
	T=rd();
	while(T--)
	{
		n=rd();m=rd();
		if(n==1&&m==1) puts("0");
		else
		{
			a=min(n,m);b=max(n,m);
			printf("%d\n",a*2+b-2);
		}
	}
	return 0;
}