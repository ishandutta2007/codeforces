#include <stdio.h>
#define T char
inline void swap(T &x, T &y)
{
	T t = x;
	x = y, y = t;
}
#undef T
#define T int
inline T read()
{
	T num = 0; int f = 1; char c = getchar();
	while (c < 48 || c > 57){ if (c == '-')f = -1; c = getchar(); }
	while (c >= 48 && c <= 57)num = num * 10 + (c ^ 48), c = getchar();
	return num * f;
}
#undef T
char a[105];
inline int rvs(int w)
{
	for(int i=1,j=w>>1;i<=j;i++)swap(a[i],a[w+1-i]);
//	printf("%s\n",a+1);
}
int main()
{
	int n=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)
		if(n%i==0)rvs(i);
	printf("%s\n",a+1);
	return 0;
}