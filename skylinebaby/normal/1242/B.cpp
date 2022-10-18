#include<bits/stdc++.h>
using namespace std;
int sz[123456];
int king[123456];
int deg[123456];
vector<int> adj[123456];
int find(int a){
	if(king[a] == a) return a;
	return king[a] = find(king[a]);
}
void merge(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(sz[x]>sz[y]) swap(x,y);
	sz[y] += sz[x];
	king[x] = y;
}
int main()
{
	int n;
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++)
	{
		sz[i] = 1;
		king[i] = i;
		deg[i] = 0;
	}
	for(int i = 0;i<m;i++)
	{
		int x;
		int y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x] ++;
		deg[y] ++;	
	}
	int p = 1;
	for(int i = 1;i<=n;i++)
	{
		adj[i].push_back(n+1);
		if(deg[p]>deg[i]) p = i;
		sort(adj[i].begin(),adj[i].end());
	}
	int pos = 1;
	int z = 0;
	for(int i = 0;i<adj[p].size();i++)
	{
		int y = adj[p][i];
		while(pos<y) 
		{
			if(find(pos)!=find(p))
			{
				merge(pos,p);
				z++;
			}
			pos++;
		}
		pos = y + 1;	
	}
	for(int i = 0;i<adj[p].size();i++)
	{
		int y = adj[p][i];
		int pos2 = 1;
		for(int j = 0;j<adj[y].size();j++)
		{
			int x = adj[y][j];
			while(pos2<x) 
			{
				if(find(pos2)!=find(y))
				{
					merge(pos2,y);
					z++;
				}
				pos2++;
			}
			pos2 = x + 1;	
		}
	}
	printf("%d\n",n - 1 - z);
	return 0;
}