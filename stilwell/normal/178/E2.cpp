#include <stdio.h>
#include <stdlib.h>
#define inf 10000
using namespace std;

int n,i,j,k,ans1,ans2;
int a[2005][2005],b[2005][2005];
int qx[4000005],qy[4000005],ll,rr;
int dx[20],dy[20];
char ch;

void add(int x,int y)
{
	a[x][y]=0;++rr;
	qx[rr]=x;qy[rr]=y;
}

void bfs(int sx,int sy)
{
	int i,j,k,x,y,d;
	qx[1]=sx;qy[1]=sy;
	a[sx][sy]=0;
	for(ll=rr=1;ll<=rr;++ll)
	{
		x=qx[ll];y=qy[ll];
		if(a[x-1][y])add(x-1,y);
		if(a[x+1][y])add(x+1,y);
		if(a[x][y-1])add(x,y-1);
		if(a[x][y+1])add(x,y+1);
	}
	if(rr<=60)return;
	dx[1]=inf;dy[1]=inf;
	dx[2]=inf;dy[2]=-inf;
	dx[3]=inf;dy[3]=-inf;
	dx[4]=-inf;dy[4]=-inf;
	dx[5]=-inf;dy[5]=-inf;
	dx[6]=-inf;dy[6]=inf;
	dx[7]=-inf;dy[7]=inf;
	dx[8]=inf;dy[8]=inf;
	for(i=1;i<=rr;++i)
	{
		x=qx[i];y=qy[i];
		if(x<dx[1]||(x==dx[1]&&y<dy[1]))dx[1]=x,dy[1]=y;
		if(x<dx[2]||(x==dx[2]&&y>dy[2]))dx[2]=x,dy[2]=y;
		if(y>dy[3]||(y==dy[3]&&x<dx[3]))dx[3]=x,dy[3]=y;
		if(y>dy[4]||(y==dy[4]&&x>dx[4]))dx[4]=x,dy[4]=y;
		if(x>dx[5]||(x==dx[5]&&y>dy[5]))dx[5]=x,dy[5]=y;
		if(x>dx[6]||(x==dx[6]&&y<dy[6]))dx[6]=x,dy[6]=y;
		if(y<dy[7]||(y==dy[7]&&x>dx[7]))dx[7]=x,dy[7]=y;
		if(y<dy[8]||(y==dy[8]&&x<dx[8]))dx[8]=x,dy[8]=y;
	}
	d=0;
	for(i=1;i<=8;++i)
	for(j=i+1;j<=8;++j)
	{
		x=dx[i]-dx[j];
		y=dy[i]-dy[j];
		if(x*x+y*y>d)d=x*x+y*y;
	}
	double w=((double)rr)/d;
	if(w>0.6)++ans1;
	else ++ans2;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		for(ch=getchar();ch!='0'&&ch!='1';ch=getchar());
		b[i][j]=ch-'0';
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		a[i][j]=b[i][j];
		k=a[i-1][j]+a[i][j-1]+a[i][j+1]+a[i+1][j];
		if(k>=3)a[i][j]=1;
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(a[i][j])
	bfs(i,j);
	printf("%d %d\n",ans1,ans2);
}