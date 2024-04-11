#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if (n%4==0)
	{
		printf("0\n");
		printf("%d ",n/2);
		for(int i = 1;i<=n/4;i++) printf("%d ",i);
		for(int i = 3*(n/4)+1;i<n;i++) printf("%d ",i);
		printf("%d\n",n);
	}
	if (n%4==3&&n!=3)
	{
		printf("0\n");
		printf("%d 3 ",n/2);
		for(int i = 4;i<=n/4+3;i++) printf("%d ",i);
		for(int i = 3*(n/4)+4;i<n;i++) printf("%d ",i);
		printf("%d\n",n);		
	}
	if (n==3) 
	{
		printf("0\n1 3\n");
	}
	if (n%4==2&&n!=2)
	{
		printf("1\n");
		printf("%d 1 ",n/2);
		for(int i = 3;i<=n/4+2;i++) printf("%d ",i);
		for(int i = 3*(n/4)+3;i<n;i++) printf("%d ",i);
		printf("%d\n",n);		
	}
	if (n==2)
	{
		printf("1\n1 1\n");
	}
	if (n%4==1)
	{
		printf("1\n");
		printf("%d ",n/2);
		for(int i = 2;i<=n/4+1;i++) printf("%d ",i);
		for(int i = 3*(n/4)+2;i<n;i++) printf("%d ",i);
		printf("%d\n",n);		
	}
	return 0;
}