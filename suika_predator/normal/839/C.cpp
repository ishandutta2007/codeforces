#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
const int MAXN=100010;
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN*2];
int top;
void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
}
int pa[MAXN],vis[MAXN];
double len[MAXN];
void dfs(int u)
{
	vis[u]=1;
	int cnt=0;
	double sum=0.0;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!vis[tmp->v])
		{
			dfs(tmp->v);
			cnt++;
			sum+=len[tmp->v];
		}
	}
	if(cnt)
		len[u]=1.0+sum/cnt;
	else len[u]=0.0;
}
int main()
{
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	dfs(1);
	printf("%.9lf",len[1]);
	return 0;
}