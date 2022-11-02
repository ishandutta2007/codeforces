#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
char s[60][60];
int d[60][60],used[60][60];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

#define f(i,n) for (int i=0;i<n;i++)
#define val(x,y) x>=0&&x<n&&y>=0&&y<m

int main()
{
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)gets(s[i]);
	int ans=1e6;
	f(i,n)f(j,m)if (!used[i][j])
	{
		deque <pair<int,int> > q;
		q.push_back(make_pair(i,j));
		f(k,n)f(l,m)d[k][l]=1e6;d[i][j]=0;
		while (!q.empty())
		{
			pair<int,int> p=q.front();q.pop_front();
			int x=p.first,y=p.second;
			f(k,4)if(val(x+dx[k],y+dy[k]))
			{
				int nx=x+dx[k],ny=y+dy[k],g=s[x][y]!=s[nx][ny];
				if (!g&&d[nx][ny]>d[x][y]+g)q.push_front(make_pair(nx,ny)),d[nx][ny]=d[x][y]+g; else
				if (d[nx][ny]>d[x][y]+g)q.push_back(make_pair(nx,ny)),d[nx][ny]=d[x][y]+g;
			}
		}
		int res=0;
		f(k,n)f(l,m)res=max(res,d[k][l]),used[k][l]|=(bool)!d[k][l];
		res+=(res%2)!=(s[i][j]=='B');
		ans=min(ans,res);
	}
	printf("%d\n", ans);
}