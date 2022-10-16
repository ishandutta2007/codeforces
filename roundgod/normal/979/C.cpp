#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN],s[MAXN],t[MAXN],tot;
void dfs(int v,int p,int d)
{
	s[v]=++tot;
	int res=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v,d+1);
		res+=sz[G[v][i]];
	}
	sz[v]=res+1;
	t[v]=tot;
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);G[v].push_back(u);
	}
	dfs(x,-1,0);
	int cnt1=sz[y],cnt2;
	for(int i=0;i<G[x].size();i++)
	{
		if(s[G[x][i]]<=s[y]&&t[G[x][i]]>=t[y])
		{
			cnt2=sz[G[x][i]];
			break;
		}
	}
	printf("%I64d\n",1LL*n*(n-1)-1LL*(n-cnt2)*cnt1);
	return 0;
}