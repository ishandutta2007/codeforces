#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int check(int x)
{
	if(x%2==0)return x*x/2;
	else return (x/2)*(x+1)+1;
}
int main()
{
	int x;scanf("%d",&x);
	if(x==1){printf("1\n");return 0;}
	if(x%4==0)
	{
		int n=1;
		while(1)
		{
			if(check(n)*4+4*(n/2)>=x)
			{
				printf("%d\n",2*n+1);
				return 0;
			}
			n++;
		}
	}
	if(x%4==1)
	{
		int n=1;
		while(1)
		{
			if(check(n)*4+4*(n/2)>=x-1)
			{
				printf("%d\n",2*n+1);
				return 0;
			}
			n++;
		}
	}
	if(x%4==2)
	{
		if(x==2)
		{
			printf("3\n");
			return 0;
		}
		int n=2;
		while(1)
		{
			if(check(n)*4+4*(n/2-1)>=x-2)
			{
				printf("%d\n",2*n+1);
				return 0;
			}
			n++;
		}
	}
	if(x%4==3)
	{
		if(x==3)
		{
			printf("5\n");
			return 0;
		}
		int n=2;
		while(1)
		{
			if(check(n)*4+4*(n/2-1)>=x-3)
			{
				printf("%d\n",2*n+1);
				return 0;
			}
			n++;
		}
	}
	return 0;
}