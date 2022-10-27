#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const int N=308;
int n,a[N];
int main(void)
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=2;i<=n;i+=2)
	{
		while(a[i-1]||a[i])
		{
			if(a[i-1]){a[i-1]--;printf("P");}
			printf("R");
			if(a[i]){a[i]--;printf("P");}
			printf("L");
		}
		printf("R");
		if(i+1<=n)printf("R");
	}
	if(n&1)
	while(a[n])
	{
		a[n]--;
		printf("PLR");
	}
	return 0;
}