#include<cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	int x=n/7;
	int y=(4-n%4)%4;
	while (x>=0&&x%4!=y) x--;
	if (x%4!=y) puts("-1");
		else 
		{
			for (int i=0;i<(n-7*x)/4;i++) printf("4");
			for (int i=0;i<x;i++) printf("7");
			puts("");
		}	
}