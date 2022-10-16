#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,r,c,x,y,i,j,ans;
char p[2005][2005];
int f[2005][2005];
struct point
{
	int x,y,dis;
	point(){}
	point(int a,int b,int c)
	{
		x=a;
		y=b;
		dis=c;
	}
};
bool operator < (point x,point y)
{
	return x.dis>y.dis;
}
priority_queue <point> q;
point t;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&x,&y);
	for (i=1;i<=n;i++)
		scanf("%s",p[i]+1);
	memset(f,-1,sizeof(f));
	f[r][c]=0;
	q.push(point(r,c,0));
	while (!q.empty())
	{
		while (!q.empty())
		{
			t=q.top();
			q.pop();
			if (t.dis==f[t.x][t.y])
				break;
		}
		if (t.dis!=f[t.x][t.y])
			break;
		if (t.x>1&&p[t.x-1][t.y]!='*')
			if (f[t.x][t.y]<f[t.x-1][t.y]||f[t.x-1][t.y]==-1)
			{
				f[t.x-1][t.y]=f[t.x][t.y];
				q.push(point(t.x-1,t.y,f[t.x-1][t.y]));
			}
		if (t.x<n&&p[t.x+1][t.y]!='*')
			if (f[t.x][t.y]<f[t.x+1][t.y]||f[t.x+1][t.y]==-1)
			{
				f[t.x+1][t.y]=f[t.x][t.y];
				q.push(point(t.x+1,t.y,f[t.x+1][t.y]));
			}
		if (t.y>1&&p[t.x][t.y-1]!='*')
			if (f[t.x][t.y]<f[t.x][t.y-1]||f[t.x][t.y-1]==-1)
			{
				f[t.x][t.y-1]=f[t.x][t.y];
				q.push(point(t.x,t.y-1,f[t.x][t.y-1]));
			}
		if (t.y<m&&p[t.x][t.y+1]!='*')
			if (f[t.x][t.y]+1<f[t.x][t.y+1]||f[t.x][t.y+1]==-1)
			{
				f[t.x][t.y+1]=f[t.x][t.y]+1;
				q.push(point(t.x,t.y+1,f[t.x][t.y+1]));
			}
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (f[i][j]<=y&&f[i][j]-j+c<=x&&f[i][j]!=-1)
				ans++;
	printf("%d\n",ans);
	return 0;
}