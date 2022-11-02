#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,i,j,k,L,R,l,x;
char opt[10],s[10];

int main()
{
	L=-1500000000;
	R=1500000000;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s%d%s",opt+1,&x,s+1);
		l=strlen(opt+1);
		if(l==2)
		{
			if(opt[1]=='>')
			{
				if(s[1]=='Y')
				{
					if(x>L)L=x;
				}
				else
				{
					if(x-1<R)R=x-1;
				}
			}
			else
			{
				if(s[1]=='Y')
				{
					if(x<R)R=x;
				}
				else
				{
					if(x+1>L)L=x+1;
				}
			}
		}
		else
		{
			if(opt[1]=='>')
			{
				if(s[1]=='Y')
				{
					if(x+1>L)L=x+1;
				}
				else
				{
					if(x<R)R=x;
				}
			}
			else
			{
				if(s[1]=='Y')
				{
					if(x-1<R)R=x-1;
				}
				else
				{
					if(x>L)L=x;
				}
			}
		}
	}
	if(L<=R)printf("%d\n",L);
	else printf("Impossible\n");
}