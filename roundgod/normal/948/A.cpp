#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,m;
char mp[MAXN][MAXN];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<4;k++)
			{
				int ni=i+dx[k],nj=j+dy[k];
				if(ni>=0&&nj>=0&&ni<n&&nj<m)
				{
					if((mp[i][j]=='S'&&mp[ni][nj]=='W')||(mp[i][j]=='W'&&mp[ni][nj]=='S'))
					{
						puts("No");
						return 0;
					}
				}
			}
		}
	puts("Yes");
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mp[i][j]=='.') mp[i][j]='D';
	for(int i=0;i<n;i++)
		printf("%s\n",mp[i]);
	return 0;
}