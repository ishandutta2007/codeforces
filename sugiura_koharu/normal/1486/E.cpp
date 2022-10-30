#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <pair<int,int> > e[5500005];
vector <pair<int,int> > qwq;
int head[5505005],cnt,dis[5505005],vis[5505005];
priority_queue <pair<int,int>,vector <pair<int,int> >,greater <pair<int,int> > > q;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		for(int i=1;i<=50;i++)
		{
			e[u*51+i].push_back({v*51,(i+w)*(i+w)});
			e[v*51+i].push_back({u*51,(i+w)*(i+w)});
		}
		e[u*51].push_back({v*51+w,0});
		e[v*51].push_back({u*51+w,0});
	}
	for(int i=1;i<=n*51+100;i++)
		dis[i]=2e9;
	q.push({0,51}),dis[51]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto X:e[x])
		{
			if(dis[X.first]>dis[x]+X.second)
			{
				dis[X.first]=dis[x]+X.second;
				q.push({dis[X.first],X.first});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i*51]>1.5e9) dis[i*51]=-1;
		cout << dis[i*51] << " ";
	}
	return 0;
}