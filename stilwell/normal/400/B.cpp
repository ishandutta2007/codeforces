#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,G,S;
int a[1005];
char s[1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;++j)if(s[j]=='G')G=j;else if(s[j]=='S')S=j;
		a[i]=S-G;
	}
	sort(a+1,a+n+1);
	if(a[1]<0)printf("-1\n");
	else
	{
		for(i=1;i<n;++i)
		if(a[i]!=a[i+1])++k;
		printf("%d\n",k+1);
	}
}