#include <algorithm>
#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
int a[35];
int main()
{
    int n=read();
    while(n--)
    {
        int n=read();
        printf("%d\n",(1<<((n>>1)+1))-2);
    }
    return 0;
}