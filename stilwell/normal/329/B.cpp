#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x,y,D,ans;
char s[1005][1005];
int qx[1000005],qy[1000005],l,r;
int dist[1005][1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='E')
	r=1,qx[r]=i,qy[r]=j;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='T')dist[i][j]=10000000;
	dist[qx[r]][qy[r]]=1;
	while(l<r)
	{
		++l;x=qx[l];y=qy[l];
		if(x>1&&!dist[x-1][y])
		{
			dist[x-1][y]=dist[x][y]+1;
			qx[++r]=x-1;qy[r]=y;
		}
		if(x<n&&!dist[x+1][y])
		{
			dist[x+1][y]=dist[x][y]+1;
			qx[++r]=x+1;qy[r]=y;
		}
		if(y>1&&!dist[x][y-1])
		{
			dist[x][y-1]=dist[x][y]+1;
			qx[++r]=x;qy[r]=y-1;
		}
		if(y<m&&!dist[x][y+1])
		{
			dist[x][y+1]=dist[x][y]+1;
			qx[++r]=x;qy[r]=y+1;
		}
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='S')
	D=dist[i][j];
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]>='0'&&s[i][j]<='9'&&dist[i][j]<=D&&dist[i][j]!=0)
	ans+=s[i][j]-'0';
	printf("%d\n",ans);
}