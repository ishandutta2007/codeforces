#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define MAX_V 200001
#define INF 100000000
using namespace std;
struct edge
{
	int to,cost;
};
typedef pair<int,int> P;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
void dijkstra(int s)
{
	priority_queue <P,vector<P>,greater<P> >que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p=que.top(); que.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main()
{
	scanf("%d",&V);
	for(int i=0;i<V-1;i++)
	{
		edge m;
		m.cost=1;
		m.to=i+1;
		G[i].push_back(m);
		m.to=i;
		G[i+1].push_back(m);
	}
	int x;
	for(int i=0;i<V;i++)
	{
		scanf("%d",&x);
		x-=1;
		edge m;
		m.cost=1;
		m.to=x;
		G[i].push_back(m);
	}
	dijkstra(0);
	for(int i=0;i<V;i++)
	  printf("%d ",d[i]);
	return 0;
}