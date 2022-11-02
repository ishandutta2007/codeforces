#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,x,i,j,k,sum;

int main()
{
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		sum+=k;
	}
	printf("%d\n",abs(sum)/x+(abs(sum)%x!=0));
}