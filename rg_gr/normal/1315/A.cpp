#include <stdio.h>
#define T int
inline T read()
{
	T num = 0; int f = 1; char c = getchar();
	while (c < 48 || c > 57){ if (c == '-')f = -1; c = getchar(); }
	while (c >= 48 && c <= 57)num = num * 10 + (c ^ 48), c = getchar();
	return num * f;
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
int a[105];
int main()
{
	int t=read();
	while(t--)
	{
		int n=read(),m=read(),x=read(),y=read();
		printf("%d\n",max(m*max(x,n-x-1),n*max(y,m-y-1)));
	}
	return 0;
}