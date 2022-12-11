#include<cstdio>
using namespace std;

int n,Flag;

int main()
{
	scanf("%d",&n);
	if (n==0) Flag=1;
	while (Flag||n)
	{
		int x=n%10;
		if (x<5) printf("O-|");else printf("-O|"),x-=5;
		for (int i=0;i<x;i++) printf("O");
		printf("-");
		for (int i=0;i<4-x;i++) printf("O");
		printf("\n");
		n/=10;Flag=0;
	}
}