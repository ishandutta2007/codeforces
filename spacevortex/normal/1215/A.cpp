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
int n,m,x,y,vmi=0,vmx=0;
void qmin(int tot)
{
	tot=max(tot-(x-1)*n-(y-1)*m,0);
	printf("%d ",tot);
}
void qmax(int tot)
{
	int cnt;
	cnt=min(n,tot/x);
	tot-=cnt*x;
	cnt+=tot/y;
	printf("%d",cnt);
}
int main()
{
	int tot;
	n=rd();m=rd();x=rd();y=rd();tot=rd();
	if(x>y)
	{
		swap(n,m);swap(x,y);
	}
	qmin(tot);qmax(tot);
	return 0;
	
}