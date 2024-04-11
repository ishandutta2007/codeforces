#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,t;
vector<int> G[MAXN];
bool connected[MAXN][MAXN];
int dist1[MAXN],dist2[MAXN];
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	memset(connected,false,sizeof(connected));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(!connected[x][y])
		{
			G[x].push_back(y);
			G[y].push_back(x);
		}
		connected[x][y]=connected[y][x]=true;
	}
	fill(dist1+1,dist1+n+1,INF);
	queue<P> que;
	que.push(P(s,0));
	while(que.size())
	{
		P p=que.front();
		que.pop();
		int v=p.F,d=p.S;
		if(dist1[v]<d) continue;
		dist1[v]=d;
		for(int i=0;i<G[v].size();i++)
			if(dist1[G[v][i]]==INF) que.push(P(G[v][i],d+1));
	}
	/*for(int i=1;i<=n;i++)
		printf("%d ",dist1[i]);
	puts("");*/
	fill(dist2+1,dist2+n+1,INF);
	que.push(P(t,0));
	while(que.size())
	{
		P p=que.front();
		que.pop();
		int v=p.F,d=p.S;
		if(dist2[v]<d) continue;
		dist2[v]=d;
		for(int i=0;i<G[v].size();i++)
			if(dist2[G[v][i]]==INF) que.push(P(G[v][i],d+1));
	}
	/*for(int i=1;i<=n;i++)
		printf("%d ",dist2[i]);
	puts("");*/
	int dis=dist1[t],cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!connected[i][j]&&(dist1[i]+1+dist2[j]>=dis&&dist2[i]+1+dist1[j]>=dis)) cnt++;
	printf("%d\n",cnt);
	return 0;
}