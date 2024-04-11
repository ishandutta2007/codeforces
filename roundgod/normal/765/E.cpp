#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
using namespace std;
int n,root;
vector<int> G[MAXN];
int deg[MAXN],depth[MAXN],fa[MAXN],t,num;
void dfs(int v,int p,int d)
{
	depth[v]=d;
	if(d>num)
	{
		num=d;
		t=v;
	}
	fa[v]=p;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v,d+1);
	}
}
int find_ans(int v,int p)
{
	if(v==root)
	{
		int res=-1,last1=-1,last2=-1;
		for(int i=0;i<G[v].size();i++)
		{
			if(G[v][i]==p) continue;
			res=find_ans(G[v][i],v);
			if(res==-1) return -1;
			if(last1!=-1&&res!=last1&&last2!=-1&&res!=last2) return -1;
			if(res!=last1&&last2==-1) last2=res;
			else if(res!=last2&&last1==-1) last1=res;
		}
		return max(last1,0)+max(last2,0)+1;
	}
	if(deg[v]>=3)
	{
		int res=-1,last=-1;
		for(int i=0;i<G[v].size();i++)
		{
			if(G[v][i]==p) continue;
			res=find_ans(G[v][i],v);
			if(res==-1||(last!=-1&&res!=last)) return -1;
			last=res;
		}
		return last+1;
	}
	else if(deg[v]==1)
	{
		return 1;
	}
	else
	{
		for(int i=0;i<G[v].size();i++)
		{
			if(G[v][i]==p) continue;
			int res=find_ans(G[v][i],v);
			if(res==-1) return -1; else return res+1;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		G[i].clear();
	memset(deg,0,sizeof(deg));
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	int ans=n;
	t=-1;num=-1;
	dfs(0,-1,0);
	int dummy=t;
	t=-1;num=-1;
	dfs(dummy,-1,0);
	int result=num/2;
	while(depth[t]!=result)
		t=fa[t];
	root=t;
	ans=find_ans(root,-1);
	if(ans==-1)
	{
		puts("-1");
		return 0;
	}
	ans--;
	while(ans%2==0)
		ans/=2;
	printf("%d\n",ans);
	return 0;
}