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
const int N=4e5+50;
int T,n;
int a[N],b[N];
int main()
{
	//freopen("a.in","r",stdin);
	int i,pd;
	T=rd();
	while(T--)
	{
		n=rd();pd=1;
		for(i=1;i<=n;i++) a[i]=rd();
		for(i=1;i<=n;i++) b[i]=rd();
		a[n+1]=a[1];b[n+1]=b[1];
		for(i=1;i<=n;i++) if(a[i]>b[i]) pd=0;
		for(i=1;i<=n;i++)
		{
			if(b[i]>=b[i+1]+2&&a[i]<b[i]) pd=0;
		}
		if(pd) puts("YES");
		else puts("NO");
	}
	return 0;
}