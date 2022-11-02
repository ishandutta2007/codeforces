#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
char s[2][100005];
int qx[200005],qy[200005],l,r,x,y;
int dis[2][100005];

void update(int x,int y,int z)
{
	if(y>n)
	{
		printf("YES\n");
		exit(0);
	}
	if(dis[x][y]||s[x][y]=='X')return;
	++r;qx[r]=x;qy[r]=y;
	dis[x][y]=z;
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	qx[1]=0;qy[1]=1;l=0;r=1;dis[0][1]=1;
	while(l<r)
	{
		++l;x=qx[l];y=qy[l];
		
		if(dis[x][y]>y)continue;
		update(x,y-1,dis[x][y]+1);
		update(x,y+1,dis[x][y]+1);
		update(1-x,y+m,dis[x][y]+1);
	}
	printf("NO\n");
}