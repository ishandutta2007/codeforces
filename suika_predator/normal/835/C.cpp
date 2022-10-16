#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,q,c;
int x,y,b;
int t,x1,y1,x2,y2;
int a[111][111][11];
int main()
{
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&b);
		for(int r=0;r<=c;r++)
		{
			a[x][y][r]+=(b+r)%(c+1);
		}
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			for(int r=0;r<=c;r++)
			{
				a[i][j][r]+=a[i][j-1][r];
			}
		}
	}
	for(int j=1;j<=100;j++)
	{
		for(int i=1;i<=100;i++)
		{
			for(int r=0;r<=c;r++)
			{
				a[i][j][r]+=a[i-1][j][r];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		t%=(c+1);
		printf("%d\n",a[x2][y2][t]-a[x1-1][y2][t]-a[x2][y1-1][t]+a[x1-1][y1-1][t]);
	}
	return 0;
}