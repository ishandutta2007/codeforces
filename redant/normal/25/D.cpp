#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define PB push_back
#define MP make_pair
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()

vector<int> g[1005];
int id[1005];
int remu[1005], remv[1005], ri=1;
int has[1005][1005];
int vis[1005];
int ind=0,c=0;

void dfs(int i)
{
	id[c]=i;
	for(int j=0;j<g[i].size();j++)
	{
		int v = g[i][j];
		if(!vis[v])
		{
			has[i][v]=has[v][i]=0;
			vis[v]=1; dfs(v);
		}
	}
}

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u, &v);
		g[u].PB(v); g[v].PB(u);
		has[u][v]=has[v][u]=1;
	}

	for(i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		c++;
		vis[i]=1; dfs(i);
		ind++;
	}

	printf("%d\n",c-1);
	
	for(i=1;i<=n;i++) for(j=i+1;j<=n;j++)
	{
		if(has[i][j]){ remu[ri]=i; remv[ri]=j; ri++; }
	}

	for(i=1;i<=c-1;i++)
	{
		printf("%d %d %d %d\n",remu[i], remv[i], id[i],id[i+1]);
	}

	return 0;
}