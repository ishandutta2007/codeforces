#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int M=1000+19;
struct note {int x,y;};
int A[M][M],Dis[M][M];
char s[M];
int r,c,Ans,sx,sy,ex,ey;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
queue<note> Q;

int main()
{
	scanf("%d%d",&r,&c);
	for (int i=1;i<=r;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=c;j++) 
			if (s[j-1]=='E') A[ex=i][ey=j]=-1;
				else if (s[j-1]=='S') A[sx=i][sy=j]=0;
					else if (s[j-1]=='T') A[i][j]=-1;else A[i][j]=s[j-1]-'0';
	}
	memset(Dis,60,sizeof(Dis));
	Q.push((note){ex,ey});
	Dis[ex][ey]=0;
	while (!Q.empty())
	{
		int x=Q.front().x,y=Q.front().y;Q.pop();
		for (int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if (nx>=1&&nx<=r&&ny>=1&&ny<=c&&A[nx][ny]!=-1&&Dis[nx][ny]>Dis[x][y]+1)
				Dis[nx][ny]=Dis[x][y]+1,Q.push((note){nx,ny});
		}
	}
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			if ((i!=sx||j!=sy)&&(i!=ex||j!=ey)&&Dis[i][j]<=Dis[sx][sy]) Ans+=A[i][j];
	printf("%d\n",Ans);
}