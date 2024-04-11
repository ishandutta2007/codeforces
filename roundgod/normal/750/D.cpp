#include<bits/stdc++.h>
#define MAXN 405
#define F first
#define S second
using namespace std;
int dx[8]={0,1,1,1,0,-1,-1,-1},dy[8]={1,1,0,-1,-1,-1,0,1};
bool visited[MAXN][MAXN];
bool dp[MAXN][MAXN][8][30];
int n,ans=0;
int t[30];
void dfs(int x,int y,int dir,int num)
{
	if(num==n||dp[x][y][dir][num]) return;
	dp[x][y][dir][num]=true;
	for(int i=0;i<t[num];i++)
	{
		x+=dx[dir];
		y+=dy[dir];
		if(!visited[x][y])
		{
			visited[x][y]=true;
			ans++;
		}
	}
	dfs(x,y,(dir+1)%8,num+1);
	dfs(x,y,(dir+7)%8,num+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&t[i]);
	memset(visited,false,sizeof(visited));
	memset(dp,false,sizeof(dp));
	dfs(200,200,0,0);
	printf("%d\n",ans);
	return 0;
}