#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
pair<int,ll> f[MAXN][2];
vector<int> ans;
int w[MAXN];
void dfs(int v,int p)
{
	f[v][0]=P(0,0); f[v][1]=P(1,-(int)G[v].size());
	for(auto to:G[v])
	{
		if(to==p) continue;
		dfs(to,v);
		P pp=max(f[to][0],f[to][1]);
		f[v][0].F+=pp.F; f[v][0].S+=pp.S;
		f[v][1].F+=f[to][0].F; f[v][1].S+=f[to][0].S;
	}
}
void recover(int v,int p,int restrict=false)
{
	if(!restrict&&f[v][1]>f[v][0])
	{
		ans.push_back(v);
		for(auto to:G[v])
		{
			if(to==p) continue;
			recover(to,v,true);
		}
	}
	else
	{
		for(auto to:G[v])
		{
			if(to==p) continue;
			recover(to,v);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}
	if(n==2)
	{
		printf("2 2\n1 1\n");
		return 0;
	}
	dfs(1,0);
	recover(1,0);
	auto pp=max(f[1][0],f[1][1]);
	printf("%d %lld\n",pp.F,-pp.S+n-pp.F);
	for(int i=1;i<=n;i++) w[i]=1;
	for(auto x:ans) w[x]=(int)G[x].size();
	for(int i=1;i<=n;i++) printf("%d%c",w[i],i==n?'\n':' ');
	return 0;
}