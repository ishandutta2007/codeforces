#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ans;

int main()
{
	scanf("%d%d",&n,&m);
	while(n)
	{
		ans+=n;
		k+=n;
		n=k/m;
		k%=m;
	}
	printf("%d\n",ans);
}