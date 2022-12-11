#include<cstdio>
using namespace std;

const int MAX=10000;
int n,x;

int main()
{
	scanf("%d",&x);
	if (x==3) {printf("5\n");return 0;}
	if (x%4!=3)
	{
		for (int i=1;i<=MAX;i+=2)
			if (i*i/2+1>=x) {printf("%d\n",i);break;}
	}
	else
	{
		for (int i=1;i<=MAX;i+=2)
			if (i*i/2-1>=x) {printf("%d\n",i);break;}
	}
}