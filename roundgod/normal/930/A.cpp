#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,p[MAXN],depth[MAXN],cnt[MAXN];
vector<int> G[MAXN];
void dfs(int v,int d)
{
	depth[v]=d;
	cnt[d]++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p[v]) continue;
		dfs(G[v][i],d+1);
	}
}
int main()
{
	scanf("%d",&n);
	p[1]=-1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&p[i]);
		G[p[i]].push_back(i);
		G[i].push_back(p[i]);
	}
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=100000;i++)
		ans+=cnt[i]&1;
	printf("%d\n",ans);
	return 0;
}