#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,color[MAXN];
vector<P> G[MAXN];
int cnt[MAXN][2];
bool added[MAXN];
int l,r;
int ans[MAXN];
int pos[MAXN];
bool dfs(int v,int c)
{
	color[v]=c;
	for(auto e:G[v])
	{
		int to=e.F;
		if(color[to]==c) return false;
		if(!color[to]&&!dfs(to,-c)) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,type;
		scanf("%d%d%d",&type,&u,&v);
		type--;
		cnt[u][type]++; cnt[v][type]++;
		G[u].push_back(P(v,type)); G[v].push_back(P(u,type));
	}
	//1: L -1: R
	for(int i=1;i<=n;i++)
	{
		if(color[i]==0&&!dfs(i,1))
		{
			puts("NO");
			return 0;
		}
	}
	memset(added,false,sizeof(added));
	queue<int> que;
	l=1; r=n;
	for(int i=1;i<=n;i++)
	{
		if(!cnt[i][0]||!cnt[i][1])
		{
			added[i]=true;
			que.push(i);
		}
	}
	while(que.size())
	{
		int v=que.front(); que.pop();
		if(!cnt[v][0])//all destined
		{
			if(color[v]==1)
			{
				ans[r]=v; r--;
			}
			else 
			{
				ans[l]=v; l++;
			}
			for(auto e:G[v])
			{
				int to=e.F;
				if(added[to]) continue;
				cnt[to][1]--;
				if(cnt[to][1]==0)
				{
					que.push(to);
					added[to]=true;
				}
			}
		}
		else //all irrelevant
		{
			if(color[v]==1)
			{
				ans[l]=v; l++;
			}
			else 
			{
				ans[r]=v; r--;
			}
			for(auto e:G[v])
			{
				int to=e.F;
				if(added[to]) continue;
				cnt[to][0]--;
				if(cnt[to][0]==0)
				{
					que.push(to);
					added[to]=true;
				}
			}
		}
	}
	if(l<=r) {puts("NO"); return 0;}
	puts("YES");
	for(int i=1;i<=n;i++) pos[ans[i]]=i;
	for(int i=1;i<=n;i++) printf("%c %d\n",color[i]==1?'L':'R',pos[i]);
	return 0;
}