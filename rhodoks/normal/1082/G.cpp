#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream> 
#include <queue>
#define MAXM 100010
#define MAXN 10010
using namespace std;

const int INF=2147483647;

int n,m,s,t;
long long maxflow=0;

struct EDGE
{
	int to,weight,next;
}edge[MAXM<<1];

int head[MAXN];
int deep[MAXN];
int cnt=0;

inline void add(int x,int y,int w)
{
	edge[cnt].to=y;
	edge[cnt].weight=w;
	edge[cnt].next=head[x];
	head[x]=cnt++;
	
	edge[cnt].to=x;
	edge[cnt].weight=0;
	edge[cnt].next=head[y];
	head[y]=cnt++;
}

void input()
{
	int x,y,w;
	cin>>n>>m;
	s=n+m+1;
	t=n+m+2;
	for (int i=1;i<=n+m+6;i++)
		head[i]=-1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(i,t,x);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(n+i,x,INF);
		add(n+i,y,INF);
		add(s,n+i,w);
		maxflow-=w;
	}
	n=t;
}

bool bfs()
{
	int cur;
	queue <int> q;
	for (int i=1;i<=n;i++)
		deep[i]=-1;
	deep[s]=0;
	q.push(s);
	while (!q.empty())
	{
		cur=q.front();
		q.pop();
		for (int i=head[cur];~i;i=edge[i].next)
			if (!~deep[edge[i].to] && edge[i].weight)
			{
				deep[edge[i].to]=deep[cur]+1;
				q.push(edge[i].to);
			}
	}
	if (~deep[t])
		return true;
	else
		return false;
}

int dfs(int cur,int limit)
{
	if (!limit || cur==t)
		return limit;
		
	int flow=0;
	int f;
	
	for (int i=head[cur];~i;i=edge[i].next)
	{
		if (deep[edge[i].to]==deep[cur]+1 && (f=dfs(edge[i].to,min(limit,edge[i].weight))))
		{
			flow+=f;
			limit-=f;
			edge[i].weight-=f;
			edge[i^1].weight+=f;
			if (!limit) break;
		}
	}
	if (!flow) deep[cur]=-1;
	return flow;
}

int dinic()
{
	while (bfs())
		maxflow+=dfs(s,INF);
	return maxflow;
}

int main()
{
	input();
	dinic();
	cout<<-maxflow<<endl;
	return 0;
}