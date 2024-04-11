#include<bits/stdc++.h>
using namespace std;
vector <int> adj[2001]; 
int vis[2001];
int pa[2001];
int sz[2001];
int ans[2001];
int iden; 
int n;
void dfs(int a,int x)
{
	vis[a] = x;
	for(int i = 0;i<adj[a].size(); i++)
	{
		if(!vis[adj[a][i]]) dfs(adj[a][i],x+1);
		if(vis[adj[a][i]]!=0 && (vis[adj[a][i]]-vis[a])%2==0)
		{
			iden=-1;
			break;
		}
	}
}
int find(int x)
{
	if(pa[x]==x) return x;
	return pa[x] = find(pa[x]);
}
void merge(int x,int y)
{
	if(find(x)==find(y)) return;
	int t = sz[find(x)];
	int s = sz[find(y)];
	if(t>s)
	{
		sz[find(x)] += s;
		pa[find(y)] = find(x);
	}
	else
	{
		sz[find(y)] += t;
		pa[find(x)] = find(y);
	}
}
int main()
{
	int m;
	iden = 0;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
	{
		pa[i] = i;
		sz[i] = 1;
	}
	for(int i = 0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
		merge(x-1,y-1);
	}
	for(int i = 0;i<n;i++)
	{
		if (!vis[i]) dfs(i,1);
		if (iden==-1)
		{
			printf("-1\n");
			return 0;
		}
	}
	//printf("ok\n");
	for(int i = 0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(i);
		int mx = 1;
		vis[i] = 1;
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(int j = 0;j<adj[x].size();j++)
			{
				int y = adj[x][j];
				if(vis[y]) continue;		
				vis[y] = vis[x] + 1;
				mx = max(mx,vis[y]);
				q.push(y);
			}
		}
		ans[find(i)] = max(ans[find(i)],mx-1);
 	}
 	int ral = ans[find(0)];
 	int cur = find(0);
 	for(int i = 1;i<n;i++)
 	{
 		if(find(i) == cur) continue;
 		ral += ans[find(i)];
 		merge(0,i);
 		cur = find(0);
	}
	printf("%d\n",ral);
	return 0;
}