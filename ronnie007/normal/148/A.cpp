#include<iostream>
#include<stdio.h>
using namespace std;

int main()
	{
	int a,b,c,d,n;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	int i;
	int br=0;
	for(i=1;i<=n;i++)
		{
		if(i%a==0 || i%b==0 || i%c==0 || i%d==0)br++;
		}
	printf("%d\n",br);
	//system("pause");
	return 0;
	}