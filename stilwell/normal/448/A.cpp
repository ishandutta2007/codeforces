#include <stdio.h>
#include <stdlib.h>
using namespace std;

int a1,a2,a3,b1,b2,b3,n;

int main()
{
	scanf("%d%d%d",&a1,&a2,&a3);
	scanf("%d%d%d",&b1,&b2,&b3);
	scanf("%d",&n);
	if((a1+a2+a3)/5+((a1+a2+a3)%5!=0)+(b1+b2+b3)/10+((b1+b2+b3)%10!=0)>n)
	printf("NO\n");else printf("YES\n");
}