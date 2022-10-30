#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,A,B,C,D,i,j,k,sum1,sum2,val;

int main()
{
	scanf("%d%d%d%d",&A,&B,&C,&D);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&val),sum1+=min(A*val,B);
	for(i=1;i<=m;++i)scanf("%d",&val),sum2+=min(A*val,B);
	sum1=min(sum1,C);sum2=min(sum2,C);
	printf("%d\n",min(sum1+sum2,D));
}