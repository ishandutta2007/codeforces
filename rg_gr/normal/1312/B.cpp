#include <stdio.h>
#define T int
inline T read()
{
	T num = 0; int f = 1; char c = getchar();
	while (c < 48 || c > 57){ if (c == '-')f = -1; c = getchar(); }
	while (c >= 48 && c <= 57)num = num * 10 + (c ^ 48), c = getchar();
	return num * f;
}
int a[105];
#include <algorithm>
int main()
{
	int t=read();
	while(t--)
	{
		int n=read();
		for(int i=0;i<n;i++)a[i]=read();
		std::sort(a,a+n);
		for(int i=n-1;i>=0;i--)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}