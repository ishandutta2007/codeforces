#include<cstdio>
#include<cstring>
char a[1005];
int main()
{
	int n,i;
	scanf("%s",a+1);n=strlen(a+1);
	for(i=1;i<=n;++i)putchar(a[i]); 
	for(i=n;--i;)putchar(a[i]);
}