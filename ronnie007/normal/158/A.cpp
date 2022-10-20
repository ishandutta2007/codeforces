#include<iostream>
#include<stdio.h>
using namespace std;


int n;
int k;
int a[60];


void input();


int main()
	{
	input();
	//system("pause");
	return 0;
	}


void input()
	{
	scanf("%d%d",&n,&k);
	int i;
	int br=0;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		if(i<=k-1 && a[i]>0)br++;
		if(i>k-1 && a[i]==a[k-1] && a[i]!=0)br++;
		}
	printf("%d\n",br);
	}