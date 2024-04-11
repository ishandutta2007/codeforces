#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a;
int b;
int n;


void input();
void solve();


int main()
    {

    input();
    solve();
    return 0;
    }


void input()
    {
	scanf("%d%d%d",&a,&b,&n);
    }


void solve()
    {
	int i;
	int fl=-1;
	for(i=0;i<=9;i++)
		{
		if((10*a+i)%b==0){fl=i;break;}
		}
	if(fl==-1)
		{
		printf("-1\n");
		return ;
		}
	printf("%d%d",a,fl);
	for(i=0;i<n-1;i++)
		{
		printf("0");
		}
	printf("\n");
    }