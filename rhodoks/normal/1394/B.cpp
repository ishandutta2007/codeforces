#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

struct edge
{
	int w;
	int to;
	
	bool operator<(edge e)
	{
		return w<e.w;
	}
};

typedef pair<int,int> pii;
vector<edge> g[MAXN];
LL hsh[10][10]; 
int n,m,k;
LL ans=1,tmp=1;
int cnt;
void dfs(int x)
{
	if (x==k+1)
	{
		//WRT(ans);
		if (ans==tmp)
			cnt++;
		return;
	} 
	LL t=ans;
	for (int i=0;i<x;i++)
	{
		ans=t*hsh[x][i]%MOD;
		dfs(x+1);
	}
	ans=t;
}

int main()
{
	cin>>n>>m>>k;
	int x,y,w;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back({w,y});
	}
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			hsh[i][j]=1;
	for (int i=1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end());
		for (int j=0;j<g[i].size();j++)
			hsh[g[i].size()][j]=hsh[g[i].size()][j]*(g[i][j].to+19260817)%MOD;
	}
	for (int i=1;i<=k;i++)
		for (int j=0;j<i;j++)
			hsh[i][j]%=MOD;
	tmp=1;
	for (int i=1;i<=n;i++)
		tmp=tmp*(i+19260817)%MOD;
	//WRT(tmp);
	dfs(1);
	cout<<cnt;
	return ~~(0^_^0);
}