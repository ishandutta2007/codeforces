#include<bits/stdc++.h>

using namespace std;

int n,m,k,cnt,ans;
char mp[66][66],mp2[66][66];
int vis[66][66];

int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};

struct edge
{
	int pos,val;
}cc[6666];

void dfs(int x,int y)
{
	mp2[x][y]='*';
	//printf("%d %d\n",x,y);
	for(int i=1;i<=4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp2[nx][ny]=='.')
			dfs(nx,ny);
	}
}

void dfs2(int x,int y)
{
	vis[x][y]=cnt;
	//printf("%d %d\n",x,y);
	for(int i=1;i<=4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp2[nx][ny]=='.'&&!vis[nx][ny])
			dfs2(nx,ny);
	}
}

bool cmp(edge a,edge b)
{
	return a.val<b.val;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)	
	{
		string s;
		cin>>s;
		for(int j=1;j<=m;j++)
			mp[i][j]=s[j-1],mp2[i][j]=s[j-1];
			
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i==n||i==1||j==1||j==m)&&mp2[i][j]=='.')
			{
				dfs(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp2[i][j]=='.'&&!vis[i][j])
			{
				cnt++;
				dfs2(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])
				cc[vis[i][j]].val++,cc[vis[i][j]].pos=vis[i][j];
		}
	}
	sort(cc+1,cc+cnt+1,cmp);
	for(int v=1;v<=cnt-k;v++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]==cc[v].pos)
				{
					ans++;//printf("%d %d %d\n",i,j,ans);
					mp[i][j]='*';
				}
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%c",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}