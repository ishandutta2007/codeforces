#include<bits/stdc++.h>
using namespace std;
vector<int> adj[201010];
int dep[201010];
int pap[201010];
int sun[201010];
int xx[201010];
void dfs(int x)
{
	for(int j = 0;j<adj[x].size();j++)
	{
		int y = adj[x][j];
		if(y==pap[x]) continue;
		pap[y] = x;
		dep[y] = dep[x]+1;
		dfs(y);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int st;
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		sun[x]=i;
		xx[i]=x;
	}
	if(xx[0]!=1)
	{
		printf("No\n");
		return 0;
	}
	st = 1;
	memset(pap,0,sizeof(pap));
	memset(dep,0,sizeof(dep));
	pap[st] = st;
	dep[st] = 0;
	dfs(st);
	int f = 0;
	//for(int i = 0;i<n;i++)printf("%d %d %d\n",xx[i],pap[xx[i]],dep[xx[i]]);
	for(int i = 1;i<n;i++)
	{
		if(dep[xx[i-1]]<=dep[xx[i]]&&sun[pap[xx[i-1]]]<=sun[pap[xx[i]]]) continue;
		f = 1; 
	}
	if(f==0) printf("Yes\n");
	else printf("No\n");
	return 0;
}