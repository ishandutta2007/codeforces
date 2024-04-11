#include<bits/stdc++.h>
#define MAXN 1005
#define M 10000000
#define int long long
using namespace std;
struct Node
{
	int x,y;
};
queue<Node>q;
int n,m,Q,a[MAXN][MAXN];
char ch[MAXN][MAXN];
signed main()
{
	memset(a,60,sizeof(a));
	scanf("%lld %lld %lld",&n,&m,&Q);
	for(int i=1;i<=n;i++) 
		scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ch[i][j]==ch[i-1][j]||ch[i][j]==ch[i+1][j]||ch[i][j]==ch[i][j-1]||ch[i][j]==ch[i][j+1])
			{
				a[i][j]=0;
				q.push((Node){i,j});	
			}
	while(!q.empty())
	{
		Node now=q.front();
		q.pop();
		int i=now.x,j=now.y;
		if(i+1<=n&&a[i+1][j]>M)
		{
			a[i+1][j]=a[i][j]+1;
			q.push((Node){i+1,j});
		}
		if(j+1<=m&&a[i][j+1]>M)
		{
			a[i][j+1]=a[i][j]+1;
			q.push((Node){i,j+1});
		}
		if(i-1>=1&&a[i-1][j]>M)
		{
			a[i-1][j]=a[i][j]+1;
			q.push((Node){i-1,j});
		}
		if(j-1>=1&&a[i][j-1]>M)
		{
			a[i][j-1]=a[i][j]+1;
			q.push((Node){i,j-1});
		}
	}
	while(Q--)
	{
		int x,y,t;
		scanf("%lld %lld %lld",&x,&y,&t);
		if(a[x][y]>t) 
			printf("%c\n",ch[x][y]);
		else
		{
			int p=t-a[x][y];
			if(p&1) 
				printf("%c\n",ch[x][y]=='0'?'1':'0');
			else 
				printf("%c\n",ch[x][y]);
		}
	}
	return 0;
}