#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <utility>
using namespace std;
vector<int> g[110000];
long long black,white;
int n;
void dfs(int x,int pre,int col)
{
	if (col==1)black++;
	else white++;
	int cnt=g[x].size();
	for(int i=0;i<cnt;i++)
		if (g[x][i]!=pre)dfs(g[x][i],x,col^1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=2;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	black=0,white=0;
	dfs(1,0,1);
	long long ans=black*white;
	ans=ans-n+1;
	cout<<ans<<endl;
}