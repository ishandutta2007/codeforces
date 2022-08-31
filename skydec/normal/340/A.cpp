#include<stdio.h>
using namespace std;
int gcd(int x,int y)
{
	if(!x||!y)return x+y;
	return gcd(y,x%y);
}
int x,y,a,b;
int main()
{
	scanf("%d%d%d%d",&x,&y,&a,&b);
	x=x*y/gcd(x,y);
	printf("%d\n",(b/x)-((a-1)/x));
	return 0;
}