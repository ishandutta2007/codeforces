#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ans;
int sum[55][55];
char s[55];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;++j)
		{
			if(s[j]=='f')sum[i][j]=1;
			if(s[j]=='a')sum[i][j]=2;
			if(s[j]=='c')sum[i][j]=4;
			if(s[j]=='e')sum[i][j]=8;
		}
	}
	for(i=2;i<=n;++i)
	for(j=2;j<=m;++j)
	if(sum[i][j]+sum[i-1][j]+sum[i][j-1]+sum[i-1][j-1]==15)
	++ans;
	printf("%d\n",ans);
}