#include <stdio.h>
#include <math.h>
#include <string.h>
inline int read()
{
	char c=getchar();int num=0;
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
const double pi=acos(-1);
int main()
{
	int T=read();
	while(T--)
	{
		int n=read()<<1;
		printf("%.8lf\n",1/tan(pi/n));
	}
}