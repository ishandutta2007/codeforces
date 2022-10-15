#include<bits/stdc++.h>
#define MAXN 200005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,maxx,k,deg[MAXN];
vector<int> G[MAXN];
int color[MAXN];
void dfs(int v,int p)
{
	int ti=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(to==p) continue;
		while(ti==color[v]||(p!=-1&&ti==color[p]))
			ti++;
		color[to]=ti;
		ti++;
	}
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(to==p) continue;
		dfs(to,v);
	}
	return;
}
int main()
{
	memset(deg,0,sizeof(deg));
	scanf("%d",&n);
	maxx=0;
	int t=0;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
		deg[x]++;deg[y]++;
		if(deg[x]>maxx)
		{
			maxx=deg[x];
			t=x;
		}
		if(deg[y]>maxx)
		{
			maxx=deg[y];
			t=y;
		}
	}
	maxx++;
	printf("%d\n",maxx);
	memset(color,0,sizeof(color));
	color[t]=1;
	dfs(t,-1);
	for(int i=0;i<n;i++)
		printf("%d ",color[i]);
	return 0;
}