#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,Maxr,Maxc;
int rsum[105],csum[105];
char s[105][105];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(s[i][j]=='E')
	++rsum[i],++csum[j];
	for(i=1;i<=n;++i)
	{
		if(rsum[i]>Maxr)Maxr=rsum[i];
		if(csum[i]>Maxc)Maxc=csum[i];
	}
	if(Maxr!=n)
	{
		for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		if(s[i][j]!='E')
		{
			printf("%d %d\n",i,j);
			break;
		}
		return 0;
	}
	if(Maxc!=n)
	{
		for(j=1;j<=n;++j)
		for(i=1;i<=n;++i)
		if(s[i][j]!='E')
		{
			printf("%d %d\n",i,j);
			break;
		}
		return 0;
	}
	printf("-1\n");
}