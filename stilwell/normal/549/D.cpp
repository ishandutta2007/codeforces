#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,ans;
int sum[105];
char s[105][105];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=n;i>=1;--i)
	{
		k=0;
		for(j=m;j>=1;--j)
		{
			k+=sum[j];
			if(s[i][j]=='W')l=1;
			else l=-1;
			if(k!=l)++ans,sum[j]+=l-k,k=l;
		}
	}
	printf("%d\n",ans);
}