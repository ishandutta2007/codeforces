#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,K,i,j,k,u,v;

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(;K;--K)
	{
		scanf("%d%d",&u,&v);
		if(u<=5||v<=5||n-u<=4||m-v<=4)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}