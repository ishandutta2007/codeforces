#include<cstdio>
using namespace std;

int c5,c0,x,n;

int main()
{
	scanf("%d",&n);
	while (n--) {scanf("%d",&x);c5+=(x==5);c0+=(x==0);}
	if (!c0) {puts("-1");return 0;}
	if (c5<9) {puts("0");return 0;}
	for (int i=0;i<c5/9*9;i++) putchar('5');
	for (int i=0;i<c0;i++) putchar('0');
	printf("\n");
}