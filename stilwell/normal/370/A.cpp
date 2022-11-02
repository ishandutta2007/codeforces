#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int r1,c1,r2,c2;

int main()
{
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	printf("%d %d %d\n",
		(r1!=r2)+(c1!=c2),
		((r1^r2)&1)==((c1^c2)&1)
		?(r1-c1!=r2-c2)+(r1+c1!=r2+c2)
		:0,
		abs(r1-r2)+abs(c1-c2)-min(abs(r1-r2),abs(c1-c2)));
	scanf("\n");
}