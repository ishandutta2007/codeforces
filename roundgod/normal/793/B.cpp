#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 2005
#define INF 1000000000
using namespace std;
typedef pair<int,int> P;
int n,m;
char grid[MAXN][MAXN];
int sx,sy,tx,ty;
int d[MAXN][MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",grid[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]=='S') {sx=i;sy=j;}
			if(grid[i][j]=='T') {tx=i;ty=j;}
		}
	queue<P> que;
	que.push(P(sx,sy));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			d[i][j]=INF;
	d[sx][sy]=0;
	while(!que.empty())
	{
		P p=que.front();
		que.pop();
		int x=p.F,y=p.S;
		for(int i=1;i+x<n;i++)
		{
			if(grid[i+x][y]!='*'&&d[i+x][y]>d[x][y])
			{
				d[i+x][y]=d[x][y]+1;
				que.push(P(i+x,y));
			}
			else break;
		}
		for(int i=1;x-i>=0;i++)
		{
			if(grid[x-i][y]!='*'&&d[x-i][y]>d[x][y])
			{
				d[x-i][y]=d[x][y]+1;
				que.push(P(x-i,y));
			}
			else break;
		}
		for(int i=1;i+y<m;i++)
		{
			if(grid[x][i+y]!='*'&&d[x][i+y]>d[x][y])
			{
				d[x][i+y]=d[x][y]+1;
				que.push(P(x,i+y));
			}
			else break;
		}
		for(int i=1;y-i>=0;i++)
		{
			if(grid[x][y-i]!='*'&&d[x][y-i]>d[x][y])
			{
				d[x][y-i]=d[x][y]+1;
				que.push(P(x,y-i));
			}
			else break;
		}
	}
	if(d[tx][ty]>3) puts("NO"); else puts("YES");
	return 0;
}