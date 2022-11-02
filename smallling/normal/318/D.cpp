#include<stdio.h>

using namespace std;

int f[5001][5001],n,m,x,y,i,j;

void ss(int x,int y,int o)
{
	if(o<4)return;
	f[x][y]=o%4;
	f[x+1][y]+=o/4;
	ss(x+1,y,f[x+1][y]);
	f[x][y+1]+=o/4;
	ss(x,y+1,f[x][y+1]);
	f[x-1][y]+=o/4;
	ss(x-1,y,f[x-1][y]);
	f[x][y-1]+=o/4;
	ss(x,y-1,f[x][y-1]);
}

int main()
{
	scanf("%d%d",&n,&m);
	f[2500][2500]=n;
	ss(2500,2500,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		x+=2500;
		y+=2500;
		if(x<=5000&&y<=5000&&x>=0&&y>=0)printf("%d\n",f[x][y]);
		else printf("0\n");
	}
}