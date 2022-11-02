#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int nx,ny,i,j,k;
int x[10],y[10],xx[10],yy[10];
int dx[1000005],dy[1000005];
bool app[5][5];

int main()
{
	for(i=1;i<=8;++i)scanf("%d%d",&x[i],&y[i]),xx[i]=x[i],yy[i]=y[i];
	sort(xx+1,xx+9);sort(yy+1,yy+9);
	nx=unique(xx+1,xx+9)-(xx+1);
	ny=unique(yy+1,yy+9)-(yy+1);
	if(nx==3&&ny==3)
	{
		for(i=1;i<=3;++i)dx[xx[i]]=i,dy[yy[i]]=i;
		for(i=1;i<=8;++i)app[dx[x[i]]][dy[y[i]]]=true;
		app[2][2]^=1;
		for(i=1;i<=3;++i)
		for(j=1;j<=3;++j)
		if(!app[i][j])
		{
			printf("ugly\n");
			return 0;
		}
		printf("respectable\n");
		return 0;
	}
	printf("ugly\n");
}