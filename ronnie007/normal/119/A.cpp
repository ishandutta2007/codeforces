#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int a,b,n;



void input();
void solve();


int main()
	{
	input();
	solve();
	//system("pause");
	return 0;
	}


void input()
	{
	scanf("%d%d%d",&a,&b,&n);
	}


void solve()
	{
	int x;
	while(1)
		{
		x=__gcd(a,n);
		//printf("%d %d \n",x,n);
		if(n>x)
			{
			n=n-x;
			}
		else
			{
			printf("0\n");
			break;
			}
		x=__gcd(b,n);
		//printf("%d %d \n",x,n);
		if(n>x)
			{
			n=n-x;
			}
		else
			{
			printf("1\n");
			break;
			}
		}		
	}