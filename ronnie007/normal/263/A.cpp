#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
	{
	int i,j;
	int x;
	int spx;
	int spy;
	for(i=0;i<5;i++)
		{
		for(j=0;j<5;j++)
			{
			scanf("%d",&x);
			if(x==1)
				{
				printf("%d\n",abs(i-2)+abs(j-2));
				}
			}
		}
	return 0;
	}