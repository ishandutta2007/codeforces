#include<bits/stdc++.h>
#define MAXN 150005
#define F first
#define S second
using namespace std;
int n,m;
vector<int> G[MAXN];
int deg[MAXN];
bool used[MAXN];
vector<int> nodes;
void dfs(int x)
{
	used[x]=true;
	nodes.push_back(x);
	for(int i=0;i<G[x].size();i++)
	{
		int to=G[x][i];
		if(!used[to]) dfs(to); 
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(deg,0,sizeof(deg));
	nodes.clear();
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++)
	{
		if(!used[i]&&deg[i]>0)
		{
			dfs(i);
			int num=nodes.size();
			for(int j=0;j<nodes.size();j++)
				if(deg[nodes[j]]!=num-1)
				{
					puts("NO");
					return 0;
				}
			nodes.clear();
		}
	}
	puts("YES");
	return 0;
}