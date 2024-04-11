#include<cstdio>
using namespace std;

int c[10];
int x;

int main()
{
	scanf("%d",&x);x++;
	for (;;x++)
	{
		int y=x,Flag=1;
		while (y) 
			if (c[y%10]==x) {Flag=0;break;}
				else c[y%10]=x,y/=10;
		if (Flag) break;
	}
	printf("%d\n",x);
}