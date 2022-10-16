#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

int n,m;

int main()
{
	scanf("%d",&n);
	if(n%4==0)
	{
		printf("0\n%d",n/2);
		for(int i=4;i<=n;i+=4)
		{
			printf(" %d %d",i-3,i);
		}
	}
	else if(n%4==1)
	{
		printf("1\n%d",n/2);
		for(int i=5;i<=n;i+=4)
		{
			printf(" %d %d",i-3,i);
		}
	}
	else if(n%4==2)
	{
		printf("1\n%d 2",n/2);
		for(int i=6;i<=n;i+=4)
		{
			printf(" %d %d",i-3,i);
		}
	}
	else
	{
		printf("0\n%d 3",n/2);
		for(int i=7;i<=n;i+=4)
		{
			printf(" %d %d",i-3,i);
		}
	}
	return 0;
}