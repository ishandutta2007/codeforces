#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,dis[3001][3001][2];
vector<int> G[3001][2];
set<pair<int,int>> v[3001][2];
array<int,5> ans;
void bfs(int s,int id)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		dis[s][i][id]=INF;
	dis[s][s][id]=0;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i:G[x][id])
			if(dis[s][i][id]>dis[s][x][id]+1)
			{
				dis[s][i][id]=dis[s][x][id]+1;
				q.push(i);
			}
	}
	for(int i=1;i<=n;i++)
		if(dis[s][i][id]!=INF)
		{
			v[s][id].insert({dis[s][i][id],i});
			if(v[s][id].size()>3)
				v[s][id].erase(v[s][id].begin());
		}
}
signed main()
{
	n=read();
	m=read();
	while(m--)
	{
		int x=read(),y=read();
		G[x][0].push_back(y);
		G[y][1].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i,0);
		bfs(i,1);
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			if(dis[i][l][0]!=INF&&i!=l)
				for(auto ii:v[i][1])
					for(auto ll:v[l][0])
					{
						int x=ii.second,y=ll.second;
						if(x==i||x==l||y==i||y==l||x==y)
							continue;
						int res=ii.first+ll.first+dis[i][l][0];
						if(res>ans[0])
							ans={res,x,i,l,y};
					}
	for(int i=1;i<=4;i++)
		cout<<ans[i]<<" ";
	return 0;
}