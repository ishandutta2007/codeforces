#include<cstdio>
using namespace std;

int n,A,G,ta,tg;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&ta,&tg);
		if (G+tg-A>500) A+=ta,putchar('A');else G+=tg,putchar('G');
	}
}