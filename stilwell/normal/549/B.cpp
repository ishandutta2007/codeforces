#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int a[105];
bool use[105];
char s[105][105];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(;;)
	{
		for(i=1;i<=n;++i)
		if(a[i]==0)
		{
			++m;
			for(j=1;j<=n;++j)
			if(s[i][j]=='1')
			--a[j];
			use[i]=true;
		}
		for(i=1;i<=n;++i)if(a[i]==0)break;
		if(i>n)break;
	}
	printf("%d\n",m);
	for(i=1;i<=n;++i)if(use[i])printf("%d ",i);
	printf("\n");
}