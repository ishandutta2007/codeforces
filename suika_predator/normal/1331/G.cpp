#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[23];
double b[23];
int main()
{
	for(int i=1;i<=11;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for(int i=11;i>=1;i--)
	{
		b[i]=a[i]*a[i]*a[i]*5+sqrt(abs(a[i]));
		if(b[i]<400)
			printf("f(%d) = %.2f\n",a[i],b[i]);
		if(b[i]>400)
			printf("f(%d) = MAGNA NIMIS!\n",a[i]);
	}
	return 0;
}