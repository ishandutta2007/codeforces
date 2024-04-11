#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ans,x,y;
char s[2005];
bool aim[2005][2005],now[2005][2005],a[2005],b[2005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=1;j<=n;++j)
		if(s[j]=='1')aim[i][j]=true;
	}
	for(i=1;i<n;++i)
	for(j=1;j<=i;++j)
	{
		x=j;y=n-i+1+j-1;
		now[x][y]=a[x]^b[y];
		if(aim[x][y]!=now[x][y])now[x][y]^=1,a[x]^=1,b[y]^=1,++ans;
	}
	for(i=1;i<=n;++i)now[i][i]^=a[i]^b[i],a[i]=b[i]=false;
	for(i=n;i>1;--i)
	for(j=i;j<=n;++j)
	{
		x=j;y=j-i+1;
		now[x][y]=a[x]^b[y];
		if(aim[x][y]!=now[x][y])now[x][y]^=1,a[x]^=1,b[y]^=1,++ans;
	}
	for(i=1;i<=n;++i)now[i][i]^=a[i]^b[i];
	for(i=1;i<=n;++i)if(now[i][i]!=aim[i][i])++ans;
	printf("%d\n",ans);
}