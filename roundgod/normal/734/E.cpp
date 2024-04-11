#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,color[MAXN],num[MAXN];
int E[MAXN][2];
vector<int> G[MAXN],GG[MAXN];
int dep[MAXN];
bool used[MAXN];
void dfs(int v,int id)
{
	used[v]=true;
	num[v]=id;
	for(int i=0;i<G[v].size();i++)
		if(color[G[v][i]]==color[v]&&!used[G[v][i]]) dfs(G[v][i],id);
}
void dfs1(int v,int p,int d)
{
	dep[v]=d;
	for(int i=0;i<GG[v].size();i++)
	{
		if(GG[v][i]==p) continue;
		dfs1(GG[v][i],v,d+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&color[i]);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&E[i][0],&E[i][1]);
		G[E[i][0]].push_back(E[i][1]);G[E[i][1]].push_back(E[i][0]);
	}
	memset(num,-1,sizeof(num));
	memset(used,false,sizeof(used));
	int t=0;
	for(int i=1;i<=n;i++)
		if(num[i]==-1) {dfs(i,t); t++;}
	for(int i=0;i<n-1;i++)
	{
		if(num[E[i][0]]!=num[E[i][1]])
		{
			GG[num[E[i][0]]].push_back(num[E[i][1]]);
			GG[num[E[i][1]]].push_back(num[E[i][0]]);
		}
	}
	memset(dep,0,sizeof(dep));
	dfs1(0,-1,0);
	int tt=-1,res=-1;
	for(int i=0;i<t;i++)
		if(dep[i]>res)
		{
			res=dep[i];
			tt=i;
		}
	dfs1(tt,-1,0);
	res=-1;
	for(int i=0;i<t;i++)
		if(dep[i]>res) res=dep[i];
	printf("%d\n",(res+1)/2);
	return 0;
}