#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int sumx[55],sumy[55];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	scanf("%d",&k),sumx[i]+=k,sumy[j]+=k;
	if(sumx[1]||sumx[n]||sumy[1]||sumy[m])
	printf("2\n");else printf("4\n");
}