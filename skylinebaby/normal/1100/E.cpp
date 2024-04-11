#include<bits/stdc++.h>
using namespace std;
struct qq{
	int first;int second;int third;
};
vector<qq> adj[123456];
int n;
int vis[123456];
int deg[123456];
int per[123456];
vector<int> need;
int flag;
int solve(int c)
{
	memset(deg,0,sizeof(deg));
	flag = 1; 
	for(int i = 1;i<=n;i++)
		for(int j = 0;j<adj[i].size();j++) if(adj[i][j].second>c) deg[adj[i][j].first]++;
	queue<int> q;
	for(int i = 1;i<=n;i++) if(!deg[i]) q.push(i);
	memset(vis,0,sizeof(vis));
	int pos = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		vis[v] = ++pos;
		//printf("%d %d\n",v,pos);
		for(int i = 0;i<adj[v].size();i++)
		{
			if(adj[v][i].second<=c) continue;
			deg[adj[v][i].first]--;
			if(!deg[adj[v][i].first]) q.push(adj[v][i].first);
		}
	}
	for(int i = 1;i<=n;i++) if(!vis[i]) flag = 0;
	return flag;
}
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++)
	{
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		adj[x].push_back((qq){y,c,i+1});
	}
	int L = 0;
	int R = 1000000000;
	while(L!=R)
	{
		int mid = (L+R-1)/2;
		if(solve(mid)) R = mid;
		else L = mid+1;
	}
	printf("%d",L);
	memset(deg,0,sizeof(deg));
	for(int i = 1;i<=n;i++)
		for(int j = 0;j<adj[i].size();j++) if(adj[i][j].second>L) deg[adj[i][j].first]++;
	queue<int> q;
	for(int i = 1;i<=n;i++) if(!deg[i]) q.push(i);
	memset(vis,0,sizeof(vis));
	int pos = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		vis[v] = pos++;
		//printf("%d %d\n",v,pos);
		for(int i = 0;i<adj[v].size();i++)
		{
			if(adj[v][i].second<=L) continue;
			deg[adj[v][i].first]--;
			if(!deg[adj[v][i].first]) q.push(adj[v][i].first);
		}
	}
	//for(int i = 1;i<=n;i++) printf("%d ",vis[i]);
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<adj[i].size();j++)
		{
			int y = adj[i][j].first;
			if(vis[y]<vis[i]) 
			{
				ans++;
				need.push_back(adj[i][j].third);
			}
		}
	}
	printf(" %d\n",ans);
	for(int i = 0;i<ans;i++)
	{
		printf("%d ",need[i]);
	}
	printf("\n");
	return 0;
}