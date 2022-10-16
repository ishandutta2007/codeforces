#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
char c;
int type[23];//0:set 0,1:set 1,2:no move,3:swap
int main()
{
	scanf("%d",&n);
	for(int i=0;i<10;i++)type[i]=2;
	for(int i=1;i<=n;i++)
	{
		scanf(" %c%d",&c,&m);
		for(int b=0;b<=9;b++)
		{
			if(c=='|'&&(m&(1<<b)))type[b]=1;
			else if(c=='&'&&((~m)&(1<<b)))type[b]=0;
			else if(c=='^'&&(m&(1<<b)))type[b]^=1;
		}
	}
	int a=(1<<10)-1,o=0,x=0;
	for(int b=0;b<=9;b++)
	{
		if(type[b]==0)a&=~(1<<b);
		else if(type[b]==1)o|=1<<b;
		else if(type[b]==3)x^=1<<b;
	}
	printf("3\n& %d\n| %d\n^ %d\n",a,o,x);
	return 0;
}