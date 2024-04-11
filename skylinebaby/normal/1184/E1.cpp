#include<bits/stdc++.h>
using namespace std;
int papa [100001];
int riajuu[100001];
int King(int i)
{
	if (papa[i]!=i) return papa[i] = King(papa[i]);
	else return i;
}
void merge(int i,int j)
{
	if (riajuu[i]>=riajuu[j])
	{
		papa[j] = i;
		riajuu[i]+=riajuu[j];
	}
	else 
	{
		papa[i] = j;
		riajuu[j]+=riajuu[i];
	}
}
struct segment
{
	int first;
	int second;
	int weight;
};
bool operator < (const segment &a,const segment &b)
{
	return a.weight<b.weight;
}
segment s[1000001];
vector<pair<int,int> > adj[100001];
int vis[100001];
pair<int,int> pa[100001];
void dfs(int x)
{
	vis[x] = 1;
	for(int i = 0;i<adj[x].size();i++)
	{
		int y = adj[x][i].first;
		int w = adj[x][i].second;
		if(vis[y]) pa[x] = make_pair(y,w);
		else dfs(y);
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++) scanf("%d %d %d",&s[i].first,&s[i].second,&s[i].weight);
	sort(s+1,s+m);
	for(int i = 1;i<=n;i++)
	{
		papa[i] = i;
		riajuu[i] = 1;	
	}		
	for(int i = 1;i<m;i++)
	{
		if (King(s[i].first)==King(s[i].second)) continue;
		merge(King(s[i].first),King(s[i].second));
		adj[s[i].first].push_back(make_pair(s[i].second,s[i].weight));
		adj[s[i].second].push_back(make_pair(s[i].first,s[i].weight));		
	}
	int ans = 0;
	for(int i = 1;i<n;i++)
	{
		if (King(i)!=King(i+1))
		{
			ans = 1000000000;
			break;
		}
	}
	if(ans) 
	{
		printf("%d\n",ans);
		return 0;
	}
	dfs(1);
	//for(int i = 1;i<=n;i++) printf("%d %d %d\n",i,pa[i].first,pa[i].second);
	
	memset(vis,0,sizeof(vis));
	int x = s[0].first;
	vis[x] = 1;
	int y = s[0].second;
	while(x!=1)
	{
		int w = pa[x].second;
		int s = vis[x];
		x = pa[x].first;
		vis[x] = max(s,w+1);
	}
	if(vis[y])
	{
		printf("%d\n",vis[y]-1);
		return 0;
	}
	//for(int i = 1;i<=n;i++) printf("vis[%d] = %d\n",i,vis[i]);
	while(y!=1)
	{
		int w = pa[y].second;
		int s = vis[y];
		if(vis[pa[y].first])
		{
			printf("%d\n",max(max(s,vis[pa[y].first]),w+1)-1);
			return 0;
		}
		y = pa[y].first;
		vis[y] = max(s,w+1);		
	}
}