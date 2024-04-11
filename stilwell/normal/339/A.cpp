#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,i,j,k,n1,n2,n3;
char s[1005];
bool add;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;++i)
	{
		if(s[i]=='1')++n1;
		if(s[i]=='2')++n2;
		if(s[i]=='3')++n3;
	}
	for(;n1;--n1)
	{
		if(add)printf("+");
		printf("1");
		add=true;
	}
	for(;n2;--n2)
	{
		if(add)printf("+");
		printf("2");
		add=true;
	}
	for(;n3;--n3)
	{
		if(add)printf("+");
		printf("3");
		add=true;
	}
	printf("\n");
}