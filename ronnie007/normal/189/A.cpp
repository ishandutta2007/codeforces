#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int n,a,b,c;

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
	scanf("%d%d%d%d",&n,&a,&b,&c);
    }


void solve()
    {
	int i,j;
	int mx=0;
	for(i=0;i*a<=n;i++)
		{
		for(j=0;j*b+i*a<=n;j++)
			{
			if((n-j*b-i*a)%c==0)
				{
				mx=max(mx,j+i+(n-j*b-i*a)/c);
				}
			}
		}
	printf("%d\n",mx);
    }