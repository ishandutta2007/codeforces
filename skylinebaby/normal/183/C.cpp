#include<bits/stdc++.h>
using namespace std;
struct P
{
	int to,d;	
};
vector<P> adj[101010];
int col[101010];
int vis[101010];
int ans;
void dfs(int x,int k)
{
	if(vis[x])
	{
		if(ans==0) ans =abs( col[x] - k );
		else ans = __gcd(ans,abs( col[x] - k ));
		return;
	}
	vis[x] = 1;
	col[x] = k;
	for(int i = 0;i<adj[x].size();i++)
	{
		if (adj[x][i].d==1) dfs(adj[x][i].to,k+1);
		else dfs(adj[x][i].to,k-1);
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int flg=0;
	for(int i = 0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if (x==y) flg=1;
		adj[x].push_back((P){y,1});
		adj[y].push_back((P){x,-1});		
	}
	if (flg==1) 
	{
		printf("1\n");
		return 0;
	}
	ans = 0;
	for(int i = 0;i<n;i++)
	{
		if (vis[i]) continue;
		dfs(i,0);
	}
	if (ans==0) printf("%d\n",n);
	else printf("%d\n",ans);
	return 0;
}