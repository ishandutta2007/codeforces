#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x,y,now;
long long ans;

int main()
{
	scanf("%d%d",&n,&m);now=1;
	for(;m;--m)
	{
		scanf("%d",&x);
		y=x-now;
		if(y<0)y+=n;
		ans+=y;
		now=x;
	}
	printf("%I64d\n",ans);
}