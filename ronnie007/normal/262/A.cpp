#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

	int n,k;

void input();
int solve(int x);


int main()
    {
    input();
    return 0;
    }


void input()
    {
	int x;
	int i;
	int ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		{
		scanf("%d",&x);
		ans+=solve(x);
		}
	printf("%d\n",ans);
    }


int solve(int x)
    {
	int br=0;
	int cifra=-1;
	while(x>0)
		{
		cifra=x%10;
		if(cifra==4 || cifra==7)br++;
		x=x/10;
		}
	if(br<=k)return 1;
	return 0;
    }