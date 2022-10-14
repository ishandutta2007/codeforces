#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];
bool visit[MAXN];
int ttt;
int ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}

int ans(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
void dfs(int pos,int fa)
{
	bool f=false;
	int to=-1;
	for (int i=0;i<g[pos].size()/2;i++)
	{
		int t=ask(g[pos][2*i],g[pos][2*i+1]);
		if (t==pos)
		{
			visit[g[pos][2*i]]=1;
			visit[g[pos][2*i+1]]=1;
		}
		else
		{
			to=t;
			g[t].erase(find(g[t].begin(),g[t].end(),pos));
			dfs(to,pos);
		}
	}
	if (g[pos].size() & 1)
	{
		if (g[pos][g[pos].size()-1]==fa)
		{
			int t=ask(g[pos][g[pos].size()-1],pos);
			if (t==pos)
				ans(pos);
			else
				ans(t);
		}
		dfs(g[pos][g[pos].size()-1],pos);
	}
	ans(pos);
}

int n;
int main()
{
	int x,y;
	cin>>n;
	if (n==2)
	{
		ans(ask(1,2));
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	return ~~(0^_^0);
}