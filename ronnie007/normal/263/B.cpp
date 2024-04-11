#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
	{
	int n,k;
	int a[100];
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
	sort(a,a+n);
	if(k>n)printf("-1\n");
	else
		{
		printf("%d %d\n",a[n-k],0);
		}
	return 0;
	}