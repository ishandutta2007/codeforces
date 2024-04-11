#include<bits/stdc++.h>

using namespace std;

const int maxn=100010;

int outn[maxn],head[maxn],vis[233][233],vis2[233][233],last;

struct edge
{
	int to,nxt,flag;
}e[maxn];

int T,cnt,n,m;

void addedge(int x,int y,int flag)
{
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].flag=flag;
}

void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].flag&&(!vis[x][e[i].to]))
		{
			vis[x][e[i].to]=vis[e[i].to][x]=1;
			printf("%d %d\n",x,e[i].to);
			dfs(e[i].to);
			return ;
		}
		else if((!e[i].flag)&&(!vis2[x][e[i].to]))
		{
			vis2[x][e[i].to]=vis2[e[i].to][x]=1;
			dfs(e[i].to);
			return ;
		}
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		memset(e,0,sizeof(e));
		memset(outn,0,sizeof(outn));
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y,1);
			addedge(y,x,1);
			outn[x]+=1;
			outn[y]+=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!(outn[i]&1))
				ans++;
			else
			{
				if(!last)
				{
					addedge(last,i,0);
					addedge(i,last,0);
				}
				else
					last=i;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			dfs(i);
		}
	}
	return 0;
}