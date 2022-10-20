#include<iostream>
#include<stdio.h>
using namespace std;


int n;
int x,y;
int mx=0;
int c;

void input();


int main()
	{
	input();
	//system("pause");
	return 0;
	}

void input()
	{
	scanf("%d",&n);
	int i;
	c=0;
	for(i=0;i<n;i++)
		{
		scanf("%d%d",&x,&y);
		c=c-x+y;
		if(c>mx)mx=c;
		}
	printf("%d\n",mx);
	}