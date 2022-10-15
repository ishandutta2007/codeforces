#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<int> G[MAXN];
int c[MAXN];
void dfs(int v,int p,int col)
{
	c[v]=col;
	for(auto to:G[v])
	{
		if(to==p) continue;
		dfs(to,v,-col);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) c[i]=0,G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v); G[v].push_back(u);
		}
		dfs(1,0,1);
		for(int i=1;i<=n;i++) printf("%d%c",(c[i]==1?(int)G[i].size():-(int)G[i].size()),i==n?'\n':' ');
	}
	return 0;
}