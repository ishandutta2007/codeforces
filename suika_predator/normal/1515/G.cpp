#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v,w;
	edge *next;
}*h[233333],pool[555555];
int top;
inline void addedge(int u,int v,int w)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->w=w;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->w=-w;pmt->next=h[v];h[v]=pmt;
}
int n,m,q;
vector<int> G[233333];
int bel[233333],dfn[233333],low[233333],ins[233333];
int ind,ccnt;
stack<int> s;
void dfs(int u)
{
	dfn[u]=low[u]=++ind;
	s.push(u);ins[u]=1;
	for(auto v:G[u])
	{
		if(!ins[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]==1)
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u])
	{
		ccnt++;
		int v;
		do
		{
			v=s.top();s.pop();
			ins[v]=2;
			bel[v]=ccnt;
		}
		while(u!=v);
	}
}
long long gg[233333];
int vis[233333];
long long dep[233333];
void dfs2(int u)
{
	vis[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		int v=tmp->v;
		if(bel[u]==bel[v]&&!vis[v])
		{
			dep[v]=dep[u]+tmp->w;
			dfs2(v);
		}
		else if(bel[u]==bel[v])
		{
//			cerr<<"go "<<bel[u]<<' '<<dep[u]-dep[v]+tmp->w<<endl;
			gg[bel[u]]=__gcd(gg[bel[u]],abs(dep[u]-dep[v]+tmp->w));
		}
	}
}
int main()
{
	int u,v,l,a,b;
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>l;
		addedge(u,v,l);
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(!ins[i])
		{
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]==low[i])
		{
			dfs2(i);
		}
	}
//	for(int i=1;i<=n;i++)cerr<<bel[i]<<' ';cerr<<endl;
//	for(int i=1;i<=ccnt;i++)cerr<<gg[i]<<' ';cerr<<endl;
	cin>>q;
	while(q--)
	{
		cin>>v>>a>>b;
		if(a==0)cout<<"YES"<<endl;
		else
		{
			int xx=bel[v];
			if(gg[xx]==0)cout<<"NO"<<endl;
			else
			{
				long long g=__gcd(gg[xx],(long long)b);
				if(a%g==0)cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}