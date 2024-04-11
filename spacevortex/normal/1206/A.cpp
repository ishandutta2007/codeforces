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
const int N=210;
int n,m,amx=0,bmx=0;
int main()
{
	int i,x;
	n=rd();
	for(i=1;i<=n;i++)
	{
		x=rd();amx=max(amx,x);
	}
	m=rd();
	for(i=1;i<=m;i++)
	{
		x=rd();bmx=max(bmx,x);
	}
	printf("%d %d",amx,bmx);
	return 0;
}