#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
struct edge
{
	int v,w;
	edge *next;
}*h[233],pool[233333];
int ord[233],ind[233],top;
inline void addedge(int u,int v,int w)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->w=w;tmp->next=h[u];h[u]=tmp;ind[v]++;
}
int n,m;
int dp[111][111][33];//0:first,1:second
queue<int> q;
bool s(int i,int j,int k)
{
	if(dp[i][j][k])return dp[i][j][k];
	bool flag=0;
	for(edge *tmp=h[i];tmp;tmp=tmp->next)
	{
		if(tmp->w>=k&&s(j,tmp->v,tmp->w)==0)
		{
			flag=1;
			break;
		}
	}
	//cout<<"dp"<<' '<<i<<' '<<j<<' '<<k<<'='<<flag<<endl;
	return (dp[i][j][k]=flag);
}
int main()
{
	scanf("%d%d",&n,&m);
	int a,b;char c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d %c",&a,&b,&c);
		addedge(a,b,c-'a'+1);
	}
	/*for(int i=1;i<=n;i++)if(ind[i]==0)q.push(i);
	int cur=n;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		ord[cur--]=u;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			ind[tmp->v]--;
			if(ind[tmp->v]==0)q.push(tmp->v);
		}
	}
	for(int i=1;i<=n;i++)cout<<ord[i]<<' ';cout<<endl;*/
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			for(int k=0;k<=26;k++)
			{
				s(x,y,k);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%c","BA"[dp[i][j][0]]);
		}
		printf("\n");
	}
	return 0;
}