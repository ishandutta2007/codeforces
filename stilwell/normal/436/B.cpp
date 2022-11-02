#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,K,i,j,k;
int ans[2005];
char s[2005][2005];

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		if(s[i][j]=='R'&&i+j-1<=m)++ans[i+j-1];
		if(s[i][j]=='L'&&j-i+1<=m)++ans[j-i+1];
		if(s[i][j]=='U'&&i%2==1)++ans[j];
	}
	printf("%d",ans[1]);
	for(i=2;i<=m;++i)printf(" %d",ans[i]);
	printf("\n");
}