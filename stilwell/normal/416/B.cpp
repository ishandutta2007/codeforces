#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int t[50005][10];
int ans[50005],n,m,i,j,k;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	scanf("%d",&t[i][j]);
	for(j=1;j<=m;++j)
	for(i=1;i<=n;++i)
	ans[i]=max(ans[i],ans[i-1])+t[i][j];
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
	printf("\n");
}