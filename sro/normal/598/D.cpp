#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const char dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},MAXD=4;
int n,m,k,cnt=0,a,b;
char mapom[1024][1024];
int richly[1024*1024];
int weid3s[1024][1024],cn2=0;

inline void dfs(int x,int y)
{
	mapom[x][y]='?';//????????
	for(int i=0;i<MAXD;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0&&nx>=n&&ny<0&&ny>=m)continue;
		if(mapom[nx][ny]=='*')
			cnt++;
		else if(mapom[nx][ny]=='.')
			weid3s[nx][ny]=cn2,dfs(nx,ny);
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)scanf("%s",mapom[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(mapom[i][j]=='.')
			{
				cnt=0;weid3s[i][j]=++cn2;
				dfs(i,j);
				richly[cn2]=cnt;
			}
		}
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		printf("%d\n",richly[weid3s[a][b]]);
	}
	return 0;
}
//
//
//