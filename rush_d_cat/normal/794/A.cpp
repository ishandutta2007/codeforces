#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
int main(void)
{
	int i,j,k,a,b,c,n;
	scanf("%d%d%d%d",&a,&b,&c,&n);
	k=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		if(b<j&&j<c)k++;
	}
	printf("%d",k);
	return 0;
}