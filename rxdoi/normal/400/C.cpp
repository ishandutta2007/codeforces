#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,x,y,z,p,a,b,pn,pm;

int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
	x%=4;y%=2;z%=4;
	pn=n;pm=m;
	for (int i=0;i<p;i++)
	{
		scanf("%d%d",&a,&b);
		n=pn;m=pm;
		for (int j=0;j<x;j++) {int ta=a;a=b;b=n-ta+1;swap(n,m);}
		for (int j=0;j<y;j++) b=m-b+1;
		for (int j=0;j<z;j++) {int tb=b;b=a;a=m-tb+1;swap(n,m);}
		printf("%d %d\n",a,b);
	}
}