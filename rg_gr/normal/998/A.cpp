#include <stdio.h>
#include <stdlib.h>
inline long long read()
{
	char c=getchar(); long long f = 1, num = 0;
	while (c< 48||c>57){if (c == '-')f = -1; c = getchar();}
	while (c >= '0'&&c <= '9')num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return f*num;
}
inline void quit(int bl)
{
	if(bl)
	{
		puts("-1");
		exit(0);
	}
}
int main()
{
	int n=read(),num;
	quit(n==1);
	if(n==2)
	{
		int a=read(),b=read();
		quit(a==b);
		printf("1\n1\n");
		return 0;
	}
	puts("1");
	int minn=114514,m=n;
	while(n--)
	{
		int x=read();
		if(x<minn)minn=x,num=n;
	}
	printf("%d\n",m-num);
	return 0;
}//!