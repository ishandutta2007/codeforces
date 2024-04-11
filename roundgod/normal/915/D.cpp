#include<bits/stdc++.h>
#define MAXV 505
#define MAXE 100005
using namespace std;
int V,E;
vector<int> G[MAXV];
int p[MAXV],color[MAXV];
vector<int> cycle,save;
bool dfs_visit(int v,int a,int b)
{
	if(cycle.size()) return false;
	color[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if((v==a)&&(to==b)) continue;
		if(color[to]==0)
		{
			p[to]=v;
			if(!dfs_visit(to,a,b)) return false;
		}
		else if(color[to]==1)
		{
			int x=v;
			while(true)
			{
				cycle.push_back(x);
				if(x==to) break;
				x=p[x];
			}
			return false;
		}
	}
	color[v]=2;
	return true;
}
bool dfs(int a,int b)
{
	cycle.clear();
	memset(color,0,sizeof(color));
	memset(p,-1,sizeof(p));
	for(int i=0;i<V;i++)
		if(color[i]==0)
			if(!dfs_visit(i,a,b)) return false;
	return true;
}
int main()
{
	scanf("%d%d",&V,&E);
	for(int i=0;i<E;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x-1].push_back(y-1);
	}
	if(dfs(0,0)) {puts("YES"); return 0;}
	for(int i=0;i<cycle.size();i++)
		save.push_back(cycle[i]);
	for(int i=0;i<save.size()-1;i++)
		if(dfs(save[i+1],save[i])) {puts("YES"); return 0;} 
	if(dfs(save[0],save[save.size()-1])) {puts("YES"); return 0;}
	puts("NO");
    return 0;
}