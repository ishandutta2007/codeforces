#include<cstdio>
#define GO {puts("NO");return 0;}
using namespace std;

int n,sum,i;

int main()
{
	scanf("%d",&n);sum=n-1;
	if (n<4) GO;puts("YES");
	if ((n-4)&1) 
	{
		sum-=4;
		printf("3 + 4 = 7\n7 + 5 = 12\n12 * 2 = 24\n24 * 1 = 24\n");
		for (i=1;i<=(n-5)/2;i++) printf("%d - %d = 1\n",5+i*2,5+i*2-1),sum--;
		for (i=1;i<sum;i++) puts("1 * 1 = 1");if (n>5) puts("24 * 1 = 24");
	}
	else
	{
		printf("3 * 4 = 12\n12 * 2 = 24\n24 * 1 = 24\n");
		sum-=3;
		for (i=1;i<=(n-4)/2;i++) printf("%d - %d = 1\n",4+i*2,4+i*2-1),sum--;
		for (i=1;i<sum;i++) puts("1 * 1 = 1");if (n>4) puts("24 * 1 = 24");
	}
}