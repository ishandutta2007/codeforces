#include<bits/stdc++.h>
using namespace std;
vector<int> G[233333];
vector<int> vec,vec2;
int ex[233333],vis[233333];
void dfs(int u)
{
	vis[u]=1;
	vector<int> tmp;
	for(auto v:G[u])
	{
		if(!vis[v])
		{
			dfs(v);
			if(ex[v])tmp.push_back(v);
			else
				vec.push_back(u),vec.push_back(v);
		}
	}
	if(tmp.size()>=2)
	{
		vec2.push_back(ex[tmp[0]]),vec2.push_back(ex[tmp[1]]);
		for(int i=2;i<(int)tmp.size();i++)
		{
			vec.push_back(u),vec.push_back(tmp[i]);
			vec2.push_back(tmp[i]),vec2.push_back(ex[tmp[i]]);
		}
		ex[u]=0;
	}
	else if(tmp.size()==1)
	{
		ex[u]=ex[tmp[0]];
	}
	else
		ex[u]=u;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,u,v;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			ex[i]=vis[i]=0;
		}
		vec.clear();vec2.clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		if(ex[1])
			vec2.push_back(1),vec2.push_back(ex[1]);
		int tans=vec.size()/2;
		cout<<tans<<endl;
		for(int i=0;i<tans;i++)
		{
			cout<<vec[i*2]<<' '<<vec[i*2+1]<<' '<<vec2[i*2+1]<<' '<<vec2[i*2+2]<<endl;
		}
	}
	
	return 0;
}