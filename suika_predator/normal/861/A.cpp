#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
long long n;
int m;
int main()
{
	scanf("%I64d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		if(n%5==0)n/=5;
	}
	for(int i=1;i<=m;i++)
	{
		if(n%2==0)n/=2;
	}
	printf("%I64d",n);
	for(int i=1;i<=m;i++)printf("0");
	printf("\n");
	return 0;
}