#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s;
vector<int> G[MAXN];
int u[MAXN],v[MAXN],dis[MAXN];
int cnt=0;
bool used[MAXN];
void dfs(int v)
{
	used[v]=true;
	cnt++;
	for(int i=0;i<G[v].size();i++)
		if(!used[G[v][i]]) dfs(G[v][i]);
}
void bfs(int s)
{
	fill(dis,dis+n,INF);
	memset(used,false,sizeof(used));
	queue<P> que;
	que.push(P(s,0));
	used[s]=true;
	while(que.size())
	{
		P p=que.front();
		que.pop();
		int v=p.F,d=p.S;
		dis[v]=d;
		cnt++;
		for(int i=0;i<G[v].size();i++)
		{
			if(!used[G[v][i]]) 
			{
				used[G[v][i]]=true;
				que.push(P(G[v][i],d+1));
			}
		}
	}
	return;
}
string ans;
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int type,x,y,t=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&type,&x,&y);
		if(type==1) G[x].push_back(y);
		else {u[t]=x; v[t]=y; t++;}
	}
	memset(used,false,sizeof(used));
	dfs(s);
	int res=cnt;
	for(int i=0;i<t;i++)
	{
		if(used[u[i]]&&!used[v[i]]) ans+="-";
		else if(!used[u[i]]&&used[v[i]]) ans+="+";
		else ans+="+";
	}
	cnt=0;
	for(int i=0;i<t;i++)
	{
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	bfs(s);
	printf("%d\n",cnt);
	for(int i=0;i<t;i++)
		if(dis[u[i]]>dis[v[i]]) printf("-"); else printf("+");
	puts("");
	printf("%d\n",res);
	cout<<ans<<endl;
	return 0;
}