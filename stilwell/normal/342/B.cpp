#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,S,T,i,j,k,now,t,l,r,dl,dr;

int main()
{
	scanf("%d%d%d%d",&n,&m,&S,&T);
	if(m)scanf("%d%d%d",&t,&l,&r),--m;
	if(S<T)dl=-1;if(S>T)dr=1;
	l+=dl;r+=dr;
	for(now=1;S!=T;++now)
	{
		if(now==t)
		{
			if(S>=l&&S<=r)
			{
				printf("X");
				if(m)scanf("%d%d%d",&t,&l,&r),l+=dl,r+=dr,--m;
				continue;
			}
			if(m)scanf("%d%d%d",&t,&l,&r),l+=dl,r+=dr,--m;
		}
		if(S<T)printf("R"),++S;else printf("L"),--S;
	}
}